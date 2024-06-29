/*****************************************************************************************************************************
**********************************    Author  : Ehab Magdy Abdullah                      *************************************
**********************************    Linkedin: https://www.linkedin.com/in/ehabmagdyy/  *************************************
**********************************    Youtube : https://www.youtube.com/@EhabMagdyy      *************************************
******************************************************************************************************************************/

#include <IRremote.hpp>

#define IR_RECEIVER_PIN      22                               // IR Receiver pin
#define LED_PIN              2                                // ESP32 inboard pin

void setup()
{
    Serial.begin(115200);                                     // Start Serial Monitor
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);   // Start IR Receiver, Enable IRreceiver led
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    if (IrReceiver.decode())        // Check if there is a received code
    {
        Serial.print("Received Data: ");
        Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print Received code on Serial Monitor in Hexadecimal
        Serial.print("  -  Received Command: ");
        Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print Received command on Serial Monitor in Hexadecimal

        if(IrReceiver.decodedIRData.command == 0x0){        // if you press a button with command number '0'
          digitalWrite(LED_PIN, LOW);                       // Turn off the led
        }
        else if(IrReceiver.decodedIRData.command == 0x1){   // if you press a button with command number '1'
            digitalWrite(LED_PIN, HIGH);                    // Turn off the led
        }

        delay(1000);
        IrReceiver.resume();       // Enable receiving of the next value
    }
}
