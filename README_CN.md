* [English Version](./README.md)

### RTL8721Dx 手动配置WiFi连接AP示例（FreeRTOS）

🔹 这是一个演示如何使用RTL8721Dx系列SoC WiFi API 进行AP连接的演示，区别与WiFi_connect_demo这个例子，该例子加入了对WiFi事件的响应，如果WiFi断线，可以触发事件进行自动回连操作，用户也可以基于自己的需求在事件中加入其他的功能执行。



- 📎 开发板链接  [🛒 淘宝](https://item.taobao.com/item.htm?id=904981157046)   |[📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)
- 📄 [芯片详情](https://aiot.realmcu.com/cn/module/index.html)
- 📚 [WiFi Document](https://aiot.realmcu.com/cn/latest/rtos/wifi/api/index.html)

---
### ✨ 功能特点

✅ 首先需要关闭SDK内建的WiFi reconnect机制  
✅ WiFi_connect_demo.h define了ssid（test）password（12345678），可以自行修改   
✅ retry连线过程中led会红色闪烁
✅ 连接上WiFi led 会变绿色
✅使用AT命令查看WiFi状态信息
✅WiFi 状态发生变化（断线，led亮红灯）可以自动触发回连操作

---
### 🔧搭建硬件环境

1️⃣ **所需组件**
   - AP，开启802.11bgn mode 支持
   - RTL8721Dx EVB（带WiFi 天线）

2️⃣ **连接导线**
   -配置AP的ssid与password
   ```bash
   #define SSID                "ax3"   //abgn mode
   #define PASSWORD            "12345678"
   ```
3️⃣ **关闭SDK WiFi自动回连开关**
   ```bash
    `{sdk}/component/soc/usrcfg/amebadplus/ameba_wificfg.c`
      wifi_user_config.fast_reconnect_en = 0;
      wifi_user_config.auto_reconnect_en = 0;
   ```

### 🚀 快速开始

1️⃣ **初始化SDK环境**
   - 设置 `env.sh` (`env.bat`) 路径：`source {sdk}/env.sh`
   - 将 `{sdk}` 替换为 [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos) 根目录的绝对路径。

⚡ **注意**：本示例仅支持 SDK 版本 **≥ v1.2**

2️⃣ **编译**
   ```bash
   source env.sh
   ameba.py build -p
   ```

3️⃣ **烧录 FLASH**
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   ⚠️ 注意：项目目录中提供的预编译bin文件也可以用如下方式烧录：
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4️⃣ **打开串口监视**
   -  `ameba.py monitor --port COMx --b 1500000`

5️⃣ **点击EVB RST按钮后，观察WiFi连接情况**
   - 使用下面AT命令查看WiFi 状态信息
      ```text
     AT+WLSTATE
     ```

---

### 📝 日志示例

```bash
日志：
11:35:53.670  ROM:[V1.1]
11:35:53.670  FLASH RATE:1, Pinmux:1
11:35:53.670  IMG1(OTA1) VALID, ret: 0
11:35:53.670  IMG1 ENTRY[f800779:0]
11:35:53.670  [BOOT-I] KM4 BOOT REASON 0: Initial Power on
11:35:53.670  [BOOT-I] KM4 CPU CLK: 240000000 Hz
11:35:53.670  [BOOT-I] KM0 CPU CLK: 96000000 Hz
11:35:53.670  [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz 
11:35:53.685  [BOOT-I] IMG1 ENTER MSP:[30009FDC]
11:35:53.685  [BOOT-I] Build Time: Mar  2 2026 10:46:49
11:35:53.685  [BOOT-I] IMG1 SECURE STATE: 1
11:35:53.685  [FLASH-I] FLASH CLK: 80000000 Hz
11:35:53.685  [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
11:35:53.685  [FLASH-I] Flash Read 4IO
11:35:53.685  [FLASH-I] FLASH HandShake[0x2 OK]
11:35:53.685  [BOOT-I] KM0 XIP IMG[0c000000:55960]
11:35:53.685  [BOOT-I] KM0 SRAM[20068000:3120]
11:35:53.685  [BOOT-I] KM0 PSRAM[0c058a80:20]
11:35:53.685  [BOOT-I] KM0 ENTRY[20004d00:60]
11:35:53.685  [BOOT-I] KM4 XIP IMG[0e000000:69d80]
11:35:53.685  [BOOT-I] KM4 SRAM[2000b000:1ee0]
11:35:53.685  [BOOT-I] KM4 PSRAM[0e06bc60:20]
11:35:53.685  [BOOT-I] KM4 ENTRY[20004d80:40]
11:35:53.685  [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1 
11:35:53.685  [BOOT-I] Image2Entry @ 0xe00d881 ...
11:35:53.685  [APP-I] KM4 APP START 
11:35:53.685  [APP-I] VTOR: 300070[L00, VTOROCKS-I] _NS:3000KM0 init_retarge7000
11:35:53.685  t_locks
11:35:53.685  [APP-I] VTOR: 30007000, VTOR_NS:30007000
11:35:53.685  [APP-I] IMG2 SECURE STATE: 1
11:35:53.701  [MAIN-[IC]L K-IIW]D G[C AreLf4rM]es: hd oenl!t
11:35:53.701  a:0 target:320 PPM[:M A0 PIN-I] PM_LimitKM0 OS S:30000 
11:35:53.701  TART 
11:35:53.701  [CLK-I] [CAL131K]: delta:8 target:2441 PPM: 3277 PPM_Limit:30000 
11:35:53.701  [LOCKS-I] KM4 init_retarget_locks
11:35:53.701  [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
11:35:53.701  [MAIN-I] KM4 MAIN 
11:35:53.701  [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
11:35:53.716  [MAIN-I] File System Init Success 
11:35:53.716  [WIFI_RECONN_DEMO-I] Customize wifi reconnect demo start!
11:35:53.716  [MAIN-I] KM4 START SCHEDULER 
11:35:53.716  interface 0 is initialized
11:35:53.716  interface 1 is initialized
11:35:53.716  [WLAN-I] LWIP consume heap 1312
11:35:53.716  [WIFI_RECONN_DEMO-I] start
11:35:53.716  [WLAN-A] Init WIFI
11:35:53.732  [WLAN-A] Band=2.4G&5G
11:35:53.752  [WLAN-I] NP consume heap 20400
11:35:53.764  [WLAN-I] AP consume heap 10400
11:35:53.764  [WLAN-I] Available heap after wifi init 332224
11:35:53.764  [WIFI_RECONN_DEMO-I] Wifi connect start, retry cnt = 0
11:35:53.764  [WLAN-A] set ssid ax3
11:35:59.065  [WLAN-A] start auth to 9e:46:33:d8:e3:14
11:35:59.074  [WLAN-A] auth success, start assoc
11:35:59.105  [WLAN-A] assoc success(4)
11:35:59.137  [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
11:35:59.152  [WLAN-A] set group key 4 1
11:35:59.152  [WLAN-I] set cam: gtk alg 4 0
11:35:59.152  [$]wifi connected
11:35:59.152  [WIFI_RECONN_DEMO-I] Wifi connect success, Start DHCP
11:35:59.733  [$]wifi got ip:"192.168.73.206"
11:35:59.733  wtn dhcp success
11:36:00.235  [WIFI_RECONN_DEMO-I] DHCP Success
11:36:04.065  [WLAN-A] sta recv disassoc 1 sta:9e:46:33:d8:e3:14
11:36:04.065  [$]wifi disconnected
11:36:04.065  [WLAN-A] IPS in
11:36:09.076  [WIFI_RECONN_DEMO-I] Wifi connect start, retry cnt = 0
11:36:09.076  [WLAN-A] IPS out
11:36:09.092  [WLAN-A] set ssid ax3
11:36:19.061  [WLAN-A] start auth to 9e:46:33:d8:e3:14
11:36:19.108  [WLAN-A] auth success, start assoc
11:36:19.112  [WLAN-A] assoc success(1)
11:36:19.155  [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
11:36:19.155  [WLAN-A] set group key 4 1
11:36:19.155  [WLAN-I] set cam: gtk alg 4 0
11:36:19.155  [$]wifi connected
11:36:19.155  [WIFI_RECONN_DEMO-I] Wifi connect success, Start DHCP
11:36:19.736  [$]wifi got ip:"192.168.22.206"
11:36:19.736  wtn dhcp success
11:36:20.239  [WIFI_RECONN_DEMO-I] DHCP Success
11:36:23.959  AT+WLSTATE
11:36:23.959  [+WLSTATE]: _AT_WLAN_INFO_
11:36:23.959  WLAN0 Status: Running
11:36:23.959  ==============================
11:36:23.974  WLAN0 Setting:
11:36:23.974  ==============================
11:36:23.974        MODE => STATION
11:36:23.974        SSID => ax3
11:36:23.974       BSSID => 9e:46:33:d8:e3:14
11:36:23.974     CHANNEL => 6
11:36:23.974    SECURITY => WPA2 AES
11:36:23.974    PASSWORD => 12345678
11:36:23.974  
11:36:23.974  Interface (0)
11:36:23.974  ==============================
11:36:23.974  MAC => c4:e5:b1:13:81:e0
11:36:23.974  IP  => 192.168.22.206
11:36:23.974  GW  => 192.168.22.223
11:36:23.974  MSK  => 255.255.255.0
11:36:23.974  
11:36:23.974  
11:36:23.974  OK
11:36:23.974  
11:36:23.974  [MEM] After do cmd, available heap 333184
11:36:23.974  
11:36:23.974  
11:36:23.974  #

```