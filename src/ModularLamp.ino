#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_Sensor.h>
#include <SPI.h>
#include <string>
#include <ctime>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <DHT.h>

// DHT11 Sensor
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// RGB
#define REDPIN 12
#define GREENPIN 13
#define BLUEPIN 15

// SH1106 Screen
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Replace with your network credentials
const char *ssid = "Orange_Swiatlowod_B50A";
const char *password = "T5XHX957MJAG";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// Week Days
String weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Month names
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void setup()
{
  Serial.begin(9600);
  dht.begin();

  // Pin configuration
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  // SH1106 Screen configuration
  delay(250);
  display.begin(i2c_Address, true);
  display.setRotation(2);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  // Connect to Wi-Fi
  display.print("Connecting to ");
  display.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    display.print(".");
  }
  timeClient.begin();
  timeClient.setTimeOffset(7200);
}

void loop()
{
  drawDateTime();
}

void drawDateTime()
{
  // Odczytujemy wilgotność i temperaturę z czujnika DHT11
  int humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Sprawdzamy, czy udało się pobrać wartości z czujnika DHT11
  if (isnan(humidity) || isnan(temperature))
    Serial.println("Nie udało się odczytać wartości z czujnika DHT11!");
  else
  {
    // Ustawiamy kolor diody RGB w zależności od wilgotności
    if (humidity < 30)
    {
      // Wilgotność poniżej 30% - dioda świeci na niebiesko
      digitalWrite(REDPIN, LOW);
      digitalWrite(GREENPIN, LOW);
      digitalWrite(BLUEPIN, HIGH);
    }
    else if (humidity >= 30 && humidity <= 60)
    {
      // Wilgotność między 30% a 60% - dioda świeci na zielono
      digitalWrite(REDPIN, LOW);
      digitalWrite(GREENPIN, HIGH);
      digitalWrite(BLUEPIN, LOW);
    }
    else
    {
      // Wilgotność powyżej 60% - dioda świeci na czerwono
      digitalWrite(REDPIN, HIGH);
      digitalWrite(GREENPIN, LOW);
      digitalWrite(BLUEPIN, LOW);
    }
  }

  display.clearDisplay();
  display.setCursor(15, 10);
  display.setTextSize(2);
  timeClient.update();
  String time = timeClient.getFormattedTime();
  display.println(time);
  display.setTextSize(1);
  // Humidity section
  display.setCursor(0, 55);
  display.print(humidity);
  display.print("%");

  // Temperature section
  display.setCursor(80, 55);
  display.print(temperature);
  int x_pos = display.getCursorX();
  int y_pos = display.getCursorY();
  display.setCursor(x_pos + 2, y_pos);
  display.drawCircle(x_pos + 2, y_pos + 1, 1, SH110X_WHITE);
  x_pos = display.getCursorX();
  y_pos = display.getCursorY();
  display.setCursor(x_pos + 4, y_pos);
  display.print("C");
  display.display();
  delay(1000);
}
