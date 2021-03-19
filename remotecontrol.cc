

#include <ESP8266WiFi.h>

const char* ssid     = "5g tower";
const char* password = "ghghgvhgbh";

const char* host = "remotrecontrolledswitch.herokuapp.com";

int ledPin = 7;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(ledPin,OUTPUT)
}

int value = 0;

void loop() {
  delay(1000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }


  string getStatusUrl="/get/status/"


  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 10000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  String line = "";
  while(client.available()){
    line = client.readStringUntil('\r');
  }

  if (line=="on"){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
  
}