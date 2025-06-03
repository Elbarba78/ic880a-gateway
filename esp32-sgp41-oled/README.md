# Demo ESP32-S3 SGP41 OLED

Questo esempio mostra come leggere i valori grezzi di VOC e NOx dal sensore Sensirion SGP41 e visualizzarli su un display OLED SSD1306 da 0,96" con il framework Arduino. L'alimentazione avviene tramite batteria 18650 ricaricata da un modulo TP4056 e controllata da un interruttore MTS-103.

## Hardware

- **Microcontrollore**: modulo ESP32-S3
- **Sensore gas**: Sensirion SGP41 (indirizzo I²C `0x59`)
- **Display**: OLED 0,96" SSD1306, 128x64 pixel
- **Alimentazione**: batteria 18650, caricatore TP4056 con protezione e interruttore a levetta MTS-103

### Collegamenti

| Pin ESP32-S3  | SGP41 | OLED |
|---------------|-------|------|
| 3V3           | VCC   | VCC  |
| GND           | GND   | GND  |
| GPIO21 (SDA)  | SDA   | SDA  |
| GPIO22 (SCL)  | SCL   | SCL  |

Nel codice questi pin sono definiti come `SDA_PIN` e `SCL_PIN`. Se la tua scheda usa pin differenti, modifica queste costanti in `src/main.cpp`.

Collega la batteria al modulo TP4056, quindi all'interruttore MTS-103 e infine al pin di alimentazione dell'ESP32 ("VBAT" o "5V" a seconda del modulo). Il TP4056 protegge la cella da sovraccarica.

## Compilazione

Usa PlatformIO o l'Arduino IDE (core ESP32 >= 2.0). Le librerie necessarie sono:

- `Adafruit SSD1306`
- `Adafruit GFX`
- `Sensirion I2C SGP41`

## Utilizzo

Carica lo sketch in `src/main.cpp` sulla tua scheda. Il display mostrerà ogni secondo i valori grezzi di VOC e NOx letti dal sensore.
