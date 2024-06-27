# TODO List for HHKB Lite 2 Pico

Numbers indicate relative importance

## June 2024 Rev

### Figure out why sole columns are not working 0️⃣

While testing, found that 5 column pins are not responding. I don't know if it
is a configuration issue, or if I damaged the GPIO pins while cleaning flux off
the PCB with an electric toothbrush.

It's not an issue with the connectors, as I tried bridging the Pi's GPIO pads
directly with a test lead.

It might be that there are alternate modes enabled on those pins that are
interfering with QMK, but seeing as how there are adjacent pins with similar
functions which work, I don't think that's the case.

#### Effected pins

* `GP19` (SPI0 TX / I2C1 SCL)
* `GP18` (SPI0 SCK / I2C1 SDA)
* `GP17` (SPI0 CSn / I2C0 SCL / UART0 RX)
* `GP13` (SPI1 CSn / I2C0 SCL / UART0 RX)
* `GP9` (SPI1 CSn / I2C0 SCL / UART1 RX)

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

### Move Right-Side Mount Hole 1️⃣

The mounting hole on the right side (nearest the Pi DEBUG connector) is too low
for my keyboard, making the board mount at an angle inside the case.

I don't know if this is an error in thirteen37's original design, or if their
keyboard has the hole in a slightly different place (since their stock
controller is also a little different from mine).

A maintainable fix is to make the hole an ellipse (along the vertical/Y-axis)
so that it can be used on any case. A 2:1 ratio is probably a good start

### Fix alignment and spacing of membrane connectors 1️⃣

On thirteen37's original design, J_Col1 (14-pin membrane connector) needs to be
moved about 2.5mm to the right (away from J_Row1).

The miss-alignment is causing wrinkes in the membrane which in turn are causing
phantom key presses.

It looks like the position of J_Row1 is correct, relative to the mounting holes.

Like the mounting hole issue, I don't know if this is an issue with thirteen37's
design, or if they're keyboard uses a different membrane. I can't think of a
way to have adjustable spacing without resorting to multiple PCBs, so I'm going
to assume it was an honest mistake and try to make it conform to my keyboard.

### Change pinout of USB3 and USB Uplink to match original USB cable 2️⃣

Need to change the pinout of the 3rd USB connector (J4) and USB Uplink connector
(J2) to match the original USB KN connector. Simple swap of VBUS and GND is all
that is needed.

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
