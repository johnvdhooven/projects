// Basic 4 Realy board connection
// Each relay is turned on for 2 seconds and then off.
// You can here them click as there state changes from off to on and on to
// off.
// You will also see the corresponding Red LED on the 4 Relay board
// light up when the relay is on.
 
 //  define names for the 4 Digital pins On the Arduino   

// These data pins link to 4 Relay board pins IN1, IN2, IN3,

#define RELAY1  12                      
#define RELAY2  13                      

 
void setup()
{    
// Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
}
 
 void loop()
{
   digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
   delay(200);                                      // Wait 0,2 seconds
   digitalWrite(RELAY1,HIGH);          // Turns Relay Off
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY2,LOW);           // Turns ON Relays 2
   delay(200);                                      // Wait 0,2 seconds
   digitalWrite(RELAY2,HIGH);          // Turns Relay Off
   delay(2000);                                      // Wait 2 seconds
 
 }
