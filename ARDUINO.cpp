#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <DFRobotDFPlayerMini.h>
#include <AccelStepper.h>

// GPS
SoftwareSerial ss(2, 3);
TinyGPSPlus gps;

// DFPlayer Mini
SoftwareSerial mySerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

// Stepper Motor setup
AccelStepper stepperHour(AccelStepper::FULL4WIRE, 4, 5, 6, 7);
AccelStepper stepperMinute(AccelStepper::FULL4WIRE, 8, 9, 12, 13);

const int stepsPerRevolution = 2048; // Adjust based on your stepper motor

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

   // Initialize steppers
   stepperHour.setMaxSpeed(1000);
   stepperHour.setAcceleration(500);
   stepperMinute.setMaxSpeed(1000);
   stepperMinute.setAcceleration(500);

   Serial.println("Initialization done.");
}

void loop()
{
   static int lastHour = -1;
   static int lastMinute = -1;

   while (ss.available() > 0)
   {
      gps.encode(ss.read());
   }

   if (gps.time.isValid())
   {
      int currentHour = gps.time.hour();
      int currentMinute = gps.time.minute();

      // Update stepper positions if the time has changed
      if (currentHour != lastHour || currentMinute != lastMinute)
      {
         lastHour = currentHour;
         lastMinute = currentMinute;

         int hourPosition = map(currentHour % 12, 0, 12, 0, stepsPerRevolution);
         int minutePosition = map(currentMinute, 0, 60, 0, stepsPerRevolution);

         stepperHour.moveTo(hourPosition);
         stepperMinute.moveTo(minutePosition);

         Serial.print("Hour: ");
         Serial.print(currentHour);
         Serial.print(" -> Stepper: ");
         Serial.println(hourPosition);

         Serial.print("Minute: ");
         Serial.print(currentMinute);
         Serial.print(" -> Stepper: ");
         Serial.println(minutePosition);
      }

      // Spiele ein File, wenn die Uhr eine neue Stunde erreicht
      if (currentMinute == 0 && gps.time.second() == 0)
      {
         int randomFile = random(1, 11);
         myDFPlayer.playMp3Folder(randomFile);
         Serial.print("Playing file: ");
         Serial.println(randomFile);
      }
   }

   stepperHour.run();
   stepperMinute.run();

   delay(1000);
}
