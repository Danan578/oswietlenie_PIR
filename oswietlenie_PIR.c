/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED1_ON HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED1_OFF HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)

#define LED2_ON HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET)
#define LED2_OFF HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET)

#define LED3_ON HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET)
#define LED3_OFF HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET)

#define LED4_ON HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET)
#define LED4_OFF HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET)

#define LED5_ON HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET)
#define LED5_OFF HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET)

#define LED6_ON HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET)
#define LED6_OFF HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET)

#define LED7_ON HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET)
#define LED7_OFF HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET)

#define LED8_ON HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET)
#define LED8_OFF HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET)

#define LED9_ON HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_SET)
#define LED9_OFF HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET)

#define LED10_ON HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_SET)
#define LED10_OFF HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET)

#define LED11_ON HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_SET)
#define LED11_OFF HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_RESET)

#define LED12_ON HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, GPIO_PIN_SET)
#define LED12_OFF HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, GPIO_PIN_RESET)

#define LED13_ON HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_SET)
#define LED13_OFF HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_RESET)

#define LED14_ON HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, GPIO_PIN_SET)
#define LED14_OFF HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, GPIO_PIN_RESET)

#define LED15_ON HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, GPIO_PIN_SET)
#define LED15_OFF HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, GPIO_PIN_RESET)

#define LED16_ON HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, GPIO_PIN_SET)
#define LED16_OFF HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, GPIO_PIN_RESET)

#define LED17_ON HAL_GPIO_WritePin(LED17_GPIO_Port, LED17_Pin, GPIO_PIN_SET)
#define LED17_OFF HAL_GPIO_WritePin(LED17_GPIO_Port, LED17_Pin, GPIO_PIN_RESET)

#define LED18_ON HAL_GPIO_WritePin(LED18_GPIO_Port, LED18_Pin, GPIO_PIN_SET)
#define LED18_OFF HAL_GPIO_WritePin(LED18_GPIO_Port, LED18_Pin, GPIO_PIN_RESET)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

uint32_t ANIM = 0;
uint32_t *wskANIM = &ANIM;

uint32_t CZG = 0;
uint32_t *wskCZG = &CZG;

uint32_t CZD = 0;
uint32_t *wskCZD = &CZD;




uint32_t CZRG(void){

		if(HAL_GPIO_ReadPin(CZUJNIKG_GPIO_Port, CZUJNIKG_Pin)== GPIO_PIN_RESET)
				return 0;
		else
			return 1;

}

uint32_t CZRD(void){

		if(HAL_GPIO_ReadPin(CZUJNIKD_GPIO_Port, CZUJNIKD_Pin)== GPIO_PIN_RESET)
				return 0;
		else
			return 1;

}

uint32_t czasani (uint32_t ct){
	if(0 <= ct&& ct < 50 )
			return 1;
	if(50 <= ct&& ct < 80 )
			return 2;
	if(80 <= ct&& ct  < 150 )
			return 3;
	if(150 <= ct&& ct  < 230 )
			return 4;
	if(230 <= ct&& ct  < 350 )
			return 5;
	if(350 <= ct&& ct  < 460 )
			return 6;
	if(460 <= ct&& ct  < 580)
			return 7;
	if(580 <= ct&& ct  < 700)
		return 8;
	if(700 <= ct&& ct  < 900)
		return 9;
	if(900 <= ct&& ct  < 1100)
		return 10;
	if(1100 <= ct&& ct  < 1200)
		return 11;
	if(1200 <= ct&& ct  < 1400 )
		return 12;
	if(1400 <= ct&& ct  < 1600)
		return 13;
	if(1600 <= ct&& ct  < 1800 )
		return 14;
	if(1800 <= ct&& ct  < 2000 )
		return 15;
	else
		return 0;
}

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
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */


  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_OC_Start_IT(&htim1, TIM_CHANNEL_1);

  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);

  HAL_ADCEx_Calibration_Start(&hadc1);


  uint32_t czas = 0;
  uint32_t TIMreset = 0;
  uint32_t jasnosc = 0;
  *wskANIM = 0;
  uint32_t adc_value = 0;
  uint32_t czastimera = 0;
  uint32_t lpled = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


		LED1_OFF;
		LED2_OFF;
		LED3_OFF;
		LED4_OFF;
		LED5_OFF;
		LED6_OFF;
		LED7_OFF;
		LED8_OFF;
		LED9_OFF;
		LED10_OFF;
		LED11_OFF;
		LED12_OFF;
		LED13_OFF;
		LED14_OFF;
		LED15_OFF;

		  HAL_ADC_Start(&hadc1);
		  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		__HAL_TIM_SET_COUNTER(&htim1,0);


		  adc_value = HAL_ADC_GetValue(&hadc1);
	if ((0 <= adc_value)&&(200 > adc_value))
		  jasnosc = 0;
	if(2500 < adc_value)
		  jasnosc = 1;
	if ((1700 <= adc_value)&&(2500 > adc_value))
		jasnosc = 2;
	if ((1200 <= adc_value)&&(1700 > adc_value))
		jasnosc = 3;
	if ((800 <= adc_value)&&(1200 >  adc_value))
		jasnosc = 4;
	if ((500 <= adc_value)&&(800 >  adc_value))
		jasnosc = 5;
	if ((300 <= adc_value)&&(500 >  adc_value))
		jasnosc = 6;
	if ((200 <= adc_value)&&(300 >  adc_value))
		jasnosc = 7;


*wskANIM = 0;
TIMreset = 0;
*wskCZG = CZRG();
*wskCZD = CZRD();

	  while (jasnosc == 0){

	  					LED1_OFF;
	  					LED2_OFF;
	  					LED3_OFF;
	  					LED4_OFF;
	  					LED5_OFF;
	  					LED6_OFF;
	  					LED7_OFF;
	  					LED8_OFF;
	  					LED9_OFF;
	  					LED10_OFF;
	  					LED11_OFF;
	  					LED12_OFF;
	  					LED13_OFF;
	  					LED14_OFF;
	  					LED15_OFF;

	  					  HAL_ADC_Start(&hadc1);
	  					  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  					__HAL_TIM_SET_COUNTER(&htim1,0);


	  					  adc_value = HAL_ADC_GetValue(&hadc1);
	  				if ((0 <= adc_value)&&(200 > adc_value))
	  					  jasnosc = 0;
	  				if(2500 < adc_value)
	  					  jasnosc = 1;
	  				if ((1700 <= adc_value)&&(2500 > adc_value))
	  					jasnosc = 2;
	  				if ((1200 <= adc_value)&&(1700 > adc_value))
	  					jasnosc = 3;
	  				if ((800 <= adc_value)&&(1200 >  adc_value))
	  					jasnosc = 4;
	  				if ((500 <= adc_value)&&(800 >  adc_value))
	  					jasnosc = 5;
	  				if ((300 <= adc_value)&&(500 >  adc_value))
	  					jasnosc = 6;
	  				if ((200 <= adc_value)&&(300 >  adc_value))
	  					jasnosc = 7;


	  	*wskANIM = 0;
	  	TIMreset = 0;
	  	*wskCZG = CZRG();
	  	*wskCZD = CZRD();


	  }

while (jasnosc != 0){

	LED1_OFF;
	  					LED2_OFF;
	  					LED3_OFF;
	  					LED4_OFF;
	  					LED5_OFF;
	  					LED6_OFF;
	  					LED7_OFF;
	  					LED8_OFF;
	  					LED9_OFF;
	  					LED10_OFF;
	  					LED11_OFF;
	  					LED12_OFF;
	  					LED13_OFF;
	  					LED14_OFF;
	  					LED15_OFF;

	  					  HAL_ADC_Start(&hadc1);
	  					  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  					__HAL_TIM_SET_COUNTER(&htim1,0);


	  					  adc_value = HAL_ADC_GetValue(&hadc1);
	  				if ((0 <= adc_value)&&(200 > adc_value))
	  					  jasnosc = 0;
	  				if(2500 < adc_value)
	  					  jasnosc = 1;
	  				if ((1700 <= adc_value)&&(2500 > adc_value))
	  					jasnosc = 2;
	  				if ((1200 <= adc_value)&&(1700 > adc_value))
	  					jasnosc = 3;
	  				if ((800 <= adc_value)&&(1200 >  adc_value))
	  					jasnosc = 4;
	  				if ((500 <= adc_value)&&(800 >  adc_value))
	  					jasnosc = 5;
	  				if ((300 <= adc_value)&&(500 >  adc_value))
	  					jasnosc = 6;
	  				if ((200 <= adc_value)&&(300 >  adc_value))
	  					jasnosc = 7;


	  	*wskANIM = 0;
	  	TIMreset = 0;
	  	*wskCZG = CZRG();
	  	*wskCZD = CZRD();



//+++++++++++++++++++++++++++++++++++++++++ ANIMACJA  Z DOLU NA GORE +++++++++++++++++++++++++++++++++++++++++
while ((*wskCZD != 0) && (*wskANIM == 0)){
	czas = __HAL_TIM_GET_COUNTER(&htim3);
	czastimera = __HAL_TIM_GET_COUNTER(&htim1);
	*wskCZD = CZRD();
	switch (jasnosc) {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5 +++++++++++++++++++++++++++++++++++++++++++++
			case 1:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 500) {


					if (lpled >= 1)
						LED1_ON;

				}
				if (czas >= 500 && czas < 1000) {


					if (lpled >= 2)
						LED2_ON;
					LED1_OFF;
				}
				if (czas >= 1000 && czas < 1500) {

					if (lpled >= 3)
						LED3_ON;
					LED2_OFF;
				}
				if (czas >= 1500 && czas < 2000) {

					if (lpled >= 4)
						LED4_ON;
					LED3_OFF;
				}

				if (czas >= 2000 && czas < 2500) {

					if (lpled >= 5)
						LED5_ON;
					LED4_OFF;
				}

				if (czas >= 2500 && czas < 3000) {

					if (lpled >= 6)
						LED6_ON;
					LED5_OFF;
				}

				if (czas >= 3000 && czas < 3500) {

					if (lpled >= 7)
						LED7_ON;
					LED6_OFF;
				}

				if (czas >= 3500 && czas < 4000) {

					if (lpled >= 8)
						LED8_ON;
					LED7_OFF;
				}

				if (czas >= 4000 && czas < 4500) {

					if (lpled >= 9)
						LED9_ON;
					LED8_OFF;
				}

				if (czas >= 4500 && czas < 5000) {

					if (lpled >= 10)
						LED10_ON;
					LED9_OFF;
				}

				if (czas >= 5000 && czas < 5500) {

					if (lpled >= 11)
						LED11_ON;
					LED10_OFF;
				}
				if (czas >= 5500 && czas < 6000) {
					if (lpled >= 12)
						LED12_ON;
					LED11_OFF;
				}
				if (czas >= 6000 && czas < 6500) {
					if (lpled >= 13)
						LED13_ON;
					LED12_OFF;
				}
				if (czas >= 6500 && czas < 7000) {
					if (lpled >= 14)
						LED14_ON;
					LED13_OFF;
				}
				if (czas >= 7000 && czas < 7500) {
					if (lpled >= 15){
						LED15_ON;
						*wskANIM = 1;
					}
					LED14_OFF;
				}
				if (czas >= 7500 && czas < 10000) {
					LED15_OFF;
					czas = 0;

				}
				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 10 +++++++++++++++++++++++++++++++++++++++++++++
			case 2:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 1000) {

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
				}

				if (czas >= 1000 && czas < 2000) {
					if (lpled >= 3)
						LED3_ON;
					if (lpled >= 4)
						LED4_ON;
					LED1_OFF;
					LED2_OFF;
				}

				if (czas >= 2000 && czas < 3000) {
					if (lpled >= 5)
						LED5_ON;
					if (lpled >= 6)
						LED6_ON;
					LED3_OFF;
					LED4_OFF;
				}

				if (czas >= 3000 && czas < 4000) {
					if (lpled >= 7)
						LED7_ON;
					if (lpled >= 8)
						LED8_ON;
					LED5_OFF;
					LED6_OFF;
				}

				if (czas >= 4000 && czas < 5000) {
					if (lpled >= 9)
						LED9_ON;
					if (lpled >= 10)
						LED10_ON;
					LED7_OFF;
					LED8_OFF;
				}

				if (czas >= 5000 && czas < 6000) {
					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					LED9_OFF;
					LED10_OFF;
				}

				if (czas >= 6000 && czas < 7000) {
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					LED11_OFF;
					LED12_OFF;
				}

				if (czas >= 7000 && czas < 8000) {
					if (lpled >= 15) {
						LED15_ON;
						*wskANIM = 1;
				}
					LED13_OFF;
					LED14_OFF;
				}

				if (czas >= 8000 && czas < 9000) {
					LED15_OFF;
				}
				if (czas >= 9000 && czas < 10000) {

					czas = 0;
				}
				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 20 +++++++++++++++++++++++++++++++++++++++++++++
			case 3:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 1900) {

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
					if (lpled >= 3)
						LED3_ON;
				}

				if (czas >= 1900 && czas < 3800) {

					if (lpled >= 4)
						LED4_ON;
					if (lpled >= 5)
						LED5_ON;
					if (lpled >= 6)
						LED6_ON;
					LED1_OFF;
					LED2_OFF;
					LED3_OFF;
				}

				if (czas >= 3800 && czas < 5700) {
					if (lpled >= 7)
						LED7_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED9_ON;
					LED4_OFF;
					LED5_OFF;
					LED6_OFF;
				}
				if (czas >= 5700 && czas < 7600) {
					if (lpled >= 10)
						LED10_ON;
					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					LED7_OFF;
					LED8_OFF;
					LED9_OFF;

				}
				if (czas >= 7600 && czas < 9500) {
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					if (lpled >= 15){
						LED15_ON;
						*wskANIM = 1;
					}
					LED10_OFF;
					LED11_OFF;
					LED12_OFF;

				}
				if (czas >= 9500 && czas < 10000) {
					LED13_OFF;
					LED14_OFF;
					LED15_OFF;
					czas = 0;
				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 25 +++++++++++++++++++++++++++++++++++++++++++++
			case 4:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 2400) {

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
					if (lpled >= 3)
						LED3_ON;
					if (lpled >= 4)
						LED4_ON;
				}
				if (czas >= 2400 && czas < 4800) {

					if (lpled >= 5)
						LED5_ON;
					if (lpled >= 6)
						LED6_ON;
					if (lpled >= 7)
						LED7_ON;
					if (lpled >= 8)
						LED8_ON;

					LED1_OFF;
					LED2_OFF;
					LED3_OFF;
					LED4_OFF;

				}
				if (czas >= 4800 && czas < 7200) {

					if (lpled >= 9)
						LED9_ON;
					if (lpled >= 10)
						LED10_ON;
					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					LED5_OFF;
					LED6_OFF;
					LED7_OFF;
					LED8_OFF;

				}
				if (czas >= 7200 && czas < 9600) {
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					if (lpled >= 15){
						LED15_ON;
						*wskANIM = 1;
					}

					LED9_OFF;
					LED10_OFF;
					LED11_OFF;
					LED12_OFF;

				}
				if (czas >= 9600 && czas < 10000) {

					LED13_OFF;
					LED14_OFF;
					LED15_OFF;
					czas = 0;
				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 33 +++++++++++++++++++++++++++++++++++++++++++++
			case 5:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 3200) {

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
					if (lpled >= 3)
						LED3_ON;
					if (lpled >= 4)
						LED4_ON;
					if (lpled >= 5)
						LED5_ON;
				}
				if (czas >= 3200 && czas < 6400) {

					if (lpled >= 6)
						LED6_ON;
					if (lpled >= 7)
						LED7_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED9_ON;
					if (lpled >= 10)
						LED10_ON;

					LED1_OFF;
					LED2_OFF;
					LED3_OFF;
					LED4_OFF;
					LED5_OFF;

				}
				if (czas >= 6400 && czas < 9600) {

					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					if (lpled >= 15){
						LED15_ON;
						*wskANIM = 1;
					}

					LED6_OFF;
					LED7_OFF;
					LED8_OFF;
					LED9_OFF;
					LED10_OFF;

				}
				if (czas >= 9600 && czas < 10000) {

					LED11_OFF;
					LED12_OFF;
					LED13_OFF;
					LED14_OFF;
					LED15_OFF;
					czas = 0;

				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 50 +++++++++++++++++++++++++++++++++++++++++++++
			case 6:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 4800) {

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
					if (lpled >= 3)
						LED3_ON;
					if (lpled >= 4)
						LED4_ON;
					if (lpled >= 5)
						LED5_ON;
					if (lpled >= 6)
						LED6_ON;
					if (lpled >= 7)
						LED7_ON;

				}
				if (czas >= 4800 && czas < 9600) {


					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED9_ON;
					if (lpled >= 10)
						LED10_ON;
					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					if (lpled >= 15){
							LED15_ON;
							*wskANIM = 1;
					}

					LED1_OFF;
					LED2_OFF;
					LED3_OFF;
					LED4_OFF;
					LED5_OFF;
					LED6_OFF;
					LED7_OFF;

				}
				if (czas >= 9600 && czas < 10000) {




					LED8_OFF;
					LED9_OFF;
					LED10_OFF;
					LED11_OFF;
					LED12_OFF;
					LED13_OFF;
					LED14_OFF;
					LED15_OFF;
					czas = 0;

				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 100 +++++++++++++++++++++++++++++++++++++++++++++
			case 7:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
									__HAL_TIM_SET_COUNTER(&htim1,0);
									TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);

					if (lpled >= 1)
						LED1_ON;
					if (lpled >= 2)
						LED2_ON;
					if (lpled >= 3)
						LED3_ON;
					if (lpled >= 4)
						LED4_ON;
					if (lpled >= 5)
						LED5_ON;
					if (lpled >= 6)
						LED6_ON;
					if (lpled >= 7)
						LED7_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED9_ON;
					if (lpled >= 10)
						LED10_ON;
					if (lpled >= 11)
						LED11_ON;
					if (lpled >= 12)
						LED12_ON;
					if (lpled >= 13)
						LED13_ON;
					if (lpled >= 14)
						LED14_ON;
					if (lpled >= 15){
							LED15_ON;
							*wskANIM = 1;
					}



				break;
			}
		}

//++++++++++++++++++++++++++++++++++++++++++ KONIEC ANIMACJI Z DOLU NA GORE +++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++++++++++++++++ POCZATEK ANIMACJI Z GORY NA DOL +++++++++++++++++++++++++++++++++++++++++++++

while ((*wskCZG != 0) && (*wskANIM == 0)){
	czas = __HAL_TIM_GET_COUNTER(&htim3);
	czastimera = __HAL_TIM_GET_COUNTER(&htim1);
	*wskCZG = CZRG();
	switch (jasnosc) {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5 +++++++++++++++++++++++++++++++++++++++++++++
			case 1:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 500) {


					if (lpled >= 1)
						LED15_ON;

				}
				if (czas >= 500 && czas < 1000) {


					if (lpled >= 2)
						LED14_ON;
					LED15_OFF;
				}
				if (czas >= 1000 && czas < 1500) {

					if (lpled >= 3)
						LED13_ON;
					LED14_OFF;
				}
				if (czas >= 1500 && czas < 2000) {

					if (lpled >= 4)
						LED12_ON;
					LED13_OFF;
				}

				if (czas >= 2000 && czas < 2500) {

					if (lpled >= 5)
						LED11_ON;
					LED12_OFF;
				}

				if (czas >= 2500 && czas < 3000) {

					if (lpled >= 6)
						LED10_ON;
					LED11_OFF;
				}

				if (czas >= 3000 && czas < 3500) {

					if (lpled >= 7)
						LED9_ON;
					LED10_OFF;
				}

				if (czas >= 3500 && czas < 4000) {

					if (lpled >= 8)
						LED8_ON;
					LED9_OFF;
				}

				if (czas >= 4000 && czas < 4500) {

					if (lpled >= 9)
						LED7_ON;
					LED8_OFF;
				}

				if (czas >= 4500 && czas < 5000) {

					if (lpled >= 10)
						LED6_ON;
					LED7_OFF;
				}

				if (czas >= 5000 && czas < 5500) {

					if (lpled >= 11)
						LED5_ON;
					LED6_OFF;
				}
				if (czas >= 5500 && czas < 6000) {
					if (lpled >= 12)
						LED4_ON;
					LED5_OFF;
				}
				if (czas >= 6000 && czas < 6500) {
					if (lpled >= 13)
						LED3_ON;
					LED4_OFF;
				}
				if (czas >= 6500 && czas < 7000) {
					if (lpled >= 14)
						LED2_ON;
					LED3_OFF;
				}
				if (czas >= 7000 && czas < 7500) {
					if (lpled >= 15){
						LED1_ON;
						*wskANIM = 1;
					}
					LED2_OFF;
				}
				if (czas >= 7500 && czas < 10000) {
					LED1_OFF;
					czas = 0;

				}
				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 10 +++++++++++++++++++++++++++++++++++++++++++++
			case 2:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 1000) {

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
				}

				if (czas >= 1000 && czas < 2000) {
					if (lpled >= 3)
						LED13_ON;
					if (lpled >= 4)
						LED12_ON;
					LED15_OFF;
					LED14_OFF;
				}

				if (czas >= 2000 && czas < 3000) {
					if (lpled >= 5)
						LED11_ON;
					if (lpled >= 6)
						LED10_ON;
					LED13_OFF;
					LED12_OFF;
				}

				if (czas >= 3000 && czas < 4000) {
					if (lpled >= 7)
						LED9_ON;
					if (lpled >= 8)
						LED8_ON;
					LED11_OFF;
					LED10_OFF;
				}

				if (czas >= 4000 && czas < 5000) {
					if (lpled >= 9)
						LED7_ON;
					if (lpled >= 10)
						LED6_ON;
					LED9_OFF;
					LED8_OFF;
				}

				if (czas >= 5000 && czas < 6000) {
					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					LED7_OFF;
					LED6_OFF;
				}

				if (czas >= 6000 && czas < 7000) {
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					LED5_OFF;
					LED4_OFF;
				}

				if (czas >= 7000 && czas < 8000) {
					if (lpled >= 15) {
						LED1_ON;
						*wskANIM = 1;
				}
					LED3_OFF;
					LED2_OFF;
				}

				if (czas >= 8000 && czas < 9000) {
					LED1_OFF;
				}
				if (czas >= 9000 && czas < 10000) {

					czas = 0;
				}
				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 20 +++++++++++++++++++++++++++++++++++++++++++++
			case 3:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 1900) {

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
					if (lpled >= 3)
						LED13_ON;
				}

				if (czas >= 1900 && czas < 3800) {

					if (lpled >= 4)
						LED12_ON;
					if (lpled >= 5)
						LED11_ON;
					if (lpled >= 6)
						LED10_ON;
					LED15_OFF;
					LED14_OFF;
					LED13_OFF;
				}

				if (czas >= 3800 && czas < 5700) {
					if (lpled >= 7)
						LED9_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED7_ON;
					LED12_OFF;
					LED11_OFF;
					LED10_OFF;
				}
				if (czas >= 5700 && czas < 7600) {
					if (lpled >= 10)
						LED6_ON;
					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					LED9_OFF;
					LED8_OFF;
					LED7_OFF;

				}
				if (czas >= 7600 && czas < 9500) {
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					if (lpled >= 15){
						LED1_ON;
						*wskANIM = 1;
					}
					LED6_OFF;
					LED5_OFF;
					LED4_OFF;

				}
				if (czas >= 9500 && czas < 10000) {
					LED3_OFF;
					LED2_OFF;
					LED1_OFF;
					czas = 0;
				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 25 +++++++++++++++++++++++++++++++++++++++++++++
			case 4:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 2400) {

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
					if (lpled >= 3)
						LED13_ON;
					if (lpled >= 4)
						LED12_ON;
				}
				if (czas >= 2400 && czas < 4800) {

					if (lpled >= 5)
						LED11_ON;
					if (lpled >= 6)
						LED10_ON;
					if (lpled >= 7)
						LED9_ON;
					if (lpled >= 8)
						LED8_ON;

					LED15_OFF;
					LED14_OFF;
					LED13_OFF;
					LED12_OFF;

				}
				if (czas >= 4800 && czas < 7200) {

					if (lpled >= 9)
						LED7_ON;
					if (lpled >= 10)
						LED6_ON;
					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					LED11_OFF;
					LED10_OFF;
					LED9_OFF;
					LED8_OFF;

				}
				if (czas >= 7200 && czas < 9600) {
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					if (lpled >= 15){
						LED1_ON;
						*wskANIM = 1;
					}

					LED7_OFF;
					LED6_OFF;
					LED5_OFF;
					LED4_OFF;

				}
				if (czas >= 9600 && czas < 10000) {

					LED3_OFF;
					LED2_OFF;
					LED1_OFF;
					czas = 0;
				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 33 +++++++++++++++++++++++++++++++++++++++++++++
			case 5:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 3200) {

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
					if (lpled >= 3)
						LED13_ON;
					if (lpled >= 4)
						LED12_ON;
					if (lpled >= 5)
						LED11_ON;
				}
				if (czas >= 3200 && czas < 6400) {

					if (lpled >= 6)
						LED10_ON;
					if (lpled >= 7)
						LED9_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED7_ON;
					if (lpled >= 10)
						LED6_ON;

					LED15_OFF;
					LED14_OFF;
					LED13_OFF;
					LED12_OFF;
					LED11_OFF;

				}
				if (czas >= 6400 && czas < 9600) {

					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					if (lpled >= 15){
						LED1_ON;
						*wskANIM = 1;
					}

					LED10_OFF;
					LED9_OFF;
					LED8_OFF;
					LED7_OFF;
					LED6_OFF;

				}
				if (czas >= 9600 && czas < 10000) {

					LED5_OFF;
					LED4_OFF;
					LED3_OFF;
					LED2_OFF;
					LED1_OFF;
					czas = 0;

				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 50 +++++++++++++++++++++++++++++++++++++++++++++
			case 6:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
											__HAL_TIM_SET_COUNTER(&htim1,0);
											TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);
				if (czas >= 0 && czas < 4800) {

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
					if (lpled >= 3)
						LED13_ON;
					if (lpled >= 4)
						LED12_ON;
					if (lpled >= 5)
						LED11_ON;
					if (lpled >= 6)
						LED10_ON;
					if (lpled >= 7)
						LED9_ON;

				}
				if (czas >= 4800 && czas < 9600) {


					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED7_ON;
					if (lpled >= 10)
						LED6_ON;
					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					if (lpled >= 15){
							LED1_ON;
							*wskANIM = 1;
					}

					LED15_OFF;
					LED14_OFF;
					LED13_OFF;
					LED12_OFF;
					LED11_OFF;
					LED10_OFF;
					LED9_OFF;

				}
				if (czas >= 9600 && czas < 10000) {




					LED8_OFF;
					LED7_OFF;
					LED6_OFF;
					LED5_OFF;
					LED4_OFF;
					LED3_OFF;
					LED2_OFF;
					LED1_OFF;
					czas = 0;

				}

				break;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 100 +++++++++++++++++++++++++++++++++++++++++++++
			case 7:
				czas = __HAL_TIM_GET_COUNTER(&htim3);
				if (TIMreset == 0){
									__HAL_TIM_SET_COUNTER(&htim1,0);
									TIMreset = 1;

										}
				czastimera = __HAL_TIM_GET_COUNTER(&htim1);
				lpled = czasani(czastimera);

					if (lpled >= 1)
						LED15_ON;
					if (lpled >= 2)
						LED14_ON;
					if (lpled >= 3)
						LED13_ON;
					if (lpled >= 4)
						LED12_ON;
					if (lpled >= 5)
						LED11_ON;
					if (lpled >= 6)
						LED10_ON;
					if (lpled >= 7)
						LED9_ON;
					if (lpled >= 8)
						LED8_ON;
					if (lpled >= 9)
						LED7_ON;
					if (lpled >= 10)
						LED6_ON;
					if (lpled >= 11)
						LED5_ON;
					if (lpled >= 12)
						LED4_ON;
					if (lpled >= 13)
						LED3_ON;
					if (lpled >= 14)
						LED2_ON;
					if (lpled >= 15){
							LED1_ON;
							*wskANIM = 1;
					}



				break;
			}
		}

//++++++++++++++++++++++++++++++++++++++++++ KONIEC ANIMACJI Z GORY NA DOL +++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++++++++++++++++++ PODSWIETLENIE SCHODOW ++++++++++++++++++++++++++++++++++++++++++
while((*wskCZG !=0 || *wskCZD != 0) && (*wskANIM != 0)){

	*wskCZD = CZRD();
	*wskCZG = CZRG();
		switch (jasnosc) {

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 5 +++++++++++++++++++++++++++++++++++++++++++++
		case 1:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 500) {

				LED1_ON;

			}
			if (czas >= 500 && czas < 1000) {
				LED2_ON;
				LED1_OFF;
			}
			if (czas >= 1000 && czas < 1500) {
				LED3_ON;
				LED2_OFF;
			}
			if (czas >= 1500 && czas < 2000) {
				LED4_ON;
				LED3_OFF;
			}
			if (czas >= 2000 && czas < 2500) {
				LED5_ON;
				LED4_OFF;
			}
			if (czas >= 2500 && czas < 3000) {
				LED6_ON;
				LED5_OFF;
			}
			if (czas >= 3000 && czas < 3500) {
				LED7_ON;
				LED6_OFF;
			}
			if (czas >= 3500 && czas < 4000) {
				LED8_ON;
				LED7_OFF;
			}
			if (czas >= 4000 && czas < 4500) {
				LED9_ON;
				LED8_OFF;
			}
			if (czas >= 4500 && czas < 5000) {
				LED10_ON;
				LED9_OFF;
			}
			if (czas >= 5000 && czas < 5500) {
				LED11_ON;
				LED10_OFF;
			}
			if (czas >= 5500 && czas < 6000) {
				LED12_ON;
				LED11_OFF;
			}
			if (czas >= 6000 && czas < 6500) {
				LED13_ON;
				LED12_OFF;
			}
			if (czas >= 6500 && czas < 7000) {
				LED14_ON;
				LED13_OFF;
			}
			if (czas >= 7000 && czas < 7500) {
				LED15_ON;
				LED14_OFF;
			}
			if (czas >= 7500 && czas < 10000) {
				LED15_OFF;
				czas = 0;

			}
			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 10 +++++++++++++++++++++++++++++++++++++++++++++
		case 2:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 1000) {

				LED1_ON;
				LED2_ON;
			}
			if (czas >= 1000 && czas < 2000) {
				LED3_ON;
				LED4_ON;
				LED1_OFF;
				LED2_OFF;
			}
			if (czas >= 2000 && czas < 3000) {
				LED5_ON;
				LED6_ON;
				LED3_OFF;
				LED4_OFF;
			}
			if (czas >= 3000 && czas < 4000) {
				LED7_ON;
				LED8_ON;
				LED5_OFF;
				LED6_OFF;
			}
			if (czas >= 4000 && czas < 5000) {
				LED9_ON;
				LED10_ON;
				LED7_OFF;
				LED8_OFF;
			}
			if (czas >= 5000 && czas < 6000) {
				LED11_ON;
				LED12_ON;
				LED9_OFF;
				LED10_OFF;
			}
			if (czas >= 6000 && czas < 7000) {
				LED13_ON;
				LED14_ON;
				LED11_OFF;
				LED12_OFF;
			}
			if (czas >= 7000 && czas < 8000) {
				LED15_ON;
				LED13_OFF;
				LED14_OFF;
			}
			if (czas >= 8000 && czas < 9000) {
				LED15_OFF;
			}
			if (czas >= 9000 && czas < 10000) {

				czas = 0;
			}
			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 20 +++++++++++++++++++++++++++++++++++++++++++++
		case 3:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 1900) {

				LED1_ON;
				LED2_ON;
				LED3_ON;
			}
			if (czas >= 1900 && czas < 3800) {

				LED4_ON;
				LED5_ON;
				LED6_ON;
				LED1_OFF;
				LED2_OFF;
				LED3_OFF;
			}
			if (czas >= 3800 && czas < 5700) {
				LED7_ON;
				LED8_ON;
				LED9_ON;
				LED4_OFF;
				LED5_OFF;
				LED6_OFF;
			}
			if (czas >= 5700 && czas < 7600) {
				LED10_ON;
				LED11_ON;
				LED12_ON;
				LED7_OFF;
				LED8_OFF;
				LED9_OFF;

			}
			if (czas >= 7600 && czas < 9500) {
				LED13_ON;
				LED14_ON;
				LED15_ON;
				LED10_OFF;
				LED11_OFF;
				LED12_OFF;

			}
			if (czas >= 9500 && czas < 10000) {
				LED13_OFF;
				LED14_OFF;
				LED15_OFF;
				czas = 0;
			}

			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 25 +++++++++++++++++++++++++++++++++++++++++++++
		case 4:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 2400) {

				LED1_ON;
				LED2_ON;
				LED3_ON;
				LED4_ON;
			}
			if (czas >= 2400 && czas < 4800) {

				LED5_ON;
				LED6_ON;
				LED7_ON;
				LED8_ON;

				LED1_OFF;
				LED2_OFF;
				LED3_OFF;
				LED4_OFF;

			}
			if (czas >= 4800 && czas < 7200) {

				LED9_ON;
				LED10_ON;
				LED11_ON;
				LED12_ON;
				LED5_OFF;
				LED6_OFF;
				LED7_OFF;
				LED8_OFF;

			}
			if (czas >= 7200 && czas < 9600) {
				LED13_ON;
				LED14_ON;
				LED15_ON;
				LED9_OFF;
				LED10_OFF;
				LED11_OFF;
				LED12_OFF;

			}
			if (czas >= 9600 && czas < 10000) {

				LED13_OFF;
				LED14_OFF;
				LED15_OFF;
				czas = 0;
			}

			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 33 +++++++++++++++++++++++++++++++++++++++++++++
		case 5:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 3200) {

				LED1_ON;
				LED2_ON;
				LED3_ON;
				LED4_ON;
				LED5_ON;
			}
			if (czas >= 3200 && czas < 6400) {

				LED6_ON;
				LED7_ON;
				LED8_ON;
				LED9_ON;
				LED10_ON;

				LED1_OFF;
				LED2_OFF;
				LED3_OFF;
				LED4_OFF;
				LED5_OFF;

			}
			if (czas >= 6400 && czas < 9600) {

				LED11_ON;
				LED12_ON;
				LED13_ON;
				LED14_ON;
				LED15_ON;

				LED6_OFF;
				LED7_OFF;
				LED8_OFF;
				LED9_OFF;
				LED10_OFF;

			}
			if (czas >= 9600 && czas < 10000) {

				LED11_OFF;
				LED12_OFF;
				LED13_OFF;
				LED14_OFF;
				LED15_OFF;
				czas = 0;

			}

			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 50 +++++++++++++++++++++++++++++++++++++++++++++
		case 6:
			czas = __HAL_TIM_GET_COUNTER(&htim3);
			if (czas >= 0 && czas < 4800) {

				LED1_ON;
				LED2_ON;
				LED3_ON;
				LED4_ON;
				LED5_ON;
				LED6_ON;
				LED7_ON;

			}
			if (czas >= 4800 && czas < 9600) {


				LED8_ON;
				LED9_ON;
				LED10_ON;
				LED11_ON;
				LED12_ON;
				LED13_ON;
				LED14_ON;
				LED15_ON;

				LED1_OFF;
				LED2_OFF;
				LED3_OFF;
				LED4_OFF;
				LED5_OFF;
				LED6_OFF;
				LED7_OFF;

			}
			if (czas >= 9600 && czas < 10000) {




				LED8_OFF;
				LED9_OFF;
				LED10_OFF;
				LED11_OFF;
				LED12_OFF;
				LED13_OFF;
				LED14_OFF;
				LED15_OFF;
				czas = 0;

			}

			break;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ 100 +++++++++++++++++++++++++++++++++++++++++++++
		case 7:

				LED1_ON;
				LED2_ON;
				LED3_ON;
				LED4_ON;
				LED5_ON;
				LED6_ON;
				LED7_ON;
				LED8_ON;
				LED9_ON;
				LED10_ON;
				LED11_ON;
				LED12_ON;
				LED13_ON;
				LED14_ON;
				LED15_ON;




			break;
		}
	}

}


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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.LowPowerAutoPowerOff = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_160CYCLES_5;
  hadc1.Init.SamplingTimeCommon2 = ADC_SAMPLETIME_160CYCLES_5;
  hadc1.Init.OversamplingMode = DISABLE;
  hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 7999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_OC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 7;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_OC_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_OC_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED11_Pin|LED12_Pin|LED13_Pin|LED14_Pin
                          |LED15_Pin|LED16_Pin|LED17_Pin|LED18_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF1_OSC;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : CZUJNIKD_Pin CZUJNIKG_Pin */
  GPIO_InitStruct.Pin = CZUJNIKD_Pin|CZUJNIKG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin LED7_Pin LED8_Pin
                           LED9_Pin LED10_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED11_Pin LED12_Pin LED13_Pin LED14_Pin
                           LED15_Pin LED16_Pin LED17_Pin LED18_Pin */
  GPIO_InitStruct.Pin = LED11_Pin|LED12_Pin|LED13_Pin|LED14_Pin
                          |LED15_Pin|LED16_Pin|LED17_Pin|LED18_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
