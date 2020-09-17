# Doorman Animatronic Project with Arduino Nano
<img src="https://github.com/rickymedrano/Doorman/blob/master/DoormanGIF.gif" width="265" height="408" />

I decided to remix the other Doorman projects on Thingiverse as they all seemed to have some sort of issue and/or instructions weren't very clear. I was able to take a combination of 3D models, code, and instructions from the other 3 Doorman projects into my own Doorman project I know is working. 
### Hardware:
-[Arduino Nano](https://www.amazon.com/ARDUINO-A000005-DEV-ATMEGA328-NANO/dp/B01873ITV8/ref=sr_1_9?keywords=arduino+nano&qid=1558018417&s=electronics&sr=1-9)

-[Arduino Nano Sensor Shield](https://www.amazon.com/gp/product/B07KCVJ6RR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)

-[5x SG90 Servos](https://www.amazon.com/SunFounder-Digital-Helicopter-Airplane-Controls/dp/B01M5LIKLQ/ref=sr_1_3?keywords=servo+sg90&qid=1558018479&s=electronics&sr=1-3)

-[Mini PIR Sensor](https://www.amazon.com/gp/product/B07FGG87JM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)

-[5V 2.5A Power Supply](https://www.amazon.com/Nexlux-Adapter-100-240V-Transformer-Modules/dp/B07CWVFGNN/ref=sr_1_6?keywords=12v+power+supply+3a&qid=1558032031&s=gateway&sr=8-6)

-[LM2596 Buck Converter](https://www.amazon.com/gp/product/B06XRN7NFQ/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)

-[Female barrel jack](https://www.amazon.com/Female-Barrel-Connector-Cameras-LED/dp/B01M0P34E8/ref=sr_1_9?keywords=barrel+jack+female&qid=1558113436&s=gateway&sr=8-9)

### Instructions
-Print the eye_holder and top_and_back at high infill. Also, the eye holder center’s servo seat needed to be trimmed a bit to accommodate the servo’s wiring. See pictures for reference.

-Print the rest of the parts. Color the eyes. The inner eyeballs and eye joints needed to be sanded down and gotten as smooth as possible. 

-Solder the barrel jack to the buck converter. Solder your other wires to go to your expansion board. This would also be a good time to use a voltmeter and a screw driver on the potentiometer to have your buck converter output 5V. Watch this video to learn how youtube.com/watch?v=bK-yif8qqsc

-Plug the Nano into the expansion board. Use only 2 screws on one side of the expansion board to secure it to the Nano_expansion_support_3. I burnt out an expansion board due to a trace being too close to a screw hole and it shorting on the screw nut. See pictures of where to and not to put your screws with nuts. I used M3x8 self-tapping screws. Mount and screw in the buck converter to the appropriate spot as well.

-Before mounting the 5 SG90’s to the eye holder, its good practice to test them out individually first with a simple servo sketch in Arduino IDE to assure they are working properly. Next screw in the 2 eye socket joints to the eye holder. Use grease on the eye socket and inside the eyeballs to ensure smooth movement.

-I used a paperclip to control the Y axes of the eyes. I initially tried using paperclips for the X axes and eyelids but ran into constant problems. What worked best for me in the end was to use simple wire that wasn’t as taught as a paperclip. I also abandoned using both sides of the servo swing-arm to control the X axes. You’ll notice I cut off half the swing-arm and only controlled the X axes on the inside of the eye. This worked out best as there was too much rubbing with the single eye lids and the bracket supporting the eyes on each side.

-Use a file to slightly enlarge the hole on the forehead to accommodate the PIR sensor. Use glue to keep it secure. Double check your wiring on the PIR sensor before plugging it in, because you'll fry it if you wire it wrong.

-Use the wiring diagram to solder 2 LEDs with an appropriate resistor to use on PIN 13. Mount/glue the LEDs under the eye holes on the ledges. 

-Once you’ve tested that your code works, screw the eye_holder_main_mod_2 to the doorman_bars_v2. Note, there are no set holes to attach the bars to, so use self-tapping screws and align it up properly yourself. Now you can pop the eye holder in and out of the mask easily without needing to use screws. Place the nano_expansion_support_3 underneath it. I did not bother securing mine. 

-I used a similar code structure as the one in the original Doorman. I cleaned it up a lot, commented it, and made it more modular by putting certain eye movements into methods. Note that the code might not work for you depending on the initial positions of your servos, so be careful. Also, it won’t work for you if you use different pins than the ones in the wiring diagram. Everything in the wiring diagram is how I hooked mine up. 

##### Is the buck converter necessary?
Yes, trying to use the barrel jack on the expansion board won't provide enough amps for the 5 servos to work. I tried it and got issues with servos just not moving at all. Using the buck converter provides the necessary amount of amps for this project.

Seen here https://www.thingiverse.com/thing:3645735
