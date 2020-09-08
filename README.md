# AsyncDNSServer_STM32


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncDNSServer_STM32.svg?)](https://www.ardu-badge.com/AsyncDNSServer_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncDNSServer_STM32.svg)](https://github.com/khoih-prog/AsyncDNSServer_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/AsyncDNSServer_STM32/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncDNSServer_STM32.svg)](http://github.com/khoih-prog/AsyncDNSServer_STM32/issues)

---
---

### Why do we need this Async [AsyncDNSServer_STM32 library](https://github.com/khoih-prog/AsyncDNSServer_STM32)

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the packet is ready
- After a DNS Client connected to this Async DNS serve, you are **immediately ready** to handle other connections while the Server is taking care of receiving and responding to the UDP packets in the background.
- You are not required to check in a tight loop() the arrival of the DNS requesting packets to process them.
- **Speed is OMG**


---

### Initial Releases v1.0.0

1. Initial coding to port [ESPAsyncDNSServer](https://github.com/devyte/ESPAsyncDNSServer) to STM32 boards using builtin LAN8742A Ethernet. More supports will be added gradually later, such as other Ethernet / WiFi shields.
2. Add more examples.
3. Add debugging features.

#### Currently Supported Boards

1. Nucleo-144 (F429ZI, F746ZG, F756ZG, F767ZI)
2. Discovery STM32F746G-DISCOVERY
3. Any STM32 boards with enough flash/memory and already configured to run LAN8742A Ethernet.

---

### [AsyncDNSServer_STM32 library](https://github.com/khoih-prog/AsyncDNSServer_STM32) for STM32 boards using builtin LAN8742A Ethernet

This [AsyncDNSServer_STM32 library](https://github.com/khoih-prog/AsyncDNSServer_STM32) is a fully asynchronous DNSServer library, designed for a trouble-free, multi-connection network environment, for STM32 boards using builtin LAN8742A Ethernet.

This library is based on, modified from:

1. [Develo's ESPAsyncDNSServer](https://github.com/devyte/ESPAsyncDNSServer)

to apply the better and faster **asynchronous** feature of the **powerful** [AsyncUDP_STM32 Library](https://github.com/khoih-prog/AsyncUDP_STM32) into STM32 boards using builtin LAN8742A Ethernet.

---
---

## Prerequisite

 1. [`Arduino IDE 1.8.12+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino Core for STM32 1.9.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32 (Use Arduino Board Manager)
 3. [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in Ethernet on (Nucleo-144, Discovery). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/STM32Ethernet.svg?)](https://www.ardu-badge.com/STM32Ethernet).
 4. [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in Ethernet on (Nucleo-144, Discovery). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/LwIP.svg?)](https://www.ardu-badge.com/LwIP).
 4. [`AsyncUDP_STM32 library v1.1.0+`](https://github.com/khoih-prog/AsyncUDP_STM32) for built-in Ethernet on (Nucleo-144, Discovery). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncUDP_STM32.svg?)](https://www.ardu-badge.com/AsyncUDP_STM32).
 
---

## Installation

### Use Arduino Library Manager
The best and easiest way is to use `Arduino Library Manager`. Search for `AsyncDNSServer_STM32`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncDNSServer_STM32.svg?)](https://www.ardu-badge.com/AsyncDNSServer_STM32) for more detailed instructions.

### Manual Install

1. Navigate to [AsyncDNSServer_STM32](https://github.com/khoih-prog/AsyncDNSServer_STM32) page.
2. Download the latest release `AsyncDNSServer_STM32-master.zip`.
3. Extract the zip file to `AsyncDNSServer_STM32-master` directory 
4. Copy the whole `AsyncDNSServer_STM32-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:
1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **AsyncDNSServer_STM32** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/). Search for ***AsyncDNSServer_STM32*** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](examples/platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically.

---

## HOWTO Setting up the Async DNS Server

```cpp
#include <LwIP.h>
#include <STM32Ethernet.h>

#include <AsyncUDP_STM32.h>
#include <AsyncDNSServer_STM32.h>

const byte DNS_PORT = 53;

IPAddress apIP;

AsyncDNSServer dnsServer;


void setup()
{
  ...
  
  // modify TTL associated  with the domain name (in seconds)
  // default is 60 seconds
  dnsServer.setTTL(300);
  // set which return code will be used for all other domains 
  // (e.g. sending ServerFailure instead of NonExistentDomain will reduce number of queries
  // sent by clients). Default is AsyncDNSReplyCode::NonExistentDomain
  dnsServer.setErrorReplyCode(AsyncDNSReplyCode::ServerFailure);

  // start DNS server for a specific domain name
  dnsServer.start(DNS_PORT, "*", Ethernet.localIP());

  ...
}

void loop() 
{
}

```

---
---

### Examples

 1. [AsyncCaptivePortalAdvanced_STM32](examples/AsyncCaptivePortalAdvanced_STM32)
 2. [AsyncCaptivePortal_STM32](examples/AsyncCaptivePortal_STM32)
 3. [AsyncDNServerFull_STM32](examples/AsyncDNServerFull_STM32) 
 4. [AsyncDNSServer_STM32](examples/AsyncDNSServer_STM32)

---

### Example [AsyncDNSServer_STM32](examples/AsyncDNSServer_STM32)

#### 1. File [AsyncDNSServer_STM32.ino](examples/AsyncDNSServer_STM32/AsyncDNSServer_STM32.ino)


```cpp
#include "defines.h"

#include <AsyncDNSServer_STM32.h>
#include <AsyncWebServer_STM32.h>

const byte DNS_PORT = 53;

IPAddress apIP;

AsyncDNSServer dnsServer;

AsyncWebServer server(80);

void handleNotFound(AsyncWebServerRequest *request)
{
  String message = "Hello World!\n\n";
  message += "URI: ";
  message += request->url();

  request->send(200, "text/plain", message);
}


void setup()
{
  Serial.begin(115200);
  Serial.println("\nStart AsyncDNSServer_STM32 on " + String(BOARD_NAME));

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
```

#### 2. File [defines.h](examples/AsyncUdpNTPClient/defines.h)

```cpp
/*
   Currently support
   1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet, 
      - See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running ENC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   3) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 shields
*/

#ifndef defines_h
#define defines_h

#if !( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
  #error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.
#endif

#define ASYNC_UDP_STM32_DEBUG_PORT      Serial
#define ASYNC_DNS_STM32_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_UDP_STM32_LOGLEVEL_      4
#define _ASYNC_DNS_STM32_LOGLEVEL_      4


#if defined(STM32F0)
  #warning STM32F0 board selected
  #define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
  #warning STM32F1 board selected
  #define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
  #warning STM32F2 board selected
  #define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
  #warning STM32F3 board selected
  #define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
  #warning STM32F4 board selected
  #define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
  #warning STM32F7 board selected
  #define BOARD_TYPE  "STM32F7"
#elif defined(STM32L0)
  #warning STM32L0 board selected
  #define BOARD_TYPE  "STM32L0"
#elif defined(STM32L1)
  #warning STM32L1 board selected
  #define BOARD_TYPE  "STM32L1"
#elif defined(STM32L4)
  #warning STM32L4 board selected
  #define BOARD_TYPE  "STM32L4"
#elif defined(STM32H7)
  #warning STM32H7 board selected
  #define BOARD_TYPE  "STM32H7"
#elif defined(STM32G0)
  #warning STM32G0 board selected
  #define BOARD_TYPE  "STM32G0"
#elif defined(STM32G4)
  #warning STM32G4 board selected
  #define BOARD_TYPE  "STM32G4"
#elif defined(STM32WB)
  #warning STM32WB board selected
  #define BOARD_TYPE  "STM32WB"
#elif defined(STM32MP1)
  #warning STM32MP1 board selected
  #define BOARD_TYPE  "STM32MP1"
#else
  #warning STM32 unknown board selected
  #define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#include <LwIP.h>
#include <STM32Ethernet.h>

#include <AsyncUDP_STM32.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
};

// Select the static IP address according to your local network
IPAddress ip(192, 168, 2, 232);

#endif    //defines_h
```

---

### Debug
Debug is enabled by default on Serial. To disable, use level 0

```cpp
#define ASYNC_DNS_STM32_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_DNS_STM32_LOGLEVEL_      0
```

You can also change the debugging level from 0 to 4

```cpp
#define ASYNC_DNS_STM32_DEBUG_PORT      Serial


// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _ASYNC_DNS_STM32_LOGLEVEL_    4
```

---
---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of Arduino IDE, the Arduino `STM32` core or depending libraries.

Sometimes, the library will only work if you update the `STM32` core to the latest version because I am always using the latest cores /libraries.


---

### Issues ###

Submit issues to: [AsyncDNSServer_STM32 issues](https://github.com/khoih-prog/AsyncDNSServer_STM32/issues)

---

## TO DO

 1. Fix bug. Add enhancement
 2. Add support to more Ethernet / WiFi shield
 3. Add support to more STM32 boards.


## DONE

 1. Initial port to STM32 using builtin LAN8742A Etnernet. Tested on **STM32F7 Nucleo-144 F767ZI**.
 2. Add more examples.
 3. Add debugging features.
 
---
---

### Initial Releases v1.0.0

1. Initial coding to port [ESPAsyncDNSServer](https://github.com/devyte/ESPAsyncDNSServer) to STM32 boards using builtin LAN8742A Ethernet. More supports will be added gradually later, such as other Ethernet / WiFi shields.
2. Add more examples.
3. Add debugging features.

#### Currently Supported Boards

1. Nucleo-144 (F429ZI, F746ZG, F756ZG, F767ZI)
2. Discovery STM32F746G-DISCOVERY
3. Any STM32 boards with enough flash/memory and already configured to run LAN8742A Ethernet.

---

This library is based on, modified from:

1. [Develo's ESPAsyncDNSServer](https://github.com/devyte/ESPAsyncDNSServer)

to apply the better and faster **asynchronous** feature of the **powerful** [AsyncUDP_STM32 Library](https://github.com/khoih-prog/AsyncUDP_STM32) into STM32 boards using builtin LAN8742A Ethernet.

---
---

### Contributions and Thanks

1. Based on and modified from [Develo's ESPAsyncDNSServer Library](https://github.com/devyte/ESPAsyncDNSServer).
2. Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for great [(ESP)AsyncUDP, (ESP)AsyncTCP, ESPAsyncWebServer Libraries](https://github.com/me-no-dev)
3. Relied on [Frederic Pillon's STM32duino LwIP Library](https://github.com/stm32duino/LwIP).


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br/><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br/></td>
    <td align="center"><a href="https://github.com/devyte"><img src="https://github.com/devyte.png" width="100px;" alt="devyte"/><br/><sub><b>⭐️ Develo</b></sub></a><br/></td>
    <td align="center"><a href="https://github.com/fpistm"><img src="https://github.com/fpistm.png" width="100px;" alt="fpistm"/><br/><sub><b>⭐️ Frederic Pillon</b></sub></a><br/></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License and credits ###

- The library is licensed under [MIT](https://github.com/khoih-prog/WebSockets2_Generic/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang

