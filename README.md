# ESP32-S3-Basics
Basics of interacting with ESP32-S3

Official Docs:
https://docs.espressif.com/projects/esp-idf/en/v5.5.1/esp32s3/get-started/index.html

Prerequisites and Setup

Hardware:
- ESP32-S3
- Microusb to USB-A

Software:
- VSCode, install PlatformIO IDE extension
- (Alternative) use Arduino IDE

After installing PlatformIO extension a icon will pop up on the left bar (alien icon)

To init a new project...
1. Click on PlatformIO extension icon on left bar
2. Under a dropdown on the "Quick Access", click "Open" and click "New Project" on the top right.
3. Name your project and select Espressif ESP32-S3-DevKitC-1-N8 as the board.
4. Let project initialize...

Adding new libraries (and the ones we need...)
1. Go to platformIO extension again (left-bar)
2. Under "Quick Access", click "Libraries"
3. Search for "Adafruit NeoPixel" (library to control onboard LED)
4. Click on it and click on "Add to Project" and select Project Name and click "Add"



