#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display.
// If 0x27 doesn't work, try 0x3F.
int buttonPin = 13; //the number of pushbutton
int buttonpushCounter = 0; 
int buttonState = 0; // variable for reading the pushbutton status
int oldButtonState = 0;


void setup()
{
  lcd.init();
  lcd.backlight(); //turn on backlight
  lcd.print("Button presses:"); //print a message to the LCD
  pinMode(buttonPin, INPUT); //set buttonPin as output
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);   // Get the current state of the button

  if (buttonState == HIGH && oldButtonState == LOW)
  {
    lcd.setCursor(1, 1); //set the cursor position
    lcd.print(++buttonpushCounter);
  }
  
  oldButtonState = buttonState;
  // save the current state as the last state
  //for next time through the loop
  Serial.print("");
    Serial.println(buttonpushCounter);
}
