// Source          ::     Lab03.CountingInBinary
// Description     ::     Count in binary using a series of LEDs, and other components to control the increment rate (+1 , +2 , +3).
// Programmed by   ::     Ella Moldez / July 17, 2022

/*

This assignment assumes the completion of Projects 01 - 04 in the Arduino Projects book. 
Its purpose is to reinforce the concepts and language constructs discussed in those chapters.

This project is a counter that counts from 0 to 15 and displays the results in BINARY code.
Each LED glows to indicate the place value, and the equivalent number in decimal can be found 
by adding all of the individual digits of the glowing LEDs.

To determine the values, we also consider the following components:
 RGB LED - to indicate the hexamedical or "16s"
 temperature sensor - to determine the room temperature and it affects the increment value for the counter01 (binary).
 switch/button - when pressed, on-board LED is turn on and overrides the increment value to 0
 
Using the serial monitor, we can obtain the information on temperature, increment value, binary and hexadecimal(16s) and understand 
what is going on in your circuit and code as it runs.


Parts required:
  - Arduino UNO
  - solderless breadboard half size
  - four red LEDs
  - one RGB LED
  - one 10 kilohm resistor
  - seven 220 ohm resistors
  - one TMP36 temperature sensor
  - one pushbutton
  - jumper wires 

*/


//********** GLOBAL VARIABLES **********************************************************
// Put ALL your variable declarations here, NOWHERE ELSE!

//variables use to store the values of 
int counter01 = 0;
int counter16 = 0;

//red LEDs connected to digital pins
int LED1 = 2; //LED connected to digital pin 2
int LED2 = 3; //LED connected to digital pin 3
int LED3 = 4; //LED connected to digital pin 4
int LED4 = 5; //LED connected to digital pin 5

int RED_PIN = 11;
int GREEN_PIN = 10;
int BLUE_PIN = 9;

//variable use to store the value of the increment
int incrementValue;

// named constant for the pin the sensor is connected to
const int sensorPin = A0;

// room temperature in Celsius
const float baselineTemp = 20.0;

//store the "state" of the switch
int switchOneState; 


//********** SETUP FUNCTION TO INITIALIZE VARIABLES ONCE *******************************
void setup() {
  
// Change the message to reflect the actual assignment.
  Serial.begin(9600);
  Serial.println("Assignment 03, Counting in Binary by Ella Moldez");
  Serial.println("    ");

//********** S_100
// Put your pinMode()'s below this statement.

  //These are RGB LED pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  //pins 2,3,4 and 5 are red LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  //13 is the "hardwired" small yellow on-board LED
  pinMode(13,OUTPUT);

  // Declare the switch pin (7) as input.
  pinMode(7, INPUT);


//********** S_200

//********** S_300

//********** S_400

//********** S_500


// This code is to help you visualize the one time execution of setup.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm leaving setup.");
  //Serial.println("    ");

}



//********** LOOP FUNCTION THAT RUNS LOGIC CONTINUOUSLY *******************************
void loop() {
 
// This code is to help you visualize the loop.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm at the top of the loop.");
  
  
//********** L_100


//********** L_200


//********** L_300
// This sections reads the temperature sensor, and determines what the "increment rate" should be.
// DO NOT actually increment counter01 and counter16 in this section!
// Put code below these comments.
  
  // read the value on Analog pin 0 and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((voltage - 500 mV) times 100)
  int temperature = round((voltage - .5) * 100);

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on the pin or not
  switchOneState  = digitalRead(7);

  //When button is pressed, increment value is set to 0 and on-board LED is ON
  if( switchOneState  == HIGH){
    incrementValue = 0;
    digitalWrite(13, HIGH);
  }
  //if the button is NOT pressed, the following codes are applied.
  else{
    //if the current temperature is lower than the baseline temperature, equal to 20.0 or rises to 2.99 degrees,
    //increment value is set to 1
      if (temperature < baselineTemp && temperature >= baselineTemp && temperature < baselineTemp + 2.99) {
        incrementValue = 1;  
      } 
      // if the temperature rises 3-5.99 degrees, increment value is set to 2
      else if (temperature >= baselineTemp + 3 && temperature < baselineTemp + 5.99) {
        incrementValue = 2;
      }
      // if the temperature rises to 6 degrees or more, increment value is set to 3
      else if (temperature >= baselineTemp + 6) {
        incrementValue = 3; 
      }  
      //on-board LED is OFF when button is NOT pressed.
      digitalWrite(13, LOW);
  }
  
//********** L_400
// This section "counts in binary" by altering the on/off pattern of the LEDs.
// DO NOT actually increment counter01 and counter16 in this section!
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
// Put code below these comments.

  switch(counter01){
    case 1: //if counter01 is equal to 1, LEDs display 0001
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,HIGH);
      break;
    case 2: //if counter01 is equal to 2, LEDs display 0010
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,LOW);
      break;
    case 3: //if counter01 is equal to 3, LEDs display 0011
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,HIGH);
      break;
    case 4: //if counter01 is equal to 4, LEDs display 0100
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,LOW);
      break;
    case 5: //if counter01 is equal to 5, LEDs display 0101
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,HIGH);
      break;
    case 6: //if counter01 is equal to 6, LEDs display 0110
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,LOW);
      break;
    case 7: //if counter01 is equal to 7, LEDs display 0111
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,HIGH);
      break;
    case 8: //if counter01 is equal to 8, LEDs display 1000
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,LOW);
      break;
    case 9: //if counter01 is equal to 9, LEDs display 1001
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,HIGH);
      break;
    case 10 : //if counter01 is equal to 10, LEDs display 1010
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,LOW);
      break;
    case 11 : //if counter01 is equal to 11, LEDs display 1011
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,HIGH);
      break;
    case 12: //if counter01 is equal to 12, LEDs display 1100
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,LOW);
      break;
    case 13: //if counter01 is equal to 13, LEDs display 1101
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,HIGH);
      break;
    case 14: //if counter01 is equal to 14, LEDs display 1110
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,LOW);
      break;
    case 15: //if counter01 is equal to 15, LEDs display 1111
      digitalWrite (LED1,HIGH);
      digitalWrite (LED2,HIGH);
      digitalWrite (LED3,HIGH);
      digitalWrite (LED4,HIGH);
      break;  
    default: //default value of LEDs is 0000
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,LOW);
      digitalWrite (LED3,LOW);
      digitalWrite (LED4,LOW);
      break;    
  }

//********** L_500
// This section alters the appearance of the RGB LED
// DO NOT actually increment counter01 and counter16 in this section!
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
 
  if(counter16 == 0){//LED light is unlit
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);  
    analogWrite(BLUE_PIN, 0);
  }
  if(counter16 == 1){ //green light will lit
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 128);  
    analogWrite(BLUE_PIN, 0);
  }
  if(counter16 == 2){ //yellow light will lit (yellow = a combination of red and green)
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);  
    analogWrite(BLUE_PIN, 0);
  }
  if(counter16 == 3){ //red light will lit
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 0);  
    analogWrite(BLUE_PIN, 0);
  }

//********** L_600
// This section displays useful information to the Serial Monitor.
// Put code below these comments.
  
  int Total = (counter16 * 16) + counter01;

  //Send the temperature value out the serial port
  Serial.print("Temperature: ");
  Serial.print(temperature);

  //Send the increment value out the serial port (based from the temperature range)
  Serial.print(", Increment: ");
  Serial.print(incrementValue);

  //Send the counter16 value out the serial port
  Serial.print(", counter16: ");
  Serial.print(counter16);

  //Send the counter01 value out the serial port
  Serial.print(", counter01: ");
  Serial.print(counter01);

  //Send the total value out the serial port
  Serial.print(", TOTAL: ");
  Serial.println(Total);



//********** L_700


//********** L_800


//********** L_900
// This section is the best place to increment counter01 and counter16,
// and take care of "rolling them over" to zero when upper limits are reached!
// Upper limit for counter01 is 15 ... that's the maximum number we can display in Base 2 using 4 LEDs ( 0000 thru 1111 )
// Upper limit for counter16 is 03 ... we've decided to stop the count at that
// Put code below these comments.

  //set the increment value based from the temperature and when the button is pressed or not
  counter01 += incrementValue; 
  
  if(counter01 > 15){
    counter01 = 0;
    ++counter16;  
  }
  if(counter16 > 3){
    counter16 = 0;
  }

// This code is to help you visualize the loop.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm at the bottom of the loop.");
  //Serial.println("    ");
  
// This delay controls the speed of your entire project
  delay(1000);  
}
