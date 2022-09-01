// Source          ::     Asgn01.SpaceshipInterfaceII.ino
// Description     ::     Controlling LEDs with switches
// Programmed by   ::     Ella Moldez / July 1, 2022 

/*
This assignment assumes the completion of Projects 01 - 02 in the Arduino Projects book. 
Its purpose is to reinforce the concepts and language constructs discussed in those chapters.

When the first button (switch) is pressed, three red LEDs flash in a specific pattern while the green LED remains off.
A second switch is pressed, which changes the red LEDs flashing sequence and illuminates the on-board LED for the duration of the switch. 
Finally, pressing both switches results in a different pattern on the flashing red LEDs.

  Parts used:
  - one green LED
  - three red LEDs
  - two pushbuttons
  - two 10 kilohm resistor
  - four 220 ohm
  - jumper wires 

*/

// Global variables to store whether the buttons are pressed or not. 
// These global variables are persistent throughout the program.

int switchState1 = 0; //store the "state" of the first switch
int switchState2 = 0; //store the "state" of the second switch

//basic functions
void setup() {

  //declare the LED pins as outputs
  // Pin 4 is a green LED, 5, 6 and 7 are red LEDs and 13 is the "hardwired" small yellow on-board LED
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  
  // Declare the switch pins (2 and 3) as input. 
  //Pins 2 and 3 are contact switches (buttons)
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

//Additional Functionality 1: a simple function to perform flashing pattern for green LED
void blinkGreenLed(){
    digitalWrite(4,HIGH); // turn the green LED on pin 4 ON (HIGH is the voltage level)
    delay(100); // delay or wait for 0.1 second before changing the light 
    digitalWrite(4,LOW); // turn the green LED on pin 4 OFF
    delay(100); // delay or wait for 0.1 second before changing the light 
}
  
void loop() {

/********************************************************************************************************
  The following code controls what happens if you press the (first) button
********************************************************************************************************/
 
  // Determine the state of the first button
  
  // read the value of the switches
  // digitalRead() checks to see if there is voltage on the pin or not
  switchState1 = digitalRead(3); //first switch
  switchState2 = digitalRead(2); //second switch
  
  if ( switchState1 == LOW && switchState2 == LOW ) { // If LOW, it means the first and second buttons are not pressed.
  
    // turn off the red LEDs and the small yellow on-board LED 
    //digitalWrite(4, HIGH); // turn the green LED on pin 4 ON
    digitalWrite(5, LOW);  // turn the red LED on pin 5 OFF
    digitalWrite(6, LOW);  // turn the red LED on pin 6 OFF
    digitalWrite(7, LOW);  // turn the red LED on pin 7 OFF 
    digitalWrite(13, LOW); // turn the small yellow on-board LED on pin 13 OFF
    blinkGreenLed(); //calls the function blinkGreenLed(), green LED turns ON and flashes when no buttons are pressed.   
  }
   
  if ( switchState1 == HIGH && switchState2 == LOW) { // If HIGH, it means the first button is pressed and LOW means the second button is NOT pressed.
       
    // Turn off the green LED
    digitalWrite(4,LOW);     
    
    // Turn off two red LEDs, and turn on one red LED
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);   
    digitalWrite(7,HIGH);
    
    delay(250); // wait for a quarter second before changing the light (250 milliseconds is 1/4 of a second)
   
    // Toggle the red LEDs
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);   
    digitalWrite(7,LOW);
    
    delay(250); // wait for a quarter second before changing the light

    // Toggle the red LEDs
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);   
    digitalWrite(7,LOW);
    
    delay(250); // wait for a quarter second before changing the light 
  }
  
 // The above two if's could be done with a single if... else.. construct,
 // but often beginning programmers find it easier to understand logic accomplished
 // step by step with individual if's
 
/********************************************************************************************************
   End of code that controls what happens if you press the (first) button
********************************************************************************************************/


/********************************************************************************************************
   The following code controls what happens if you press the (second) button
********************************************************************************************************/

// Determine the state of the second button
   
 if ( switchState1 == LOW && switchState2 == HIGH ) { // If HIGH, it means the second button is pressed and LOW means the first button is NOT pressed.

    // Turn on the small yellow on-board LED 
    digitalWrite(13, HIGH);
    
    // Turn off the green LED
    digitalWrite(4,LOW);    
      
    // Turn off two red LEDs, and turn on one red LED
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);   
    digitalWrite(7,LOW);
    
    delay(100); // delay or wait for 0.1 second before changing the light 
   
    // Toggle the red LEDs
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);   
    digitalWrite(7,LOW);
    
    delay(100); // delay or wait for 0.1 second before changing the light 

    // Toggle the red LEDs
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);   
    digitalWrite(7,HIGH);
    
    delay(100); // delay or wait for 0.1 second before changing the light 
   }
  
 // The above two if's could be done with a single if... else.. construct,
 // but often beginning programmers find it easier to understand logic accomplished
 // step by step with individual if's

 
/********************************************************************************************************
   End of code that controls what happens if you press the (second) button
********************************************************************************************************/


/********************************************************************************************************
  Additional Functionality 2: The following code controls what happens if you press both buttons
********************************************************************************************************/

  if ( switchState1 == HIGH && switchState2 == HIGH ) { // If HIGH, it means the (first and second) buttons are pressed.   
    
    digitalWrite(4,LOW);  // Turn off the green LED   
    digitalWrite(13, LOW); // Turn on the small yellow on-board LED 
      
    // Turn off two red LEDs, and turn on one red LED
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);   
    digitalWrite(7,LOW);
    delay(1000); // waits for a second before changing the light 

   // Turn on the two red LEDs, and turn off one red LED
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);   
    digitalWrite(7,HIGH);
    delay(1000); // waits for a second before changing the light
  }

 
/********************************************************************************************************
   End of Additional Functionality 2 - code that controls what happens if you press both buttons
********************************************************************************************************/



// this process (function) will infinitely repeat
}
/********************************************************************************************************
   End of program.  Nothing should be below here!
********************************************************************************************************/
