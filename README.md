# Hardware für das Meisterstück

- [Arduino Nano](https://www.bastelgarage.ch/arduino/boards/arduino-nano-esp32)
- [DFPlayer (exkl SD Karte)](https://www.bastelgarage.ch/dfplayer-mini-mp3-player-modul-fur-arduino)
- [GPS Modul (für Zeit)](https://www.bastelgarage.ch/gps-modul-neo-6m-kompatibel?search=neo-6m)
- [SD Karte 256MB](https://www.bastelgarage.ch/256mb-microsd-karte)
- [Lautsprecher (max 3W)](https://www.bastelgarage.ch/lautsprecher-4ohm-3w-40mm)
- [Netzteil](https://www.digitec.ch/de/s1/product/raspberry-pi-official-raspberry-pi-4-power-adapter-usb-c-schwarz-entwicklungsboard-zubehoer-11268330)


# Anschlüsse

GPS Module "NEO-6M GPS Module"

    GPS Module VCC zu Arduino Nano 5V
    GPS Module GND zu Arduino Nano GND
    GPS Module TX zu Arduino Nano RX (D0)
    GPS Module RX zu Arduino Nano TX (D1)

DFPlayer

    DFPlayer Mini VCC zu Arduino Nano 5V
    DFPlayer Mini GND zu Arduino Nano GND
    DFPlayer Mini RX zu Arduino Nano D10
    DFPlayer Mini TX zu Arduino Nano D11
    Connect speaker zu DFPlayer Mini SPK_1 und SPK_2 pins

Lautsprecher

    SPK_1 --> Lautsprecher 1
    SPK_2 --> Lautsprecher 2


# SD Karte

Auf der SD-Karte müssen alle MP3s folgendermassen abgespeichert werden:
- 001.mp3
- 002.mp3
- ...
  
Die SD-Karte muss zwingend FAT32 formatiert sein!
-> Wir müssen wissen, wie viele Total, denn das muss für den Random eingegeben werden.
