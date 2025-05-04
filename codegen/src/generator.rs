enum Peripheral{
    GPIO(Gpio)
}

struct Gpio{
    mode: bool // 1 for output, 0 for input
}