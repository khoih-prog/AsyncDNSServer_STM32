# AsyncDNSServer_STM32 Library


[![arduino-library-badge](https://www.ardu-badge.com/badge/AsyncDNSServer_STM32.svg?)](https://www.ardu-badge.com/AsyncDNSServer_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AsyncDNSServer_STM32.svg)](https://github.com/khoih-prog/AsyncDNSServer_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/AsyncDNSServer_STM32/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AsyncDNSServer_STM32.svg)](http://github.com/khoih-prog/AsyncDNSServer_STM32/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>
<a href="https://profile-counter.glitch.me/khoih-prog/count.svg" title="Total khoih-prog Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog/count.svg" style="height: 30px;width: 200px;"></a>
<a href="https://profile-counter.glitch.me/khoih-prog-AsyncDNSServer_STM32/count.svg" title="AsyncDNSServer_STM32 Visitor count"><img src="https://profile-counter.glitch.me/khoih-prog-AsyncDNSServer_STM32/count.svg" style="height: 30px;width: 200px;"></a>

---
---

## Table of Contents


* [Changelog](#changelog)
  * [Releases v1.1.1](#releases-v111)
  * [Releases v1.1.0](#releases-v110)
  * [Initial Releases v1.0.0](#initial-releases-v100)

---
---

## Changelog

### Releases v1.1.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.1.0

1. Add support to **LAN8720** Ethernet for many **STM32F4** (F407xx, NUCLEO_F429ZI) and **STM32F7** (DISCO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG) boards.
2. Add LAN8720 examples
3. Add Packages' Patches for STM32 to use LAN8720 with STM32Ethernet and LwIP libraries
4. Add Table-of-Contents

### Initial Releases v1.0.0

1. Initial coding to port [ESPAsyncDNSServer](https://github.com/devyte/ESPAsyncDNSServer) to STM32 boards using builtin LAN8742A Ethernet. More supports will be added gradually later, such as other Ethernet / WiFi shields.
2. Add more examples.
3. Add debugging features.



