#ifndef __my_uart_h
#define __my_uart_h

#include "messages.h"

#define MAXUARTBUF 4
#if (MAXUARTBUF > MSGLEN)
#define MAXUARTBUF MSGLEN
#endif
typedef struct __uart_comm {
    unsigned char buffer[MAXUARTBUF];
    unsigned char buflen;
} uart_comm;

void init_uart_recv(uart_comm *);
void uart_recv_int_handler(void);

// CURTIS CHANGES
void configure_eusart();
void setup_uart_send();

void uart_send(uart_comm *);
// END CURTIS CHANGES


#endif
