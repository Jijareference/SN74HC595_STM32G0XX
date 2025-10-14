# SN74HC595 Shift Register

This library is used to connect and expand the microcontroller's functionality to add 8 Digital Outputs (DO). There are 3 functional inputs and 2 power supply inputs:

## Functional Inputs
1. **SI (PIN 14)** - Serial Data Input  
2. **SCK (PIN 11)** - Shift Register Clock Input  
3. **RCK (PIN 12)** - Storage Register Clock Input

## Additional Functional Inputs
1. **SCLR (PIN 10)** - Shift Register Clear Input (*this input is inverted*)  
2. **G (PIN 13)** - Output Enable Input (*this input is inverted*)  

## Power Supply Inputs  
1. **VCC (PIN 16)** - Positive Supply Voltage  
2. **GND (PIN 8)** - Ground (0V)  

## Pin Connetion
                                                 -----| |-----  
                                          Qb(1)  |           | Vcc(16)   
                                          Qc(2)  |           | Qa(15)   
                                          Qd(3)  |           | SI(14)  
                                          Qe(4)  |           | /G(13)  
                                          Qf(5)  |           | RCK(12)  
                                          Qg(6)  |           | SCK(11)  
                                          Qh(7)  |           | /SCLR(10)  
                                          GND(8) |           | Qh'(9)  
                                                 -------------   
## Stages of work(without Additional Functional Inputs)  
1. The first data bit is transmited to the buffer in the 14 pin.
2. Enable Pin 11.
3. Repeat 8 times to transfer the data byte
4. Eneable pin 12. At this stage DO at SN54HC595 start working
***
## Functions  
1. void TN74SetParam(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t type)  
  This function use to adress your physical Pin with Lib.(Use HAL functions)    
2. void WriteByte(uint16_t Byte)  
   This function is used to write a byte into the chip buffer and send it to DO
---
## Working principle  
Each digital output has its own bit in a byte. For example, if you need to control the second pin, you would send **0b00000010**.  
This library contains 8 constants for convenient control (PIN1 - PIN8).  
## Warning
This library contains a delay and is not recommended for use in production projects. Non_delay logic will be added in future versions.
