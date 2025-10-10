# SN54HC595 Shift Register

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

## PIN CONNECTION  
                                              -----| |-----  
                                          Qb(1)  |           | Vcc  
                                          Qc(2)  |           | Qa(15)   
                                          Qd(3)  |           | SI(14)  
                                          Qe(4)  |           | /G(13)  
                                          Qf(5)  |           | RCK(12)  
                                          Qg(6)  |           | SCK(11)  
                                          Qh(7)  |           | /SCLR(10)  
                                          GND(8) |           | Qh'(9)  
                                                 -------------  
