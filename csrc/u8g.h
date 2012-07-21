/*

  u8g.h
  
  Universal 8bit Graphics Library
  
  Copyright (c) 2011, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/

#ifndef _U8G_H
#define _U8G_H

#include <stddef.h>
#include <stdint.h>

#if defined(__AVR__)
#include <avr/pgmspace.h>
#endif 

#ifdef __cplusplus
extern "C" {
#endif

  
/*===============================================================*/
#ifdef __GNUC__
#define U8G_NOINLINE __attribute__((noinline))
#define U8G_PURE  __attribute__ ((pure))
#define U8G_NOCOMMON __attribute__ ((nocommon))
#define U8G_SECTION(name) __attribute__ ((section (name)))
#else
#define U8G_NOINLINE
#define U8G_PURE
#define U8G_NOCOMMON
#define U8G_SECTION(name)
#endif
  
/*===============================================================*/
/* flash memory access */

#if defined(__AVR__)
/* U8G_PROGMEM is used by the XBM example */
#define U8G_PROGMEM U8G_SECTION(".progmem.data")
typedef uint8_t PROGMEM u8g_pgm_uint8_t;
typedef uint8_t u8g_fntpgm_uint8_t;
#define u8g_pgm_read(adr) pgm_read_byte_near(adr)
#define U8G_PSTR(s) ((u8g_pgm_uint8_t *)PSTR(s))
#else
#define U8G_PROGMEM
#define PROGMEM
typedef uint8_t u8g_pgm_uint8_t;
typedef uint8_t u8g_fntpgm_uint8_t;
#define u8g_pgm_read(adr) (*(const u8g_pgm_uint8_t *)(adr)) 
#define U8G_PSTR(s) ((u8g_pgm_uint8_t *)(s))
#endif
  
/*===============================================================*/
/* forward */
typedef struct _u8g_t u8g_t;
typedef struct _u8g_dev_t u8g_dev_t;


/*===============================================================*/
/* generic */
#if defined(U8G_16BIT)
typedef uint16_t u8g_uint_t;
typedef int16_t u8g_int_t;
#else
typedef uint8_t u8g_uint_t;
typedef int8_t u8g_int_t;
#endif

struct _u8g_box_t
{
  u8g_uint_t x0, y0, x1, y1;  
};
typedef struct _u8g_box_t u8g_box_t;


/*===============================================================*/
/* device list */

/* Size: 128x64 SDL, u8g_dev_sdl.c */
extern u8g_dev_t u8g_dev_sdl_1bit;
extern u8g_dev_t u8g_dev_sdl_1bit_h;
extern u8g_dev_t u8g_dev_sdl_2bit;
extern u8g_dev_t u8g_dev_sdl_2bit_double_mem;
extern u8g_dev_t u8g_dev_sdl_8bit;
int u8g_sdl_get_key(void);

/* Size: 70x30 monochrom, stdout */
extern u8g_dev_t u8g_dev_stdout;

/* Size: monochrom, writes "u8g.pbm" */
extern u8g_dev_t u8g_dev_pbm;

/* Size: 128x64 monochrom, no output, used for performance measure */
extern u8g_dev_t u8g_dev_gprof;

/* Display: EA DOGS102, Size: 102x64 monochrom */
extern u8g_dev_t u8g_dev_uc1701_dogs102_sw_spi;
extern u8g_dev_t u8g_dev_uc1701_dogs102_hw_spi;

/* Display: EA DOGM132, Size: 128x32 monochrom */
extern u8g_dev_t u8g_dev_st7565_dogm132_sw_spi;
extern u8g_dev_t u8g_dev_st7565_dogm132_hw_spi;

/* Display: EA DOGM128, Size: 128x64 monochrom */
extern u8g_dev_t u8g_dev_st7565_dogm128_sw_spi;
extern u8g_dev_t u8g_dev_st7565_dogm128_hw_spi;
/* Display: Topway LM6063 128x64 */
extern u8g_dev_t u8g_dev_st7565_lm6063_sw_spi;
extern u8g_dev_t u8g_dev_st7565_lm6063_hw_spi;
/* Display: Topway LM6059 128x64 (Adafruit) */
extern u8g_dev_t u8g_dev_st7565_lm6059_sw_spi;
extern u8g_dev_t u8g_dev_st7565_lm6059_hw_spi;

/* dfrobot 128x64 Graphic LCD (SKU:FIT0021) */
extern u8g_dev_t u8g_dev_st7920_128x64_sw_spi;
extern u8g_dev_t u8g_dev_st7920_128x64_8bit;

/* NHD-19232WG */
extern u8g_dev_t u8g_dev_st7920_192x32_sw_spi;
extern u8g_dev_t u8g_dev_st7920_192x32_8bit;

/* LC7981 160x80 display*/
extern u8g_dev_t u8g_dev_lc7981_160x80_8bit;
/* LC7981 240x64 display*/
extern u8g_dev_t u8g_dev_lc7981_240x64_8bit;

/* Display: EA DOGXL160, Size: 160x104 monochrom & gray level */
extern u8g_dev_t u8g_dev_uc1610_dogxl160_bw_sw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_bw_hw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_gr_sw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_gr_hw_spi;

extern u8g_dev_t u8g_dev_uc1610_dogxl160_2x_bw_sw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_2x_bw_hw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_2x_gr_sw_spi;
extern u8g_dev_t u8g_dev_uc1610_dogxl160_2x_gr_hw_spi;

/* Display: Generic KS0108b, Size: 128x64 monochrom */
extern u8g_dev_t u8g_dev_ks0108_128x64;         /* official Arduino Library interface */
extern u8g_dev_t u8g_dev_ks0108_128x64_fast;    /* faster, but uses private tables from the Arduino Library */

/* Nokia 84x48 Display with PCD8544 */
extern u8g_dev_t u8g_dev_pcd8544_84x48_sw_spi;

/* Nokia 96x65 Display with PCF8812 */
extern u8g_dev_t u8g_dev_pcf8812_96x65_sw_spi;

/* NHD-2.7-12864UCY3 OLED Display with SSD1325 Controller */
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_bw_sw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_bw_hw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_bw_parallel;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_gr_sw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_gr_hw_spi;

extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_2x_bw_sw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_2x_bw_hw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_2x_bw_parallel;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_2x_gr_sw_spi;
extern u8g_dev_t u8g_dev_ssd1325_nhd27oled_2x_gr_hw_spi;

/* LY120 OLED with SSD1327 Controller (tested with Seeedstudio module) */
extern u8g_dev_t u8g_dev_ssd1327_96x96_gr_sw_spi;
extern u8g_dev_t u8g_dev_ssd1327_96x96_gr_hw_spi;
extern u8g_dev_t u8g_dev_ssd1327_96x96_gr_i2c;

extern u8g_dev_t u8g_dev_ssd1327_96x96_2x_gr_sw_spi;
extern u8g_dev_t u8g_dev_ssd1327_96x96_2x_gr_hw_spi;
extern u8g_dev_t u8g_dev_ssd1327_96x96_2x_gr_i2c;

/* NHD-3.12-25664 OLED Display with SSD1322 Controller */
extern u8g_dev_t u8g_dev_ssd1322_nhd31oled_bw_sw_spi;
extern u8g_dev_t u8g_dev_ssd1322_nhd31oled_bw_hw_spi;
extern u8g_dev_t u8g_dev_ssd1322_nhd31oled_2x_bw_sw_spi;
extern u8g_dev_t u8g_dev_ssd1322_nhd31oled_2x_bw_hw_spi;

/* OLED 128x64 Display with SSD1306 Controller */
extern u8g_dev_t u8g_dev_ssd1306_128x64_sw_spi;
extern u8g_dev_t u8g_dev_ssd1306_128x64_hw_spi;

/* experimental 65K TFT with st7687 controller */
extern u8g_dev_t u8g_dev_st7687_c144mvgd_sw_spi;
extern u8g_dev_t u8g_dev_st7687_c144mvgd_8bit;

/* SBN1661/SED1520 display with 122x32 */
extern u8g_dev_t u8g_dev_sbn1661_122x32;

/* ILI9325D based TFT */
extern u8g_dev_t u8g_dev_ili9325d_320x240_8bit;

/*===============================================================*/
/* device messages */

struct _u8g_dev_arg_pixel_t
{
  u8g_uint_t x, y;              /* will be modified */
  uint8_t pixel;                  /* will be modified */
  uint8_t dir;
  uint8_t color;
};
typedef struct _u8g_dev_arg_pixel_t u8g_dev_arg_pixel_t;

struct _u8g_dev_arg_bbx_t
{
  u8g_uint_t x, y, w, h;
};
typedef struct _u8g_dev_arg_bbx_t u8g_dev_arg_bbx_t;

#define U8G_DEV_MSG_INIT                10
#define U8G_DEV_MSG_STOP                  11

/* arg: pointer to uint8_t, contranst value between 0 and 255 */
#define U8G_DEV_MSG_CONTRAST            15

#define U8G_DEV_MSG_PAGE_FIRST                  20
#define U8G_DEV_MSG_PAGE_NEXT                    21

/* arg: u8g_dev_arg_bbx_t * */
#define U8G_DEV_MSG_IS_BBX_INTERSECTION 22

/*
#define U8G_DEV_MSG_PRIMITIVE_START             30
#define U8G_DEV_MSG_PRIMITIVE_END               31
*/

/* arg: u8g_dev_arg_pixel_t * */
#define U8G_DEV_MSG_SET_PIXEL                           50
#define U8G_DEV_MSG_SET_8PIXEL                          59

#define U8G_DEV_MSG_SET_COLOR_INDEX                60

#define U8G_DEV_MSG_SET_XY_CB                           61

#define U8G_DEV_MSG_GET_WIDTH                           70
#define U8G_DEV_MSG_GET_HEIGHT                           71
#define U8G_DEV_MSG_GET_MODE                  72

/*===============================================================*/
/* device modes */
#define U8G_MODE(is_color, bits_per_pixel) (((is_color)<<4)|(bits_per_pixel))

#define U8G_MODE_UNKNOWN     0
#define U8G_MODE_BW     U8G_MODE(0, 1)
#define U8G_MODE_GRAY2BIT     U8G_MODE(0, 2)
#define U8G_MODE_R3G3B2  U8G_MODE(1, 8)

#define U8G_MODE_GET_BITS_PER_PIXEL(mode) ((mode)&15)
#define U8G_MODE_IS_COLOR(mode) (((mode)&16)==0?0:1)


/*===============================================================*/
/* com messages */

#define U8G_COM_MSG_STOP        0
#define U8G_COM_MSG_INIT        1

#define U8G_COM_MSG_ADDRESS 2

/* CHIP_SELECT argument: number of the chip which needs to be activated, so this is more like high active */
#define U8G_COM_MSG_CHIP_SELECT 3

#define U8G_COM_MSG_RESET 4

#define U8G_COM_MSG_WRITE_BYTE 5
#define U8G_COM_MSG_WRITE_SEQ 6
#define U8G_COM_MSG_WRITE_SEQ_P 7


/* com driver */
uint8_t u8g_com_null_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);               /* u8g_com_null.c */
uint8_t u8g_com_arduino_std_sw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);        /* u8g_com_arduino_std_sw_spi.c */
uint8_t u8g_com_arduino_sw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);        /* u8g_com_arduino_sw_spi.c */
uint8_t u8g_com_arduino_hw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);          /* u8g_com_arduino_hw_spi.c */
uint8_t u8g_com_arduino_st7920_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);  /* u8g_com_arduino_st7920_spi.c */
uint8_t u8g_com_arduino_parallel_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);           /* u8g_com_arduino_parallel.c */
uint8_t u8g_com_arduino_fast_parallel_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);      /* u8g_com_arduino_fast_parallel.c */
uint8_t u8g_com_arduino_port_d_wr_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);       /* u8g_com_arduino_port_d_wr.c */
uint8_t u8g_com_arduino_no_en_parallel_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);	/* u8g_com_arduino_no_en_parallel.c */		
uint8_t u8g_com_arduino_ssd_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);		/* u8g_com_arduino_ssd_i2c.c */


uint8_t u8g_com_atmega_hw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);      /* u8g_com_atmega_hw_spi.c */
uint8_t u8g_com_atmega_sw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);      /* u8g_com_atmega_sw_spi.c */
uint8_t u8g_com_atmega_parallel_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);    /* u8g_com_atmega_parallel.c */


/* 
  Translation of system specific com drives to generic com names
  At the moment, the following generic com drives are available
  U8G_COM_HW_SPI
  U8G_COM_SW_SPI
  U8G_COM_PARALLEL
  U8G_COM_FAST_PARALLEL
  U8G_COM_SSD_I2C
*/
#if defined(ARDUINO)
#define U8G_COM_HW_SPI u8g_com_arduino_hw_spi_fn
#endif
#ifndef U8G_COM_HW_SPI
#if defined(__AVR__)
#define U8G_COM_HW_SPI u8g_com_atmega_hw_spi_fn
#endif
#endif
#ifndef U8G_COM_HW_SPI
#define U8G_COM_HW_SPI u8g_com_null_fn
#endif

#if defined(ARDUINO)
#define U8G_COM_SW_SPI u8g_com_arduino_sw_spi_fn
#endif
#ifndef U8G_COM_SW_SPI
#if defined(__AVR__)
#define U8G_COM_SW_SPI u8g_com_atmega_sw_spi_fn
#endif
#endif
#ifndef U8G_COM_SW_SPI
#define U8G_COM_SW_SPI u8g_com_null_fn
#endif

#if defined(ARDUINO)
#define U8G_COM_PARALLEL u8g_com_arduino_parallel_fn
#define U8G_COM_FAST_PARALLEL u8g_com_arduino_fast_parallel_fn
#endif
#ifndef U8G_COM_PARALLEL
#if defined(__AVR__)
#define U8G_COM_PARALLEL u8g_com_atmega_parallel_fn
#define U8G_COM_FAST_PARALLEL u8g_com_atmega_parallel_fn
#endif
#endif
#ifndef U8G_COM_PARALLEL
#define U8G_COM_PARALLEL u8g_com_null_fn
#define U8G_COM_FAST_PARALLEL u8g_com_null_fn
#endif

#if defined(ARDUINO)
#define U8G_COM_SSD_I2C u8g_com_arduino_ssd_i2c_fn
#endif
#ifndef U8G_COM_SSD_I2C
#define U8G_COM_SSD_I2C u8g_com_null_fn
#endif



/*===============================================================*/
/* common init device structure */

/* device prototype */
typedef uint8_t (*u8g_dev_fnptr)(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* com prototype */
typedef uint8_t (*u8g_com_fnptr)(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);



struct _u8g_dev_t
{
  u8g_dev_fnptr dev_fn;         /* device procedure */
  void *dev_mem;                /* device memory */
  u8g_com_fnptr com_fn;         /* communication procedure */
};


/*===============================================================*/
/* com api */
uint8_t u8g_InitCom(u8g_t *u8g, u8g_dev_t *dev);
void u8g_StopCom(u8g_t *u8g, u8g_dev_t *dev);
void u8g_EnableCom(u8g_t *u8g, u8g_dev_t *dev);         /* obsolete */
void u8g_DisableCom(u8g_t *u8g, u8g_dev_t *dev);        /* obsolete */
void u8g_SetChipSelect(u8g_t *u8g, u8g_dev_t *dev, uint8_t cs);
void u8g_SetResetLow(u8g_t *u8g, u8g_dev_t *dev);
void u8g_SetResetHigh(u8g_t *u8g, u8g_dev_t *dev);
void u8g_SetAddress(u8g_t *u8g, u8g_dev_t *dev, uint8_t address);
uint8_t u8g_WriteByte(u8g_t *u8g, u8g_dev_t *dev, uint8_t val);
uint8_t u8g_WriteSequence(u8g_t *u8g, u8g_dev_t *dev, uint8_t cnt, uint8_t *seq);
uint8_t u8g_WriteSequenceP(u8g_t *u8g, u8g_dev_t *dev, uint8_t cnt, const uint8_t *seq);

#define U8G_ESC_DLY(x) 255, ((x) & 0x7f)
#define U8G_ESC_CS(x) 255, (0xd0 | ((x)&0x0f))
#define U8G_ESC_ADR(x) 255, (0xe0 | ((x)&0x0f))
#define U8G_ESC_RST(x) 255, (0xc0 | ((x)&0x0f))
#define U8G_ESC_END 255, 254
#define U8G_ESC_255 255, 255
//uint8_t u8g_WriteEscSeqP(u8g_t *u8g, u8g_dev_t *dev, u8g_pgm_uint8_t *esc_seq);
uint8_t u8g_WriteEscSeqP(u8g_t *u8g, u8g_dev_t *dev, const uint8_t *esc_seq);

/*===============================================================*/
/* u8g_arduino_common.c */
void u8g_com_arduino_digital_write(u8g_t *u8g, uint8_t pin_index, uint8_t value);
void u8g_com_arduino_assign_pin_output_high(u8g_t *u8g);

/*===============================================================*/
/* u8g_com_io.c */

/* create internal number from port and pin */
uint8_t u8g_Pin(uint8_t port, uint8_t bit);
#define PN(port,bit) u8g_Pin(port,bit)

/* low level procedures */
void u8g_SetPinOutput(uint8_t internal_pin_number);
void u8g_SetPinLevel(uint8_t internal_pin_number, uint8_t level);
void u8g_SetPinInput(uint8_t internal_pin_number);
uint8_t u8g_GetPinLevel(uint8_t internal_pin_number);

/* u8g level procedures, expect U8G_PI_xxx macro */
void u8g_SetPIOutput(u8g_t *u8g, uint8_t pi);
void u8g_SetPILevel(u8g_t *u8g, uint8_t pi, uint8_t level);


/*===============================================================*/
/* page */
struct _u8g_page_t
{
  u8g_uint_t page_height;
  u8g_uint_t total_height;
  u8g_uint_t page_y0;
  u8g_uint_t page_y1;
  uint8_t page;
};
typedef struct _u8g_page_t u8g_page_t;

void u8g_page_First(u8g_page_t *p) U8G_NOINLINE;                                                                                        /* u8g_page.c */
void u8g_page_Init(u8g_page_t *p, u8g_uint_t page_height, u8g_uint_t total_height ) U8G_NOINLINE;            /* u8g_page.c */
uint8_t u8g_page_Next(u8g_page_t *p) U8G_NOINLINE;                                                                                   /* u8g_page.c */

/*===============================================================*/
/* page buffer (pb) */

struct _u8g_pb_t
{
  u8g_page_t p;
  u8g_uint_t width;
  void *buf;
};
typedef struct _u8g_pb_t u8g_pb_t;


/* u8g_pb.c */
void u8g_pb_Clear(u8g_pb_t *b);
uint8_t u8g_pb_IsYIntersection(u8g_pb_t *pb, u8g_uint_t v0, u8g_uint_t v1);
uint8_t u8g_pb_IsXIntersection(u8g_pb_t *b, u8g_uint_t v0, u8g_uint_t v1);
uint8_t u8g_pb_IsIntersection(u8g_pb_t *pb, u8g_dev_arg_bbx_t *bbx);
uint8_t u8g_pb_Is8PixelVisible(u8g_pb_t *b, u8g_dev_arg_pixel_t *arg_pixel);
uint8_t u8g_pb_WriteBuffer(u8g_pb_t *b, u8g_t *u8g, u8g_dev_t *dev);

/*
  note on __attribute__ ((nocommon))
    AVR scripts often use  --gc-sections on the linker to remove unused section.
    This works fine for initialed data and text sections. In principle .bss is also
    handled, but the name##_pb definition is not removed. Reason is, that
    array definitions are placed in the COMMON section, by default
    The attribute "nocommon" removes this automatic assignment to the
    COMMON section and directly puts it into .bss. As a result, if more
    than one buffer is defined in one file, then it will be removed with --gc-sections

    .. not sure if Arduino IDE uses -fno-common... if yes, then the attribute is
    redundant.
*/
#define U8G_PB_DEV(name, width, height, page_height, dev_fn, com_fn) \
uint8_t name##_buf[width] U8G_NOCOMMON ; \
u8g_pb_t name##_pb = { {page_height, height, 0, 0, 0},  width, name##_buf}; \
u8g_dev_t name = { dev_fn, &name##_pb, com_fn }


void u8g_pb8v1_Init(u8g_pb_t *b, void *buf, u8g_uint_t width)   U8G_NOINLINE;
void u8g_pb8v1_Clear(u8g_pb_t *b) U8G_NOINLINE;

uint8_t u8g_pb8v1_IsYIntersection(u8g_pb_t *b, u8g_uint_t v0, u8g_uint_t v1);
uint8_t u8g_pb8v1_IsXIntersection(u8g_pb_t *b, u8g_uint_t v0, u8g_uint_t v1);
uint8_t u8g_pb8v1_WriteBuffer(u8g_pb_t *b, u8g_t *u8g, u8g_dev_t *dev);

uint8_t u8g_dev_pb8v1_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* u8g_pb16v1.c */
uint8_t u8g_dev_pb16v1_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* u8g_pb8v2.c */
uint8_t u8g_dev_pb8v2_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* u8g_pb16v2.c (double memory of pb8v2) */
uint8_t u8g_dev_pb16v2_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);


/* u8g_pb8h1.c */
uint8_t u8g_dev_pb8h1_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* u8g_pb8h1f.c */
uint8_t u8g_dev_pb8h1f_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

/* u8g_pb8h8.c */
uint8_t u8g_dev_pb8h8_base_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);


/*===============================================================*/
/* u8g_ll_api.c */

/* cursor draw callback */
typedef void (*u8g_draw_cursor_fn)(u8g_t *u8g);

/* vertical reference point calculation callback */
typedef u8g_uint_t (*u8g_font_calc_vref_fnptr)(u8g_t *u8g);

/* state backup and restore procedure */
typedef void (*u8g_state_cb)(uint8_t msg);


/* PI = Pin Index */

/* reset pin, usually optional */
#define U8G_PI_RESET 0

/* address / data or instruction */
#define U8G_PI_A0 1
#define U8G_PI_DI 1

/* chip select line */
#define U8G_PI_CS 2
#define U8G_PI_CS1 2
#define U8G_PI_CS2 3

/* enable / clock signal */
#define U8G_PI_EN 4
#define U8G_PI_CS_STATE 4
#define U8G_PI_SCK 4
#define U8G_PI_SCL 4


/* data pins, shared with SPI and I2C pins */
#define U8G_PI_D0 5
#define U8G_PI_MOSI 5
#define U8G_PI_SDA 5
#define U8G_PI_D1 6
#define U8G_PI_MISO 6
#define U8G_PI_D2 7
#define U8G_PI_A0_STATE 7
#define U8G_PI_D3 8
#define U8G_PI_D4 9
#define U8G_PI_D5 10
#define U8G_PI_I2C_OPTION 11
#define U8G_PI_D6 11
#define U8G_PI_D7 12

/* read/write pin, must be the last pin in the list, this means U8G_PIN_LIST_LEN =  U8G_PI_RW + 1*/
#define U8G_PI_RW 13 

#define U8G_PIN_LIST_LEN 14


#define U8G_PIN_NONE 255

#define U8G_FONT_HEIGHT_MODE_TEXT 0
#define U8G_FONT_HEIGHT_MODE_XTEXT 1
#define U8G_FONT_HEIGHT_MODE_ALL 2

struct _u8g_t
{
  u8g_uint_t width;
  u8g_uint_t height;
  
  
  u8g_dev_t *dev;               /* first device in the device chain */
  const u8g_pgm_uint8_t *font;             /* regular font for all text procedures */
  const u8g_pgm_uint8_t *cursor_font;  /* special font for cursor procedures */
  uint8_t cursor_fg_color, cursor_bg_color;
  uint8_t cursor_encoding;
  uint8_t mode;                         /* display mode, one of U8G_MODE_xxx */
  u8g_uint_t cursor_x;
  u8g_uint_t cursor_y;
  u8g_draw_cursor_fn cursor_fn;
  
  int8_t glyph_dx;
  int8_t glyph_x;
  int8_t glyph_y;
  uint8_t glyph_width;
  uint8_t glyph_height;
  
  u8g_font_calc_vref_fnptr font_calc_vref;
  uint8_t font_height_mode;
  int8_t font_ref_ascent;
  int8_t font_ref_descent;
  uint8_t font_line_spacing_factor;     /* line_spacing = factor * (ascent - descent) / 64 */
  uint8_t line_spacing;
  
  u8g_dev_arg_pixel_t arg_pixel;
  /* uint8_t color_index; */

  uint8_t pin_list[U8G_PIN_LIST_LEN];
  
  u8g_state_cb state_cb;
};

#define u8g_GetFontAscent(u8g) ((u8g)->font_ref_ascent)
#define u8g_GetFontDescent(u8g) ((u8g)->font_ref_descent)
#define u8g_GetFontLineSpacing(u8g) ((u8g)->line_spacing)

uint8_t u8g_call_dev_fn(u8g_t *u8g, u8g_dev_t *dev, uint8_t msg, void *arg);

uint8_t u8g_InitLL(u8g_t *u8g, u8g_dev_t *dev);
void u8g_FirstPageLL(u8g_t *u8g, u8g_dev_t *dev);
uint8_t u8g_NextPageLL(u8g_t *u8g, u8g_dev_t *dev);
uint8_t u8g_SetContrastLL(u8g_t *u8g, u8g_dev_t *dev, uint8_t contrast);
void u8g_DrawPixelLL(u8g_t *u8g, u8g_dev_t *dev, u8g_uint_t x, u8g_uint_t y);
void u8g_Draw8PixelLL(u8g_t *u8g, u8g_dev_t *dev, u8g_uint_t x, u8g_uint_t y, uint8_t dir, uint8_t pixel);
uint8_t u8g_IsBBXIntersectionLL(u8g_t *u8g, u8g_dev_t *dev, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h);
u8g_uint_t u8g_GetWidthLL(u8g_t *u8g, u8g_dev_t *dev);
u8g_uint_t u8g_GetHeightLL(u8g_t *u8g, u8g_dev_t *dev);

void u8g_UpdateDimension(u8g_t *u8g);
uint8_t u8g_Init(u8g_t *u8g, u8g_dev_t *dev);   /* only usefull if the device only as hardcoded ports */
uint8_t u8g_InitSPI(u8g_t *u8g, u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset);
uint8_t u8g_InitHWSPI(u8g_t *u8g, u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset);
uint8_t u8g_InitI2C(u8g_t *u8g, u8g_dev_t *dev, uint8_t options);	/* use U8G_I2C_OPT_NONE as options */
uint8_t u8g_Init8BitFixedPort(u8g_t *u8g, u8g_dev_t *dev, uint8_t en, uint8_t cs, uint8_t di, uint8_t rw, uint8_t reset);
uint8_t u8g_Init8Bit(u8g_t *u8g, u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, 
  uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw, uint8_t reset);
void u8g_FirstPage(u8g_t *u8g);
uint8_t u8g_NextPage(u8g_t *u8g);
uint8_t u8g_SetContrast(u8g_t *u8g, uint8_t contrast);
void u8g_DrawPixel(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y);
void u8g_Draw8Pixel(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t dir, uint8_t pixel);
uint8_t u8g_IsBBXIntersection(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h);

uint8_t u8g_Stop(u8g_t *u8g);
void u8g_SetColorIndex(u8g_t *u8g, uint8_t idx);
uint8_t u8g_GetColorIndex(u8g_t *u8g);

uint8_t u8g_GetDefaultForegroundColor(u8g_t *u8g);
void u8g_SetDefaultForegroundColor(u8g_t *u8g);

uint8_t u8g_GetDefaultBackgroundColor(u8g_t *u8g);
void u8g_SetDefaultBackgroundColor(u8g_t *u8g);

uint8_t u8g_GetDefaultMidColor(u8g_t *u8g);
void u8g_SetDefaultMidColor(u8g_t *u8g);

#define u8g_GetWidth(u8g) ((u8g)->width)
#define u8g_GetHeight(u8g) ((u8g)->height)
#define u8g_GetMode(u8g) ((u8g)->mode)
/*
  U8G_MODE_GET_BITS_PER_PIXEL(u8g_GetMode(u8g))
  U8G_MODE_IS_COLOR(u8g_GetMode(u8g)) 
*/

/* u8g_state.c */
#define U8G_STATE_ENV_IDX 0
#define U8G_STATE_U8G_IDX 1
#define U8G_STATE_RESTORE 0
#define U8G_STATE_BACKUP 1
#define U8G_STATE_MSG_COMPOSE(cmd,idx) (((cmd)<<1) | (idx))

#define U8G_STATE_MSG_RESTORE_ENV U8G_STATE_MSG_COMPOSE(U8G_STATE_RESTORE,U8G_STATE_ENV_IDX)
#define U8G_STATE_MSG_BACKUP_ENV U8G_STATE_MSG_COMPOSE(U8G_STATE_BACKUP,U8G_STATE_ENV_IDX)
#define U8G_STATE_MSG_RESTORE_U8G U8G_STATE_MSG_COMPOSE(U8G_STATE_RESTORE,U8G_STATE_U8G_IDX)
#define U8G_STATE_MSG_BACKUP_U8G U8G_STATE_MSG_COMPOSE(U8G_STATE_BACKUP,U8G_STATE_U8G_IDX)

#define U8G_STATE_MSG_GET_IDX(msg) ((msg)&1)
#define U8G_STATE_MSG_IS_BACKUP(msg) ((msg)&2)



void u8g_state_dummy_cb(uint8_t msg);
void u8g_backup_avr_spi(uint8_t msg);		/* backup SPI state on atmel avr controller */

void u8g_SetHardwareBackup(u8g_t *u8g, u8g_state_cb backup_cb);


/* u8g_dev_rot.c */

void u8g_UndoRotation(u8g_t *u8g);
void u8g_SetRot90(u8g_t *u8g);
void u8g_SetRot180(u8g_t *u8g);
void u8g_SetRot270(u8g_t *u8g);


/* u8g_font.c */

size_t u8g_font_GetSize(const void *font);
uint8_t u8g_font_GetFontStartEncoding(const void *font) U8G_NOINLINE;
uint8_t u8g_font_GetFontEndEncoding(const void *font) U8G_NOINLINE;

void u8g_SetFont(u8g_t *u8g, const u8g_fntpgm_uint8_t *font);

uint8_t u8g_GetFontBBXWidth(u8g_t *u8g);
uint8_t u8g_GetFontBBXHeight(u8g_t *u8g);
int8_t u8g_GetFontBBXOffX(u8g_t *u8g);
int8_t u8g_GetFontBBXOffY(u8g_t *u8g);
uint8_t u8g_GetFontCapitalAHeight(u8g_t *u8g);

uint8_t u8g_IsGlyph(u8g_t *u8g, uint8_t requested_encoding);
int8_t u8g_GetGlyphDeltaX(u8g_t *u8g, uint8_t requested_encoding);


int8_t u8g_DrawGlyphDir(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t dir, uint8_t encoding);
int8_t u8g_DrawGlyph(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t encoding);
int8_t u8g_DrawGlyph90(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t encoding);
int8_t u8g_DrawGlyph180(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t encoding);
int8_t u8g_DrawGlyph270(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t encoding);
int8_t u8g_DrawGlyphFontBBX(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t dir, uint8_t encoding);

u8g_uint_t u8g_DrawStr(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const char *s);
u8g_uint_t u8g_DrawStr90(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const char *s);
u8g_uint_t u8g_DrawStr180(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const char *s);
u8g_uint_t u8g_DrawStr270(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const char *s);

u8g_uint_t u8g_DrawStrDir(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t dir, const char *s);


u8g_uint_t u8g_DrawStrP(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const u8g_pgm_uint8_t *s);
u8g_uint_t u8g_DrawStr90P(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const u8g_pgm_uint8_t *s);
u8g_uint_t u8g_DrawStr180P(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const u8g_pgm_uint8_t *s);
u8g_uint_t u8g_DrawStr270P(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const u8g_pgm_uint8_t *s);


void u8g_SetFontRefHeightText(u8g_t *u8g);
void u8g_SetFontRefHeightExtendedText(u8g_t *u8g);
void u8g_SetFontRefHeightAll(u8g_t *u8g);
void u8g_SetFontLineSpacingFactor(u8g_t *u8g, uint8_t factor);

u8g_uint_t u8g_font_calc_vref_font(u8g_t *u8g);
u8g_uint_t u8g_font_calc_vref_bottom(u8g_t *u8g);
u8g_uint_t u8g_font_calc_vref_top(u8g_t *u8g);
u8g_uint_t u8g_font_calc_vref_center(u8g_t *u8g);

void u8g_SetFontPosBaseline(u8g_t *u8g);
void u8g_SetFontPosBottom(u8g_t *u8g);
void u8g_SetFontPosCenter(u8g_t *u8g);
void u8g_SetFontPosTop(u8g_t *u8g);


u8g_uint_t u8g_GetStrPixelWidth(u8g_t *u8g, const char *s);
u8g_uint_t u8g_GetStrPixelWidthP(u8g_t *u8g, const u8g_pgm_uint8_t *s);
int8_t u8g_GetStrX(u8g_t *u8g, const char *s);
int8_t u8g_GetStrXP(u8g_t *u8g, const u8g_pgm_uint8_t *s);
u8g_uint_t u8g_GetStrWidth(u8g_t *u8g, const char *s);
u8g_uint_t u8g_GetStrWidthP(u8g_t *u8g, const u8g_pgm_uint8_t *s);


u8g_uint_t u8g_DrawStrFontBBX(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, uint8_t dir, const char *s);



void u8g_GetStrMinBox(u8g_t *u8g, const char *s, u8g_uint_t *x, u8g_uint_t *y, u8g_uint_t *width, u8g_uint_t *height);
void u8g_GetStrAMinBox(u8g_t *u8g, const char *s, u8g_uint_t *x, u8g_uint_t *y, u8g_uint_t *width, u8g_uint_t *height);

/* u8g_rect.c */

void u8g_DrawHLine(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w);
void u8g_DrawVLine(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w);
void u8g_DrawFrame(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h);
void u8g_DrawBox(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h);

/* u8g_bitmap.c */

void u8g_DrawHBitmap(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, const uint8_t *bitmap);
void u8g_DrawHBitmapP(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, const u8g_pgm_uint8_t *bitmap);
void u8g_DrawBitmap(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, u8g_uint_t h, const uint8_t *bitmap);
void u8g_DrawBitmapP(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t cnt, u8g_uint_t h, const u8g_pgm_uint8_t *bitmap);

void u8g_DrawXBM(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h, const uint8_t *bitmap);
void u8g_DrawXBMP(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, u8g_uint_t w, u8g_uint_t h, const u8g_pgm_uint8_t *bitmap);


/* u8g_line.c */
void u8g_DrawLine(u8g_t *u8g, u8g_uint_t x1, u8g_uint_t y1, u8g_uint_t x2, u8g_uint_t y2);


/* u8g_circle.c */

/* the following, commented code has been rewritten or is not yet finished
#define U8G_CIRC_UPPER_RIGHT 0x01
#define U8G_CIRC_UPPER_LEFT  0x02
#define U8G_CIRC_LOWER_LEFT 0x04
#define U8G_CIRC_LOWER_RIGHT  0x08
#define U8G_CIRC_ALL (U8G_CIRC_UPPER_RIGHT|U8G_CIRC_UPPER_LEFT|U8G_CIRC_LOWER_RIGHT|U8G_CIRC_LOWER_LEFT)
void u8g_DrawEmpCirc(u8g_t *u8g, u8g_uint_t x0, u8g_uint_t y0, u8g_uint_t rad, uint8_t option);
void u8g_DrawFillCirc(u8g_t *u8g, u8g_uint_t x0, u8g_uint_t y0, u8g_uint_t rad, uint8_t option);
void u8g_DrawEllipseRect(u8g_t *u8g, u8g_uint_t x0, u8g_uint_t y0, u8g_uint_t x1, u8g_uint_t y1);
*/

#define U8G_DRAW_UPPER_RIGHT 0x01
#define U8G_DRAW_UPPER_LEFT  0x02
#define U8G_DRAW_LOWER_LEFT 0x04
#define U8G_DRAW_LOWER_RIGHT  0x08
#define U8G_DRAW_ALL (U8G_DRAW_UPPER_RIGHT|U8G_DRAW_UPPER_LEFT|U8G_DRAW_LOWER_RIGHT|U8G_DRAW_LOWER_LEFT)

void u8g_DrawCircle(u8g_t *u8g, u8g_uint_t x0, u8g_uint_t y0, u8g_uint_t rad, uint8_t option);
void u8g_DrawDisc(u8g_t *u8g, u8g_uint_t x0, u8g_uint_t y0, u8g_uint_t rad, uint8_t option);



/* u8g_cursor.c */
void u8g_SetCursorFont(u8g_t *u8g, const u8g_pgm_uint8_t *cursor_font);
void u8g_SetCursorStyle(u8g_t *u8g, uint8_t encoding);
void u8g_SetCursorPos(u8g_t *u8g, u8g_uint_t cursor_x, u8g_uint_t cursor_y);
void u8g_SetCursorColor(u8g_t *u8g, uint8_t fg, uint8_t bg);
void u8g_EnableCursor(u8g_t *u8g);
void u8g_DisableCursor(u8g_t *u8g);
void u8g_DrawCursor(u8g_t *u8g);



/*===============================================================*/
void st_Draw(uint8_t fps);
void st_Step(uint8_t player_pos, uint8_t is_auto_fire, uint8_t is_fire);

/*===============================================================*/
/* u8g_com_i2c.c */

/* options for u8g_i2c_init() */
#define U8G_I2C_OPT_NONE 0

/* retrun values from u8g_twi_get_error() */
#define U8G_I2C_ERR_NONE 0x00
/* the following values are bit masks */
#define U8G_I2C_ERR_TIMEOUT 0x01
#define U8G_I2C_ERR_BUS 0x02

void u8g_i2c_clear_error(void) U8G_NOINLINE;
uint8_t  u8g_i2c_get_error(void) U8G_NOINLINE;
uint8_t u8g_i2c_get_err_pos(void) U8G_NOINLINE;
void u8g_i2c_init(uint8_t options) U8G_NOINLINE;		/* use U8G_I2C_OPT_NONE as options */
uint8_t u8g_i2c_wait(uint8_t mask, uint8_t pos) U8G_NOINLINE;
uint8_t u8g_i2c_start(uint8_t sla) U8G_NOINLINE;
uint8_t u8g_i2c_send_byte(uint8_t data) U8G_NOINLINE;
void u8g_i2c_stop(void) U8G_NOINLINE;


/*===============================================================*/
/* u8g_u8toa.c */

/* v = value, d = number of digits */
const char *u8g_u8toa(uint8_t v, uint8_t d);

/*===============================================================*/
/* u8g_delay.c */

/* delay by the specified number of milliseconds */
void u8g_Delay(uint16_t val);

/*===============================================================*/
/* chessengine.c */
#define CHESS_KEY_NONE 0
#define CHESS_KEY_NEXT 1
#define CHESS_KEY_PREV 2
#define CHESS_KEY_SELECT 3
#define CHESS_KEY_BACK 4

void chess_Init(u8g_t *u8g, uint8_t empty_body_color);
void chess_Draw(void);
void chess_Step(uint8_t keycode);

/*===============================================================*/
/* font definitions */

extern const u8g_fntpgm_uint8_t u8g_font_m2icon_5[] U8G_SECTION(".progmem.u8g_font_m2icon_5");
extern const u8g_fntpgm_uint8_t u8g_font_m2icon_7[] U8G_SECTION(".progmem.u8g_font_m2icon_7");
extern const u8g_fntpgm_uint8_t u8g_font_m2icon_9[] U8G_SECTION(".progmem.u8g_font_m2icon_9");


extern const u8g_fntpgm_uint8_t u8g_font_6x12_75r[] U8G_SECTION(".progmem.u8g_font_6x12_75r");
extern const u8g_fntpgm_uint8_t u8g_font_6x13_75r[] U8G_SECTION(".progmem.u8g_font_6x13_75r");
extern const u8g_fntpgm_uint8_t u8g_font_7x13_75r[] U8G_SECTION(".progmem.u8g_font_7x13_75r");
extern const u8g_fntpgm_uint8_t u8g_font_8x13_75r[] U8G_SECTION(".progmem.u8g_font_8x13_75r");
extern const u8g_fntpgm_uint8_t u8g_font_9x15_75r[] U8G_SECTION(".progmem.u8g_font_9x15_75r");
extern const u8g_fntpgm_uint8_t u8g_font_9x18_75r[] U8G_SECTION(".progmem.u8g_font_9x18_75r");
extern const u8g_fntpgm_uint8_t u8g_font_cu12_75r[] U8G_SECTION(".progmem.u8g_font_cu12_75r");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_75r[] U8G_SECTION(".progmem.u8g_font_unifont_75r");
extern const u8g_fntpgm_uint8_t u8g_font_10x20_75r[] U8G_SECTION(".progmem.u8g_font_10x20_75r");

extern const u8g_fntpgm_uint8_t u8g_font_10x20_67_75[] U8G_SECTION(".progmem.u8g_font_10x20_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_10x20_78_79[] U8G_SECTION(".progmem.u8g_font_10x20_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_10x20[] U8G_SECTION(".progmem.u8g_font_10x20");
extern const u8g_fntpgm_uint8_t u8g_font_10x20r[] U8G_SECTION(".progmem.u8g_font_10x20r");
extern const u8g_fntpgm_uint8_t u8g_font_4x6[] U8G_SECTION(".progmem.u8g_font_4x6");
extern const u8g_fntpgm_uint8_t u8g_font_4x6r[] U8G_SECTION(".progmem.u8g_font_4x6r");
//extern const u8g_fntpgm_uint8_t u8g_font_4x6n[] U8G_SECTION(".progmem.u8g_font_4x6n");
extern const u8g_fntpgm_uint8_t u8g_font_5x7[] U8G_SECTION(".progmem.u8g_font_5x7");
extern const u8g_fntpgm_uint8_t u8g_font_5x7r[] U8G_SECTION(".progmem.u8g_font_5x7r");
extern const u8g_fntpgm_uint8_t u8g_font_5x8[] U8G_SECTION(".progmem.u8g_font_5x8");
extern const u8g_fntpgm_uint8_t u8g_font_5x8r[] U8G_SECTION(".progmem.u8g_font_5x8r");
extern const u8g_fntpgm_uint8_t u8g_font_6x10[] U8G_SECTION(".progmem.u8g_font_6x10");
extern const u8g_fntpgm_uint8_t u8g_font_6x10r[] U8G_SECTION(".progmem.u8g_font_6x10r");
extern const u8g_fntpgm_uint8_t u8g_font_6x12_67_75[] U8G_SECTION(".progmem.u8g_font_6x12_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_6x12_78_79[] U8G_SECTION(".progmem.u8g_font_6x12_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_6x12[] U8G_SECTION(".progmem.u8g_font_6x12");
extern const u8g_fntpgm_uint8_t u8g_font_6x12r[] U8G_SECTION(".progmem.u8g_font_6x12r");
extern const u8g_fntpgm_uint8_t u8g_font_6x13_67_75[] U8G_SECTION(".progmem.u8g_font_6x13_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_6x13_78_79[] U8G_SECTION(".progmem.u8g_font_6x13_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_6x13B[] U8G_SECTION(".progmem.u8g_font_6x13B");
extern const u8g_fntpgm_uint8_t u8g_font_6x13Br[] U8G_SECTION(".progmem.u8g_font_6x13Br");
extern const u8g_fntpgm_uint8_t u8g_font_6x13[] U8G_SECTION(".progmem.u8g_font_6x13");
extern const u8g_fntpgm_uint8_t u8g_font_6x13r[] U8G_SECTION(".progmem.u8g_font_6x13r");
extern const u8g_fntpgm_uint8_t u8g_font_6x13O[] U8G_SECTION(".progmem.u8g_font_6x13O");
extern const u8g_fntpgm_uint8_t u8g_font_6x13Or[] U8G_SECTION(".progmem.u8g_font_6x13Or");
extern const u8g_fntpgm_uint8_t u8g_font_7x13_67_75[] U8G_SECTION(".progmem.u8g_font_7x13_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_7x13_78_79[] U8G_SECTION(".progmem.u8g_font_7x13_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_7x13B[] U8G_SECTION(".progmem.u8g_font_7x13B");
extern const u8g_fntpgm_uint8_t u8g_font_7x13Br[] U8G_SECTION(".progmem.u8g_font_7x13Br");
extern const u8g_fntpgm_uint8_t u8g_font_7x13[] U8G_SECTION(".progmem.u8g_font_7x13");
extern const u8g_fntpgm_uint8_t u8g_font_7x13r[] U8G_SECTION(".progmem.u8g_font_7x13r");
extern const u8g_fntpgm_uint8_t u8g_font_7x13O[] U8G_SECTION(".progmem.u8g_font_7x13O");
extern const u8g_fntpgm_uint8_t u8g_font_7x13Or[] U8G_SECTION(".progmem.u8g_font_7x13Or");
extern const u8g_fntpgm_uint8_t u8g_font_7x14B[] U8G_SECTION(".progmem.u8g_font_7x14B");
extern const u8g_fntpgm_uint8_t u8g_font_7x14Br[] U8G_SECTION(".progmem.u8g_font_7x14Br");
extern const u8g_fntpgm_uint8_t u8g_font_7x14[] U8G_SECTION(".progmem.u8g_font_7x14");
extern const u8g_fntpgm_uint8_t u8g_font_7x14r[] U8G_SECTION(".progmem.u8g_font_7x14r");
extern const u8g_fntpgm_uint8_t u8g_font_8x13_67_75[] U8G_SECTION(".progmem.u8g_font_8x13_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_8x13B[] U8G_SECTION(".progmem.u8g_font_8x13B");
extern const u8g_fntpgm_uint8_t u8g_font_8x13Br[] U8G_SECTION(".progmem.u8g_font_8x13Br");
extern const u8g_fntpgm_uint8_t u8g_font_8x13[] U8G_SECTION(".progmem.u8g_font_8x13");
extern const u8g_fntpgm_uint8_t u8g_font_8x13r[] U8G_SECTION(".progmem.u8g_font_8x13r");
extern const u8g_fntpgm_uint8_t u8g_font_8x13O[] U8G_SECTION(".progmem.u8g_font_8x13O");
extern const u8g_fntpgm_uint8_t u8g_font_8x13Or[] U8G_SECTION(".progmem.u8g_font_8x13Or");

extern const u8g_fntpgm_uint8_t u8g_font_9x15_67_75[] U8G_SECTION(".progmem.u8g_font_9x15_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_9x15_78_79[] U8G_SECTION(".progmem.u8g_font_9x15_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_9x15B[] U8G_SECTION(".progmem.u8g_font_9x15B");
extern const u8g_fntpgm_uint8_t u8g_font_9x15Br[] U8G_SECTION(".progmem.u8g_font_9x15Br");
extern const u8g_fntpgm_uint8_t u8g_font_9x15[] U8G_SECTION(".progmem.u8g_font_9x15");
extern const u8g_fntpgm_uint8_t u8g_font_9x15r[] U8G_SECTION(".progmem.u8g_font_9x15r");

extern const u8g_fntpgm_uint8_t u8g_font_9x18_67_75[] U8G_SECTION(".progmem.u8g_font_9x18_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_9x18_78_79[] U8G_SECTION(".progmem.u8g_font_9x18_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_9x18B[] U8G_SECTION(".progmem.u8g_font_9x18B");
extern const u8g_fntpgm_uint8_t u8g_font_9x18[] U8G_SECTION(".progmem.u8g_font_9x18");
extern const u8g_fntpgm_uint8_t u8g_font_9x18Br[] U8G_SECTION(".progmem.u8g_font_9x18Br");
extern const u8g_fntpgm_uint8_t u8g_font_9x18r[] U8G_SECTION(".progmem.u8g_font_9x18r");

extern const u8g_fntpgm_uint8_t u8g_font_cursor[] U8G_SECTION(".progmem.u8g_font_cursor");
extern const u8g_fntpgm_uint8_t u8g_font_cursorr[] U8G_SECTION(".progmem.u8g_font_cursorr");
extern const u8g_fntpgm_uint8_t u8g_font_micro[] U8G_SECTION(".progmem.u8g_font_micro");

extern const u8g_fntpgm_uint8_t u8g_font_cu12_67_75[] U8G_SECTION(".progmem.u8g_font_cu12_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_cu12_78_79[] U8G_SECTION(".progmem.u8g_font_cu12_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_cu12[] U8G_SECTION(".progmem.u8g_font_cu12");

/* 
  Free-Universal Bold 
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_fub11[] U8G_SECTION(".progmem.u8g_font_fub11");
extern const u8g_fntpgm_uint8_t u8g_font_fub11r[] U8G_SECTION(".progmem.u8g_font_fub11r");
extern const u8g_fntpgm_uint8_t u8g_font_fub11n[] U8G_SECTION(".progmem.u8g_font_fub11n");
extern const u8g_fntpgm_uint8_t u8g_font_fub14[] U8G_SECTION(".progmem.u8g_font_fub14");
extern const u8g_fntpgm_uint8_t u8g_font_fub14r[] U8G_SECTION(".progmem.u8g_font_fub14r");
extern const u8g_fntpgm_uint8_t u8g_font_fub14n[] U8G_SECTION(".progmem.u8g_font_fub14n");
extern const u8g_fntpgm_uint8_t u8g_font_fub17[] U8G_SECTION(".progmem.u8g_font_fub17");
extern const u8g_fntpgm_uint8_t u8g_font_fub17r[] U8G_SECTION(".progmem.u8g_font_fub17r");
extern const u8g_fntpgm_uint8_t u8g_font_fub17n[] U8G_SECTION(".progmem.u8g_font_fub17n");
extern const u8g_fntpgm_uint8_t u8g_font_fub20[] U8G_SECTION(".progmem.u8g_font_fub20");
extern const u8g_fntpgm_uint8_t u8g_font_fub20r[] U8G_SECTION(".progmem.u8g_font_fub20r");
extern const u8g_fntpgm_uint8_t u8g_font_fub20n[] U8G_SECTION(".progmem.u8g_font_fub20n");
extern const u8g_fntpgm_uint8_t u8g_font_fub25[] U8G_SECTION(".progmem.u8g_font_fub25");
extern const u8g_fntpgm_uint8_t u8g_font_fub25r[] U8G_SECTION(".progmem.u8g_font_fub25r");
extern const u8g_fntpgm_uint8_t u8g_font_fub25n[] U8G_SECTION(".progmem.u8g_font_fub25n");
extern const u8g_fntpgm_uint8_t u8g_font_fub30[] U8G_SECTION(".progmem.u8g_font_fub30");
extern const u8g_fntpgm_uint8_t u8g_font_fub30r[] U8G_SECTION(".progmem.u8g_font_fub30r");
extern const u8g_fntpgm_uint8_t u8g_font_fub30n[] U8G_SECTION(".progmem.u8g_font_fub30n");
extern const u8g_fntpgm_uint8_t u8g_font_fub35n[] U8G_SECTION(".progmem.u8g_font_fub35n");
extern const u8g_fntpgm_uint8_t u8g_font_fub42n[] U8G_SECTION(".progmem.u8g_font_fub42n");
extern const u8g_fntpgm_uint8_t u8g_font_fub49n[] U8G_SECTION(".progmem.u8g_font_fub49n");

/* 
  Free-Universal Regular
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_fur11[] U8G_SECTION(".progmem.u8g_font_fur11");
extern const u8g_fntpgm_uint8_t u8g_font_fur11r[] U8G_SECTION(".progmem.u8g_font_fur11r");
extern const u8g_fntpgm_uint8_t u8g_font_fur11n[] U8G_SECTION(".progmem.u8g_font_fur11n");
extern const u8g_fntpgm_uint8_t u8g_font_fur14[] U8G_SECTION(".progmem.u8g_font_fur14");
extern const u8g_fntpgm_uint8_t u8g_font_fur14r[] U8G_SECTION(".progmem.u8g_font_fur14r");
extern const u8g_fntpgm_uint8_t u8g_font_fur14n[] U8G_SECTION(".progmem.u8g_font_fur14n");
extern const u8g_fntpgm_uint8_t u8g_font_fur17[] U8G_SECTION(".progmem.u8g_font_fur17");
extern const u8g_fntpgm_uint8_t u8g_font_fur17r[] U8G_SECTION(".progmem.u8g_font_fur17r");
extern const u8g_fntpgm_uint8_t u8g_font_fur17n[] U8G_SECTION(".progmem.u8g_font_fur17n");
extern const u8g_fntpgm_uint8_t u8g_font_fur20[] U8G_SECTION(".progmem.u8g_font_fur20");
extern const u8g_fntpgm_uint8_t u8g_font_fur20r[] U8G_SECTION(".progmem.u8g_font_fur20r");
extern const u8g_fntpgm_uint8_t u8g_font_fur20n[] U8G_SECTION(".progmem.u8g_font_fur20n");
extern const u8g_fntpgm_uint8_t u8g_font_fur25[] U8G_SECTION(".progmem.u8g_font_fur25");
extern const u8g_fntpgm_uint8_t u8g_font_fur25r[] U8G_SECTION(".progmem.u8g_font_fur25r");
extern const u8g_fntpgm_uint8_t u8g_font_fur25n[] U8G_SECTION(".progmem.u8g_font_fur25n");
extern const u8g_fntpgm_uint8_t u8g_font_fur30[] U8G_SECTION(".progmem.u8g_font_fur30");
extern const u8g_fntpgm_uint8_t u8g_font_fur30r[] U8G_SECTION(".progmem.u8g_font_fur30r");
extern const u8g_fntpgm_uint8_t u8g_font_fur30n[] U8G_SECTION(".progmem.u8g_font_fur30n");
extern const u8g_fntpgm_uint8_t u8g_font_fur35n[] U8G_SECTION(".progmem.u8g_font_fur35n");
extern const u8g_fntpgm_uint8_t u8g_font_fur42n[] U8G_SECTION(".progmem.u8g_font_fur42n");
extern const u8g_fntpgm_uint8_t u8g_font_fur49n[] U8G_SECTION(".progmem.u8g_font_fur49n");

/* 
  Gentium Bold
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_gdb11[] U8G_SECTION(".progmem.u8g_font_gdb11");
extern const u8g_fntpgm_uint8_t u8g_font_gdb12[] U8G_SECTION(".progmem.u8g_font_gdb12");
extern const u8g_fntpgm_uint8_t u8g_font_gdb14[] U8G_SECTION(".progmem.u8g_font_gdb14");
extern const u8g_fntpgm_uint8_t u8g_font_gdb17[] U8G_SECTION(".progmem.u8g_font_gdb17");
extern const u8g_fntpgm_uint8_t u8g_font_gdb20[] U8G_SECTION(".progmem.u8g_font_gdb20");
extern const u8g_fntpgm_uint8_t u8g_font_gdb25[] U8G_SECTION(".progmem.u8g_font_gdb25");
extern const u8g_fntpgm_uint8_t u8g_font_gdb30[] U8G_SECTION(".progmem.u8g_font_gdb30");

extern const u8g_fntpgm_uint8_t u8g_font_gdb11r[] U8G_SECTION(".progmem.u8g_font_gdb11r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb12r[] U8G_SECTION(".progmem.u8g_font_gdb12r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb14r[] U8G_SECTION(".progmem.u8g_font_gdb14r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb17r[] U8G_SECTION(".progmem.u8g_font_gdb17r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb20r[] U8G_SECTION(".progmem.u8g_font_gdb20r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb25r[] U8G_SECTION(".progmem.u8g_font_gdb25r");
extern const u8g_fntpgm_uint8_t u8g_font_gdb30r[] U8G_SECTION(".progmem.u8g_font_gdb30r");

extern const u8g_fntpgm_uint8_t u8g_font_gdb11n[] U8G_SECTION(".progmem.u8g_font_gdb11n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb12n[] U8G_SECTION(".progmem.u8g_font_gdb12n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb14n[] U8G_SECTION(".progmem.u8g_font_gdb14n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb17n[] U8G_SECTION(".progmem.u8g_font_gdb17n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb20n[] U8G_SECTION(".progmem.u8g_font_gdb20n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb25n[] U8G_SECTION(".progmem.u8g_font_gdb25n");
extern const u8g_fntpgm_uint8_t u8g_font_gdb30n[] U8G_SECTION(".progmem.u8g_font_gdb30n");

/* 
  Gentium Regular
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_gdr9[] U8G_SECTION(".progmem.u8g_font_gdr9");
extern const u8g_fntpgm_uint8_t u8g_font_gdr10[] U8G_SECTION(".progmem.u8g_font_gdr10");
extern const u8g_fntpgm_uint8_t u8g_font_gdr11[] U8G_SECTION(".progmem.u8g_font_gdr11");
extern const u8g_fntpgm_uint8_t u8g_font_gdr12[] U8G_SECTION(".progmem.u8g_font_gdr12");
extern const u8g_fntpgm_uint8_t u8g_font_gdr14[] U8G_SECTION(".progmem.u8g_font_gdr14");
extern const u8g_fntpgm_uint8_t u8g_font_gdr17[] U8G_SECTION(".progmem.u8g_font_gdr17");
extern const u8g_fntpgm_uint8_t u8g_font_gdr20[] U8G_SECTION(".progmem.u8g_font_gdr20");
extern const u8g_fntpgm_uint8_t u8g_font_gdr25[] U8G_SECTION(".progmem.u8g_font_gdr25");
extern const u8g_fntpgm_uint8_t u8g_font_gdr30[] U8G_SECTION(".progmem.u8g_font_gdr30");

extern const u8g_fntpgm_uint8_t u8g_font_gdr9r[] U8G_SECTION(".progmem.u8g_font_gdr9r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr10r[] U8G_SECTION(".progmem.u8g_font_gdr10r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr11r[] U8G_SECTION(".progmem.u8g_font_gdr11r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr12r[] U8G_SECTION(".progmem.u8g_font_gdr12r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr14r[] U8G_SECTION(".progmem.u8g_font_gdr14r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr17r[] U8G_SECTION(".progmem.u8g_font_gdr17r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr20r[] U8G_SECTION(".progmem.u8g_font_gdr20r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr25r[] U8G_SECTION(".progmem.u8g_font_gdr25r");
extern const u8g_fntpgm_uint8_t u8g_font_gdr30r[] U8G_SECTION(".progmem.u8g_font_gdr30r");

extern const u8g_fntpgm_uint8_t u8g_font_gdr9n[] U8G_SECTION(".progmem.u8g_font_gdr9n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr10n[] U8G_SECTION(".progmem.u8g_font_gdr10n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr11n[] U8G_SECTION(".progmem.u8g_font_gdr11n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr12n[] U8G_SECTION(".progmem.u8g_font_gdr12n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr14n[] U8G_SECTION(".progmem.u8g_font_gdr14n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr17n[] U8G_SECTION(".progmem.u8g_font_gdr17n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr20n[] U8G_SECTION(".progmem.u8g_font_gdr20n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr25n[] U8G_SECTION(".progmem.u8g_font_gdr25n");
extern const u8g_fntpgm_uint8_t u8g_font_gdr30n[] U8G_SECTION(".progmem.u8g_font_gdr30n");

/* 
  Old-Standard Bold
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_osb18[] U8G_SECTION(".progmem.u8g_font_osb18");
extern const u8g_fntpgm_uint8_t u8g_font_osb21[] U8G_SECTION(".progmem.u8g_font_osb21");
extern const u8g_fntpgm_uint8_t u8g_font_osb26[] U8G_SECTION(".progmem.u8g_font_osb26");
extern const u8g_fntpgm_uint8_t u8g_font_osb29[] U8G_SECTION(".progmem.u8g_font_osb29");
extern const u8g_fntpgm_uint8_t u8g_font_osb35[] U8G_SECTION(".progmem.u8g_font_osb35");

extern const u8g_fntpgm_uint8_t u8g_font_osb18r[] U8G_SECTION(".progmem.u8g_font_osb18r");
extern const u8g_fntpgm_uint8_t u8g_font_osb21r[] U8G_SECTION(".progmem.u8g_font_osb21r");
extern const u8g_fntpgm_uint8_t u8g_font_osb26r[] U8G_SECTION(".progmem.u8g_font_osb26r");
extern const u8g_fntpgm_uint8_t u8g_font_osb29r[] U8G_SECTION(".progmem.u8g_font_osb29r");
extern const u8g_fntpgm_uint8_t u8g_font_osb35r[] U8G_SECTION(".progmem.u8g_font_osb35r");

extern const u8g_fntpgm_uint8_t u8g_font_osb18n[] U8G_SECTION(".progmem.u8g_font_osb18n");
extern const u8g_fntpgm_uint8_t u8g_font_osb21n[] U8G_SECTION(".progmem.u8g_font_osb21n");
extern const u8g_fntpgm_uint8_t u8g_font_osb26n[] U8G_SECTION(".progmem.u8g_font_osb26n");
extern const u8g_fntpgm_uint8_t u8g_font_osb29n[] U8G_SECTION(".progmem.u8g_font_osb29n");
extern const u8g_fntpgm_uint8_t u8g_font_osb35n[] U8G_SECTION(".progmem.u8g_font_osb35n");

/* 
  Old-Standard Regular
  r: Reduced char set (codes 32 - 128)
  n: Numbers (codes 42 - 57)
  no char: Full set (codes 32 - 255)
*/

extern const u8g_fntpgm_uint8_t u8g_font_osr18[] U8G_SECTION(".progmem.u8g_font_osr18");
extern const u8g_fntpgm_uint8_t u8g_font_osr21[] U8G_SECTION(".progmem.u8g_font_osr21");
extern const u8g_fntpgm_uint8_t u8g_font_osr26[] U8G_SECTION(".progmem.u8g_font_osr26");
extern const u8g_fntpgm_uint8_t u8g_font_osr29[] U8G_SECTION(".progmem.u8g_font_osr29");
extern const u8g_fntpgm_uint8_t u8g_font_osr35[] U8G_SECTION(".progmem.u8g_font_osr35");

extern const u8g_fntpgm_uint8_t u8g_font_osr18r[] U8G_SECTION(".progmem.u8g_font_osr18r");
extern const u8g_fntpgm_uint8_t u8g_font_osr21r[] U8G_SECTION(".progmem.u8g_font_osr21r");
extern const u8g_fntpgm_uint8_t u8g_font_osr26r[] U8G_SECTION(".progmem.u8g_font_osr26r");
extern const u8g_fntpgm_uint8_t u8g_font_osr29r[] U8G_SECTION(".progmem.u8g_font_osr29r");
extern const u8g_fntpgm_uint8_t u8g_font_osr35r[] U8G_SECTION(".progmem.u8g_font_osr35r");

extern const u8g_fntpgm_uint8_t u8g_font_osr18n[] U8G_SECTION(".progmem.u8g_font_osr18n");
extern const u8g_fntpgm_uint8_t u8g_font_osr21n[] U8G_SECTION(".progmem.u8g_font_osr21n");
extern const u8g_fntpgm_uint8_t u8g_font_osr26n[] U8G_SECTION(".progmem.u8g_font_osr26n");
extern const u8g_fntpgm_uint8_t u8g_font_osr29n[] U8G_SECTION(".progmem.u8g_font_osr29n");
extern const u8g_fntpgm_uint8_t u8g_font_osr35n[] U8G_SECTION(".progmem.u8g_font_osr35n");

//extern const u8g_fntpgm_uint8_t u8g_font_osr41[] U8G_SECTION(".progmem.u8g_font_osr41");

/* GNU unifont */

extern const u8g_fntpgm_uint8_t u8g_font_unifont_18_19[] U8G_SECTION(".progmem.u8g_font_unifont_18_19");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_72_73[] U8G_SECTION(".progmem.u8g_font_unifont_72_73");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_67_75[] U8G_SECTION(".progmem.u8g_font_unifont_67_75");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_76[] U8G_SECTION(".progmem.u8g_font_unifont_76");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_77[] U8G_SECTION(".progmem.u8g_font_unifont_77");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_78_79[] U8G_SECTION(".progmem.u8g_font_unifont_78_79");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_86[] U8G_SECTION(".progmem.u8g_font_unifont_86");
extern const u8g_fntpgm_uint8_t u8g_font_unifont[] U8G_SECTION(".progmem.u8g_font_unifont");
extern const u8g_fntpgm_uint8_t u8g_font_unifontr[] U8G_SECTION(".progmem.u8g_font_unifontr");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_0_8[] U8G_SECTION(".progmem.u8g_font_unifont_0_8");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_2_3[] U8G_SECTION(".progmem.u8g_font_unifont_2_3");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_4_5[] U8G_SECTION(".progmem.u8g_font_unifont_4_5");
extern const u8g_fntpgm_uint8_t u8g_font_unifont_8_9[] U8G_SECTION(".progmem.u8g_font_unifont_8_9");

/* 04b fonts */

extern const u8g_fntpgm_uint8_t u8g_font_04b_03b[] U8G_SECTION(".progmem.u8g_font_04b_03b"); 
extern const u8g_fntpgm_uint8_t u8g_font_04b_03bn[] U8G_SECTION(".progmem.u8g_font_04b_03bn");
extern const u8g_fntpgm_uint8_t u8g_font_04b_03br[] U8G_SECTION(".progmem.u8g_font_04b_03br");
extern const u8g_fntpgm_uint8_t u8g_font_04b_03[] U8G_SECTION(".progmem.u8g_font_04b_03");
extern const u8g_fntpgm_uint8_t u8g_font_04b_03n[] U8G_SECTION(".progmem.u8g_font_04b_03n");
extern const u8g_fntpgm_uint8_t u8g_font_04b_03r[] U8G_SECTION(".progmem.u8g_font_04b_03r");
extern const u8g_fntpgm_uint8_t u8g_font_04b_24[] U8G_SECTION(".progmem.u8g_font_04b_24");
extern const u8g_fntpgm_uint8_t u8g_font_04b_24n[] U8G_SECTION(".progmem.u8g_font_04b_24n");
extern const u8g_fntpgm_uint8_t u8g_font_04b_24r[] U8G_SECTION(".progmem.u8g_font_04b_24r");

/* orgdot fonts */

extern const u8g_fntpgm_uint8_t u8g_font_orgv01[] U8G_SECTION(".progmem.u8g_font_orgv01");
extern const u8g_fntpgm_uint8_t u8g_font_orgv01r[] U8G_SECTION(".progmem.u8g_font_orgv01r");
extern const u8g_fntpgm_uint8_t u8g_font_orgv01n[] U8G_SECTION(".progmem.u8g_font_orgv01n");

extern const u8g_fntpgm_uint8_t u8g_font_fixed_v0[] U8G_SECTION(".progmem.u8g_font_fixed_v0");
extern const u8g_fntpgm_uint8_t u8g_font_fixed_v0r[] U8G_SECTION(".progmem.u8g_font_fixed_v0r");
extern const u8g_fntpgm_uint8_t u8g_font_fixed_v0n[] U8G_SECTION(".progmem.u8g_font_fixed_v0n");

extern const u8g_fntpgm_uint8_t u8g_font_tpssb[] U8G_SECTION(".progmem.u8g_font_tpssb");
extern const u8g_fntpgm_uint8_t u8g_font_tpssbr[] U8G_SECTION(".progmem.u8g_font_tpssbr");
extern const u8g_fntpgm_uint8_t u8g_font_tpssbn[] U8G_SECTION(".progmem.u8g_font_tpssbn");

extern const u8g_fntpgm_uint8_t u8g_font_tpss[] U8G_SECTION(".progmem.u8g_font_tpss");
extern const u8g_fntpgm_uint8_t u8g_font_tpssr[] U8G_SECTION(".progmem.u8g_font_tpssr");
extern const u8g_fntpgm_uint8_t u8g_font_tpssn[] U8G_SECTION(".progmem.u8g_font_tpssn");

#ifdef __cplusplus
}
#endif

#endif /* _U8G_H */

