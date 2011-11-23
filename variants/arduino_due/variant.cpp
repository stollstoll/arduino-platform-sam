/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"


/*
 * DUE Board pin   |  PORT
 * ----------------+--------
 *   0   RX0       |  PA11
 *   1   TX0       |  PA12
 *   2       PWML3 |  PC9
 *   3       PWMH3 |  PB16
 *   4       NPCS0 |  PA16
 *   5       PWM   |  PA30
 *   6       PWMH2 |  PA6
 *   7       PWML2 |  PC8
 *   8       PWML1 |  PC7
 *   9       PWMH1 |  PA5
 *  10             |  PA1
 *  11       PWMH0 |  PA4
 *  12       PWML0 |  PC6
 *  13             |  PC21
 *  14   TX3       |  PA22
 *  15   RX3       |  PA23
 *  16   TX2       |  PA20
 *  17   RX2       |  PA21
 *  18   TX1       |  PA18
 *  19   RX1       |  PA19
 *  20   SDA       |  PA24
 *  21   SCL       |  PA25
 *  22             |  PC3
 *  23             |  PC2
 *  24             |  PC1
 *  25             |  PC0
 *  26             |  PB28
 *  27             |  PB27
 *  28             |  PB26
 *  29             |  PB25
 *  30             |  PB24
 *  31             |  PB23
 *  32             |  PB22
 *  33             |  PB21
 *  34             |  PB20
 *  35             |  PB19
 *  36             |  PB18
 *  37             |  PB17
 *  38             |  PA28
 *  39             |  PA29
 *  40             |  PC22
 *  41             |  PA31
 *  42             |  PC23
 *  43             |  PB0
 *  44             |  PC24
 *  45             |  PB1
 *  46             |  PC25
 *  47             |  PB2
 *  48             |  PC26
 *  49             |  PB11
 *  50             |  PB12
 *  51             |  PB13
 *  52             |  PC27
 *  53             |  PA27
 *  A0             |  PB5
 *  A1             |  PB6
 *  A2             |  PB7
 *  A3             |  PB8
 *  A4             |  PC28
 *  A5             |  PC29
 *  A6             |  PC30
 *  A7             |  PC31
 *  A8             |  PB3
 *  A9             |  PB4
 * A10             |  PC15
 * A11             |  PC16
 * A12             |  PC17
 * A13             |  PC18
 * A14             |  This pin is DAC0 output of LTC1661CMS8
 * A15             |  This pin is DAC1 output of LTC1661CMS8
 *      SDA1       |  PA9
 *      SCL1       |  PA10
 *
 *
 * LTC1661CMS8 pin |  PORT
 * ----------------+--------
 * #CS/LD          |  PB9
 *  SCK            |  PB10
 *  DIN            |  PB14
 *
 *
 * LEDs            |  PORT
 * ----------------+--------
 * "TX"            |  PC19
 * "RX"            |  PC14
 * "L"             |  PC21
 */


/*
 * Pins descriptions
 */
extern const PinDescription g_APinDescription[]=
{
  // 0 .. 53 - Digital pins

  // 0/1 - UART (Serial)
  { PIOA, PIO_PA11A_URXD, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // URXD
  { PIOA, PIO_PA12A_UTXD, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // UTXD

  // 2
  { PIOC, PIO_PC9B_PWML3, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWML3
  { PIOB, PIO_PB16B_PWMH3, ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWMH3
  { PIOC, PIO_PA16A_NPCS0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // NPCS0

  // 5
  { PIOA, PIO_PA30B_TIOA2, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWM
  { PIOA, PIO_PA6B_PWMH2, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWMH2
  { PIOC, PIO_PC8B_PWML2, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWML2
  { PIOC, PIO_PC7B_PWML1, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWML1
  { PIOA, PIO_PA5B_PWMH1, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWMH1

  // 10
  { PIOA, PIO_PA1, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, 0, NONE }, // PIN 10
  { PIOA, PIO_PA4B_PWMH0, ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWMH0
  { PIOC, PIO_PC6B_PWML0, ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NONE, NONE }, // PWML0

  // 13 - AMBER LED
  { PIOC, PIO_PC21, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 13

  // 14/15 - USART2 (Serial4)
  { PIOA, PIO_PA22A_TXD2, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TXD2
  { PIOA, PIO_PA23A_RXD2, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // RXD2

  // 16/17 - USART1 (Serial3)
  { PIOA, PIO_PA20A_TXD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TXD1
  { PIOA, PIO_PA21A_RXD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // RXD1

  // 18/19 - USART0 (Serial2)
  { PIOA, PIO_PA18A_TXD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TXD0
  { PIOA, PIO_PA19A_RXD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // RXD0

  // 20/21 - TWI1
  { PIOA, PIO_PA24A_TWD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TWD1 - SDA0
  { PIOA, PIO_PA25A_TWCK1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TWCK1 - SCL0

  // 22
  { PIOC, PIO_PC3 , ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 22
  { PIOC, PIO_PC2 , ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 23
  { PIOC, PIO_PC1 , ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 24
  { PIOC, PIO_PC0 , ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 25

  // 26
  { PIOB, PIO_PB28, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 26
  { PIOB, PIO_PB27, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 27
  { PIOB, PIO_PB26, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 28
  { PIOB, PIO_PB25, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 29

  // 30
  { PIOB, PIO_PB24, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 30
  { PIOB, PIO_PB23, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 31
  { PIOB, PIO_PB22, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 32
  { PIOB, PIO_PB21, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 33

  // 34
  { PIOB, PIO_PB20, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 34
  { PIOB, PIO_PB19, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 35
  { PIOB, PIO_PB18, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 36
  { PIOB, PIO_PB17, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 37

  // 38
  { PIOA, PIO_PA28, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 38
  { PIOA, PIO_PA29, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 39
  { PIOC, PIO_PC22, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 40
  { PIOA, PIO_PA31, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 41

  // 42
  { PIOC, PIO_PC23, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 42
  { PIOB, PIO_PB0 , ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 43
  { PIOC, PIO_PC24, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 44
  { PIOB, PIO_PB1 , ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 45

  // 46
  { PIOC, PIO_PC25, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 46
  { PIOB, PIO_PB2 , ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 47
  { PIOC, PIO_PC26, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 48
  { PIOB, PIO_PB11, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 49

  // 50
  { PIOB, PIO_PB12, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 50
  { PIOB, PIO_PB13, ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 51
  { PIOC, PIO_PC27, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 52
  { PIOA, PIO_PA27, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // PIN 53

  // 54 .. 67 - Analog Inputs
  { PIOB, PIO_PB5X1_AD0, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC0, ADC0 }, // AD0
  { PIOB, PIO_PB6X1_AD1, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC1, ADC1 }, // AD1
  { PIOB, PIO_PB7X1_AD2, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC2, ADC2 }, // AD2
  { PIOB, PIO_PB8X1_AD3, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC3, ADC3 }, // AD3
  // 58
  { PIOC, PIO_PC28X1_AD4, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC4, ADC4 }, // AD4
  { PIOC, PIO_PC29X1_AD5, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC5, ADC5 }, // AD5
  { PIOC, PIO_PC30X1_AD6, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC6, ADC6 }, // AD6
  { PIOC, PIO_PC31X1_AD7, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC7, ADC7 }, // AD7
  // 62
  { PIOB, PIO_PB3X1_AD12B2, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC8, ADC2 }, // AD8
  { PIOB, PIO_PB4X1_AD12B3, ID_PIOB, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC9, ADC3 }, // AD9
  { PIOC, PIO_PC15X1_AD12B4, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC10, ADC4 }, // AD10
  { PIOC, PIO_PC16X1_AD12B5, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC11, ADC5 }, // AD11
  // 66
  { PIOC, PIO_PC17X1_AD12B6, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC12, ADC6 }, // AD12
  { PIOC, PIO_PC18X1_AD12B7, ID_PIOC, PIO_INPUT, PIO_DEFAULT, PIN_ATTR_ANALOG, ADC13, ADC7 }, // AD13

  // 68/69 - TWI0
  { PIOA, PIO_PA9A_TWD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TWD0 - SDA1
  { PIOA, PIO_PA10A_TWCK0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // TWCK0 - SCL1

  // 70/71/72 - External DAC
  { PIOB, PIO_PB9, ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // DAC-CS
  { PIOB, PIO_PB10, ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // DAC-SCK
  { PIOB, PIO_PB14, ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // DAC-DIN

  // 73/74 - LEDs
  { PIOC, PIO_PC14, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // LED AMBER RXL
  { PIOC, PIO_PC19, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // LED AMBER TXL

  // 75/76/77 - SPI
  { PIOA, PIO_PA13A_MISO, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // MISO
  { PIOA, PIO_PA14A_MOSI, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // MOSI
  { PIOA, PIO_PA15A_SPCK, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL, NONE, NONE }, // SPCK

  // 78 .. 83 - "All pins" masks

  // 78 - TWI0 all pins
  { PIOA, PIO_PA9A_TWD0|PIO_PA10A_TWCK0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All TWI0 pins
  // 79 - TWI1 all pins
  { PIOA, PIO_PA24A_TWD1|PIO_PA25A_TWCK1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All TWI1 pins
  // 80 - UART (Serial) all pins
  { PIOA, PIO_PA11A_URXD|PIO_PA12A_UTXD, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All UART pins
  // 81 - USART0 (Serial2) all pins
  { PIOA, PIO_PA19A_RXD0|PIO_PA18A_TXD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All USART0 pins
  // 82 - USART1 (Serial3) all pins
  { PIOA, PIO_PA21A_RXD1|PIO_PA20A_TXD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All USART1 pins
  // 83 - USART2 (Serial4) all pins
  { PIOA, PIO_PA23A_RXD2|PIO_PA22A_TXD2, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NONE, NONE }, // All USART2 pins

  { NULL, 0, 0, PIO_NOT_A_PIN, PIO_DEFAULT, 0, NONE, NONE } /* END */
} ;

/*
 * UART objects
 */
RingBuffer rx_buffer1 ;

UARTClass Serial( UART, UART_IRQn, ID_UART, &rx_buffer1 ) ;

// IT handlers
void UART_IrqHandler(void)
{
  Serial.IrqHandler() ;
}

// ----------------------------------------------------------------------------
/*
 * USART objects
 */
RingBuffer rx_buffer2 ;
RingBuffer tx_buffer2 ;
RingBuffer rx_buffer3 ;
RingBuffer tx_buffer3 ;
RingBuffer rx_buffer4 ;
RingBuffer tx_buffer4 ;

USARTClass Serial2( USART0, USART0_IRQn, ID_USART0, &rx_buffer2, &tx_buffer2 ) ;
USARTClass Serial3( USART1, USART1_IRQn, ID_USART1, &rx_buffer3, &tx_buffer3 ) ;
USARTClass Serial4( USART2, USART2_IRQn, ID_USART2, &rx_buffer4, &tx_buffer4 ) ;

#ifdef __cplusplus
extern "C" {
#endif

// IT handlers
extern void USART0_IrqHandler( void )
{
  Serial2.IrqHandler() ;
}

extern void USART1_IrqHandler( void )
{
  Serial3.IrqHandler() ;
}

extern void USART2_IrqHandler( void )
{
  Serial4.IrqHandler() ;
}

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 */
extern void init( void )
{
  SystemInit() ;

  /* Set Systick to 1ms interval, common to all SAM3 variants */
  if ( SysTick_Config( SystemCoreClock / 1000 ) )
  {
    /* Capture error */
    while ( 1 ) ;
  }

  /* Disable watchdog, common to all SAM variants */
  WDT_Disable( WDT ) ;

  // Initialize Serial port UART, common to all SAM3 variants
  PIO_Configure( g_APinDescription[PINS_UART].pPort, g_APinDescription[PINS_UART].ulPinType,
                 g_APinDescription[PINS_UART].ulPin, g_APinDescription[PINS_UART].ulPinConfiguration ) ;

  // Initialize 10bit Analog Controller
  /* Enable peripheral clock.*/
  PMC_EnablePeripheral( ID_ADC ) ;
  
  /* Initialize ADC. */
  /*  startup = 8:    512 periods of ADCClock
   * for prescal = 4
   *     prescal: ADCClock = MCK / ( (PRESCAL+1) * 2 ) => 64MHz / ((4+1)*2) = 6.4MHz
   *     ADC clock = 6.4 MHz
   */
  adc_init( ADC, SystemCoreClock, 6400000, 10 ) ;
  adc_configure_timing( ADC, 1200 ) ;
  adc_configure_trigger( ADC, ADC_TRIG_SW ) ;	
  adc_disable_interrupt( ADC, 0xFFFFFFFF ) ; /* Disable all adc interrupt. */	
  adc_disable_channel( ADC, ADC_ALL_CHANNEL ) ;

  // Initialize 12bit Analog Controller
  /* Enable peripheral clock.*/
  PMC_EnablePeripheral( ID_ADC12B ) ;
  
  /* Initialize ADC12. */
  /*  startup = 8:    512 periods of ADCClock
   * for prescal = 4
   *     prescal: ADCClock = MCK / ( (PRESCAL+1) * 2 ) => 64MHz / ((4+1)*2) = 6.4MHz
   *     ADC clock = 6.4 MHz
   */
  adc12_init( ADC12B, SystemCoreClock, 6400000, 10, 1200 ) ;
  adc12_configure_timing( ADC12B, 1200 ) ;
  adc12_configure_trigger( ADC12B, ADC_TRIG_SW ) ;	
  adc12_disable_interrupt( ADC12B, 0xFFFFFFFF ) ; /* Disable all adc interrupt. */
  adc12_disable_channel( ADC12B, ADC_ALL_CHANNEL ) ;
}
#ifdef __cplusplus
}
#endif

