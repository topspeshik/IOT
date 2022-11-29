#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void handle_root(){
  String form = "<form action=\"/LED\" method=\"POST\">";
  form = form + "<input type=\"submit\" value=\"Toggle LED\">";
  form = form + "</form>";
  
  server.send(200, "text/html",form);
}

void handleLED(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleNotFound(){
  server.send(404, "text/plain", "404:Not Found");
}

void server_init(){
  server.on("/", HTTP_GET, handle_root);
  server.on("/LED", HTTP_POST, handleLED);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server started at port 80");
}
