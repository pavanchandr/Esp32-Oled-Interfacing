#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//OLED display Size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//ESP32 I2C pins
#define OLED_SDA 23
#define OLED_SCL 21

//Create displey object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Start I2C with custom pins
  Wire.begin(OLED_SDA, OLED_SCL);

  //Initialise OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();

  //Draw some text
  display.setTextSize(2);//Text size
  display.setTextColor(SSD1306_WHITE);//Text colour
  display.setCursor(0,0);//Start at top left
  display.print("Hi Pavan");

  display.display();// Push buffer to screen
}

void loop() {
  // put your main code here, to run repeatedly:

}
