**IMPORTANT**: Current design has not been tested, and this readme has not be completely updated.

# Pi Pico SMD controller relacement for HHKB Lite 2

Based on the [Teensy 2.0 controller by thirteen37](https://github.com/thirteen37/HHKB-Lite-2-Teensy).

This is a QMK-compatible replacement controller for the [HHKB Lite
2](https://deskthority.net/wiki/HHKB_Lite), identified by model
numbers PD-KB200W/U or PD-KB200B/U.

This Lite version of the HHKB is a membrane keyboard and not exactly
popular compared to more expensive Professional versions that use
Topre switches. But the wiring is simple and is a good first project
for modding commercial keyboards.

This replacement uses a [Raspberry Pi Pico or Pico W](https://www.raspberrypi.com/products/raspberry-pi-pico/), which is cheap, has
plenty of pins, and is supported by works well with the [QMK
firmware](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md). Note, this
board uses the Pico as an SMD component (for space considerations) and needs a Pico that
*does not* have headers pre-soldered.

If you don't mind losing the built-in USB ports, then only 4 parts are required: this PCB, two
FFC connectors, and a Pi Pico. Optionally, you can add the necessary components to integrate a USB
2.0 hub and keep using the built in USB ports -- with the added benefit that they are now USB 2.0!

## Steps

1. Acquire/fabricate the PCB.
2. Get the parts
3. Disassemble the keyboard.
4. Solder the components on to the board. Take care to leave enough
   room for the USB cable.
5. Reconnect the flex cables and insulate the backplate.
6. Get the USB cable you will be using and insert it through the keyboard connector hole and plug it in to the Pi Pico.
7. Flash your firmware and test your keyboard.
8. Reassemble the shell.

### PCB fabrication

The fabrication-ready files are in `plots/`. Just send them to your
preferred fab. It is a pretty standard 1.6mm PCB with conservative via
and track parameters that just about any shop can handle.

> TODO: Change this to pi pico
>
> You can also [order the PCBs through PCBway](https://www.pcbway.com/project/shareproject/HHKB_Lite_2___Teensy_2_0_controller.html). With
their new user discount, you would only have to pay shipping.

### Parts

#### Minimum Parts

* 1 [Pi Pico or Pico W](https://www.raspberrypi.com/products/raspberry-pi-pico/) (WITHOUT headers)
* 1 Molex Easy-On 14-pin 1.25mm pitch FFC connector 39-53-2145
* 1 Molex Easy-On 8-pin 1.25mm pitch FFC connector 39-53-2085
* MicroUSB or USB-C cable for the Pi Pico, depending on which model (or clone) you have.

#### Optional Extras

To re-enable the built-in USB ports, add:
* FE1.1s IC, revision B or later, SSOP package
* 12mhz crystal, 16-20pf, 4-pin 3225 package
* (2x) 10uF capacitors, 1206 package
* 2.7K-10k resistor, 805 package
* A MicroUSB to USB-A cable you don't mind cutting apart

For USB Status LEDs add:
* (3x) 220-470 ohm resistors, 805 package
* (5x) LED (any colour), 805 package

### Bonus connectors

There are several extra breakouts you can use for your own fun:

* External reset/power connector (J1), needs:
   - 2.7K-10k resistor, 805 package
   - 2.54mm header, through-hole, 1x3 positions
* 3rd, hidden USB 2.0 port (J5, back of board)
   - Needs 2.54mm header, through-hole (but soldered as SMD), 4 positions
* Breakout of the remaining unused Pi Pico Pins (J6)
   - Needs 2.54mm header, through-hole, 2x4 positions
   - Provides access to GP22, GP25, GP27, GP28, VBUS, and 3V3

### Disassembly

The keyboard is held together by a few screws. Don't forget the screw
hiding under the label. When the shell is open, there are also further
one screw holding down the metal backplate and one screw each for
the PCBa.

![Screw locations](images/screws.jpg)

The USB cable can be removed from the shell but does not need to be
detached from the PCB. We will be using another USB cable instead.

The flex cables can be eased out gently. There is no latching
mechanism.

### Modify the USB cable

> TODO: Change this to pi pico
>
>The Mini-USB plug that goes to the Teensy needs to be shaved down to save about 1mm of thickness.

![Shaved USB](images/shaved_usb.jpg)

### Soldering the board

> TODO: Change this to pi pico
> My recommended order is:
> 1. Headers for Teensy on to the board
> 2. Molex connectors
> 3. Teensy

The Molex connectors are oriented in opposite directions, with pin 1
(the edge with a little notch) of each connector facing each
other. This is important because the flex cables and connectors are
single sided.

> TODO: Change this to pi pico
> Note that the Teensy should be mounted upside down, on the same side
> as the connectors. This is to save a couple of millimeters of space
> from the stacked height of the connectors. You may have to trim down
> the header pins after you've soldered on the Teensy. The USB cable
> should still be able to fit.
>
> ![Teensy upside down](images/teensy_mounting.jpg)
>
> ![Teensy clearance](images/teensy_clearance.jpg)

### Connect flex cables and insulate the backplate

Connect the flex cables to the PCB. Note the orientation.

The metal backplate should be insulated, at least around the area of
the PCB, to minimize the risk of it shorting the board. I use a few
strips of electrical insulation tape here.

![Insulated backplate](images/insulation.jpg)

### Flash the firmware and test

> Plug in the USB cable to your computer and flash the firmware. There's
> a copy of the firmware with the default layout at
> `firmware/hhkblite2.hex`.
>
> Programming is done using [Teensy
> Loader](https://www.pjrc.com/teensy/loader.html). Since the Teensy is
> mounted upside down and the reset button no longer exposed, you can
> short the `RST` and `GND` pins instead.

After a successful initial flash, you can use the `reset` key to enter
flashing mode instead of having to open the keyboard. On my default
configuration, the `reset` key is `Fn` + `Esc`.

After flashing, you should be able to type something. It's easiest to
just put the silicone membrane over the traces and try typing
something.

### Reassembly

The PCB here only uses one of the original PCB mounting screws. Route
the USB cable around the internal strain relief. Don't forget the
screw for the backplate.

You're done!

## PCB details

This is a [KiCad](https://kicad.org/) project, but you can find
the generated fabrication files in `plots/`. Just send them to your
preferred PCB factory.

The schematics are fairly straightforward, with 8 row pins and 14
column pins:

> TODO: Change this to pi pico
> ![Schematic](images/schematic.png)

The PCB layout is likewise simple:

> TODO: Change this to pi pico
> ![PCB](images/pcb.png)


## Firmware

The configuration in `firmware/` can be uploaded to [Keyboard Firmware
Builder](https://kbfirmware.com/) to generate firmware for the
standard US QWERTY layout.

![QWERTY keymap](images/keymap.png)

There will be a warning "Not every key has a unique position in the
wiring matrix". This can be ignored and it is due to both `Fn` keys
being wired exactly the same. You should take note of this when
designing your own layouts: it is not possible to assign different
keycodes to each `Fn` key as they are electrically indistinguishable.

The wiring matrix is a bit of a mess, as is typical of membrane
keyboards that do not have diodes to prevent ghosting: the matrix is
designed to minimize ghosting from common key combinations but will
never completely eliminate it.

> TODO: Change this to pi pico
> ![Wiring matrix](images/wiring.png)
>
> The pin assignments are:
>
> | Matrix    | Pin |
> |-----------|-----|
> | *Rows*    |     |
> | 0         | F5  |
> | 1         | F4  |
> | 2         | F1  |
> | 3         | F0  |
> | 4         | B0  |
> | 5         | B1  |
> | 6         | B2  |
> | 7         | B3  |
> | *Columns* |     |
> | 0         | F6  |
> | 1         | F7  |
> | 2         | B6  |
> | 3         | B5  |
> | 4         | B4  |
> | 5         | D7  |
> | 6         | D6  |
> | 7         | D4  |
> | 8         | D5  |
> | 9         | C7  |
> | 10        | C6  |
> | 11        | D3  |
> | 12        | D2  |
> | 13        | D1  |
>

## Credit

[Original Teensy project by thirteen37](https://github.com/thirteen37/HHKB-Lite-2-Teensy).

Pi Pico footprint is [konkers/KiCad-RP-Pico](https://github.com/konkers/).