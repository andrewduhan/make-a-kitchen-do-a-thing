#Make A Kitchen Do A Thing

![Board layout and photo](http://dl.dropbox.com/u/126001/circuits/kitchen-layout_and_board.jpg)


##Description

This is an Arduino clone with handy connections for 8 physical inputs and 8 high(er) current outputs, a built-in [ULN2803](http://www.ti.com/lit/ds/symlink/uln2803a.pdf) darlington array, and selectable output voltage.  The project began as a way to add lights and stuff to my daughter's play kitchen, but turned into a more general-purpose board.

Inputs and outputs have 2.0mm [JST right-angle locking connectors](http://media.digikey.com/pdf/Data%20Sheets/JST%20PDFs/PH%20Series.pdf).  There are also pads to wire in whatever you'd like.

##Inputs
Four inputs are wired for switches (digital) and four have three pins to connect to a pot/knob (analog).  Of course you can use them all for something else entirely.   Each input has an LED that indicates the current state of that switch or knob.

##Outputs
Devices connected to an output will see a voltage (either 5V or VIN) when the corresponding processor pin is set LOW. Each output can sink up to 500mA though the transistor, and I wouldn't sink more than 1500mA in total across all eight channels at any one time.  Six of the outputs are on PWM-capable channels.  Each output has an LED that indicates it's current state.

##Power
9-24V DC into the barrel jack or directly onto the pads next to the barrel jack.  The Power LED will light when power is connected.
Output voltage can be set in the center-right of the board.
Set to 5V by wiring the VOUT pad to the 5V pad - this will cause all output power to come through the 7805 voltage regulator, and therefore limits your total current consumption to 1A.
Wiring the VOUT pad to the VIN pad will set your outputs to VIN, bypassing the regulator and allowing you to drive higher voltage devices like relays and motors.  The board's internal circuitry will still use 5V, only the output is changed.

##Software
The arduino sketch "basic-kitchen.ino" causes the outputs to reflect the inputs.  This could be a good starting point for your projects.
The six FT232 pins in the center of the board will connect with a standard FTDI-style serial breakout board for programming via USB or such.

----

##Build Notes
* Add the small parts first.
* If you don't like the LEDs, you don't need to install them.   They're just to make programming easier.
* I like to use a chip socket for the processor, but I suggest you solder the ULN2803 directly to the board so that it can thermally couple with the exposed copper beneath.  If you're going to sink a lot of current, maybe dab a bit of heatsink compound under there?

##rev 19
* The resistor network values aren't marked on the board, whoops.  4 of them are 1k, and the one right next to the processor is 10k.
* The voltage regulator section has markings for both 1000uf (solid line) and 100uf (dashed line) caps. If you're not going to pull a lot of current through the voltage regulator, you can use 100uf.  In BOTH cases, the NEGATIVE pin should go into the ROUND hole.  Whichever you choose, ignore the left over square pad.
* I goofed the silkscreen orientation markings for the LEDS, whoops.  The NEGATIVE/ANODE side with the SHORT pin should go into the ROUND pad.  The POSITIVE/CATHODE side with the LONG pin should go into the SQUARE hole.
* The holes for header pins (like the FT232 block) are really really tight with standard pins.  They'll fit, but you gotta work them gently/firmly back and forth.  Sorry about that.