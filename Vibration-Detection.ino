#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width
#define SCREEN_HEIGHT 64 // OLED display height

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

#define VIBRATION_SENSOR_PIN 2
#define BUZZER_PIN 3
#define RED_LED_PIN 4
#define GREEN_LED_PIN 5

// Define the bell icon as a 8x8 bitmap
static const unsigned char PROGMEM bell_bmp[] =
{ 
  B00011000,
  B00111100,
  B00111100,
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B00011000
};

void setup() {
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
}

void loop() {
  int sensorValue = digitalRead(VIBRATION_SENSOR_PIN);
  if(sensorValue == HIGH) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Vibration Detected!");
    display.drawBitmap(64, 0, bell_bmp, 8, 8, 1); // Draw the bell icon at (64,0)
    display.display();
    delay(5000); // buzzer beeps and LED glows for 5 seconds
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    display.clearDisplay();
    display.display();
  } else {
    digitalWrite(GREEN_LED_PIN, HIGH);
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("No Vibration Detected");
    display.display();
  }
}
