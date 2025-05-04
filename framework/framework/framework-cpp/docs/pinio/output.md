# Pinio - output

Handles general gpio output functions.

#### `IO activate_pin(volatile register uint8_t* portn, const uint8_t pin_offset)`

Turns on a pin.

#### `IO deactivate_pin(volatile register uint8_t* portn, const uint8_t pin_offset)`

Turns off a pin.

#### `IO flip_pin(volatile register uint8_t* portn, const uint8_t pin_offset)`

Flips a pin between 1 and 0. More efficient and consice than branching with
`activate_pin` and `deactivate_pin`.

#### `IO set_pin(volatile uint8_t* portn, const uint8_t pin_offset, uint8_t mode)`

Sets a pin to either 1 or 0. More efficient and concise than branching with `activate_pin` and `deactivate_pin`.
