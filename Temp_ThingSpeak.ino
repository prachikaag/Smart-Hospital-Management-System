#include <ESP8266WiFi.h>
String apiWritekey = "K4DEALYLVFA0IRSG"; // replace with your THINGSPEAK WRITEAPI key here
const char* ssid = "G-207"; // your wifi SSID name
const char* password = "superwoman" ;// wifi pasword
const char* server = "api.thingspeak.com";
float resolution=3.3/2307;// 3.3 is the supply volt & 1023 is max analog read value
WiFiClient client;
void setup() {
Serial.begin(115200);
WiFi.disconnect();
delay(10);
WiFi.begin(ssid, password);
Serial.println();//prints over the serial port 
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("NodeMcu connected to wifi...");
Serial.println(ssid);
Serial.println();
}
void loop() {
float temp = (analogRead(A0) * resolution) * 100;
if (client.connect(server,80))
{
String tsData = apiWritekey;
tsData +="&field1=";
tsData += String(temp);
tsData += "\r\n\r\n";
client.print("POST /update HTTP/1.1\n");//here the post is been done over the //think speak 
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(tsData.length());
client.print("\n\n"); // the 2 carriage returns indicate closing of Header fields & starting of data
client.print(tsData);
Serial.print("Temperature: ");
Serial.print(temp);
Serial.println("uploaded to Thingspeak server....");
}
client.stop();
Serial.println("Waiting to upload next reading...");
Serial.println();
// thingspeak needs minimum 15 sec delay between updates
delay(15000);
}
