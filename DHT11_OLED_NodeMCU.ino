#include<Adafruit_SSD1306.h>
#include<DHT.h>
#define PIN D5
#define TYPE DHT11 // DHT22 DHT21
#define RESET LED_BUILTIN

Adafruit_SSD1306 oled(RESET);
DHT dht(PIN, TYPE);

float temperature, humidity;
void setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.display();
  delay(2000);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setCursor(0, 0);
  oled.print("WELCOME\nTO\nIoT");
  oled.display();
  delay(2000);
}
void loop()
{
  temperature = dht.readTemperature(); // For Degree Fahrenheit use dht.readTemperature(true);
  humidity = dht.readHumidity();
  delay(2000);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setCursor(0, 0);
  oled.print("DHT - 11");
  oled.println();
  oled.print("TEMP");
  oled.println();
  oled.print(temperature);
  oled.display();
  delay(2000);
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.print("DHT - 11");
  oled.println();
  oled.print("HUMIDITY");
  oled.println();
  oled.print(humidity);
  oled.display();
  delay(2000);
}
