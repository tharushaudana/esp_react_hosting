# Arduino ESP32/ESP8266 Host React with LittleFS

This project demonstrates how to host a React web application using an ESP32 or ESP8266 microcontroller, along with using LittleFS to manage the file system for storing web content.

## Getting Started

To get started with this project, you'll need to install the LittleFS uploader plugin for the Arduino IDE. Follow the instructions in this [tutorial](https://randomnerdtutorials.com/arduino-ide-2-install-esp32-littlefs/) to install the plugin.

## Uploading Web Content

After installing the LittleFS uploader plugin, you can use it to upload the web content for your React application to the ESP32 or ESP8266 file system. Follow these steps:

1. Build your React application to create the production build files.
2. Create a folder named `data` in your Arduino project directory.
3. Copy all the build files (from the `build` folder of your React project) into the `data` folder in your Arduino project directory. Your `data` folder should now contain all the static files (HTML, CSS, JavaScript) and assets (images, fonts) of your React application.
4. Use the LittleFS uploader plugin to upload the contents of the `data` folder to the ESP32 or ESP8266 file system. This will transfer all your React build files to the microcontroller's file system.

## Flashing the ESP32/ESP8266

Once you have uploaded the web content to the ESP32 or ESP8266 file system, you can flash the microcontroller with the Arduino sketch provided in this project. The sketch will serve the web content to clients accessing the ESP32 or ESP8266.

## Usage

To access the React application hosted on the ESP32 or ESP8266, connect to the microcontroller's Wi-Fi network and open a web browser. Enter the IP address of the microcontroller to access the web application.

## Contributing

Contributions are welcome! Please read the [contributing guidelines](CONTRIBUTING.md) for more information.

## License

This project is licensed under the [MIT License](LICENSE).
