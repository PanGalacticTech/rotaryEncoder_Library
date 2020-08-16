




void ledButtonFunctions() {     // Function to handle all the button test events and LED outputs

  if (encoderOne.shortPress) {
    led.toggleLED();
    encoderOne.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken
  }

  if (encoderOne.longPress) {
    led.blinkEvent(10, 100, 200);
    encoderOne.buttonReset();     // .buttonReset method resets longPress & shortPress variables once action has been taken
  }


  led.performBlink();    // Function from the LED library to perform blink events.

}









void serialPrintout() {  // Function to handle all test serial printouts.

  if (printSerial) {

    if (printDelay.millisDelay(printDelayTime)) {



      Serial.print("rotaryCount: ");
      Serial.print(encoderOne.rotaryCount);


      /*
            Serial.print("   Press Count: ");
            Serial.print(encoderButton.pressCount);

            Serial.print("   longPress Count: ");
            Serial.print(encoderButton.longPressCount);

            Serial.print("   Release Count: ");
            Serial.print(encoderButton.releaseCount);

      */

      Serial.println(" ");

    }

  }

}
