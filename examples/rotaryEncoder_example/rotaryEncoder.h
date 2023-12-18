/* --------------- Rotary Encoder Library - Example -----------------

    Library to simplify the implementation of Rotary Encoders for inclusion with
    User Interfaces.


   Imogen Wren
   Pan Galactic Tech
   16/08/2020

   Released for public use


*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Rotary Encoder Object ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Ran into a small problem in implementing this library.
// ISR routines cannot be called from inside a class
//  ISR routine needs to be external to library, but can pass known variables to the library.
// - Workaround - ISR function external to library simply calls the ISR routine from inside the library.



#ifndef rotaryEncoder_h
#define rotaryEncoder_h

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <buttonObject.h>



/*
    buttonObject is the BASE class

    rotaryEncoder is the DERIVED class

    My aim for this library was to make rotaryEncoder a Derived Class of button, and
    inheret all the functions from the buttonObject library.

    https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-superclass-constructor
    THIS PAGE HELPS!

    //https://paulmurraycbr.github.io/ArduinoTheOOWay.html  << This page was very confusing

*/






// Derived Class ------------// Base Class
class rotaryEncoder: public buttonObject {

  public:




    // Constructor
    rotaryEncoder(int buttonPin, int buttonActiveState, int encoder_pin_a, int encoder_pin_b):   // Note syntax and structure here: Important for implementing Derived Classes
      buttonObject (buttonPin, buttonActiveState),                                                  // BASE class is called without naming an instance, but passing any required values as arguments.

      encoderPinA(encoder_pin_a),                                                                     // Note commas and unsuaul punctuation.
      encoderPinB(encoder_pin_b)
    {
    }







    // Methods
    void begin();



    void encodeDirection();

    void  resetEncoder();

    void isr();

    // Variables



    bool rotaryUp;       // returns as true if encoder is turned up

    bool rotaryDown;     // returns as true if encoder is turned down.

    byte rotaryCount = 0;
    byte prevCount = 1;


  private:


    int encoderPinA;
    int encoderPinB;

    volatile bool fired;
    volatile bool up;


};




#endif
