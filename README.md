I didn't have a KB2040 handy that was used in this guide: https://learn.adafruit.com/fisher-price-usb-controller?view=all so decided to take a different approach.
Daemonbite Arcade Encoder customized for use with the Fisher Price Controller using an Arduino Pro Micro in DirectInput mode.  Works great with the MiSTer FPGA. 
Source: https://github.com/MickGyver/DaemonBite-Arcade-Encoder/

# Fisher Price Controller button to Pro Micro map:

* X - B1
* Circle - B2
* Square - B3
* Triangle - B4
* Blue Push Knob - B5

![wiring](https://github.com/svirant/FisherPriceController_Arduino/assets/62872229/927fd66c-30b1-4238-81b8-79b671a74bb7)

![guts](https://github.com/svirant/FisherPriceController_Arduino/assets/62872229/fc62230c-be8a-49b3-b64d-884a8ae3294b)

# Disable Speaker mod for revision without rear switch
This mod removes the switch's ability to choose sound "modes."  Red wire connection for permanant "play" sounds or omitted for permanent "learn" sounds. I personally prefer the former.
## Switch Positions
* LEFT - powered off
* MIDDLE - speaker off
* RIGHT - speaker on

## Involves 3 trace cuts and 3 wires as shown
![IMG_6653](https://github.com/svirant/FisherPriceController_Arduino/assets/62872229/d606d9ab-5425-4f3c-970b-c47137ebab69)
