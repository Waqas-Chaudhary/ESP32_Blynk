char ssid[] = "Chaudhary";
char pass[] = "Madagascar";
String Name = "Ms.Fazaila Ali Qazi";
String Post = "Director Student Affairs";
String status_string = "N/A";
int O[5];






#define BLYNK_TEMPLATE_ID "TMPLQNYoPB1X"
#define BLYNK_DEVICE_NAME "RAAS"
#define BLYNK_AUTH_TOKEN "derjv04Q9fp3h9poVBYDGYIN27PUoyqT"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
int IN[7]={0,0,0,0,0,0,0};
BlynkTimer timer;
BLYNK_WRITE(V0)
{
  IN[0] = param.asInt();
  //Blynk.virtualWrite(V1, value);
   Serial.println("I am here 0");
}
BLYNK_WRITE(V1)
{
  IN[1] = param.asInt();
  //Blynk.virtualWrite(V1, value);
  Serial.println("I am here 1");
}
BLYNK_WRITE(V2)
{
  
  //Blynk.virtualWrite(V1, value);
   status_string = "Available";
}
BLYNK_WRITE(V7)
{
  
  //Blynk.virtualWrite(V1, value);
  status_string = "In Meeting";
}
BLYNK_WRITE(V4)
{ 
  //Blynk.virtualWrite(V1, value);
  status_string = "Busy";
}
BLYNK_WRITE(V5)
{ 
  //Blynk.virtualWrite(V1, value);
  status_string = "Break";
}
BLYNK_WRITE(V6)
{ 
  //Blynk.virtualWrite(V1, value);
  status_string = "On Leave";
}
BLYNK_CONNECTED()
{
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}
void Setup_Blynk()
{
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}
void Read_Switch()
{
  Blynk.run();
  timer.run();
}



void set_IO_Pins()
{
  if (IN[0] == 1)//Door Lock
  {
    digitalWrite(O[0], HIGH);
  }
  else
  {
    digitalWrite(O[0], LOW);
  }
  if (IN[1] == 1) //Lights
  {
    digitalWrite(O[1], HIGH);
  }
  else
  {
    digitalWrite(O[1], LOW);
  }
}

void setup()
{
  Serial.begin(115200);
  Setup_Blynk();
  for (int x = 0; x < 5; x++)
  {
    pinMode(O[x], OUTPUT);
  }
  
}

void loop()
{
  Read_Switch();
 // set_IO_Pins();
 Serial.println(status_string);
}
