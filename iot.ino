#include <ESP8266WiFi.h>  
WiFi Client client;  
WiFi Server server (80);  
const char* ssid = "purple";  
const char* password = "1234567890";  
String command ="";   
int rightMotor2 = D3;     
 void setup ()  
{  
 Serial. begin(115200);  
 Pin Mode (rightMotor2, OUTPUT);    
 digital Write (rightMotor2, HIGH);  
 connect WiFi ();  
 server. Begin ();  
}  
void loop ()  
{  
    client = server. Available ();  
    if (! client) return;   
    command = check Client ();  
         if (command == "door%20open" ||command == "door%201%20open" || command == "VOICE1"|| command == "a frente") VOICE1();  
    else if (command == "door%20close" ||command == "door%20one%20close"|| command == "relay%20one%20of"|| command == "voltar") VOICE2();  
     
    Serial. Println (command);  
    Send Back Echo(command);   
    command = "";  
}
  
void VOICE1(void)     
     
{  
  Digital Write (rightMotor2, LOW);  
}  
void VOICE2(void)     
{  
  Digital Write (rightMotor2, HIGH);  
}  
 
void stop Motor(void)     
{  
  
  Digital Write(rightMotor2,HIGH);  
}  
  
/* connecting WiFi */  
void connect WiFi ()  
{  
  Serial .println ("Connecting to WIFI");  
  WiFi.begin (ssid, password);  
  while ((!(WiFi.status() == WL_CONNECTED)))  
  {  
    Delay (300);  
    Serial.print("..");  
  }  
  Serial.println(" ");  
  Serial.println("WiFi connected");  
  Serial.println("NodeMCU L 
ocal IP is : "); 
Serial.print((WiFi.localIP()));  
}  
  
/* check command received from Android Device */  
String checkClient (void)  
{  
  while(!client.available()) delay(1);   
  String request = client.readStringUntil('\r');  
  request.remove(0, 5);  
  request.remove (request.length()-9,9);  
  return request;  
}  
  
/* send command echo back to android device */  
void send Back Echo (String echo)  
{  
  Client .println ("HTTP/1.1 200 OK");  
  client. Println("Content-Type: text/html");  
  client. println("");  
  client. println("<!DOCTYPE HTML>");  
  client .println("<html>");  
  client .println(echo);  
  client .println("</html>");  
  client .stop();  
  delay (1); 
} 
 
 

  