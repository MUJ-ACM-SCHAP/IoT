#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <sstream>



#include "ESP8266WiFi.h"


#define WIFI_SSID "aesher9o1"
#define WIFI_PASSWORD "iamagoodboy"
#define FIREBASE_HOST "muj-files.firebaseio.com"
#define FIREBASE_AUTH "HcaXZ8RLfS3ay9C9Z679C2ocCMlSsHkrFF7xuwPO"


char ssid[]     = "aesher9o1";
char password[] = "iamagoodboy";


void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  while (Firebase.failed()) {
       Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
        Serial.println("Connecting...");
  }
}
 
void loop() {
  Firebase.setInt("arduino",random(0,255));
   
   
   if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }


  if(Firebase.getInt("arduino")==15)
     Serial.print(Firebase.getInt("arduino"));


}




