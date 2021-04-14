/****************************************************************************************************************************
  hal_conf_extra.h
  
  For STM32 with LAN8720 (STM32F4/F7)or built-in LAN8742A Ethernet (Nucleo-144, DISCOVERY, etc)
  
  AsyncDNSServer_STM32 is a Async DNS Server library for the STM32 using built-in LAN8742A Ethernet
  
  Based on and modified from ESPAsyncDNSServer Library (https://github.com/devyte/ESPAsyncDNSServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncDNSServer_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/
 
// Note: Must replace 
// .arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h
// as described in README.md

#pragma once
  
#ifndef HAL_CONF_EXTRA_STM32_H
#define HAL_CONF_EXTRA_STM32_H

#define HAL_ETH_MODULE_ENABLED

#define LAN8742A_PHY_ADDRESS            0x01U

#endif      // HAL_CONF_EXTRA_STM32_H
