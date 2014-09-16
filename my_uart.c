#include "maindefs.h"
#ifndef __XC8
#include <usart.h>
#else
#include <plib/usart.h>
#endif
#include "my_uart.h"

static uart_comm *uc_ptr;

void uart_recv_int_handler() {
#ifdef __USE18F26J50
    if (DataRdy1USART()) {
        uc_ptr->buffer[uc_ptr->buflen] = Read1USART();
#else
#ifdef __USE18F46J50
    if (DataRdy1USART()) {
        uc_ptr->buffer[uc_ptr->buflen] = Read1USART();
#else
    if (DataRdyUSART()) {
        uc_ptr->buffer[uc_ptr->buflen] = ReadUSART();
#endif
#endif

        uc_ptr->buflen++;
        // check if a message should be sent
        if (uc_ptr->buflen == 2) {
            unsigned char msgtype;
            unsigned char msgbuffer[MSGLEN + 1];
            signed char length = FromMainLow_recvmsg(MSGLEN, &msgtype, (void *) msgbuffer);
            uart_comm uart_trans;
            uart_trans.buffer[0] = msgbuffer[0];
            uart_trans.buffer[1] = msgbuffer[0];
            uart_trans.buflen = 2;
            uart_send(&uart_trans);
           // ToMainLow_sendmsg(uc_ptr->buflen, MSGT_UART_DATA, (void *) uc_ptr->buffer);
            uc_ptr->buflen = 0;
        }
    }
#ifdef __USE18F26J50
    if (USART1_Status.OVERRUN_ERROR == 1) {
#else
#ifdef __USE18F46J50
    if (USART1_Status.OVERRUN_ERROR == 1) {
#else
    if (USART_Status.OVERRUN_ERROR == 1) {
#endif
#endif
        // we've overrun the USART and must reset
        // send an error message for this
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
        ToMainLow_sendmsg(0, MSGT_OVERRUN, (void *) 0);
    }
}

void init_uart_recv(uart_comm *uc) {
    uc_ptr = uc;
    uc_ptr->buflen = 0;
}

// CURTIS CHANGES

void configure_eusart()
{
    // Configuring pins for EUSART1
    RCSTA1bits.SPEN = 0x1; // Set SPEN bit to 1
    TRISCbits.TRISC7 = 0x1; // Set to 1 for EUSART1
    TRISCbits.TRISC6 = 0x0; // Set to 0 for asynchronous master mode
}

void setup_uart_send()
{
    // Configuring pins for EUSART1
    RCSTA1bits.SPEN = 0x1; // Set SPEN bit to 1
    TRISCbits.TRISC7 = 0x1; // Set to 1 for EUSART1
    TRISCbits.TRISC6 = 0x0; // Set to 0 for asynchronous master mode

    // Register 20-1: TXSTAx: TRANSMIT STATUS AND CONTROL REGISTER (ACCESS FADh, FA8h)
    TXSTA1bits.TXEN = 0x1; // Transmit is enabled
    TXSTA1bits.SYNC = 0x0; // Set EUSART mode to Asynchronous
    TXSTA1bits.BRGH = 0x1; // High speed Baud Rate

    // Register 20-2: RCSTAx: RECEIVE STATUS AND CONTROL REGISTER (ACCESS FACh, F9Ch)
    RCSTA1bits.SPEN = 0x1; // Serial port is enabled

    // Register 20-3: BAUDCONx: BAUD RATE CONTROL REGISTER (ACCESS F7Eh, F7Ch)
    BAUDCON1bits.BRG16 = 0x1; // 16-bit Baud Rate Generator

    // Set up baud rate generator for 57,600. See Baud Rate formula on page 328 of datasheet.
    // Actual baud rate generated here is 57,692 which is 0.16% error.
    SPBRGH1 = 0x0; // High byte
    SPBRG1 = 0xCF; // Low byte, 207 in decimal
}

void uart_send(uart_comm * u)
{
    
    
    while( u->buflen )
    {
        if(! Busy1USART( ) )
        {
            Write1USART( u->buffer[u->buflen - 1] );
            u->buflen--;
        }
    }
    
}
// END CURTIS CHANGES