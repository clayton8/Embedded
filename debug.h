/* 
 * File:   debug.h
 * Author: s45504
 *
 * Created on September 9, 2014, 11:51 AM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

    
// Define this to turn on instrumentation
#define DO_DEBUG
// Use definitions to make debugging configurable
#define TIMER1_D LATBbits.LATB0
#define AD_GoDone LATBbits.LATB1
#define GET_SENSOR_MAIN LATBbits.LATB2
// Define our debugging functions
#ifdef DO_DEBUG
#define DEBUG_ON(a) {\
a = 1;\
}
#define DEBUG_OFF(a){\
a = 0;\
}
#define DEBUG_FLIP(a){\
a ^= 1;\
}
#else
#define DEBUG_ON(a)
#define DEBUG_OFF(a)
#define DEBUG_FLIP(a)
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

