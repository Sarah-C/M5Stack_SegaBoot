# M5Stack_SegaBoot
Recreates a MegaDrive boot screen.

I was inspired to make this after seeing the M5Stack-Core-Grey factory test where the logo fades up, and the little jingle plays.
Then when I saw M5Stack was involved in an emulator for Sonic the Hedgehog, I knew I just had to write a little boot intro for everyone! https://www.facebook.com/M5Stack/posts/2769865619915835:0


It takes only 203Kb for this classic effect, so even on a small 4MB flash version of the M5Stack core, that leaves 95% free!


 - The logo was a PNG converted to raw RBG565 via another online service, imageToCPP. https://javl.github.io/image2cpp/

 - I then used my online "Arduino PROGMEM file converter / creator V.1.0" to turn the Audacity 8 unsigned bit, 20,000 samples/s audio file into a header file for the Arduino IDE. https://codepen.io/SarahC/pen/dyWZLBG

The audio sings "SEEEEEEEEEEEEEEE - GAAAAAAAAAAAAAAA!", while the modern Sega logo fades up and then out.

![image](https://user-images.githubusercontent.com/1586332/126994927-d8b4fb86-3673-40d6-b617-c31d8efc8877.png)
