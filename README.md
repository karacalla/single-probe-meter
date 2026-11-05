# Single probe meter experiment

**Goal:** Calculate Voltage and Current of a voltage divider setup with only one Analog pin.

### Setup:
![schematic](circuit.svg)
- 1 Arduino UNO R4 WiFi (equivalent OK)
- 1 $560 \Omega$ resistor (code is modular)
- 1 $1k \Omega$ resistor (code is modular)
- jumper wires
- breadboard

#### Functions
`float voltage(int reading){}`: returns current voltage (takes reading, multiplies it by `5` for the 5V and by `1023` for the [10-bit ADC](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/)).
`float current(float U, float R)`: returns current in milliamps `mA`.


### Physical interpretation
In this setup, I had to recreate a multimeter's function with only one Analog pin. 

![pont diviseur de tension](Impedance_voltage_divider.svg.webp)
and $V_{out} = I \cdot Z_{2}$$.
Source: [Wikipedia](https://en.wikipedia.org/wiki/Voltage_divider)
$V_{in}$: the voltage coming from the Arduino board, $5V$.
$V_{out}$: `pin_voltage`, what our A0 pin reads. 
$Z_{1}$: `R1`, the $1k \Omega$ resistor.
$Z_{2}$: `R2`, the $560 \Omega$ resistor.
$I$: `pin_current` the current we're looking to calculate.
We also know that $I = \frac{V_{in}}{Z_{1} + Z_{2}}$, So in theory, $I_{theo}= \frac{5}{1000+560} = 0,0032 = 3,2mA$;
And  $V_{out_{theo}} = I_{theo} \cdot Z_{2} = 0.0032*560 = 1,79V$ (hence the code `pin_current = current(pin_voltage, R2)`).

#### experimentation
Serial Monitor: 
```
Voltage: 1.794 V, Current: 3.20
```
Confirmed!


