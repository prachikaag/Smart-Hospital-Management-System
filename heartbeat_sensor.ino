#include <ESP8266WiFi.h>
String apiWritekey = "4QDNCV5V95FN1LMR"; // replace with your THINGSPEAK WRITEAPI key here
const char* ssid = "G-207"; // your wifi SSID name
const char* password = "superwoman" ;// wifi pasword
const char* server = "api.thingspeak.com";
WiFiClient client;
int led_Pin = 13;                                      // initializing the led pin
int output_Pin = A0;                                // initializing the sensor output pin
//initializng other variables
double alpha = 0.75;
int period = 2000;
double change = 0.0;
void setup ( )                           // Code written in it will only run once.
{
  pinMode (led_Pin, OUTPUT);                   // declaring led pin as output
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
Serial.println();// setting baud rate at 9600
}
void loop ()
{
    // initializing other variables

    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead (output_Pin);                                         // Reading the sensors values
    double value = alpha * oldValue + (1 - alpha) * rawValue;         // calculating values using the formula
    //Serial.print (rawValue);              // printing the sensor output value on the screen
    //Serial.print (",");                                                                                          
    //Serial.println (value);             // printing the heart beat value on the screen
    //oldValue = value;


    //float temp = (analogRead(A0) * resolution) * 100;
if (client.connect(server,80))
{
String tsData = apiWritekey;
tsData +="&field1=";
tsData += String(rawValue);
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
Serial.print("Heartbeat: ");
Serial.print(value);
Serial.println("uploaded to Thingspeak server....");
}
client.stop();
Serial.println("Waiting to upload next reading...");
Serial.println();
// thingspeak needs minimum 15 sec delay between updates
delay(period);
} 
