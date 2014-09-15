/* 
 * File:   maskingdefs.h
 * Author: s45504
 *
 * Created on September 14, 2014, 12:16 PM
 */

#ifndef MASKINGDEFS_H
#define	MASKINGDEFS_H

// A to D config bits

/*********** ADCON0 *************/
// VCFG1: Voltage Reference Configuration bit (VREF- source)
#define ADCON0_VREFG1_VREF 0b11111111
#define ADCON0_VREFG1_AVss 0b01111111

// VCFG0: Voltage Reference Configuration bit (VREF+ source)
#define ADCON0_VREFG0_VREF 0b11111111
#define ADCON0_VREFG0_ACdd 0b10111111

// CHS<3:0>: Analog Channel Select bits
#define ADCON0_CHNL_0                      0b11000011
#define ADCON0_CHNL_1                      0b11000111
#define ADCON0_CHNL_2                      0b11001011
#define ADCON0_CHNL_3                      0b11001111
#define ADCON0_CHNL_4                      0b11010011
#define ADCON0_CHNL_5                      0b11010111
#define ADCON0_CHNL_6                      0b11011011
#define ADCON0_CHNL_7                      0b11011111
#define ADCON0_CHNL_8                      0b11100011
#define ADCON0_CHNL_9                      0b11100111
#define ADCON0_CHNL_10                     0b11101011
#define ADCON0_CHNL_11                     0b11101111
#define ADCON0_CHNL_12                     0b11110011
#define ADCON0_CHNL_RESERVED               0b11110111
#define ADCON0_CHNL_VDDCORE                0b11111011
#define ADCON0_CHNL_VBG_ABSOLUTE_REFERENCE 0b11111111

// GO/DONE': A/D Conversion Status bit
#define ADCON0_GO   0b11111111
#define ADCON0_DONE 0b11111101

// ADON: A/D On bit
#define ADCON0_ON  0b11111111
#define ADCON0_OFF 0b11111110


/*********** ADCON1 *************/

// ADFM: A/D Result Format Select bit
#define ADCON1_JUSTIFY_RIGHT 0b11111111
#define ADCON1_JUSTIFY_LEFT  0b01111111

// ADCAL: A/D Calibration bit
#define ADCON1_CAL_NEXT        0b11111111 // Calibration is performed on next A/D conversion
#define ADCON1_JUSTIFY_NORMAL  0b10111111 // Normal A/D Converter operation

// ACQT<2:0>: A/D Acquisition Time Select bits
#define ADCON1_ACQ_TIME_20 0b11111111
#define ADCON1_ACQ_TIME_16 0b11110111
#define ADCON1_ACQ_TIME_12 0b11101111
#define ADCON1_ACQ_TIME_8  0b11100111
#define ADCON1_ACQ_TIME_6  0b11011111
#define ADCON1_ACQ_TIME_4  0b11010111
#define ADCON1_ACQ_TIME_2  0b11001111
#define ADCON1_ACQ_TIME_0  0b11000111

//ADCS<2:0>: A/D Conversion Clock Select bits
#define ADCON1_CLOCK_CONVERSRSION_64 0b11111110 // Fosc / 64
#define ADCON1_CLOCK_CONVERSRSION_16 0b11111101
#define ADCON1_CLOCK_CONVERSRSION_4  0b11111100
#define ADCON1_CLOCK_CONVERSRSION_RC 0b11111011 //(clock derived from A/D RC oscillator)
#define ADCON1_CLOCK_CONVERSRSION_32 0b11111010
#define ADCON1_CLOCK_CONVERSRSION_8  0b11111001
#define ADCON1_CLOCK_CONVERSRSION_2  0b11111000


#endif	/* MASKINGDEFS_H */

