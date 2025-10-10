#include "stm32g0xx_hal.h"

#define RCK 1

#define SI 2

#define SCK 3

#define ZERO 0b00000000

#define PIN1 0b00000001

#define PIN2 0b00000010

#define PIN3 0b00000100

#define PIN4 0b00001000

#define PIN5 0b00010000

#define PIN6 0b00100000

#define PIN7 0b01000000

#define PIN8 0b10000000

#define DELAY 2

void WriteByte(uint16_t Byte);

void TN74SetParam(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t type);
