int latchPin = 12;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 13; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 14;  // Data pin of 74HC595 is connected to Digital pin 4
int oePin = 5;    // oePin - not using this

uint16_t Data ;

void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(oePin, OUTPUT);

}

void loop() 
{

            Data = 0b0000000000000001;         // Relay 1
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000000000011;         // Relay 2
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000000000111;         // Relay 3
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000000001111;         // Relay 4
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000000011111;         // Relay 5
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000000111111;         // Relay 6
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000001111111;         // Relay 7
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
            Data = 0b0000000011111111;         // Relay 8
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, (Data >> 8));
      shiftOut(dataPin, clockPin, MSBFIRST, Data);
      digitalWrite(latchPin, HIGH);
      delay(100);
}
