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

void setup() {
  Serial.begin(115200);
  Init_Shifter_Pins();
}

void loop() {
  for(int i = 0; i<=7; i++)
  {
    Set_Relay_Status((RELAY_ID)i, RELAY_STATE_ON);
    Update_Relays_State();
    delay(100);
  }

  for(int i = 0; i<=7; i++)
  {
    Set_Relay_Status((RELAY_ID)i, RELAY_STATE_OFF);
    Update_Relays_State();
    delay(100);
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
