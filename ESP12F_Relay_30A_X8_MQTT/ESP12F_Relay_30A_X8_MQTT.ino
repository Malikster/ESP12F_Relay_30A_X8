/*
  Arduino MQTT DEMO
*/

#include <ArduinoMqttClient.h>
//#include <WiFiNINA.h> // for MKR1000 change to: #include <WiFi101.h>
//#include <WiFi101.h>
#include "ESP8266WiFi.h"

#include "arduino_secrets.h"

// Thanks to Petre Cristi for help
#define LATCH_PIN 12  // Latch pin- INLOCUIESTI 9 cu 12 si vei avea: #define LATCH_PIN 12
#define CLOCK_PIN 13  // Clock pin INLOCUIESTI 10 cu 13
#define DATA_PIN  14  // Data pin INLOCUIESTI 8 cu 14
#define OE_PIN 5 // Not used

enum RELAY_ID {
  RELAY_ID_1,
  RELAY_ID_2,
  RELAY_ID_3,
  RELAY_ID_4,
  RELAY_ID_5,
  RELAY_ID_6,
  RELAY_ID_7,
  RELAY_ID_8,
};

enum RELAY_STATE {
  RELAY_STATE_OFF,
  RELAY_STATE_ON,
};


uint8_t Relays_Status_Current = 0;
uint8_t Relays_Status_Stored = 0;

void Update_Relays_State();
void Set_Relay_Status(RELAY_ID ID, RELAY_STATE STATE);
RELAY_STATE Get_Relay_Status(RELAY_ID ID);
void Init_Shifter_Pins();

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

// To connect with SSL/TLS:
// 1) Change WiFiClient to WiFiSSLClient.
// 2) Change port value from 1883 to 8883.
// 3) Change broker value to a server with a known SSL/TLS root certificate
//    flashed in the WiFi module.

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "192.168.1.250"; // Address of the MQTT server
int        port     = 1883;
const char topic[]  = "arduino/simple"; // Topic for MQTT

char reply[22];

int count = 0;

String subMessage = "";

void setup() {
  //Initialize serial
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  //
  //  buttonPin.setDebounceTime(50);

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  // mqttClient.setId("clientId");

  // You can provide a username and password for authentication
  // mqttClient.setUsernamePassword("user", "password");

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  while (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
  // subscribe to a topic
  mqttClient.subscribe(topic);
  //  digitalWrite(LED_BUILTIN, LOW);
  Init_Shifter_Pins();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alives which
  // avoids being disconnected by the broker
  //mqttClient.poll();
  //
  //  buttonPin.loop();

  int messageSize = mqttClient.parseMessage();
  if (messageSize) {
    subMessage = "";
    // we received a message, print out the topic and contents
    Serial.print("Received a message with topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.print(messageSize);
    Serial.println(" bytes:");

    // use the Stream interface to print the contents
    while (mqttClient.available()) {
      subMessage = subMessage + (char)mqttClient.read();
    }
    Serial.println(subMessage);
    
    checkcommand(subMessage);
  }
}

void switcher(int p, int s) {
  p = p - 1;
  for (int i = 0; i <= 15; i++)
  {
    if (p == i) {
      if (s == 1) {
        Set_Relay_Status((RELAY_ID)i, RELAY_STATE_ON);
      }
      if (s == 0) {
        Set_Relay_Status((RELAY_ID)i, RELAY_STATE_OFF);
      }
    }
    Update_Relays_State();
    delay(100);
  }
}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


void checkcommand(String inputMessage) {
  float value;
  String command;
  inputMessage.trim();
  command = getValue(inputMessage, ':', 0);

  if (command == "switch") {
    int  unit = getValue(inputMessage, ':', 1).toInt();
    int stat = getValue(inputMessage, ':', 2).toInt();
    String(command + String(unit) + ":" +  String(stat)).toCharArray(reply, 20);
    switcher(unit, stat);
  }

  if (strcmp(reply, "unknown") == 0) {
    String("unknown:" + inputMessage).toCharArray(reply, 20);
  }
}


void Update_Relays_State()
{
  //Check if the State has changed
  if (Relays_Status_Current != Relays_Status_Stored)
  {
    //Update the EEPROM

    //Set Relays_Status_Stored to Relays_Status_Current
    Relays_Status_Stored = Relays_Status_Current;
    //Send data to Shifter
    digitalWrite(LATCH_PIN, LOW);
    //shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (Relays_Status_Stored >> 8 ));
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, Relays_Status_Stored);
    digitalWrite(LATCH_PIN, HIGH);

  }
}

void Set_Relay_Status(RELAY_ID ID, RELAY_STATE STATE)
{
  bitWrite(Relays_Status_Current, ID, STATE);
}

RELAY_STATE Get_Relay_Status(RELAY_ID ID)
{
  return (RELAY_STATE)bitRead(Relays_Status_Current, ID);
}

void Init_Shifter_Pins()
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(OE_PIN, OUTPUT);
}
