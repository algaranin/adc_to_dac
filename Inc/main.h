/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_dma.h"

#include "stm32f4xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define MY_DEBUG           /* Enable debug pins */ 
//#define ALT_SOLUTION       /* Enable alternative solution without HAL and LL */

#ifdef ALT_SOLUTION
#define BITBAND_PERI_REF        0x40000000
#define BITBAND_PERI_BASE       0x42000000
#define BITBAND_PERI(a,b)       ((BITBAND_PERI_BASE +\
                                (a-BITBAND_PERI_REF)*32 + (b*4)))  // Convert PERI address
																
#define DMA2_LISR               DMA2_BASE
#define DMA2_LISR_TCIF0         *((volatile uint32_t*)(BITBAND_PERI(DMA2_LISR, 5)))

#define DMA2_LIFCR              (DMA2_BASE + 0x08)
#define DMA2_LIFCR_CTCIF0       *((volatile uint32_t*)(BITBAND_PERI(DMA2_LIFCR, 5)))  
								
#define DMA2_S0CR               (DMA2_BASE + 0x10) 
#define DMA2_S0CR_CT            *((volatile uint32_t*)(BITBAND_PERI(DMA2_S0CR, 19)))

#define DAC_DHR12R2             *((volatile uint16_t*)(DAC_BASE + 0x14))

#endif

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#ifndef ALT_SOLUTION
void AdcDmaTransferComplete_Callback(void);
#else
void AdcDmaTransferComplete_CallbackAlt(void);
#endif

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
