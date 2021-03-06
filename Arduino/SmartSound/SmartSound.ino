#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ATT_IOT.h>                           
#include <SPI.h>
#include <Wire.h>                             
#define httpServer "api.allThingsTalk.io"                                  
#define mqttServer httpServer 
#define cicletime 10
#define numberofCicles 1000
#define brightness 1
#define pricetoStart 2.50
#define color1 0,255,0
#define color2 255,80,0
#define color3 255,0,0
#define color4 255,0,100
int pixelnr=60;
int unlock=25;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelnr, D6, NEO_GRB + NEO_KHZ800); 
char deviceId[] = "c3Sup5D8N5bCVCS4pdMPzO5D"; 
char clientId[] = "PaprikaYT_gcHaggvf";
char clientKey[] = "G0sFl3FM";
const char* ssid     = "Makerversity";
const char* password = "Mak3rvers1t!";
ATTDevice Device(deviceId, clientId, clientKey);            
int audioReal;                                             
int beer= 0;
int soundlevel = 1;
void callback(char* topic, byte* payload, unsigned int length);
WiFiClient ethClient;
PubSubClient pubSub(mqttServer, 1883, callback,ethClient);  


void setup()
{  
  pixels.begin(); 
  Wire.begin();
  Wire.setTimeout(1000);
  Serial.begin(9600);  
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    animationstart();
  }
  delay(1000);
  while(!Device.Connect(&ethClient, httpServer)){}
  Device.AddAsset(beer,"Level","Level",false,"integer");
  Device.AddAsset(soundlevel,"Realtime Soundlevel","Realtime Soundlevel",false,"integer");
  while(!Device.Subscribe(pubSub)){}                          
  animationend();
  ESP.wdtEnable(10000);                                                   
}
                    
void loop()
{
  ESP.wdtFeed();
  runforever();
}




