//Automatic Plant Watering System ESP 32

#define uS_TO_S_FACTOR 1000000 // Convert milliseconds to seconds
#define TIME_TO_SLEEP 30  // time to sleep 30 seconds

//Initiate For Blynk View
//Ypu can get therefrom you're 
#define BLYNK_TEMPLATE_ID           "TMPxxxx-xxxxxx"
#define BLYNK_DEVICE_NAME           "Auto Watering System"
#define BLYNK_AUTH_TOKEN            "YOUR BLYNK AUTH TOKEN"


#define BLYNK_PRINT Serial

//Library in use
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

char auth[] = BLYNK_AUTH_TOKEN;
// You're SSID and Password
char ssid[] = "My WiFi";
char pass[] = "My Password";



BlynkTimer timer;
// Address pin used
const int relay = 14; // declaration of relay pin 14
const int soilmoisture = 34;  //declaration of soilmoisture sensor pin 34
float persen;

BLYNK_WRITE(V0)
{ 
  int value1 = param.asInt();
  digitalWrite(RL1,value1);  
}

void setup()
{
  
  Serial.begin(115200);
  pinMode (relay,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, analogSense);   //Memory reading time in deepsleep
// Looping sensor readings
  for(int i=0; i<5; i++){
    analogSense();
    delay(500);
}
  
//settings for the DeepSleep timer
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Blynk.run();
  timer.run(); 
}

void loop()
{
  Blynk.run();
  timer.run();  
}
 void analogSense(){   //Soil moisture sensor
    float soil = analogRead(soilmoisture);  //detect the value from the soil moisture sensor
    persen=(soil/8192)*100;  //presents the sensor value readings to percent
//Display on serial monitor
    Serial.print("\nSoil Moisture: ");
    Serial.print(soil);
    delay(800);
    Serial.print("Hasil Persen: ");
    Serial.print(persen);
    delay(900);
//Display on Blynk via virtual PIN
    Blynk.virtualWrite(V3, soil);
    Blynk.virtualWrite(V7, persen);

//For dry soil conditions
     if(persen>25){ //if the soil moisture <= 25, then the pump is on
    relayON();
  }

// For wet soil conditions
    else if(persen<=85){ // if soil moisture > 25 pump off
    relayOFF();
    }
    delay(100);
  }

//Initiate the use of the relay
  void relayON(){
  digitalWrite(relay, HIGH);
  relay.on();
}
void relayOFF(){
  digitalWrite(relay, LOW);
  relay.off();
}
