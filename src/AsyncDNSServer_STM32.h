/****************************************************************************************************************************
  AsyncDNSServer_STM32.h - Dead simple AsyncWebServer for STM32 built-in LAN8742A Ethernet
  
  For STM32 with LAN8720 (STM32F4/F7)or built-in LAN8742A Ethernet (Nucleo-144, DISCOVERY, etc)
  
  AsyncDNSServer_STM32 is a Async DNS Server library for the STM32 using built-in LAN8742A Ethernet
  
  Based on and modified from ESPAsyncDNSServer Library (https://github.com/devyte/ESPAsyncDNSServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncDNSServer_STM32
  Licensed under MIT license
  
  Version: 1.1.1
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      08/09/2020 Initial coding for STM32 for built-in Ethernet (Nucleo-144, DISCOVERY, etc).
  1.1.0   K Hoang      14/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
  1.1.1   K Hoang      09/10/2021 Update `platform.ini` and `library.json`
  *****************************************************************************************************************************/

#pragma once
  
#ifndef AsyncDNSServer_STM32_h
#define AsyncDNSServer_STM32_h

#define ASYNC_DNS_SERVER_STM32_VERSION      "AsyncDNSServer_STM32 v1.1.1"

#include <AsyncUDP_STM32.h>
#include "AsyncDNSServer_Debug_STM32.h"

#define DNS_QR_QUERY 0
#define DNS_QR_RESPONSE 1
#define DNS_OPCODE_QUERY 0

enum class AsyncDNSReplyCode : unsigned char
{
  NoError = 0,
  FormError = 1,
  ServerFailure = 2,
  NonExistentDomain = 3,
  NotImplemented = 4,
  Refused = 5,
  YXDomain = 6,
  YXRRSet = 7,
  NXRRSet = 8
};

class AsyncDNSServer
{
  public:
    AsyncDNSServer();
    void setErrorReplyCode(const AsyncDNSReplyCode &replyCode);
    void setTTL(const uint32_t ttl);

    // Returns true if successful, false if there are no sockets available
    bool start(const uint16_t port,
              const String &domainName,
              const IPAddress &resolvedIP);
    // stops the DNS server
    void stop();

  private:
    AsyncUDP _udp;
    uint16_t _port;
    String _domainName;
    unsigned char _resolvedIP[4];
    uint32_t _ttl;
    AsyncDNSReplyCode _errorReplyCode;

    void processRequest(AsyncUDPPacket &packet);
    void replyWithIP(AsyncUDPPacket &packet);
    void replyWithCustomCode(AsyncUDPPacket &packet);
};

#include "AsyncDNSServer_Impl_STM32.h"

#endif    // AsyncDNSServer_STM32_h
