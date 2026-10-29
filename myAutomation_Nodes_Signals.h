/*
 *
 * @file myAutomation_Nodes_Signals.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */


#include "NVSTable.h"


//CONFIGURE_DIALOG("RosscoeTrain Wifi Setup",myRTWifiDialog)

#if defined(DCCEX_NODE_SIGNAL) || defined(DCCEX_NODE_NANO_SIGNAL)

AUTOSTART
STEALTH(
    pinMode(S_1_PIN ,OUTPUT);
    pinMode(S_2_PIN ,OUTPUT);
    pinMode(S_3_PIN ,OUTPUT);
    pinMode(S_4_PIN ,OUTPUT);
    pinMode(S_5_PIN ,OUTPUT);
    pinMode(S_6_PIN ,OUTPUT);
    pinMode(S_7_PIN ,OUTPUT);
    pinMode(S_8_PIN ,OUTPUT);
    pinMode(S_9_PIN ,OUTPUT);
    pinMode(S_10_PIN ,OUTPUT);
    pinMode(S_11_PIN ,OUTPUT);
    pinMode(S_12_PIN ,OUTPUT);
    pinMode(S_13_PIN ,OUTPUT);
    pinMode(S_14_PIN ,OUTPUT);
    pinMode(S_15_PIN ,OUTPUT);
    pinMode(S_16_PIN ,OUTPUT);
)
PARSE("<D SHARE>")
HAL(NVSMap,1000)  // maps over nvs0..255
DONE

#endif

/*
DELAY stealth from UKBloke(aka Chris)
STEALTH(delayMe(NVSTable::nvs[27]);)
https://discord.com/channels/713189617066836079/1520043886083313674/1533743820217516052
*/

#ifdef DCCEX_NODE_SIGNAL
#define S_1_PIN 33
#define S_2_PIN 32
#define S_3_PIN 25
#define S_4_PIN 26
#define S_5_PIN 27
#define S_6_PIN 14
#define S_7_PIN 12
#define S_8_PIN 13
#define S_9_PIN 15
#define S_10_PIN 16
#define S_11_PIN 17
#define S_12_PIN 18
#define S_13_PIN 19
#define S_14_PIN 21
#define S_15_PIN 22
#define S_16_PIN 23
#endif

#ifdef DCCEX_NODE_NANO_SIGNAL
#define S_1_PIN 6           // D3 arduino nano
#define S_1_PIN 7           // D4
#define S_2_PIN 8           // D5
#define S_2_PIN 9           // D6
#define S_3_PIN 10          // D7
#define S_3_PIN 17          // D8
#define S_4_PIN 18          // D9
#define S_4_PIN 21          // D10
#define S_5_PIN 38          // D11
#define S_5_PIN 47          // D12
#define S_6_PIN 48          // D13
#define S_6_PIN 1           // A0
#define S_7_PIN 3           // A2
#define S_7_PIN 4           // A3
#define S_8_PIN 11          // A4
#define S_8_PIN 12          // A5
#endif

#if defined(DCCEX_NODE_SIGNAL) || defined(DCCEX_NODE_NANO_SIGNAL)

CONFIGURE_DIALOG("RosscoeTrain Signals",myRTSignalConfig)
CONFIGURE_DIALOG("RosscoeTrain Signals Help", myRTSignalHelpConfig)


// Signal 1

IFGTE(1001, 5)
ELSE
IFGTE(1001, 4)
ELSE
IFGTE(1001, 3)
ELSE
IFGTE(1001, 2)                      // three aspect
SIGNAL(S_1_PIN, S_2_PIN, S_3_PIN)
ELSE
IFGTE(1001, 1)                      // two aspect
SIGNAL(S_1_PIN, S_2_PIN, 0)
ENDIF

// Signal 2

IFGTE(1002, 5)
ELSE
IFGTE(1002, 4)
ELSE
IFGTE(1002, 3)
ELSE
IFGTE(1002, 2)                      // three aspect
SIGNAL(S_4_PIN, S_5_PIN, S_6_PIN)
ELSE
IFGTE(1002, 1)                      // two aspect
SIGNAL(S_3_PIN, S_4_PIN, 0)
ENDIF

// Signal 3

IFGTE(1003, 5)
ELSE
IFGTE(1003, 4)
ELSE
IFGTE(1003, 3)
ELSE
IFGTE(1003, 2)                      // three aspect
SIGNAL(S_7_PIN, S_8_PIN, S_9_PIN)
ELSE
IFGTE(1003, 1)                      // two aspect
SIGNAL(S_5_PIN, S_6_PIN, 0)
ENDIF

// Signal 4

IFGTE(1004, 5)
ELSE
IFGTE(1004, 4)
ELSE
IFGTE(1004, 3)
ELSE
IFGTE(1004, 2)                      // three aspect
SIGNAL(S_10_PIN, S_11_PIN, S_12_PIN)
ELSE
IFGTE(1004, 1)                      // two aspect
SIGNAL(S_7_PIN, S_8_PIN, 0)
ENDIF

// Signal 5

IFGTE(1005, 5)
ELSE
IFGTE(1005, 4)
ELSE
IFGTE(1005, 3)
ELSE
IFGTE(1005, 2)                      // three aspect
SIGNAL(S_13_PIN, S_14_PIN, S_15_PIN)
ELSE
IFGTE(1005, 1)                      // two aspect
SIGNAL(S_9_PIN, S_10_PIN, 0)
ENDIF

// Signal 6

IFGTE(1006, 5)
ELSE
IFGTE(1006, 4)
ELSE
IFGTE(1006, 3)
ELSE
IFGTE(1006, 2)                      // three aspect
//SIGNAL(S__PIN, S__PIN, S__PIN)
ELSE
IFGTE(1006, 1)                      // two aspect
SIGNAL(S_11_PIN, S_12_PIN, 0)
ENDIF

// Signal 7

IFGTE(1007, 5)
ELSE
IFGTE(1007, 4)
ELSE
IFGTE(1007, 3)
ELSE
IFGTE(1007, 2)                      // three aspect
//SIGNAL(S__PIN, S__PIN, S__PIN)
ELSE
IFGTE(1007, 1)                      // two aspect
SIGNAL(S_13_PIN, S_14_PIN, 0)
ENDIF

// Signal 8

IFGTE(1008, 5)
ELSE
IFGTE(1008, 4)
ELSE
IFGTE(1008, 3)
ELSE
IFGTE(1008, 2)                      // three aspect
//SIGNAL(S__PIN, S__PIN, S__PIN)
ELSE
IFGTE(1008, 1)                      // two aspect
SIGNAL(S_15_PIN, S_16_PIN, 0)
ENDIF



#endif


