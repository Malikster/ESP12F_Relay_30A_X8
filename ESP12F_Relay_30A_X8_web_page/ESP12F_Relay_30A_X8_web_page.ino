#include <avr/pgmspace.h>

const char index_html[] PROGMEM = R"rawliteral(
<!doctype html>
  <head>
    <title>Arduino controls</title>
    <meta charset="UTF-8">
    <meta name="apple-mobile-web-app-capable" content="yes" />
    <meta name="viewport" content="initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0" />
    <link rel="icon" href="data:,">
<style>
* { 
  height: 100%;
  width: 100%;
  margin: 0;
  padding: 0;
}


body{
  width: 100%;
  height: 100%;
  background: black !important;
  overflow: hidden; 
  -ms-overflow-style: none; /* for Internet Explorer, Edge */
    scrollbar-width: none; /* for Firefox */
    overflow: no-scroll; 
}
body::-webkit-scrollbar {
    display: none; /* for Chrome, Safari, and Opera */
}

#commonsection{
  position: absolute;
  top: 0.5%;
  left: 1%;
  width: 97.5%;
  height: 8%;
  border: 0.2em groove gold;
  border-radius: 45px;
  background: grey;
  overflow: show;
  box-shadow: 0.2em 0.2em 0.2em 0.2em rgba(255,255,255,.4); 
  z-index: 100;
  }

#switchbuttons{
  position: absolute;
  bottom: 2%;
  left: 1%;
  width: 48%;
  height: 85%;
  border: 0.2em groove gold;
  border-radius: 45px;
  background: grey;
  overflow: hidden;
  z-index: 90;
  transition:1s ease;
}
   button.halves {
     width: 50%;
     float: left;
    }


.responses {
  height: 20px;
}

.bottoms{
  position: absolute;
  bottom: 2%;
  right: 1%;
  width: 48%;
  height: 85%;
  border: 0.2em groove gold;
  border-radius: 2em;
  background: grey;
  overflow: hidden;
  z-index: 90;
  transition:1s ease; 
  }

  
.sections {
/** border: 2px solid red; **/
  width: 14.3em;
  height: 20em;
  float: left;
  padding: 0.1em 0.3em 0.1em 0.3em; 
  }
  .sections button {
      margin: 1%;
      height:15%;
      background: white;
      border: 0.1% solid black;
      border-radius: 45px;
      font-size: 16px;
      font-family: Courier;
      font-weight: bold;
      text-transform: uppercase;
    }



 
.buts{
  width: 90%;
  height: 3vw;
  margin-top: 5px;
  background: white;
  border: 1px groove black;
  border-radius: 3em;
  text-align: center;
  vertical-align: bottom;
  font-size: 1vw;
  font-family: Courier;
  font-weight: bold;
  text-transform: uppercase;
  box-shadow: 2px 2px 12px 1px rgba(255,255,255,.9); 
  z-index: 1500;

}
.buts:hover {
  color: grey;
  border-color: 1px solid grey;
  box-shadow: 0.2em 0.2em 0.2em 0.2em rgba(255,255,255,.4); 
} 
button {
  width: 100%;
  height: 2vw;
  box-shadow: 2px 2px 12px 1px rgba(255,255,255,.9); 
}

button:hover {
  color: grey;
  border-color: 1px solid grey;
  box-shadow: 0.2em 0.2em 0.2em 0.2em rgba(255,255,255,.4); 
} 
  
.coolshadow{
  box-shadow: 0.2em 0.2em 0.2em 0.2em rgba(255,255,255,.4); 
}

button.sectionbuts {
  width: 15em;
  height: 3vw;
  margin-top: 2%;
  line-height: 3vw;
  background: white;
  border: 1px groove black;
  border-radius: 3em;
  text-align: center;
  vertical-align: bottom;
  font-size: 16px;
  font-family: Courier;
  font-weight: bold;
  text-transform: uppercase;
  box-shadow: 2px 2px 12px 1px rgba(255,255,255,.9); 
  z-index: 1500;
}

  

table.tables {
  position: absolute; 
  top: 0; 
  left: 0; 
  width: 100%; 
  height: 100%; 
  vertical-align: top;
}
tr {
  height: 100%; 
  vertical-align: top;
}
td.half {
  padding: 2%;
  width: 50%;
  vertical-align: top;
  text-align: center;
}

.format {font-size:3rem}
small {font-size:1.4rem}
</style>
    <script type="text/javascript">
    

    
    function jsGo(c)
    {
        var command = c;
        var x = "?command=" + command; //encodeURIComponent(command);
        var fileName = "http://192.168.2.94/get"+x;     // Change this IP with your board network IP
        var fileName = fileName;
        var ajaxRequest;
        ajaxRequest = new XMLHttpRequest();
        ajaxRequest.onreadystatechange = function(){
            if(ajaxRequest.readyState == 4){
            theParent = document.getElementById("feedtd");
            theKid = document.createElement("div");
            theKid.className = "responses";
            theKid.innerHTML = ajaxRequest.responseText; //decodeURIComponent(ajaxRequest.responseText);
            theParent.appendChild(theKid);
            theParent.insertBefore(theKid, theParent.firstChild);
            }
        }
        ajaxRequest.open("GET", fileName, true);
        ajaxRequest.send(null);
    }
    </script>
</head>
<body>
  <div id="fulldiv" class="fullpage">
    <div id="commonsection">
      
    </div>
    
    

    <div id="switchbuttons">
        <table class="tables">
          <tr class="tables">
            <td class="half">
              <button  class="buts halves"  onclick="jsGo('switch:1:1')">1 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:1:0')">1 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:2:1')">2 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:2:0')">2 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:3:1')">3 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:3:0')">3 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:4:1')">4 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:4:0')">4 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:5:1')">5 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:5:0')">5 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:6:1')">6 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:6:0')">6 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:7:1')">7 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:7:0')">7 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:8:1')">8 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:8:0')">8 off</button>
            </td>
            <td class="half">
              <button  class="buts halves"  onclick="jsGo('switch:9:1')">9 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:9:0')">9 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:10:1')">10 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:10:0')">10 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:11:1')">11 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:11:0')">11 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:12:1')">12 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:12:0')">12 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:13:1')">13 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:13:0')">13 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:14:1')">14 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:14:0')">14 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:15:1')">15 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:15:0')">15 off</button>
              <button  class="buts halves"  onclick="jsGo('switch:16:1')">16 on</button>
              <button  class="buts halves"  onclick="jsGo('switch:16:0')">16 off</button>
            </td>
          </tr>
        </table>
        </div>
    <div id="switchessection" class="bottoms" data="Switches">
        <table class="tables">
          <tr class="tables">
            <td class="half" id="feedtd">
            </td>
            <td class="half">
            </td>
          </tr>
        </table>
    </div>

  </div>
  <script>
if (!!window.EventSource) {
 var source = new EventSource('/events');

 source.addEventListener('open', function(e) {
  console.log("Events Connected");
 }, false);
 source.addEventListener('error', function(e) {
  if (e.target.readyState != EventSource.OPEN) {
    console.log("Events Disconnected");
  }
 }, false);

 source.addEventListener('message', function(e) {
  console.log("message", e.data);
 }, false);


}
</script> 
  </body>
</html>)rawliteral";




//wifi
#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>




const char* ssid = "YOUR WIFI"; //your WiFi Name
const char* password = "YOUR PASS";  //Your Wifi Password



AsyncWebServer server(80);
// Create an Event Source on /events
AsyncEventSource events("/events");

unsigned long lastTime = 0;  
unsigned long timerDelay = 30000;

const char* PARAM_INPUT_1 = "command";
const char* PARAM_MESSAGE = "command";

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}
//Progmem
#define PROGMEM   ICACHE_RODATA_ATTR
#define ICACHE_RODATA_ATTR  __attribute__((section(".irom.text")))
#define PGM_P       const char *
#define PGM_VOID_P  const void *
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))


char buffer[18];
char reply[22];


#define LATCH_PIN 12  // Latch pin of 74HC595 is connected to Digital pin 5
#define CLOCK_PIN 13  // Clock pin of 74HC595 is connected to Digital pin 6
#define DATA_PIN  14  // Data pin of 74HC595 is connected to Digital pin 4
#define OE_PIN    5   // oePin - not using this

enum RELAY_ID {
    RELAY_ID_1,
    RELAY_ID_2,
    RELAY_ID_3,
    RELAY_ID_4,
    RELAY_ID_5,
    RELAY_ID_6,
    RELAY_ID_7,
    RELAY_ID_8,
    RELAY_ID_9,
    RELAY_ID_10,
    RELAY_ID_11,
    RELAY_ID_12,
    RELAY_ID_13,
    RELAY_ID_14,
    RELAY_ID_15,
    RELAY_ID_16
};

enum RELAY_STATE {
    RELAY_STATE_OFF,
    RELAY_STATE_ON,
};

uint16_t Relays_Status_Current = 0;
uint16_t Relays_Status_Stored = 0;

void Update_Relays_State();
void Set_Relay_Status(RELAY_ID ID, RELAY_STATE STATE);
RELAY_STATE Get_Relay_Status(RELAY_ID ID);
void Init_Shifter_Pins();


void switcher(int p,int s){

p = p -1;

  for(int i = 0; i<=15; i++)
  {
      if(p == i){    
          if(s == 1){
          Set_Relay_Status((RELAY_ID)i, RELAY_STATE_ON);
          }
          if(s == 0){
          Set_Relay_Status((RELAY_ID)i, RELAY_STATE_OFF);
          }
      }

    Update_Relays_State();
    delay(100);
  }

}


String getValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


void checkcommand(String inputMessage){
      float value;
      String command;
      inputMessage.trim();
         command = getValue(inputMessage, ':', 0);
             
            if(command == "switch"){
              int  unit = getValue(inputMessage, ':', 1).toInt();
              int stat = getValue(inputMessage, ':', 2).toInt();
              String(command + String(unit) + ":"+  String(stat)).toCharArray(reply, 20);
                switcher(unit, stat);
              }
            
          if(strcmp(reply, "unknown") == 0) {
            String("unknown:" + inputMessage).toCharArray(reply, 20);
            }
       

          
}

// Initialize WiFi
void initWiFi() {
  ESP.eraseConfig(); 
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());
}


String processor(const String& var){


  return String();
}



void setup() {
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266

  Init_Shifter_Pins();

   String("unknown").toCharArray(reply, 8);

      
  delay(10);
  initWiFi();
  delay(10);


   
  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String com;
    String vari;
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      com = request->getParam(PARAM_INPUT_1)->value();
        vari = PARAM_INPUT_1;
    }  else {
      com = "No message sent";
      vari = "none";
    }
  if(vari == "command"){

  checkcommand(com); 
//String("awesome reply").toCharArray(reply, 20); 

  } else {
      strcpy(reply, "unknown");
    }
    
    request->send(200, "text/html", reply);
    strcpy(reply, "");
  });

  // Handle Web Server Events
  events.onConnect([](AsyncEventSourceClient *client){
    if(client->lastId()){
      //Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
    }
    // send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!", NULL, millis(), 10000);
  });
  server.addHandler(&events);
  server.begin();  

}



void loop() {

 delay(0); 
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
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (Relays_Status_Stored >> 8));
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, Relays_Status_Stored);
    digitalWrite(LATCH_PIN, HIGH);

  }else{
    //Do nothing
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
