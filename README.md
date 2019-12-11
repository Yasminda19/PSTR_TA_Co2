# TUGAS AKHIR PSTR
## PENDEKATAN IMPLEMENTASI BERBAGAI ARSITEKTUR ALAT MONITORING BERKALA GAS DALAM GREENHOUSE

Anggota Kelompok

  - Yasmin Salamah
  - Muhamad Hilmy Haidar
  - Suko Martin
 
### Komponen yang digunakan

|Sensor|
|--|
| MQ-4 Methane Gas Sensor |
| MQ-135 Air Quality Sensor |
| MQ-9 Carbon Monoxide Sensor |
| MQ-7 Smoke Sensor |

|Sistem Kontrol |
|--|
| Arduino Mega|
| esp8266 |

|Aktuator|
|--|
| Arduino LCD TFT 3.5" 480X320 Module Shield for Uno / Mega Shield|
| LED x 4 |
| Piezo Buzzer |

|Komunikasi|
|--|
| Wifi |

### Arsitektur 

Implementasi nodemcu sebagai client yang menggunakan API dari Thingspeak

Implementasi nodemcu sebagai client yang dapat mengconsume API ke I-surf (Dibuat server pribadi)

Implementasi nodemcu sebagai server.
