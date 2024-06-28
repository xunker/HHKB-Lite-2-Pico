# TODO List for HHKB Lite 2 Pico

Numbers indicate relative importance

## June 2024 Rev

### Figure out why GP9 columns are not working 0️⃣

While testing, found that 5 column pins are not responding. After disabling some
optional features in QMK, I whittled that down to one pin not working, GP9.

#### Not bad hardware

It's not a case of those GPIOs being damaged. A simple Arduino prog to verifies
each of the above pins is working:

```c
#define TEST_PIN_COUNT 5
int testPins[TEST_PIN_COUNT] = { D19, D18, D17, D13, D9 };
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  for (uint8_t i = 0; i < TEST_PIN_COUNT; i++) {
    pinMode(testPins[i], INPUT_PULLUP);
  }
}

bool lightLed = false;
void loop() {
  for (uint8_t i = 0; i < TEST_PIN_COUNT; i++) {
    if (lightLed)
      break;
    if (!digitalRead(testPins[i]))
      lightLed = true;
  }

  digitalWrite(LED_BUILTIN, lightLed);

  lightLed = false;

  delay(50);
}
```

#### Bad config

Even swapping GP9 for another pin line GP22 doesn't make that line come alive,
so is my config bad?

I should try swapping GP8-GP9 and see if 9 starts to work and 8 stops.

Update: swapping GP8 and GP9 did what I expected; now GP8 doesn't respond. So it
absolutely a config issue.

Update Update: Looking at my keyboard.json, I see that there is only ONE entry
in the layout matrix for column 1 (GP9). Is this the FN key?

Yes, it IS the FN key. It's dedicated!

### Move Right-Side Mount Hole 1️⃣

The mounting hole on the right side (nearest the Pi DEBUG connector) is too low
for my keyboard, making the board mount at an angle inside the case.

I don't know if this is an error in thirteen37's original design, or if their
keyboard has the hole in a slightly different place (since their stock
controller is also a little different from mine).

At first I thought it needed to be moved along the vertical/Y-axis, but when I
look at a printed overlay I think it needs to move toward the centre of the pcb.

I'm not sure, so another (probably more extensible idea) is to make that hole
quite a bit bigger, so it has a lot of adjustment play and can be cinched down
using a large nylon fender washer.

### Fix alignment and spacing of membrane connectors 1️⃣

On thirteen37's original design, J_Col1 (14-pin membrane connector) needs to be
moved about 2.5mm to the right (away from J_Row1). Or maybe they both need to
come to the centre by 1.25mm, not sure.

The miss-alignment is causing wrinkles in the membrane which in turn are causing
phantom key presses.

Like the mounting hole issue, I don't know if this is an issue with thirteen37's
design, or if they're keyboard uses a different membrane. I can't think of a
way to have adjustable spacing without resorting to multiple PCBs, so I'm going
to assume it was an honest mistake and try to make it conform to my keyboard.

### Change pinout of USB3 and USB Uplink to match original USB cable 2️⃣

Need to change the pinout of the 3rd USB connector (J4) and USB Uplink connector
(J2) to match the original USB KN connector. Simple swap of VBUS and GND is all
that is needed.

### xtal traces on FE1.1s do not need to be length-matched 2️⃣

The traces are not a true differential pair, they're simply in-out, so that
means they don't need to have the same length. That means I can mount the xtal
squarely instead of at an angle (and maybe on the top copper instead of bottom).

It also means I could use a different package than 3525, but I've already bought
a dozen in this package...

### Different Parts for the membrane connection? 2️⃣

This is a tough call.

The original Teensy design calls for the Molex Easy-On connector. This connector
specifies a sheet thickness of 0.3mm, but the membrane on my HHKB-Lite-2 is
0.42mm thick.

I can get the connector to make contact, but the retaining clip won't lock and
I've had to widen the slot on the retaining clip so that I can remove the
membrane (or else it gets stuck).

Clones of the original connectors (probably TE 84534-8) are available, but the
orientation of the pins is opposite so redesigning the board to use them would
make it so the Molex Easy-On can't be used.

### Add grounding-strap pad 3️⃣

Missing a pad to connect the grounding strap for the metal plate. This can be
connected to any GND spot on the PCB, but a specific pad would be nice.

### Move extra GPIO connection to bottom of board 3️⃣

Move the pins that are in JP6 to JP1, so all are accessible out the back of the
case. That way they could be used as jumper blocks, too, if needed.
It'll be a tight fit for the opening, so maybe using 2.0m headers instead of
2.54mm is in order?

It will need to be a 2x05 block, though only 9 pins are needed so could have
the remaining pin as an N/C or key pin? Have it line up with VBUS so if you use
a 2x05 connector and plug it in upside down, VBUS will remain disconnected and
not ruin anything.

#### Rework which pins are "bonus" 3️⃣

To avoid walking across the whole board, consider shifting the column pins to
the right by 4 so the "bonus" pins are GP8-GP11. That way they are a
straight-shot to the connector.
