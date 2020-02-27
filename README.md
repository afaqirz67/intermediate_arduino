# intermediate_arduino
2019-2020 | Engineering 2 | All pictures are from [Tim Wiessman's github page](https://github.com/tweissm35) 



## TABLE OF CONTENTS
* [TABLE OF CONTENTS](#TABLE-OF-CONTENTS)
* [LED FADE](#LED-FADE)
* [HELLO LCD](#HELLO-LCD)
* [LCD BACKPACK](#LCD-Backpack)
* [PHOTO INTERRUPTER](#Photointrrupter)



 ## LED FADE
Using CirciutPython I developed code to make an led light slowly get brighter and then to slowly face back until it is very dim. To do this I had to utilize PWM, pulse width modification, and dutycycle which control the amount of energy/pulse/voltage that is sent to the the LED making it fade.  
### Wiring
<img src="https://github.com/tweissm35/CircuitPython/blob/master/media/fade.jpg" width="350">
Fritzing from [Tim Wiessman's github page](https://github.com/tweissm35) 


### Code
 
```C
//LED FADE
//Asadullah
//This code will change the brightness of the led.

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.print("-");
}

// the loop routine runs over and over again forever:
void loop() {
  
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  
  Serial.println(brightness);
}
```

### Lessons Learned
I learned the basics of Circuitpython and its differences from arduino coding. Specifically, I learned how to import libraries into Circuitpython by writing at the top of your code "import *library*". I also gained an understanding of dutycycle, the part of the code that controls the amount of time the led is ON compared to the time it taks to complete the cycle. This caused the LED to fade. [More info for PWM](https://learn.adafruit.com/circuitpython-essentials/circuitpython-pwm)
 




## Hello LCD
I used [this](https://learn.adafruit.com/character-lcds/wiring-a-character-lcd) for doing Hello LCD assignment. We were supposed to wire up an LCD Screen and Code it to print "Hello" on it's screen.

### Wiring
<img src=https://github.com/jbrown56/Intermediate-Arduino/blob/master/hello_LCD/hello_lcd_fritzing.jpeg>

### Code
```C
//Hello LCD
//Asadullah
//Set up a LCD Screen and Print "HELLO" on it's screen.

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
```

### Lessons Learned
I learned that there are different libraries are there to provide extra functionality and you have to find the right one to make it work. 



## LCD Backpack
This assignment was pretty much the same as the Hello LCD, but circuit and wiring was much clear and suficiente than Hello LCD. We used more libraries to give more functionality. It was supposed to count on numbers while the button is pressed.
## Wiring
<img src="https://github.com/tweissm35/CircuitPython/blob/master/media/lcdcount.jpg">
### Code

```C
//LCD Backpack
//Asadullah
//Count when the button is pressed.

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
```

### Lessons Learned
I learned the shortcut way of wiring an LCD screen by doing this assignment.

# Photointerrupter 

In this assignment we were supposed to wire up a circuit that's supposed to turn on an LED when there was an object in between two legs of the Photointerrupter. I used [this](https://github.com/zdeguzm53/CircuitPython) github account as a guid for doing this assignment.

## Circuit
<img src="https://github.com/zdeguzm53/CircuitPython/blob/master/pictures/photointerrupter_pic.PNG"> 

### Code
```C 
// Photointerrupter 
//Asadullah
//This code will turn on an LED when something is in between the legs of photo interrupter.

const int GatePin2 = 0; //setup integers and declare
const int GatePin3 = 1;
const int LEDPin = 9;
int counter = 0;
int Blocked;
 
 
void setup()
{
Serial.begin(9600);
pinMode(LEDPin, OUTPUT);
attachInterrupt(GatePin2, LEDon, RISING); //tells the light to turn on when the photoresistor is bloacked
attachInterrupt(GatePin3, LEDoff, FALLING); //tells the light to turn off when the photoresistor isn't blocked
}
 
void loop(){
 
}
 
 
 void LEDon()
{
  digitalWrite(LEDPin, HIGH); //allows the LED to turn on
  counter ++; //increases the counter by one
 
 
  Serial.println("");  
  Serial.print("LEDon Interruptions:");
  Serial.print(counter);
 
}
void LEDoff()
{
  digitalWrite(LEDPin, LOW); //allows for the LED to be turned off
}
```

### Lessons Learned
This assignment wasn't that hard, but I was a little trickey. At first, I didn't quiet get what the instructions were supposed to mean. I struggled with the wirring a little too, but after some research I got what I had to do and recognized what my mistake was. I had the negative wire of the Photointerrupter and the positive wire of the photointerrupter wired in wrong order. That was the only part I run into a problem. After I switched the wires the circut was working fine and there wasn't any problem with the code. 
```
