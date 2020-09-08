/****************************************************************************************************************************
  AsyncCaptivePortalAdvanced_STM32.ino

  For STM32 with built-in LAN8742A Ethernet (Nucleo-144, DISCOVERY, etc)

  AsyncDNSServer_STM32 is a Async DNS Server library for the STM32 using built-in LAN8742A Ethernet

  Based on and modified from ESPAsyncUDP Library (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncUDP_STM32
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      08/09/2020 Initial coding for STM32 for built-in Ethernet (Nucleo-144, DISCOVERY, etc).
 *****************************************************************************************************************************/

#include "defines.h"

#include <AsyncDNSServer_STM32.h>
#include <AsyncWebServer_STM32.h>

/*
   This example serves a "hello world".

   Now the STM32 is in your network. You can reach it through http://192.168.x.x/

   This is a captive portal because it will redirect any http request to http://192.168.x.x/
*/

// DNS server
const byte DNS_PORT = 53;

AsyncDNSServer dnsServer;

// Web server
AsyncWebServer server(80);

IPAddress apIP;

/** Is this an IP? */
bool isIp(String str)
{
  for (size_t i = 0; i < str.length(); i++)
  {
    int c = str.charAt(i);

    if (c != '.' && (c < '0' || c > '9'))
    {
      return false;
    }
  }

  return true;
}

/** IP to String? */
String toStringIp(IPAddress ip)
{
  String res = "";

  for (int i = 0; i < 3; i++)
  {
    res += String((ip >> (8 * i)) & 0xFF) + ".";
  }

  res += String(((ip >> 8 * 3)) & 0xFF);

  return res;
}

/** Handle root or redirect to captive portal */
void handleRoot(AsyncWebServerRequest * request)
{
  if (captivePortal(request))
  {
    // If captive portal redirect instead of displaying the page.
    return;
  }

  String Page = F(
                  "<!DOCTYPE html><html lang='en'><head>"
                  "<meta name='viewport' content='width=device-width'>"
                  "<title>CaptivePortal</title></head><body>"
                  "<h1>HELLO WORLD!!</h1>");

  Page +=   "<h2>From " + String(BOARD_NAME) + "</h2>";

  AsyncWebServerResponse *response = request->beginResponse(200, "text/html", Page);
  response->addHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  response->addHeader("Pragma", "no-cache");
  response->addHeader("Expires", "-1");

  request->send(response);
}

// Redirect to captive portal if we got a request for another domain. 
// Return true in that case so the page handler do not try to handle the request again.
bool captivePortal(AsyncWebServerRequest * request)
{
  if (!isIp(request->host()))
  {
    Serial.println("Request redirected to captive portal");

    // Empty content inhibits Content-length header so we have to close the socket ourselves.
    AsyncWebServerResponse *response = request->beginResponse(302, "text/plain", "");
    response->addHeader("Location", String("http://") + toStringIp(request->client()->localIP()));

    request->send(response);

    request->client()->stop(); // Stop is needed because we sent no content length

    return true;
  }

  return false;
}

void handleNotFound(AsyncWebServerRequest * request)
{
  if (captivePortal(request))
  {
    // If captive portal redirect instead of displaying the error page.
    return;
  }

  String message = F("File Not Found\n\n");

  message += F("URI: ");
  message += request->url();
  message += F("\nMethod: ");
  message += (request->method() == HTTP_GET) ? "GET" : "POST";
  message += F("\nArguments: ");
  message += request->args();
  message += F("\n");

  for (uint8_t i = 0; i < request->args(); i++)
  {
    message += String(F(" ")) + request->argName(i) + F(": ") + request->arg(i) + F("\n");
  }

  AsyncWebServerResponse *response = request->beginResponse(404, "text/plain", message);
  response->addHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  response->addHeader("Pragma", "no-cache");
  response->addHeader("Expires", "-1");

  request->send(response);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("\nStart AsyncCaptivePortalAdvanced_STM32 on " + String(BOARD_NAME));

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
  // set which return code will be used for all other domains (e.g. sending
  // ServerFailure instead of NonExistentDomain will reduce number of queries
  // sent by clients)
  // default is AsyncDNSReplyCode::NonExistentDomain
  dnsServer.setErrorReplyCode(AsyncDNSReplyCode::ServerFailure);

  dnsServer.start(DNS_PORT, "*", apIP);

  /* Setup web pages: root, wifi config pages, SO captive portal detectors and not found. */
  // simple HTTP server to see that DNS server is working
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    handleRoot(request);
  });

  //Android captive portal. Maybe not needed. Might be handled by notFound handler.
  server.on("/generate_204", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    handleRoot(request);
  });

  //Microsoft captive portal. Maybe not needed. Might be handled by notFound handler.
  server.on("/fwlink", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    handleRoot(request);
  });

  server.onNotFound(handleNotFound);

  server.begin(); // Web server start

  Serial.print(F("HTTP DNSServer is @ IP : "));
  Serial.println(apIP);
}

void loop()
{
}
