#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SensirionI2CSgp41.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SensirionI2CSgp41 sgp41;

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("OLED init failed"));
        while (true)
            ;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("SGP41 Demo"));
    display.display();

    sgp41.begin(Wire);
    // Conditioning, uses default values for humidity and temperature (0)
    sgp41.executeConditioning(0, 0);
}

void loop() {
    uint16_t vocRaw = 0;
    uint16_t noxRaw = 0;
    if (sgp41.measureRawSignal(vocRaw, noxRaw) == 0) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print(F("VOC: "));
        display.println(vocRaw);
        display.print(F("NOx: "));
        display.println(noxRaw);
        display.display();
    } else {
        Serial.println(F("SGP41 read failed"));
    }
    delay(1000);
}
