#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
 
int buttonPin = 13;
int a = 0;
int buttonState = 0;
int oldButtonState = 0;
int switchPin = 12;
int switchState = 0;
 
void setup() {
lcd.begin (16,2); 
lcd.init();
lcd.backlight();
lcd.print("Button presses:");
pinMode(2, INPUT);
pinMode (switchPin, INPUT);
Serial.begin(9600);
}
 
void loop() {
	switchState = digitalRead(switchPin);
	Serial.println(switchState);
	buttonState = digitalRead(buttonPin);
	lcd.setCursor(0,1);
 
if ( buttonState == HIGH && oldButtonState == LOW && switchState == 0){ //This makes the numbers count up if the switch is in its zero position.
a++;
 lcd.setCursor(0,1); //Position of numbers on the screen.
 lcd.print(a);
 lcd.print(" "); //Clears the numbers so there is no space left to add a zero to make the numbers wrong.
 delay(200);
}
 
if ( buttonState == HIGH && oldButtonState == LOW && switchState == 1){ //This makes the numbers count down if the switch is in its one position.
a--;
 lcd.setCursor(0,1);
 lcd.print(a);
 lcd.print(" "); //Clears the numbers so there is no space left to add a zero to make the numbers wrong.
 delay(200);
}
 
 oldButtonState = buttonState; 
}