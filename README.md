# NYU-Tandon-Embedded-Challenge-2017
This project involves designing a controller to motivate a small vehicle through a meandering track without exiting track boundaries. Control of the vehicle is accomplished
remotely and exclusively by hand/arm gestures.

Vehicle Details: The vehicle consists of an aluminum chassis with three wheels (one front
center wheel, two rear wheels). Each rear wheel has a dedicated DC motor used to motivate
each wheel independently. Both DC motors are connected to a PWM motor driver unit that
controls the RPM of each motor independently based on a 2 PWM signals.

Microcontroller Requirements: This project requires 2 microcontrollers.
Microcontroller 1: Atmel328P : This microcontroller will interface the PWM motor
drivers on the vehicle and a wireless module to communicate to the other embedded
microcontroller. The Wireless module used is the Nordic NRF24L01+ module (SPI). This microprocessor is powered by a 4 bank AA battery pack that plugs directly into the microcontroller Vin.

Microcontroller 2: Atmel328P : This microcontroller will interface the sensor/s used to
wirelessly instruct the vehicle. It may be powered by a 9V battery or any other suitable power
supply. The same wireless module (NRF24L01+) is interfaced by this microcontroller to
communicate wirelessly to the vehicle. Any number of sensors may be used, however, only
sensors that communicate SPI, I2C, UART, or Analog signals may be used. Digital I/O (GPIO)
may not be used. 

Other restrictions:
- If at any time any part of the vehicle passes any track boundary (inside edge) a 3 second
penalty is be incurred (each time)
- The only preexisting library that can be used in the code is the NRF24 communications library. No high level abstraction is allowed. All other code must be in C
- Performance was ranked according to completion time. Our team achieved 34 seconds, the third shortest time out of 18 teams.
