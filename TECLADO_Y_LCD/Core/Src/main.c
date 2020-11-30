/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

enum states {STATE0, STATE1, STATE2, STATE3, STATE4} current_state; //, STATE5

char input;  // aqui va estar el dato que se presione

char a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
int i=0;
char ba,bb,bc,bd;
char cal[11]={'0','1','2','3','4','5','6','7','8','9','\0'};
char str[11];

//{"0","1","2","3","4","5","6","7","8","9","*","A","B",
//		"C","D","*","#"};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
char read_keypad(void);
void cursor (char*);
void pulsa(char*);
void error(char*);
void x(char*);
void lock_safe();
void unlock_safe();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  Lcd_PortType ports[] = {
      	D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
      };

      Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};

      Lcd_HandleTypeDef lcd;

      lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);

      Lcd_string(&lcd, "*Bienvenido*");

      Lcd_cursor(&lcd, 1,0);
      Lcd_string(&lcd, "Ingrese pin: ");

//      Lcd_cursor(&lcd, 1,5);
//     Lcd_int(&lcd,cursor);



      lock_safe(); // inicializa seguro
//
      current_state = STATE0; //inicializamos el estado
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
      while (1)
       {
         /* USER CODE END WHILE */
           input = read_keypad();
           if(input !='F'){
         	  switch(current_state){
     			case STATE0:
					if(i<4){
						switch(input){
							case '1':
							a1=1;
							cursor("1");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '2':
							a2=2;
							cursor("2");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '3':
							a3=3;
							cursor("3");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '4':
							a4=4;
							cursor("4");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '5':
							a5=5;
							cursor("5");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '6':
							a6=6;
							cursor("6");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '7':
							a7=7;
							cursor("7");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '8':
							a8=8;
							cursor("8");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '9':
							a9=9;
							cursor("9");
							current_state = STATE0;
							i=i+1;
							break;}
						switch(input){
							case '0':
							a0=0;
							cursor("0");
							current_state = STATE0;
							i=i+1;
							break;}
						}// if
					else{
						current_state = STATE0;
						error("");
					}
                break;
     			case STATE1:
					if(i<4){
						switch(input){
							case '1':
							a1=1;
							cursor("1");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '2':
							a2=2;
							cursor("2");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '3':
							a3=3;
							cursor("3");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '4':
							a4=4;
							cursor("4");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '5':
							a5=5;
							cursor("5");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '6':
							a6=6;
							cursor("6");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '7':
							a7=7;
							cursor("7");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '8':
							a8=8;
							cursor("8");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '9':
							a9=9;
							cursor("9");
							current_state = STATE1;
							i=i+1;
							break;}
						switch(input){
							case '0':
							a0=0;
							cursor("0");
							current_state = STATE2;
							i=i+1;
							break;}
						}// if
					else{
						current_state = STATE0;
						error("");
					}
                break;
     			case STATE2:
					if(i<4){
						switch(input){
							case '1':
							a1=1;
							cursor("1");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '2':
							a2=2;
							cursor("2");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '3':
							a3=3;
							cursor("3");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '4':
							a4=4;
							cursor("4");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '5':
							a5=5;
							cursor("5");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '6':
							a6=6;
							cursor("6");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '7':
							a7=7;
							cursor("7");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '8':
							a8=8;
							cursor("8");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '9':
							a9=9;
							cursor("9");
							current_state = STATE2;
							i=i+1;
							break;}
						switch(input){
							case '0':
							a0=0;
							cursor("0");
							current_state = STATE2;
							i=i+1;
							break;}
						}// if
					else{
						current_state = STATE0;
						error("");
					}
     			break;
     			case STATE3:
					if(i<4){
						switch(input){
							case '1':
							a1=1;
							cursor("1");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '2':
							a2=2;
							cursor("2");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '3':
							a3=3;
							cursor("3");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '4':
							a4=4;
							cursor("4");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '5':
							a5=5;
							cursor("5");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '6':
							a6=6;
							cursor("6");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '7':
							a7=7;
							cursor("7");
							current_state = STATE4;
							i=i+1;
							break;}
						switch(input){
							case '8':
							a8=8;
							cursor("8");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '9':
							a9=9;
							cursor("9");
							current_state = STATE3;
							i=i+1;
							break;}
						switch(input){
							case '0':
							a0=0;
							cursor("0");
							current_state = STATE3;
							i=i+1;
							break;}
						}// if
					else{
						current_state = STATE0;
						error("");
					}
				break;
     			case STATE4:
					unlock_safe();
					cursor("*");
					pulsa("");
				break;

     		  } // switch(current_state)
           }
         /* USER CODE BEGIN 3 */
       }
       /* USER CODE END 3 */
     }

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RO_Pin|LD2_Pin|D7_Pin|RS_Pin
                          |F2_Pin|F1_Pin|VE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D6_Pin|F4_Pin|F3_Pin|D5_Pin
                          |D4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RO_Pin LD2_Pin D7_Pin RS_Pin
                           F2_Pin F1_Pin VE_Pin */
  GPIO_InitStruct.Pin = RO_Pin|LD2_Pin|D7_Pin|RS_Pin
                          |F2_Pin|F1_Pin|VE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : C2_Pin C1_Pin */
  GPIO_InitStruct.Pin = C2_Pin|C1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D6_Pin F4_Pin F3_Pin D5_Pin
                           D4_Pin */
  GPIO_InitStruct.Pin = D6_Pin|F4_Pin|F3_Pin|D5_Pin
                          |D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : C4_Pin C3_Pin */
  GPIO_InitStruct.Pin = C4_Pin|C3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : EN_Pin */
  GPIO_InitStruct.Pin = EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EN_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
uint32_t pos=5;
uint32_t post=5;
char contra[11];
//uint32_t v1[4] = {0,0,0,0};






void cursor (char* val){
if(pos==5){
	strcpy(str, val);
}
else{
	strcat(str, val);
}
 Lcd_PortType ports[] = {D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port};

		  Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};

		  Lcd_HandleTypeDef lcd;

		  lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);

		  Lcd_cursor(&lcd, 1,0);
		  Lcd_string(&lcd, "pin:");
		  Lcd_cursor(&lcd, 1,pos);
		  Lcd_string(&lcd,val);
		  pos=pos+1;
		  if (pos==9){
			  Lcd_cursor(&lcd, 1,5);
			  Lcd_string(&lcd,str);
		  }

}



void pulsa (char* posicion){


 Lcd_PortType ports[] = {
			D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
		  };

		  Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};

		  Lcd_HandleTypeDef lcd;

		  lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);


	 Lcd_cursor(&lcd, 1,0);
	 Lcd_string(&lcd, "Abierto");
	 Lcd_cursor(&lcd, 1,post);
     Lcd_string(&lcd,posicion);


 }


void error (char* posicion){


 Lcd_PortType ports[] = {
			D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
		  };

		  Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};

		  Lcd_HandleTypeDef lcd;

		  lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);


	 Lcd_cursor(&lcd, 1,0);
	 Lcd_string(&lcd, "ERROR");
	 Lcd_cursor(&lcd, 1,post);
     Lcd_string(&lcd,posicion);


 }

char read_keypad(void)
{
	/* tomar la fila 1 en bajo y hacer las demas en altos */
	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F3_GPIO_Port, F3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F4_GPIO_Port, F4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) // si la columna 1 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
	    return '1';
	}

	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) // si la columna 2 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '2';
    }

	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) // si la columna 3 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '3';
	}

	if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) // si la columna 4 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return 'A';
	}


	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(F3_GPIO_Port, F3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F4_GPIO_Port, F4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) // si la columna 1 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '4';
	}

	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) // si la columna 2 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '5';
	 }

	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) // si la columna 3 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '6';
	}

	if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) // si la columna 4 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return 'B';
	}


	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F3_GPIO_Port, F3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(F4_GPIO_Port, F4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) // si la columna 1 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '7';
	}

	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) // si la columna 2 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '8';
	}

	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) // si la columna 3 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return '9';
	}

	if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) // si la columna 4 esta en bajo
	{
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		return 'C';
	}


	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F3_GPIO_Port, F3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F4_GPIO_Port, F4_Pin, GPIO_PIN_RESET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) // si la columna 1 esta en bajo
		{
		  while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		  return '*';
		}

		if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) // si la columna 2 esta en bajo
		{
		  while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
		  return '0';
		 }

		if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) // si la columna 3 esta en bajo
		{
			while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
			return '#';
		}

		if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) // si la columna 4 esta en bajo
		{
			while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))); // espere hasta que este presionado el boton(metodo de antirrebote)
			return 'D';
		}
		return 'F';
}

    void lock_safe(void)
    {
	  HAL_GPIO_WritePin(VE_GPIO_Port, VE_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(RO_GPIO_Port, RO_Pin, GPIO_PIN_SET);
    }


    void unlock_safe(void)
    {
     cursor("0");
	 HAL_GPIO_WritePin(VE_GPIO_Port, VE_Pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(RO_GPIO_Port, RO_Pin, GPIO_PIN_RESET);
     }

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
