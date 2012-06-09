#Make A Kitchen Do A Thing

![Board layout and photo](http://dl.dropbox.com/u/126001/circuits/kitchen-layout_and_board.jpg)


##Description

This is an Arduino clone with handy connections for eight physical inputs and eight high(er) current outputs, a built-in [ULN2803](http://www.ti.com/lit/ds/symlink/uln2803a.pdf) darlington array, per-pin LEDs for easy programming, and selectable output voltage.  The project began as a way to add lights and stuff to my daughter's play kitchen, but turned into a more general-purpose board.

Inputs and outputs have 2.0mm [JST right-angle locking connectors](http://media.digikey.com/pdf/Data%20Sheets/JST%20PDFs/PH%20Series.pdf).  There are also pads to wire in whatever you'd like.

The files were created in the free edition of CadSoft Eagle.

The board makes heavy use of curved traces simply because I think they look neat.  Unfortunately, curved traces are a pain in the ass to work with or edit;   I will add a straight-traces version soon.

###Inputs
Four inputs are wired with two pins for switches for [digital input](http://arduino.cc/en/Reference/digitalRead).  They are "ON" when the signal pin is pulled LOW (connected to the ground pin.) Four inputs have three pins for [analog input](http://arduino.cc/en/Reference/analogRead), like a knob.  This makes it easy to attach a pot to the ground and 5V pins, with the center (wiper) pin moving between 0 and 5V.  Of course you can use them all for something else entirely.  Each input has an LED that indicates the current state of that switch or knob.

###Outputs
Devices connected to an output will see a voltage ( either 5V or VIN, *minus the drop across the transistor*: 1V to 1.5V depending on current) when the corresponding processor pin is set HIGH.  Each output can sink up to 500mA though the transistor, and I wouldn't sink more than 1500mA in total across all eight channels at any one time.  Six of the outputs are on [PWM pins](http://arduino.cc/en/Reference/analogWrite), the other two can only output [On/Off](http://arduino.cc/en/Reference/digitalWrite).  Each output has an LED that indicates it's current state.

###Power
Supply 9-24V DC into the barrel jack or directly onto the pads next to the barrel jack.  The Power LED will light when power is connected.
Output voltage can be selected with the three larger pads marked VIN, VOUT, and 5V in the center-right of the board.
Wiring the VOUT pad to the 5V pad will cause all output power to come through the 7805 voltage regulator, and therefore limits your total current consumption to 1A.
Wiring the VOUT pad to the VIN pad will set your outputs to VIN, bypassing the regulator and allowing you to drive higher voltage devices like relays and motors.  The board's internal circuitry will still use 5V, only the output is changed.

###Software
The arduino sketch "basic-kitchen.ino" has constants defined for the I/O pins and simply makes the outputs to reflect the inputs.  This could be a good starting point for your projects.
The six FT232 pins in the center of the board will connect with a standard FTDI-style serial breakout board for programming via USB, [like this one](http://www.sparkfun.com/products/9716).

###Extras
The Arduino firmware gives the ATMega328 a total of twenty I/O pins.  On this board, sixteen of those are used for the main I/O and two are used for the serial FT232 block.  The remaining two unused pins (digital 2 and 4) are broken out to pads on the left side of the board.

----

###Build Notes
* Add the small parts first.
* If you don't like the LEDs, you don't need to install them.   They're just to make programming easier.
* I like to use a chip socket for the processor, but I suggest you solder the ULN2803 directly to the board so that it can thermally couple with the exposed copper beneath.  If you're going to sink a lot of current, maybe dab a bit of heatsink compound under there?
* Large capacitors:  the NEGATIVE pin goes in the ROUND hole.  The positive can go in either square hole, depending on the size of the cap.

###rev 19
* Output connectors are wired with positive to the LEFT when you look at the board with outputs at the top.  This is actually backwards from what JST connectors usually do, so on pre-made connectors you will have BLACK = POSITIVE.  Whoops.
* The resistor network values aren't marked on the board, whoops.  4 of them are 1k, and the one right next to the processor is 10k.
* The voltage regulator section has markings for both 1000uf (solid line) and 100uf (dashed line) caps. If you're not going to pull a lot of current through the voltage regulator, you can use 100uf.  In BOTH cases, the NEGATIVE pin should go into the ROUND hole.  Whichever you choose, ignore the left over square pad.
* I goofed the silkscreen orientation markings for the LEDS, whoops.  The NEGATIVE/ANODE side with the SHORT pin should go into the ROUND pad.  The POSITIVE/CATHODE side with the LONG pin should go into the SQUARE hole.
Specifically: look at the board so you can read "Make a kitchen do a thing" and the outputs are at the top, inputs at the bottom.   All of the output LEDs should have their FLAT side to your LEFT.  The four input LEDs on the left (marked 12-15) should have their FLAT side to your RIGHT.  The other four input LEDS (marked A2-A5) should have their FLAT side to your LEFT.    
* The holes for header pins (like the FT232 block) are really really tight with standard pins.  They'll fit, but you gotta work them gently/firmly back and forth.  Sorry about that.