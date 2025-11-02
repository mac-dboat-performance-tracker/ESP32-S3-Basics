#include <Adafruit_NeoPixel.h> 

// define global object to control the PIO48 RGB LED (onboard LED)
  // LED_RGB Object = {# of LEDS, GPIOPIN_48, Type of LED, Data Rate/Communication Speed}
  // !! NEO_GRBW = Green + Red + Blue + White !!
Adafruit_NeoPixel LED_RGB(1, 48, NEO_GRBW + NEO_KHZ800); 

// setup code (runs once)
void setup() {
  LED_RGB.begin();            
  LED_RGB.setBrightness(150); // brightness range: [0, 255] (untested)
}

// main loop block (repeatedly runs)
void loop() {
  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(255, 0, 0))); // set to RED
  LED_RGB.show();                                               
  delay(2000);  // millisecs                                 

  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(0, 255, 0))); // set to GREEN
  LED_RGB.show();                                               
  delay(2000);                                           

  LED_RGB.setPixelColor(0, uint32_t(LED_RGB.Color(0, 0, 255))); // set to BLUE
  LED_RGB.show();                                               
  delay(2000);                                                  
}