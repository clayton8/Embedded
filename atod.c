#include "maindefs.h"
#include "atod.h"
#include "maskingdefs.h"
#include "messages.h"
#include "debug.h"


void init_ad()
{

    TRISAbits.TRISA0 = 1;

    // Interrupt bits
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.GIE = 1;

    ANCON0 = 0;
    ANCON1 = 0;

    // Set it to read from AN0 channel 00 and set the AD on with the last bit.
    ADCON0 = ADCON0_VREFG1_AVss & ADCON0_VREFG0_ACdd & ADCON0_CHNL_0 & ADCON0_DONE & ADCON0_ON;
    ADCON1 = ADCON1_JUSTIFY_RIGHT & ADCON1_JUSTIFY_NORMAL & ADCON1_ACQ_TIME_16 & ADCON1_CLOCK_CONVERSRSION_4;

}

void atod_converter_interrupt_handler()
{
    unsigned short int highReg;
    unsigned short int lowReg;
    unsigned short int adValue;
    // Get the High and low values from the A/D
    // Then convert that into inches and send it to the
    // Main queue.
    highReg = ADRESH << 8;
    lowReg = ADRESL;
    adValue = highReg | lowReg;
    adValue = (9462/(adValue - 16.92))*2;


    ToMainHigh_sendmsg(sizeof(adValue), MSGT_SENSOR_IR1, &adValue);

    DEBUG_FLIP(AD_GoDone);
}