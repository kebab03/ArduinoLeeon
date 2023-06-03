#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
  // Connect to HTTP server
//WiFiClient client;
//const char* ssid     = "TCL 20Y";
//const char* password = "123456al";
const char* ssid = "Wokwi-GUEST";
const char* password = "";
String wserverName = "http://192.168.1.106:1880/update-sensor";
String serverName ="https://test-s-327822-default-rtdb.europe-west1.firebasedatabase.app/";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 500;

void setup() {
  Serial.begin(115200); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + ".json";
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      //
      int httpResponseCode = http.GET();
        StaticJsonDocument<128> doc;

  // Add key-value pairs to the JSON document
  doc["Whu"] = 234;
  doc["Nnaw"] =35;
  doc["Kleon"] = 312;

  // Serialize the JSON document into a string
  String jsonString;
  serializeJson(doc, jsonString);
      int httpResponseCodeP = http.PUT(jsonString);

      //{"hu":23,"kaw":75,"leon":32}
      //put("lji:","34");
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}