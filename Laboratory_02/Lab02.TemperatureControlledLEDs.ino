// Source          ::     Lab02.TemperatureControlledLEDs
// Description     ::     Reads from a temperature sensor to control the blink rate of a set of LEDs ( hotter == faster )
// Programmed by   ::     Ella Moldez / July 8, 2022


/*

Project Description:

This assignment assumes the completion of Projects 01 - 03 in the Arduino Projects book. 
Its purpose is to reinforce the concepts and language constructs discussed in those chapters.

The primary goal of this project is to implement a function that measures the temperature of the 
room or the hands of the experimenter if she or he touches the temperature sensor and controls the LEDs' blink rate.
Using the serial monitor, we can also obtain sensor status information, understand what is going 
on in your circuit, and code as it runs.

Parts used:
  - one TMP36 temperature sensor
  - four red LEDs
  - one yellow LED  
  - five 220 ohm resistors
  - one 10 kilohm resistor
  - one pushbuttons
  - jumper wires 

*/


//********** GLOBAL VARIABLES **********************************************************
// Put ALL your variable declarations here, NOWHERE ELSE!

//default delay time
int dTime = 1000;

// named constant for the pin the sensor is connected to
const int sensorPin = A0;

// room temperature in Celsius
const float baselineTemp = 20.0;

//store the "state" of the switch
int switchOneState; 

//********** SETUP FUNCTION TO INITIALIZE VARIABLES ONCE *******************************
void setup() {
 
// Change the message to reflect the actual assignment.

  // open a serial connection to display values
  Serial.begin(9600);
  
  // Declare the switch pin (6) as input.
  pinMode(7, INPUT); //button
  //13 is the "hardwired" small yellow on-board LED
  pinMode(13,OUTPUT);
  //set pin 6 for yellow LED
  pinMode(6,OUTPUT);
  
  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  Serial.println("Assignment 02, Temperature Sensor by Ella Moldez");
  Serial.println("    ");

//********** S_100
// Put your pinMode()'s below this statement.


//********** S_200

//********** S_300

//********** S_400

//********** S_500

// This code is to help you visualize the one time execution of setup.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm leaving setup.");
 // Serial.println("    ");

}

//********** blink yellow led function **********************************************************
//This function was added to indicate when the temperature reaches 26 degrees Celsius or higher. 
//If this occurs, the yellow LED will begin to blink.

void blinkYellowLed(){
    digitalWrite(6,HIGH); // turn the green LED on pin 4 ON (HIGH is the voltage level)
    delay(200); // delay or wait for 0.1 second before changing the light 
    digitalWrite(6,LOW); // turn the green LED on pin 4 OFF
    delay(200); // delay or wait for 0.1 second before changing the light 
}

//********** LOOP FUNCTION THAT RUNS LOGIC CONTINUOUSLY *******************************
void loop() {
 
 // This code is to help you visualize the loop.  
// Comment out or remove when you no longer require it


 // Serial.println("I'm at the top of the loop.");
  
  
//********** L_100


//********** L_200



//********** L_300
// This section reads the temperature sensor and switch state.
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
// Put code below these comments.

  // read the value on AnalogIn pin 0 and store it in a variable
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
  
//********** L_350
// This section determines what the "delay time" should be based on the temperature and switch state.
// DO NOT put any Serial.print()'s in this section!
// DO NOT put any delay()'s in this section!
// Put code below these comments.
  
  // HIGH, it means if the button is pressed. 
  if( switchOneState  == HIGH){
    //When button is pressed, delay time is set to 2000ms or 2 seconds and on-board LED is ON
    dTime = 2000;
    digitalWrite(13, HIGH);
  }
  //if button is NOT pressed, the blink rate of the red LEDs will depend on the following relationships 
  //(of temmperature and delay time) and on-board LED is OFF
  else{
      digitalWrite(13, LOW);
      
      // if the current temperature is lower than the baseline temperature, delay time would be 1500ms
      if (temperature < baselineTemp) {
        dTime = 1500;
      } 
      // if the temperature is equal to 20.0 or rises to 1.99 degree, delay time would be 1000ms
      else if (temperature >= baselineTemp && temperature < baselineTemp + 1.99) {
        dTime = 1000;
      } 
      // if the temperature rises 2-3.99 degrees, change delay time to 800ms
      else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 3.99) {
        dTime = 800;
      }
      // if the temperature rises 4-5.99 degrees, change delay time to 600ms
      else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 5.99) {
        dTime = 600; 
      } 
      // if the temperature rises to 6 degrees or more, change delay time to 400ms
      else if (temperature >= baselineTemp + 6) {
        dTime = 400;
        blinkYellowLed(); //calles the blinkYellowLed function
      }  
  }
  
//********** L_400
// This section is where you blink the LEDs
// DO NOT put any Serial.print()'s in this section!
// Put code below these comments.

    // turn the red LED on pin 2 ON and turn the red LEDs on pins 3,4 and 5 OFF
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(dTime); 

    // turn the red LED on pin 3 ON and turn the red LEDs on pins 2,4 and 5 OFF
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(dTime);

    // turn the red LED on pin 4 ON and turn the red LEDs on pins 2,3 and 5 OFF
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(dTime);

    // turn the red LED on pin 5 ON and turn the red LEDs on pins 2,3 and 4 OFF
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(dTime);

//********** L_500



//********** L_600
// This is the "serial port display section" that will show the temperature sensor reading,
// and the switch state.
// Put code below these comments.

  // send the 10-bit sensor value out the serial port
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Send the voltage level out the serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);

  //Send the temperature value out the serial port
  Serial.print(", Degrees C: ");
  Serial.print(temperature);

  //Send the delay time as per the temperature range out the serial port
  Serial.print(", Delay: ");
  Serial.println(dTime);


//********** L_700


//********** L_800


//********** L_900
  
  

// This code is to help you visualize the loop.  
// Comment out or remove when you no longer require it
  //Serial.println("I'm at the bottom of the loop.");
  //Serial.println("    ");
  
}
