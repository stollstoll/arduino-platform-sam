#ifndef Pins_Arduino_h
#define Pins_Arduino_h

//#ifdef ARDUINO_MAIN

#define PIN_LED_BLUE         (0u)
#define PIN_LED_GREEN        (1u)
#define PIN_LED_RED          (2u)
#define PIN_LED              PIN_LED_BLUE

const static uint8_t SS   = 34 ;
const static uint8_t MOSI = 32 ;
const static uint8_t MISO = 31 ;
const static uint8_t SCK  = 33 ;

#define PINS_UART            (16u)

/* Types used for the tables below */
typedef struct _PinDescription
{
    Pio* pPort ;
    uint32_t dwPin ;
    uint32_t dwPeripheralId ;
    EPioType dwPinType ;
    uint32_t dwPinAttribute ;
} PinDescription ;

static const PinDescription APinDescription[]=
{
  // LEDS, 0..2
#ifdef BOARD_REV_A
  { PIOC, PIO_PC20, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT }, // LED BLUE
  { PIOC, PIO_PC21, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT }, // LED GREEN
  { PIOC, PIO_PC22, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT }, // LED RED
#endif
#ifdef BOARD_REV_B
  { PIOA, PIO_PA19, ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT }, // LED BLUE
  { PIOA, PIO_PA20, ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT }, // LED GREEN
  { PIOC, PIO_PC20, ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT }, // LED RED
#endif

  // Clock 32KHz, 3..4
  { PIOA, PIO_PA7, ID_PIOA, PIO_NOT_A_PIN, PIO_DEFAULT }, // XIN32
  { PIOA, PIO_PA8, ID_PIOA, PIO_NOT_A_PIN, PIO_DEFAULT }, // XOUT32

  // Clock 12MHz, 5..6
  { PIOB, PIO_PB9, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // XIN
  { PIOB, PIO_PB8, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // XOUT

  // JTAG, 7..10
  { PIOB, PIO_PB4, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // TDI
  { PIOB, PIO_PB5, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // TDO
  { PIOB, PIO_PB6, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // TMS
  { PIOB, PIO_PB7, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // TCK

  // USB, 11..13
  { PIOB, PIO_PB10, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // DDM
  { PIOB, PIO_PB11, ID_PIOB, PIO_NOT_A_PIN, PIO_DEFAULT }, // DDP
#ifdef BOARD_REV_A
  { PIOC, PIO_PC23, ID_PIOC, PIO_INPUT, PIO_PULLUP }, // USB_VBUS
#endif
#ifdef BOARD_REV_B
  { PIOC, PIO_PC21, ID_PIOC, PIO_INPUT, PIO_PULLUP }, // USB_VBUS
#endif

  // UART0 (Serial), 14..16
  { PIOA, PIO_PA9, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // URXD0
  { PIOA, PIO_PA10, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // UTXD0
  { PIOA, PIO_PA9|PIO_PA10, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // All UART0 pins

  // Push buttons, 17..18
  { PIOB, PIO_PB3, ID_PIOB, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE }, // PB1
  { PIOC, PIO_PC12, ID_PIOC, PIO_INPUT, PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE }, // PB2

  // QTouch Slider, 19..20
  { PIOA, (PIO_PA0 | PIO_PA2 | PIO_PA4), ID_PIOA, PIO_INPUT, PIO_DEFAULT }, // QTSLIDR SNS
  { PIOA, (PIO_PA1 | PIO_PA3 | PIO_PA5), ID_PIOA, PIO_INPUT, PIO_DEFAULT }, // QTSLIDR SNSK

  // QTouch Buttons, 21..22
  { PIOC, (PIO_PC22 | PIO_PC24 | PIO_PC26 | PIO_PC28 | PIO_PC30), ID_PIOC, PIO_INPUT, PIO_DEFAULT }, // KEYS SNS
  { PIOC, (PIO_PC23 | PIO_PC25 | PIO_PC27 | PIO_PC29 | PIO_PC31), ID_PIOC, PIO_INPUT, PIO_DEFAULT }, // KEYS SNSK

  // MCI (SDCARD), 23..30
#ifdef BOARD_REV_A
  { PIOA, PIO_PA15, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // MCI Card Detect
#endif
#ifdef BOARD_REV_B
  { PIOA, PIO_PA6, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // MCI Card Detect
#endif
  { PIOA, PIO_PA30, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCDA0
  { PIOA, PIO_PA31, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCDA1
  { PIOA, PIO_PA26, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCDA2
  { PIOA, PIO_PA27, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCDA3
  { PIOA, PIO_PA28, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCCDA
  { PIOA, PIO_PA29, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // MCCK

  { PIOA, PIO_PA26|PIO_PA27|PIO_PA28|PIO_PA29|PIO_PA30|PIO_PA31, ID_PIOA, PIO_PERIPH_C, PIO_PULLUP }, // All MCI Pins

  // SPI, 31..34
  { PIOA, PIO_PA12A_MISO, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // MISO
  { PIOA, PIO_PA13A_MOSI, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // MOSI
  { PIOA, PIO_PA14A_SPCK, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // SPCK
  { PIOA, PIO_PA11A_NPCS0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // NPCS0

  // TouchScreen, 35..36
#ifdef BOARD_REV_A
  { PIOA, PIO_PA4, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // IRQ_TSC
  { PIOA, PIO_PA5, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // BUSY_TSC
#endif
#ifdef BOARD_REV_B
  { PIOA, PIO_PA16, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // IRQ_TSC
  { PIOA, PIO_PA17, ID_PIOA, PIO_INPUT, PIO_PULLUP }, // BUSY_TSC
#endif

  // USART1, 37..41
  { PIOA, PIO_PA21A_RXD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // RXD1
  { PIOA, PIO_PA22A_TXD1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // TXD1
  { PIOA, PIO_PA24A_RTS1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // RTS1
  { PIOA, PIO_PA25A_CTS1, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT }, // CTS1
  { PIOA, PIO_PA23A_SCK1, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT }, // COM1 ENABLE (MAX232)

  // LCD, 42..47
  { PIOC, 0xFF, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP }, // EBI Data bus
  { PIOC, PIO_PC8, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP }, // EBI_NWE
  { PIOC, PIO_PC11, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP }, // EBI_NRD
  { PIOC, PIO_PC15, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP }, // LCD CS
  { PIOC, PIO_PC19, ID_PIOC, PIO_PERIPH_A, PIO_PULLUP }, // LCD RS
  { PIOC, PIO_PC13, ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT }, // LCD BackLight
  
  { NULL, 0, 0, PIO_NOT_A_PIN, PIO_DEFAULT } // END
} ;

#ifdef BOARD_REV_A
#  define PIN_TSC_IRQ_WUP_ID (1UL << 3)
#endif
#ifdef BOARD_REV_B
#  define PIN_TSC_IRQ_WUP_ID (1UL << 15)
#endif

#define BOARD_LCD_PINS              PIN_EBI_DATA_BUS, PIN_EBI_NRD, PIN_EBI_NWE, PIN_EBI_NCS1, PIN_EBI_LCD_RS
#define BOARD_LCD_BASE              0x61000000 /** Define ILI9325 base address. */
#define BOARD_LCD_RS                (1 << 1) /** Define ILI9325 register select signal. */

//#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h