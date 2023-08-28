# AmbientHue Modular OLED RGB Lamp with Environmental Monitoring

This project involves creating a modular lamp equipped with various sensors to monitor the environment and display relevant information on an OLED screen. The lamp incorporates features such as temperature and humidity sensing, RGB lighting, and a real-time clock.

## Features

- **Environmental Monitoring:** The lamp includes a DHT11 sensor to measure temperature and humidity levels in the surrounding environment.

- **RGB Lighting:** The lamp's RGB LED is used to indicate humidity levels: blue for humidity below 30%, green for humidity between 30% and 60%, and red for humidity above 60%.

- **Real-Time Clock:** The lamp retrieves accurate time information from an NTP server using Wi-Fi connectivity and displays it on an OLED screen.

## Components Used

- ESP8266 microcontroller
- DHT11 sensor for temperature and humidity monitoring
- RGB LED for ambient lighting
- SH1106 OLED screen for displaying information
- Wi-Fi module for internet connectivity

## Installation and Setup

1. Install the required libraries for the project, including `Adafruit_GFX`, `Adafruit_SH110X`, `Adafruit_Sensor`, `SPI`, `Wire`, `ESP8266WiFi`, `NTPClient`, and `WiFiUdp`.

2. Modify the Wi-Fi network credentials (`ssid` and `password`) in the code to match your network.

3. Upload the code to your ESP8266 board using the Arduino IDE or your preferred programming tool.

4. Assemble the lamp by connecting the DHT11 sensor, RGB LED, and SH1106 OLED screen to the appropriate pins on the ESP8266 board.

5. Power on the lamp and observe the temperature, humidity, and RGB lighting effects.

## Usage

The lamp will continuously monitor the temperature and humidity in the environment and display the current time on the OLED screen. The RGB LED will change color based on the humidity level detected.

## Future Enhancements

`Mobile App Integration`: \
Integrate the lamp with a dedicated mobile application to gather data and provide remote control. This will enable you to monitor temperature and humidity trends over time, adjust RGB lighting settings, and receive alerts about significant environmental changes.

`Weather Forecast`: \
Incorporate weather forecasting into the lamp's functionality. By connecting to a weather API, the lamp can display the current weather conditions and a short-term forecast, allowing you to plan your day accordingly.

`Mobile Light Management`: \
Implement mobile-based control over the RGB LED lighting. Through the mobile app, you can change the LED color, brightness, and effects to create various ambient lighting moods.

`Data Logging and Visualization`: \
Extend the capabilities of the mobile app to include data logging and visualization. This will allow you to review historical data trends and gain insights into environmental patterns over time.

`Customizable Alerts`: \
Develop a notification system that sends alerts to your mobile app when specific environmental thresholds are exceeded. This could be particularly useful for monitoring extreme temperature or humidity levels.

## License

This project is licensed under the [MIT License](LICENSE).
