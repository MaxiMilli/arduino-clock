#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <DFRobotDFPlayerMini.h>

// GPS
SoftwareSerial ss(2, 3);
TinyGPSPlus gps;

// DFPlayer Mini
SoftwareSerial mySerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
   Serial.begin(9600);
   ss.begin(9600);
   mySerial.begin(9600);

   // Initialize DFPlayer
   if (!myDFPlayer.begin(mySerial))
   {
      Serial.println("DFPlayer Mini initialization failed!");
      while (true)
         ;
   }
   myDFPlayer.volume(20); // Set volume value (0-30).

   Serial.println("Initialization done.");
}

void loop()
{
   static int lastHour = -1;

   while (ss.available() > 0)
   {
      gps.encode(ss.read());
   }

   if (gps.time.isValid())
   {
      int currentHour = gps.time.hour();

      // Spiele ein File, wenn die Uhr eine neue Stunde erreicht
      if (currentHour != lastHour)
      {
         lastHour = currentHour;

         int randomFile = random(1, 11);
         myDFPlayer.playMp3Folder(randomFile);
         Serial.print("Playing file: ");
         Serial.println(randomFile);
      }
   }

   delay(1000);
}
