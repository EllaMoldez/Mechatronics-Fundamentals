// Source          ::     Lab04.CountingInBinaryII
// Description     ::     Count in binary using a series of LEDs, and other components to control the increment rate using the Potentiometer.
// Programmed by   ::     Ella Moldez / July 25, 2022

/*

This assignment assumes the completion of Projects 01 - 05 in the Arduino Projects book. 
Its purpose is to reinforce the concepts and language constructs discussed in those chapters.

This project is similar to Assignment 03, which involved manipulating the binary count rate with a potentiometer; 
A counter from 0 to 15 displays the results in BINARY code. Each LED glows to indicate the place value, 
and the equivalent decimal number can be found by adding all of the glowing LEDs' digits.

To determine the values, we also consider the following components:
 RGB LED - to indicate the hexamedical or "16s"
 potentiometer - it controls the increment value
 
Using the serial monitor, we can obtain the information on increment value, counter16 and counter01 and understand 
what is going on in your circuit and code as it runs.


Parts required:
  - Arduino UNO
  - solderless breadboard half size
  - four red LEDs
  - one RGB LED
  - 4four220 ohm resistors
  - one Potentiometer
  - one capacitor
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

//RGB LED connected to digital pins
int RED_PIN = 11;
int BLUE_PIN = 10;
int GREEN_PIN = 9;

int total = 0;

//variable use to store the value of the increment
int incrementValue = 0;


int const potPin = A0; // analog pin used to connect the potentiometer
int potValue = 0; // variable to read the value from the analog pin
int mappedValue; // variable to hold the data of the potentiometer

int lightVal = 0;
 
//********** SETUP FUNCTION TO INITIALIZE VARIABLES ONCE *******************************
void setup() {
  
// Change the message to reflect the actual assignment.
  Serial.begin(9600);
  Serial.println("Assignment 04b, Counting in Binary (with Potentiometer -4 thru 4) by Ella Moldez");
  Serial.println("    ");

//********** S_100
// Put your pinMode()'s below this statement.

  //These are RGB LED pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  //pins for red LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

 
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
// This sections reads the potentiometer, and determines what the "increment rate" should be.
// DO NOT actually increment counter01 and counter16 in this section!
// Put code below these comments.
    
    potValue = analogRead(potPin); // read the value of the potentiometer
    mappedValue = map(potValue, 0, 1023, 4, -4); // scale the numbers from the potentiometer


  
//********** L_400
// This section "counts in binary" by altering the on/off pattern of the LEDs.
// DO NOT actually increment counter01 and counter16 in this section!
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
// Put code below these comments.
  lightVal = counter01;

  if((lightVal - 8) > 0 ){
    digitalWrite(LED1, HIGH);

    lightVal -= 8;
  } else{
    digitalWrite(LED1, LOW);  
  }

  if((lightVal - 4) > 0 ){
    digitalWrite(LED2, HIGH);

    lightVal -= 4;
  } else{
    digitalWrite(LED2, LOW);  
  }

  if((lightVal - 2) > 0 ){
    digitalWrite(LED3, HIGH);

    lightVal -= 2;
  } else{
    digitalWrite(LED3, LOW);  
  }

  if((lightVal - 1) > 0 ){
    digitalWrite(LED4, HIGH);

    lightVal -= 1;
  } else{
    digitalWrite(LED4, LOW);  
  }

//********** L_500
// This section alters the appearance of the RGB LED
// DO NOT actually increment counter01 and counter16 in this section!
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
 
  switch(counter16){//LED light is unlit
    case 0:
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);  
      digitalWrite(BLUE_PIN, LOW);
      break;

    case 1: //green light will lit
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);  
      digitalWrite(BLUE_PIN, LOW);
      break;
    case 2: //yellow light will lit (yellow = a combination of red and green)
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);  
      digitalWrite(BLUE_PIN, LOW);
      break;
    case 3: //red light will lit
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);  
      digitalWrite(BLUE_PIN, LOW);
      break;
  }

  
//********** L_600
// This section displays useful information to the Serial Monitor.
// Put code below these comments.
  
  total = (counter16 * 16) + counter01;

 //Send the increment value out the serial port (based from the movement of potentiometer)
  Serial.print("Increment: ");
  Serial.print(incrementValue);

  //Send the counter16 value out the serial port
  Serial.print(", counter16: ");
  Serial.print(counter16);

  //Send the counter01 value out the serial port
  Serial.print(", counter01: ");
  Serial.print(counter01);

  //Send the total value out the serial port
  Serial.print(", TOTAL: ");
  Serial.println(total);

 

//********** L_700


//********** L_800


//********** L_900
// This section is the best place to increment counter01 and counter16,
// and take care of "rolling them over" to zero when upper limits are reached!
// Upper limit for counter01 is 15 ... that's the maximum number we can display in Base 2 using 4 LEDs ( 0000 thru 1111 )
// Upper limit for counter16 is 03 ... we've decided to stop the count at that
// Put code below these comments.

  if(incrementValue >= 0){
    if((counter01 + incrementValue) > 15){
      if(counter16 == 3){
        counter16 = 0;
      }else{
        counter16++;
      }

      counter01 = (counter01 + incrementValue) - 16;
    } else{
      counter01 += incrementValue;
    }
    
  } else {
    if((counter01 + incrementValue) < 0){
      if(counter16 == 0){
        counter16 = 3;
      }else{
        counter16 -= 1;
      }

      counter01 = (counter01 + incrementValue) + 16;
    } else{
      counter01 += incrementValue;
    }
  
  }
  
  



  /*solution for 1-8 mappedValue
  if(counter01 + incrementValue) > 15{
    if(counter16 == 3){
      counter16 = 0;
    }else{
      counter16++;
    }

    counter01 = (counter01 + incrementValue) - 16;
  } else{
    counter01 += inc;
  }
*/


// This code is to help you visualize the loop.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm at the bottom of the loop.");
  //Serial.println("    ");
  
// This delay controls the speed of your entire project
  delay(1000);  
}
