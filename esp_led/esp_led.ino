
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL-ZVK_63U"
#define BLYNK_DEVICE_NAME "LED BLYNK HOME AUTOMATION"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
BLYNK_WRITE(V0)
{
  int pinvalue = param.asInt();
  if(param.asInt()==1){
    digitalWrite(D4, LOW);
  }
  else{
    digitalWrite(D4, HIGH);
  }
}

BLYNK_CONNECTED()
{
  pinMode(D4, OUTPUT);
  Blynk.syncVirtual(V0);  
}


void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(D4, OUTPUT);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
