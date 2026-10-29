/*
 *
 * @file myAutomation_Nodes_Dual.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#include "NVSTable.h"


//CONFIGURE_DIALOG("RosscoeTrain Wifi Setup",myRTWifiDialog)


#if defined(DCCEX_NODE_DUAL) || defined(DCCEX_NODE_NANO_DUAL)

AUTOSTART
STEALTH(
    pinMode(C_1_PIN ,OUTPUT);
    pinMode(T_1_PIN ,OUTPUT);
    pinMode(C_2_PIN ,OUTPUT);
    pinMode(T_2_PIN ,OUTPUT);
    pinMode(C_3_PIN ,OUTPUT);
    pinMode(T_3_PIN ,OUTPUT);
    pinMode(C_4_PIN ,OUTPUT);
    pinMode(T_4_PIN ,OUTPUT);
    pinMode(C_5_PIN ,OUTPUT);
    pinMode(T_5_PIN ,OUTPUT);
    pinMode(C_6_PIN ,OUTPUT);
    pinMode(T_6_PIN ,OUTPUT);
    pinMode(C_7_PIN ,OUTPUT);
    pinMode(T_7_PIN ,OUTPUT);
    pinMode(C_8_PIN ,OUTPUT);
    pinMode(T_8_PIN ,OUTPUT);
)
PARSE("<D SHARE>")

DONE

#endif

/*
DELAY stealth from UKBloke(aka Chris)
STEALTH(delayMe(NVSTable::nvs[27]);)
https://discord.com/channels/713189617066836079/1520043886083313674/1533743820217516052
*/

#ifdef DCCEX_NODE_DUAL
#ifdef PCB_REV_B
#define C_1_PIN 33    // solenoid to close turnout
#define T_1_PIN 32    // solenoid to throw turnout
#define C_2_PIN 25
#define T_2_PIN 26
#define C_3_PIN 27
#define T_3_PIN 14
#define C_4_PIN 12
#define T_4_PIN 13
#define C_5_PIN 15
#define T_5_PIN 16
#define C_6_PIN 17
#define T_6_PIN 18
#define C_7_PIN 19
#define T_7_PIN 21
#define C_8_PIN 22
#define T_8_PIN 23
#endif
#ifdef PCB_REV_C
#define C_1_PIN 33    // AD3    // solenoid to close turnout
#define T_1_PIN 32    // AD4    // solenoid to throw turnout
#define C_2_PIN 25    // AD5
#define T_2_PIN 26    // AD6
#define C_3_PIN 27    // AD7
#define T_3_PIN 14    // AD8
#define C_4_PIN 12    // AD9
#define T_4_PIN 13    // AD10
#define C_5_PIN 15    // AD12
#define T_5_PIN 4     // AD11
#define C_6_PIN 16    // AD13
#define T_6_PIN 17    // AD14
#define C_7_PIN 5     // AD15
#define T_7_PIN 18    // AD16
#define C_8_PIN 19    // AD17
#define T_8_PIN 23    // AD18
#endif
#endif

#ifdef DCCEX_NODE_NANO_DUAL
#define C_1_PIN 6           // D3 arduino nano   // solenoid to close turnout
#define T_1_PIN 7           // D4                // solenoid to throw turnout
#define C_2_PIN 8           // D5
#define T_2_PIN 9           // D6
#define C_3_PIN 10          // D7
#define T_3_PIN 17          // D8
#define C_4_PIN 18          // D9
#define T_4_PIN 21          // D10
#define C_5_PIN 38          // D11
#define T_5_PIN 47          // D12
#define C_6_PIN 48          // D13
#define T_6_PIN 1           // A0
#define C_7_PIN 3           // A2
#define T_7_PIN 4           // A3
#define C_8_PIN 11          // A4
#define T_8_PIN 12          // A5
#endif

#if defined(DCCEX_NODE_DUAL) || defined(DCCEX_NODE_NANO_DUAL)

CONFIGURE_DIALOG("RosscoeTrain Dual Solenoid",myRTDualConfig)

#define SOLENOIDTURNOUT(id,pc,pt,del,desc)\
  VIRTUAL_TURNOUT(id,desc)\
  ONCLOSE(id)\
    SET(pc)\
    PRINT("Close start")\
    DELAY(del)\
    PRINT("Close end")\
    RESET(pc)\
    DONE\
  ONTHROW(id)\
    SET(pt)\
    DELAY(del)\
    RESET(pt)\
    DONE

SOLENOIDTURNOUT(NVS(0), C_1_PIN, T_1_PIN, NVS(1), NVST(2))
SOLENOIDTURNOUT(NVS(0) + 1, C_2_PIN, T_2_PIN, NVS(3), NVST(4))
SOLENOIDTURNOUT(NVS(0) + 2, C_3_PIN, T_3_PIN, NVS(5), NVST(6))
SOLENOIDTURNOUT(NVS(0) + 3, C_4_PIN, T_4_PIN, NVS(7), NVST(8))
SOLENOIDTURNOUT(NVS(0) + 4, C_5_PIN, T_5_PIN, NVS(9), NVST(10))
SOLENOIDTURNOUT(NVS(0) + 5, C_6_PIN, T_6_PIN, NVS(11), NVST(12))
SOLENOIDTURNOUT(NVS(0) + 6, C_7_PIN, T_7_PIN, NVS(13), NVST(14))
SOLENOIDTURNOUT(NVS(0) + 7, C_8_PIN, T_8_PIN, NVS(15), NVST(16))



#endif


