# intermediate_arduino
2019-2020 // Engineering 3 //All pictures are from [Tim Wiessman's github page](https://github.com/tweissm35) 



## TABLE OF CONTENTS
* [TABLE OF CONTENTS](#TABLE-OF-CONTENTS)
* [LED FADE](#LED-FADE)
* [HELLO LCD](#HELLO-LCD)
* [A LITTLE PRACTICE](#A-Little-Practice)
* [LCD BACKPACK](#LCD-Backpack)
* [SWEEPS AND LOFTS](#Sweeps-and-Lofts)
* [HELLO FUNCTIONS](#Hello-Functions)
* [NEW PING](#New-Ping)



 ## LED FADE
Using CirciutPython I developed code to make an led light slowly get brighter and then to slowly face back until it is very dim. To do this I had to utilize PWM, pulse width modification, and dutycycle which control the amount of energy/pulse/voltage that is sent to the the LED making it fade.  
### Wiring
<img src="https://github.com/tweissm35/CircuitPython/blob/master/media/fade.jpg" width="350">
Fritzing from [Tim Wiessman's github page] 


### Code
 
```C
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
 
My LED fade code [link](https://github.com/lwielar29/CircutPython/blob/master/fade.py)





## Hello LCD
I used this tutorial for doing this assignment(https://learn.adafruit.com/character-lcds/wiring-a-character-lcd)
### Wiring
<img src=https://github.com/jbrown56/Intermediate-Arduino/blob/master/hello_LCD/hello_lcd_fritzing.jpeg>

### Code
```C
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




## A Little Practice
In this assignment we were supposed to follow a tutorial provided by SolidWorks itself and have to different parts done. One part which included an assembly and a part and the second one just included just one part.
### Wiring
picture or fritzing image goes here

### Lessons Learned
These were the first assignments of the year so kind of refreshed everything in my memorry and the new skill I learned by doing this assignment was how to use Linear Patern. It basically allows you to copy your drawn sketch multiple times in a specific pattern.  





##LCD Backpack
This assignment was pretty much the same as the Hello LCD, but circuit and wiring was much clear and suficiente than Hello LCD. We used more libraries to give more functionality. 
## Wiring
<img src="https://github.com/tweissm35/CircuitPython/blob/master/media/lcdcount.jpg">
### Code

```C
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
The lesson I learned from this assignment was shortcut way of wiring an LCD screen.





# Sweeps and Lofts
This assignment includes using lofted cuts, revolves and sweeps. We were to sketch a hammer head and we had the choice to make a handle for it or not. Same as the last assignment we used a tutorial that's in SolidWorks.
## Picture
picture or fritzing image goes here


### Lessons Learned
I learned how to use lofted cuts, revolves and sweepes by doing this assignment. I had trouble with the Flex, but after playing with it for a while I figured out how it works.  

# Hello Functions
Description...


## Fritzing 



### Lessons Learned






# New Ping
Description


## Picture




### Lessons Learned





