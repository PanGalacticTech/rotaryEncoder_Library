/* --------------- Rotary Encoder Library - Example -----------------
 * 
 *  Library to simplify the implementation of Rotary Encoders for inclusion with
    User Interfaces.

    My aim for this library was to make rotaryEncoder a Derived Class of button, and
    inheret all the functions from the buttonObject library, as well as add in methods
    to record the direction the rotary encoder is turning.


   Declan Heard
   Pan Galactic Tech
   16/08/2020

   Released for Public Use
 * 
 * 
 */




#include <autoDelay.h>       // Used for delaying Serial printing, otherwise not required. Available @:  https://github.com/PanGalacticTech/autoDelay_Library
#include <ledObject.h>       // Required Dependancy Available @:                                         https://github.com/PanGalacticTech/buttonObject_Library                                      


#include "rotaryEncoder.h"




autoDelay printDelay;

int printDelayTime = 100;    // milliSeconds

ledObject led;  



//----------------------------------------------
// ~~ ENCODER INPUT ~~


#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

// Hardware Interrupts
// on Arduino UNO & NANo:
// = Pins 2 & 3
// 
// Only 1 interupt required for each encoder 
// So max TWO Encoder inputs.

#define ENCODER_BUTTON_PIN 4

// Set up instance of rotaryEncoder. Requires button pin, button active state, and 2 encoder pins.

rotaryEncoder encoderOne(ENCODER_BUTTON_PIN, BUTTON_PULL_HIGH, ENCODER_PIN_A, ENCODER_PIN_B);    





void setup() {

  Serial.begin(115200);


  led.begin(13 , 1);

  encoderOne.begin();    // encoder Begin function also calls the buttonObject begin function


//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround - Each instance of rotaryEncoder will require this line attaching 
// hardware interrupt to one of the encoders pins.
// & The ISR function below the main loop, referencing the isr function contained in the library

 attachInterrupt (digitalPinToInterrupt (ENCODER_PIN_A), isr , CHANGE);   // interrupt 0 is pin 2


}







bool printSerial = true;   // if true test serial output is printed.


void loop() {



  encoderOne.buttonLoop(750);   // button functions are borrowed directly from buttonObject library and can be
                                 // Accessed the same way. long int value passed is the time to register a long press in millis (defaults to 1 second)

  encoderOne.encodeDirection();  // Function returns rotaryUp = true or rotaryDown = true & rotaryCount
                                   // If used to control functions elsewhere bools can be reset using:
  //encoderOne.resetEncoder();                                  


  ledButtonFunctions();   // Test function to tie button input to LED output. (pin 13)
  
  serialPrintout();        // Prints out encoderOne.rotaryCount to serial monitor for testing.

}




//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround - for some reason isr must not be in capitals. 


void isr (){

encoderOne.isr();

  
}
