# Smart-Hospital Management System
# Abstract
This system allows us to detect temperature and heartbeat of the  patient from anywhere. It sends a trigger if the heartbeat/temperature is beyond the usual range.
A LM35 sensor is used to detect the temperature and KY039 sensor is used to detect the heartbeat.This project module is a combined integration of NodeMCU ESP8266 and ThinkSpace files. These libraries have been added to the Arduino IDE.
# Hardware Required:
· Nodemcu ESP8266 module.
· LM35 Temp Sensor
· KY039 Heartbeat Sensor
· Jumper Wires
· A Smartphone
· A Computer.
· Micro USB cable
# Software Required:
· Arduino IDE.
· ESP8266 library.
· LM35 Library.
· KY039 Library.
· ThingSpeak MQTT Library.
# Miscellaneous:
· Wifi Internet Connection
· Soldering tool
· Soldering wires

# Total Cost Of Components-Rs.1000-Rs.1500

# System Overview
The main component of the setup is the Nodemcu ESP8266 module. All the other hardware components are connected   to the Nodemcu. The board is programmed in Arduino IDE and uses the ESP8266,LM35,KY039 and ThingSpeak MQTT libraries. These libraries have been added to the Arduino IDE.
The LM35 temperature sensor along with KY039 heartbeat sensor is directly connected to the NodeMCU using a micro USB cable. This is used to detect the body temperature and heartbeat and is signalled by the programmed NodeMCU ESP8266 with a trigger as an Email using ThingSpeak.

# Programming NodeMCU and setting up ThingSpeak Dashboard 
• Import ESP8266WiFi.h Library to the Arduino IDE
• Fill your THINGSPEAK WRITEAPI key , wifi ssid, and wifi password to the code.
• Upload temperature sensor and heartbeat detection code to your NodeMCU
• Setup your Thingspeak dashboard, add a new channel and two visualization and give it name, and press add widget.
• Now press the trigger, give trigger's name, on if add the widget added before, on then fill email with your email, and press save.

# Links to Github and Youtube:
# Github:
https://github.com/prachikaag/Smart-Hospital-Management-System/edit/master/README.md
# You-tube:
