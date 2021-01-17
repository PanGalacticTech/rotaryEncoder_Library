# rotaryEncoder_Library
 Libary to handle reading information from rotary encoders.
 
 
 Uses public class buttonObject from buttonObject.h library.   
 // Required Dependancy Available @: https://github.com/PanGalacticTech/buttonObject_Library  
 
 
 

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
 
 // Hardware Interrupts
// on Arduino UNO & NANO:
// = Pins 2 & 3
// 
// Only 1 interupt required for each encoder 
// So max TWO Encoder inputs.


_______________________________________________________ Guide & Use _______________________________________________________

////////////// Constructor ///////////////

// Set up instance of rotaryEncoder. Requires button pin, button active state, and 2 encoder pins.

rotaryEncoder encoderOne(ENCODER_BUTTON_PIN, BUTTON_PULL_HIGH, ENCODER_PIN_A, ENCODER_PIN_B);  


////////////// Setup ///////////////

 encoderOne.begin();    // encoder Begin function also calls the buttonObject begin function


//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround - Each instance of rotaryEncoder will require this line attaching 
// hardware interrupt to one of the encoders pins.
// & The ISR function below the main loop, referencing the isr function contained in the library

 attachInterrupt (digitalPinToInterrupt (ENCODER_PIN_A), isr , CHANGE);   // interrupt 0 is pin 2


This should be declared underneath void loop();


void isr (){
encoderOne.isr();  
}

//-- This is a fudge, as isr methods cannot be inside our rotaryEncoder library
// This is a workaround - for some reason isr must not be in capitals. 


////////////// Loop ///////////////

// Call these functions in every loop

  encoderOne.buttonLoop(750);   // button functions are borrowed directly from buttonObject library and can be
                                 // Accessed the same way. long int value passed is the time to register a long press in millis (defaults to 1 second)
                                 // For information on buttonObject see buttonObject.h

  encoderOne.encodeDirection();  // Function returns rotaryUp = true or rotaryDown = true & rotaryCount
  

// Call this function to reset latching bools after using them for control
                                  
  //encoderOne.resetEncoder();    // If used to control functions elsewhere bools can be reset using:                          


eg :
if (encoderOne.rotaryUp){
incrementValue;
encoderOne.resetEncoder();    
} else if (encoderOne.rotaryDown){
decrementValue;
encoderOne.resetEncoder();
}



