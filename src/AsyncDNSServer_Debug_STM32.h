/****************************************************************************************************************************
  AsyncDNSServer_Debug_STM32.h - Dead simple AsyncWebServer for STM32 built-in LAN8742A Ethernet
  
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
 
#ifndef AsyncDNSServer_Debug_STM32_H
#define AsyncDNSServer_Debug_STM32_H

#ifdef ASYNC_DNS_STM32_DEBUG_PORT
  #define DBG_PORT      ASYNC_DNS_STM32_DEBUG_PORT
#else
  #define DBG_PORT      Serial
#endif

// Change _ASYNC_DNS_STM32_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ASYNC_DNS_STM32_LOGLEVEL_
  #define _ASYNC_DNS_STM32_LOGLEVEL_       0
#endif

#define DNS_LOGERROR(x)         if(_ASYNC_DNS_STM32_LOGLEVEL_>0) { DBG_PORT.print("[DNS] "); DBG_PORT.println(x); }
#define DNS_LOGERROR0(x)        if(_ASYNC_DNS_STM32_LOGLEVEL_>0) { DBG_PORT.print(x); }
#define DNS_LOGERROR1(x,y)      if(_ASYNC_DNS_STM32_LOGLEVEL_>0) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DNS_LOGERROR2(x,y,z)    if(_ASYNC_DNS_STM32_LOGLEVEL_>0) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DNS_LOGERROR3(x,y,z,w)  if(_ASYNC_DNS_STM32_LOGLEVEL_>0) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#define DNS_LOGWARN(x)          if(_ASYNC_DNS_STM32_LOGLEVEL_>1) { DBG_PORT.print("[DNS] "); DBG_PORT.println(x); }
#define DNS_LOGWARN0(x)         if(_ASYNC_DNS_STM32_LOGLEVEL_>1) { DBG_PORT.print(x); }
#define DNS_LOGWARN1(x,y)       if(_ASYNC_DNS_STM32_LOGLEVEL_>1) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DNS_LOGWARN2(x,y,z)     if(_ASYNC_DNS_STM32_LOGLEVEL_>1) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DNS_LOGWARN3(x,y,z,w)   if(_ASYNC_DNS_STM32_LOGLEVEL_>1) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#define DNS_LOGINFO(x)          if(_ASYNC_DNS_STM32_LOGLEVEL_>2) { DBG_PORT.print("[DNS] "); DBG_PORT.println(x); }
#define DNS_LOGINFO0(x)         if(_ASYNC_DNS_STM32_LOGLEVEL_>2) { DBG_PORT.print(x); }
#define DNS_LOGINFO1(x,y)       if(_ASYNC_DNS_STM32_LOGLEVEL_>2) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DNS_LOGINFO2(x,y,z)     if(_ASYNC_DNS_STM32_LOGLEVEL_>2) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DNS_LOGINFO3(x,y,z,w)   if(_ASYNC_DNS_STM32_LOGLEVEL_>2) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#define DNS_LOGDEBUG(x)         if(_ASYNC_DNS_STM32_LOGLEVEL_>3) { DBG_PORT.print("[DNS] "); DBG_PORT.println(x); }
#define DNS_LOGDEBUG0(x)        if(_ASYNC_DNS_STM32_LOGLEVEL_>3) { DBG_PORT.print(x); }
#define DNS_LOGDEBUG1(x,y)      if(_ASYNC_DNS_STM32_LOGLEVEL_>3) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DNS_LOGDEBUG2(x,y,z)    if(_ASYNC_DNS_STM32_LOGLEVEL_>3) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DNS_LOGDEBUG3(x,y,z,w)  if(_ASYNC_DNS_STM32_LOGLEVEL_>3) { DBG_PORT.print("[DNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#endif    //AsyncDNSServer_Debug_STM32_H
