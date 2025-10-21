#include <SN74HC595.h>

#include <string.h>

static GPIO_TypeDef* RCK_port;

static GPIO_TypeDef* SCK_port;

static GPIO_TypeDef* SI_port;

static uint16_t RCK_pin;

static uint16_t SCK_pin;

static uint16_t SI_pin;

void SN74SetParam(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t type){
 if (type == RCK) {
	 RCK_port = GPIOx;
	 RCK_pin = GPIO_Pin;
	 HAL_GPIO_WritePin(RCK_port, RCK_pin, GPIO_PIN_RESET);
 }
 else if (type == SI){
	 SI_port = GPIOx;
	 SI_pin = GPIO_Pin;
	 HAL_GPIO_WritePin(SI_port, SI_pin, GPIO_PIN_RESET);
 }
 else if (type == SCK){
	 SCK_port = GPIOx;
	 SCK_pin = GPIO_Pin;
	 HAL_GPIO_WritePin(SCK_port, SCK_pin, GPIO_PIN_RESET);
 }

}

static void delay_us(uint16_t us) {
    for(uint32_t i = 0; i < us; i++) {
        __NOP();
    }
}

void WriteByte(uint8_t Byte){
	HAL_GPIO_WritePin(RCK_port, RCK_pin, GPIO_PIN_RESET);
	for (int i = 0 ;i<8; i++){
		if (Byte & 0x80)
			HAL_GPIO_WritePin(SI_port, SI_pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(SI_port, SI_pin, GPIO_PIN_RESET);
		delay_us(DELAY);
		HAL_GPIO_WritePin(SCK_port, SCK_pin, GPIO_PIN_SET);
		delay_us(DELAY);
		HAL_GPIO_WritePin(SCK_port, SCK_pin, GPIO_PIN_RESET);
		Byte <<= 0x01;
	}
	HAL_GPIO_WritePin(RCK_port, RCK_pin, GPIO_PIN_SET);
}
