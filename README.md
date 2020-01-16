# intermediate_arduino
2019-2020 // Engineering 3 //All pictures are from [Tim Wiessman's github page](https://github.com/tweissm35) 



## TABLE OF CONTENTS
* [TABLE OF CONTENTS](#TABLE-OF-CONTENTS)
* [LED FADE](#LED-FADE)
* [LED BLINK](#LED-BLINK)
* [SERVO](#SERVO)
* [LCD PRESSES](#LCD-PRESSES)
* [PHOTOINTERRUPTER](#PHOTOINTERRUPTER)
* [DISTANCE SENSOR](#DISTANCE-SENSOR)
* [CLASSES, OBJECTS, AND MODULES](#CLASSES-OBJECTS-AND-MODULES)
* [HELLO VS CODE](#HELLO-VS-CODE)
* [FANCY LED](#FANCY-LED)


  


 ## LED FADE
 
Using CirciutPython I developed code to make an led light slowly get brighter and then to slowly face back until it is very dim. To do this I had to utilize PWM, pulse width modification, and dutycycle which control the amount of energy/pulse/voltage that is sent to the the LED making it fade.  
### Wiring
picture or fritzing image goes here
<img src="https://github.com/tweissm35/CircuitPython/blob/master/media/fade.jpg" width="350">
Fritzing from [Tim Wiessman's github page](https://github.com/tweissm35/CircuitPython) 


### Code
link to code here, or copy your code in,  look at conrad's github page (cheins48)
 
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
 

## Assignment Name
Description goes here:

### Wiring
picture or fritzing image goes here

### Code
link to code here, or copy your code in,  look at conrad's github page (cheins48)

### Lessons Learned
Put your reflection here



## Assignment Name
Description goes here:

### Wiring
picture or fritzing image goes here

### Code
link to code here, or copy your code in,  look at conrad's github page (cheins48)

### Lessons Learned
Put your reflection here



## Assignment Name
Description goes here:

### Wiring
picture or fritzing image goes here

### Code
link to code here, or copy your code in,  look at conrad's github page (cheins48)

### Lessons Learned
Put your reflection here



## Assignment Name
Description goes here:

### Wiring
picture or fritzing image goes here

### Code
link to code here, or copy your code in,  look at conrad's github page (cheins48)

### Lessons Learned
Put your reflection here
