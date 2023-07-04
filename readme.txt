/**
  @mainpage adc_to_dac ADC conversion using DMA for data transfer and setting the average values on the DAC

  @verbatim
  ******************************************************************************
  * @file    adc_to_dac/readme.txt 
  * @author  Alexander Garanin
  * @brief   Description of the adc_to_dac project
  * @date    1.07.23
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 ag.
  * All rights reserved.
  *
  ******************************************************************************
   @endverbatim

@par Project Description

In this project, the system clock is 102.4MHz, APB2 = 6.4MHz and ADC clock = APB2/8. 
Since ADC1 clock is 800 kHz and sampling time is set to 28 cycles, the conversion 
time to 12bit data is 12 cycles so the total conversion time is (12+28)/0.8 = 50us(20 ksps).

ADC1 configured for continuous conversion of channel 1 is connected on GPIO pin PA0.
DAC1 channel2 is configured to connect DAC channel output on GPIO pin PA5. 
Each time an end of conversion occurs the DMA transfers, in double buffer mode, the
converted data from ADC1 DR register to the uhADCxConvertedValue variable.
At the end of the transfer a Transfer Complete interrupt is generated since it
is enabled and the callback function is called. 
The callback function calculates the average value over 1 ms (20 transfers * 50 us total conversion time) 
and is set it to the DAC, also calculates the average value over 1 second and sends it to the debug terminal.

@note Pins PG13, PG14 configured as outputs for debuging.

@par Keywords

Analog, ADC, Analog to Digital Converter, Regular Conversion, DMA, Continuous Conversion, DAC

@par Directory contents 

  - adc_to_dac/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - adc_to_dac/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - adc_to_dac/Inc/main.h                  Main program header file  
  - adc_to_dac/Src/stm32f4xx_it.c          Interrupt handlers
  - adc_to_dac/Src/main.c                  Main program
  - adc_to_dac/Src/stm32f4xx_hal_msp.c     HAL MSP module
  - adc_to_dac/Src/system_stm32f4xx.c      STM32F4xx system clock configuration file


@par Hardware and Software environment
 
  - This example runs on STM32F429xx devices.
    
  - This example has been tested with STMicroelectronics STM32F429I-Discovery
    boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your MDK Keil 
 - Rebuild all files and load your image into target memory
 - Run the project


 */
