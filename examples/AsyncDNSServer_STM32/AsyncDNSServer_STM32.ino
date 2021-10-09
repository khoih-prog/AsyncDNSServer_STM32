/****************************************************************************************************************************
  AsyncDNSServer.ino

  For STM32 with LAN8720 (STM32F4/F7)or built-in LAN8742A Ethernet (Nucleo-144, DISCOVERY, etc)
  
  AsyncDNSServer_STM32 is a Async DNS Server library for the STM32 using built-in LAN8742A Ethernet
  
  Based on and modified from ESPAsyncDNSServer Library (https://github.com/devyte/ESPAsyncDNSServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncDNSServer_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

#include <AsyncDNSServer_STM32.h>
#include <AsyncWebServer_STM32.h>

const byte DNS_PORT = 53;

IPAddress apIP;

AsyncDNSServer dnsServer;

AsyncWebServer server(80);

void handleNotFound(AsyncWebServerRequest *request)
{
  String message = "Hello World from " + String(BOARD_NAME) + "using LAN8742A\n\n";
  message += "URI: ";
  message += request->url();

  request->send(200, "text/plain", message);
}


void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(1000);

  Serial.print("\nStart AsyncDNSServer_STM32 on ");
  Serial.println(BOARD_NAME);
  Serial.println(ASYNC_DNS_SERVER_STM32_VERSION);

  // start the ethernet connection and the server
  // Use random mac
  uint16_t index = millis() % NUMBER_OF_MAC;

  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  // Use DHCP dynamic IP and random mac
  Ethernet.begin(mac[index]);;

  apIP = Ethernet.localIP();

  // modify TTL associated  with the domain name (in seconds)
  // default is 60 seconds
  dnsServer.setTTL(300);
  // set which return code will be used for all other domains 
  // (e.g. sending ServerFailure instead of NonExistentDomain will reduce number of queries
  // sent by clients). Default is AsyncDNSReplyCode::NonExistentDomain
  dnsServer.setErrorReplyCode(AsyncDNSReplyCode::ServerFailure);

  // start DNS server for a specific domain name
  dnsServer.start(DNS_PORT, "*", apIP);

  server.onNotFound(handleNotFound);

  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(apIP);
}

void loop() 
{
}
