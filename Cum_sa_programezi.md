# Ghid de programare pentru modulul de releu cu 8 canale și 30A ESP8266 ESP-12F

Acest ghid explică cum să programezi modulul **ESP8266 ESP-12F** pe un **modul de releu cu 8 canale și 30A** folosind o altă placă Arduino ca convertor USB-TTL. Arduino-ul va fi folosit pentru a încărca codul pe [...]

## Cerințe

### Hardware
- **Modul releu ESP8266 ESP-12F (alimentat cu DC 7-28V / 5V)**
- **Placă Arduino (de exemplu, Arduino Uno sau Nano)**
- **Cabluri jumper**
- **Cablu USB** (pentru conexiunea Arduino-PC)

### Software
- **Arduino IDE**
- **Pachetul de plăci ESP8266 pentru Arduino IDE**

---

## Instrucțiuni pas cu pas

### 1. Pregătește placa Arduino ca un convertor USB-TTL
Va trebui să ocolești microcontrolerul de pe placa Arduino, astfel încât să poată funcționa ca o interfață USB-serial.

#### Opțiunea 1: Scoate microcontrolerul
Dacă folosești un Arduino cu un microcontroler detașabil (de exemplu, Arduino Uno sau Nano):
- **Scoate microcontrolerul ATmega328** pentru a evita interferențele cu comunicarea serială.

#### Opțiunea 2: Dezactivează microcontrolerul
Dacă microcontrolerul nu este detașabil:
- **Conectează pinul RESET la GND**. Acest lucru va ține microcontrolerul în modul resetare, dezactivându-l astfel încât placa să funcționeze ca un convertor USB-TTL.

### 2. Conexiuni de cabluri

Conectează ESP8266 la Arduino conform tabelului:

| **Pin ESP8266** | **Pin Arduino** | **Descriere**                           |
|-----------------|------------------|-----------------------------------------|
| TX (GPIO1)      | RX (Pin 0)       | Recepție serială de la ESP8266          |
| RX (GPIO3)      | TX (Pin 1)       | Transmisie serială către ESP8266        |
| GND             | GND              | Masă comună                             |
| VCC             | 3.3V / 5V        | Alimentare pentru ESP8266 (în funcție de modul) |
| EN (CH_PD)      | 3.3V             | Pin activare (setat la high pentru a activa ESP8266) |
| GPIO0           | GND              | Setat la GND pentru modul de flashare   |

### 3. Alimentarea modulului de releu
Asigură-te că modulul de releu este alimentat corect:
- **Alimentează** modulul de releu folosind intrările de alimentare furnizate (DC 7-28V sau 5V).
- Asigură-te că ESP8266 primește suficientă putere (de obicei, este necesară o logică de 3.3V).

### 4. Instalarea pachetului de plăci ESP8266 în Arduino IDE

1. Deschide **Arduino IDE**.
2. Mergi la **File** -> **Preferences**.
3. În câmpul **"Additional Board Manager URLs"**, adaugă următorul URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json
4. Apasă **OK**.
5. Mergi la **Tools** -> **Board** -> **Boards Manager**, caută **ESP8266** și instalează pachetul.

### 5. Selectarea plăcii ESP8266 în Arduino IDE

1. Mergi la **Tools** -> **Board** -> **Generic ESP8266 Module**.
2. Sub **Tools**, configurează următoarele setări:
- **Flash Mode**: DIO
- **Flash Frequency**: 40MHz
- **CPU Frequency**: 80MHz
- **Flash Size**: 4M (1M SPIFFS)
- **Upload Speed**: 115200 (sau 9600 pentru depanare)
3. Selectează **Portul** corect (cel atribuit Arduino-ului).

### 6. Pune ESP8266 în modul de flashare

Pentru a programa ESP8266:
- **Conectează GPIO0 la GND** înainte de a apăsa butonul **RESET** sau de a alimenta modulul. Acest lucru va pune ESP8266 în modul de flashare.

### 7. Încărcarea codului pe ESP8266

1. Scrie sau deschide schița pe care vrei să o încarci. De exemplu, un test WiFi de bază:
```cpp
#include <ESP8266WiFi.h>

const char* ssid     = "your_SSID";
const char* password = "your_PASSWORD";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Codul tău aici
}
```

2. Apasă butonul Upload în Arduino IDE.

Dacă este necesar, apasă butonul RESET pe modulul ESP8266 sau deconectează temporar pinul EN (CH_PD) de la 3.3V.

### 8. Finalizare
După ce încărcarea este completă:

Deconectează GPIO0 de la GND pentru a scoate ESP8266 din modul de flashare.
Apasă butonul RESET sau deconectează și reconectează alimentarea modulului.
ESP8266-ul tău ar trebui acum să ruleze programul încărcat!

### Depanare
Dacă încărcarea eșuează, încearcă să reduci viteza de încărcare la 9600 baud.
Asigură-te că ESP8266 primește suficientă putere. Dacă folosești pinul de 3.3V al Arduino-ului, acesta poate să nu furnizeze suficient curent pentru ESP8266 în timpul operațiunilor WiFi. Ia în considerare utilizarea unei surse de alimentare externe de 3.3V.
Verifică dublu conexiunile, în special TX la RX și RX la TX.
Asigură-te că GPIO0 este conectat la masă doar în timpul flashării. După încărcare, ar trebui să fie deconectat de la GND.
Licență
Acest ghid este open-source și disponibil pentru utilizare sub Licența MIT.
