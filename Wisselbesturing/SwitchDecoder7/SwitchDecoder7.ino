// Simple DCC Led Accessory Decoder
// Luca Dentella, 25.11.2017

// include NmraDcc library
#include <NmraDcc.h>
#include <SoftwareSerial.h>
// include Servo library
#include <Servo.h> 

// These data pins link to 4 Relay board pins IN1, IN2, IN3,

#define RELAY1  12                        
#define RELAY2  13                        

 
 


// Create NmraDcc en Servo object
NmraDcc Dcc;

Servo myservo1; // create servo object to control a servo 
Servo myservo2; // create servo object to control a servo
Servo myservo3; // create servo object to control a servo
Servo myservo4; // create servo object to control a servo 
Servo myservo5; // create servo object to control a servo

  int pos1 = 100; // variable to store the servo position 
  int pos2 = 100; // variable to store the servo position 
  int pos3 = 100; // variable to store the servo position 
  int pos4 = 100; // variable to store the servo position 
  int pos5 = 100; // variable to store the servo position 
  int pos6 = 100; // variable to store the servo position 
  int left = 50; //Servo position Left
  int right = 100; //Servo position Right


// a maximum of eight servo objects can be created 

// definitions
#define DCC_PIN         2
#define BOARD_ADDRESS   1
#define BOARD_ADDRESS2  2

#define PAIR_ADDRESS1   1
#define PAIR_ADDRESS2   2
#define PAIR_ADDRESS3   3
#define PAIR_ADDRESS4   4
#define PAIR_ADDRESS5   5
#define PAIR_ADDRESS6   6
#define GREEN_LED_PIN   3
#define RED_LED_PIN     4

#define This_Decoder_Address 16
uint8_t Decoder_Address = This_Decoder_Address;

void notifyDccAccState(uint16_t Addr, uint16_t BoardAddr, uint8_t OutputAddr, uint8_t State) {
 
  int pairAddress = (OutputAddr >> 1) + 1;
  int outputInPair = OutputAddr & 0x01;
  


    // check if the command is for our address and output

//Switch1
    
  if((BoardAddr == BOARD_ADDRESS) && (pairAddress == PAIR_ADDRESS1)) {
    if(outputInPair == 0) {
      Serial.println('switch1:'); 
      if (pos1!=left){
          pos1=left;
          Serial.println(pos1);
          myservo1.write(pos1);
      }
    } else {
      Serial.println('switch1:',pos1);
      if (pos1!=right){
          pos1=right;
          myservo1.write(pos1);
      }      
    }
  }

//Switch2

  if((BoardAddr == BOARD_ADDRESS) && (pairAddress == PAIR_ADDRESS2)) {
    if(outputInPair == 0) {
      Serial.println('switch2:'); 
      if (pos2!=left){
          pos2=left;
          Serial.println(pos2);
          myservo2.write(pos2);
      }
    } else {
      Serial.println('switch2:');
      if (pos2!=right){
          pos2=right;
          Serial.println(pos2);
          myservo2.write(pos2);
      }      
    }
  }  
  
//Switch 3

  if((BoardAddr == BOARD_ADDRESS) && (pairAddress == PAIR_ADDRESS3)) {
    if(outputInPair == 0) {
      Serial.println('switch3:'); 
      if (pos3!=left){
          pos3=left;
          Serial.println(pos3);
          myservo3.write(pos3);
      }
    } else {

      if (pos3!=right){
          pos3=right;
          Serial.println(pos3);
          myservo3.write(pos3);
      }      
    }
  }

//Switch 4

  if((BoardAddr == BOARD_ADDRESS) && (pairAddress == PAIR_ADDRESS4)) {
    if(outputInPair == 0) {
      Serial.println('switch4:'); 
      if (pos4!=left){
          pos4=left;
          Serial.println(pos4);
          myservo4.write(pos4);
          digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
          delay(200);                                      // Wait 0,2 seconds
          digitalWrite(RELAY1,HIGH);          // Turns Relay Off
      }
    } else {
      if (pos4!=right){
          pos4=right;
          Serial.println(pos4);
          myservo4.write(pos4);
          digitalWrite(RELAY2,LOW);           // Turns ON Relays 2
          delay(200);                                      // Wait 0,2 seconds
          digitalWrite(RELAY2,HIGH);          // Turns Relay Off
      }      
    }
  }

//Switch 5

    if((BoardAddr == BOARD_ADDRESS2) && (pairAddress == PAIR_ADDRESS5)) {
    if(outputInPair == 0) {
      Serial.println('switch5:');
      if (pos5!=left){
          pos5=left;
          Serial.println(pos5);
          myservo5.write(pos5);
      }
    } else {
      if (pos5!=right){
          pos5=right;
          Serial.println(pos5);
          myservo5.write(pos5);
      }      
    }
  }

//Switch 6

    if((BoardAddr == BOARD_ADDRESS2) && (pairAddress == PAIR_ADDRESS6)) {
    if(outputInPair == 0) {
      Serial.println('switch6:');
      if (pos6!=left){
          pos6=left;
          Serial.println(pos6);
          digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
          delay(200);                                      // Wait 0,2 seconds
          digitalWrite(RELAY1,HIGH);          // Turns Relay Off
   
      }
    } else {
      if (pos6!=right){
          pos6=right;
          Serial.println(pos6);
          digitalWrite(RELAY2,LOW);           // Turns ON Relays 2
          delay(200);                                      // Wait 0,2 seconds
          digitalWrite(RELAY2,HIGH);          // Turns Relay Off

      }      
    }
  }


  
}


void setup() {

  // Servo

  myservo1.attach(A0); // attaches the servo on pin A3 to the servo object 
  myservo2.attach(A1); // attaches the servo on pin A3 to the servo object 
  myservo3.attach(A3); // attaches the servo on pin A3 to the servo object 
  myservo4.attach(A4); // attaches the servo on pin A3 to the servo object 
  myservo5.attach(A5); // attaches the servo on pin A3 to the servo object 

  // Serial output for debugging
  Serial.begin(115200);
  Serial.println("DCC Led Accessory Decoder");
  Serial.println();

  // init NmraDcc library (PIN, manufacturer, version...) 
  Dcc.pin(digitalPinToInterrupt(DCC_PIN), DCC_PIN, 1);
  Dcc.init(MAN_ID_DIY, 1, FLAGS_DCC_ACCESSORY_DECODER, 0);

  // configure pins
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  Serial.println("- decoder ready");

// relais

// Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1,HIGH);           // Turns ON Relays 2
  digitalWrite(RELAY2,HIGH);           // Turns ON Relays 2

  
}


void loop() {

   Dcc.process();
}

