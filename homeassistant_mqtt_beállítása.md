# Home Assistant MQTT Statestream és Univerzális Vezérlés Útmutató

Ez az útmutató bemutatja, hogyan konfigurálhatod a **Home Assistant MQTT Statestream** integrációját, hogyan szűrheted az átvitt entitásokat a hálózat védelmében, és hogyan hozhatsz létre egyetlen **univerzális automatizálást** az eszközök MQTT-n keresztüli vezérlésére.

---

## 1. MQTT Statestream beállítása (`configuration.yaml`)

Az MQTT Statestream integráció automatikusan közzéteszi az entitások állapotváltozásait az MQTT brókeren. 

### Szűrés (Ajánlott lépés!)
Ha nagyon sok okoseszközöd van, a teljes rendszer kiárasztása MQTT-re feleslegesen leterhelheti a hálózatot. Érdemes pontosan megadni, melyik entitásokat vagy domaineket akarod megosztani.

Az alábbi példa bemutatja az alapbeállításokat, kiegészítve a **domain és entitás szintű szűréssel**, hogy csak a kijelölt lámpák és kapcsolók kerüljenek átadásra:

```yaml
# configuration.yaml kiegészítése
mqtt_statestream:
  base_topic: homeassistant
  publish_attributes: true
  publish_timestamps: true
  
  # Szűrés: Csak a megadott domainek vagy entitások kerülnek publikálásra
  include:
    domains:
      - switch
      - light
    entities:
      - binary_sensor.nappali_mozes_erzekelo
```

---

## 2. Univerzális Vezérlő Automatizálás (`automations.yaml`)

Ahelyett, hogy minden egyes kapcsolóhoz külön automatizálást írnál, az alábbi **univerzális automatizmus** dinamikusan kezeli az összes `homeassistant/switch/<kapcsolo_neve>/set` topikra érkező parancsot.

A kód kinyeri a kapcsoló pontos nevét az MQTT témakörből (`trigger.topic`), és közvetlenül a megfelelő Home Assistant entitásnak adja át az `ON` vagy `OFF` parancsot.

```yaml
- id: mqtt_universal_switch_control
  alias: "MQTT Univerzális Kapcsoló Vezérlés"
  description: "Bármilyen homeassistant/switch/+/set topikra érkező üzenetet kezel és végrehajt"
  trigger:
    - platform: mqtt
      topic: "homeassistant/switch/+/set"
  condition:
    - condition: template
      value_template: "{{ trigger.payload in ['ON', 'OFF'] }}"
  action:
    - service: "switch.turn_{{ trigger.payload | lower }}"
      target:
        entity_id: "switch.{{ trigger.topic.split('/')[2] }}"
  mode: parallel
  max: 10
```

### Hogyan működik?
1. **Trigger:** Figyeli a `homeassistant/switch/+/set` témakört, ahol a `+` egy helyettesítő karakter (wildcard) bármelyik kapcsoló nevére.
2. **Condition:** Ellenőrzi, hogy a beérkező üzenet (payload) valóban `ON` vagy `OFF` értékű-e, kiszűrve a hibás parancsokat.
3. **Action:** 
   - A `switch.turn_{{ trigger.payload | lower }}` dinamikusan `switch.turn_on` vagy `switch.turn_off` szolgáltatást hív meg.
   - A `trigger.topic.split('/')[2]` darabolja a topikot a `/` karakterek mentén, és kinyeri a harmadik elemet (a kapcsoló objektumazonosítóját), így pontosan a célzott `switch.id` fog átkapcsolni.
   - A `mode: parallel` biztosítja, hogy ha egyszerre több eszköz kap parancsot, az automatizmus mindegyiket párhuzamosan fel tudja dolgozni.
