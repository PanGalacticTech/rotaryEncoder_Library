/* --------------- Rotary Encoder Library - Example -----------------

    Library to simplify the implementation of Rotary Encoders for inclusion with
    User Interfaces.

    My aim for this library was to make rotaryEncoder a Derived Class of button, and
    inheret all the functions from the buttonObject library.


   Imogen Wren
   Pan Galactic Tech
   16/08/2020

   Released for public use


*/




#include "rotaryEncoder.h"

#include <buttonObject.h>






void rotaryEncoder::begin() {                            

  buttonObject::begin();

  pinMode (encoderPinA, INPUT);
  pinMode (encoderPinB, INPUT);

 
}



/*
   Checks to see if rotary encoder has moved.
   Returns Values:
  // rotaryCount
  // rotaryUp - bool
  // rotaryDown - bool

*/





void rotaryEncoder::encodeDirection() {      // Method to decern the direction of rotary encoder movement and return latching bools to control functions elsewhere

  prevCount = rotaryCount;
  if (fired)  {

    if (up) {
      rotaryCount++;
    } else {
      rotaryCount--;
    }
    fired = false;
  }  // end if fired

  if (rotaryCount > prevCount) {          // This is nessissary as fired irs tends to be triggered twice for every click of the encoder.
    rotaryUp = true;                      // Otherwise these variables would be set directly by if statements above.
  } else if (rotaryCount < prevCount) {
    rotaryDown = true;
  }
}



void rotaryEncoder::resetEncoder() {

  rotaryUp = false;
  rotaryDown = false;


}




// ------------------------Rotary Turn Direction--------------------------------

// Wiring: Connect common pin of encoder to ground. <<< Accidently connected to +5v seems to work well
// Connect pin A (one of the outer ones) to a pin that can generate interrupts (eg. D2)
// Connect pin B (the other outer one) to another free pin (eg. D3)

void rotaryEncoder::isr () {                                      // interrupt service routine
  if (digitalRead (encoderPinA)) {                 // if change is detected on interrupt pin
    up = digitalRead (encoderPinB);
  } else {
    up = !digitalRead (encoderPinB);
  }
  fired = true;


}  // end of isr



//-----------------------------------------------------
