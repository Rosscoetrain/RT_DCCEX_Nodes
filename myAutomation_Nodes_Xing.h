/*
 *
 * @file myAutomation_Nodes_Master.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */


#ifdef DCCEX_NODE_XING

#warning Building for RT Node Xing


HAL(ServoESP, 100, 2, 18, 19)
HAL(NVSMap,1000)  // maps over nvs0..255

AUTOSTART
PARSE("<D SHARE>")
DONE

CONFIGURE_DIALOG("RosscoeTrain Xing Node",myRTXingConfig)

SERVO_TURNOUT(1, 100, NVS(1), NVS(2), Instant + NVS(3), HIDDEN)             //
SERVO_TURNOUT(2, 101, NVS(5), NVS(6), Instant + NVS(7), HIDDEN)             //

VIRTUAL_TURNOUT(NVS(0), "Level Crossing")           // activate crossing
VIRTUAL_TURNOUT(NVS(0) + 1, NVST(4))                 // servo 1
VIRTUAL_TURNOUT(NVS(0) + 2, NVST(8))                 // servo 2
VIRTUAL_TURNOUT(NVS(0) + 3, HIDDEN)                 // led 1 on/off
VIRTUAL_TURNOUT(NVS(0) + 4, HIDDEN)                 // led 2 on/off
VIRTUAL_TURNOUT(NVS(0) + 5, HIDDEN)                 // led 1 and 2 on/off
VIRTUAL_TURNOUT(NVS(0) + 6, HIDDEN)                 // flash leds
VIRTUAL_TURNOUT(NVS(0) + 7, HIDDEN)                 // aux on/off

AUTOSTART
PARSE("<D SHARE>")
CLOSE(NVS(0) + 1)                                 // both servos to closed
CLOSE(NVS(0) + 2)
CLOSE(NVS(0) + 3)                                 // auxillary and leds off
CLOSE(NVS(0) + 4)
CLOSE(NVS(0) + 5)
CLOSE(NVS(0) + 6)
CLOSE(NVS(0) + 7)
DONE



ONCLOSE(NVS(0))\
 PRINT("Deactivate crossing")\
 CLOSE(2)\
 CLOSE(1)\
 DELAY(NVS(14))\
 RESET(15)\
 RESET(16)\
 RESET(17)\
 DONE

ONTHROW(NVS(0))\
 PRINT("Activate crossing")\
 SET(15)\
 BLINK(16, NVS(9), NVS(10))\
 DELAY(NVS(9))\
 BLINK(17,NVS(11), NVS(12))\
 DELAY(NVS(13))\
 THROW(1)\
 THROW(2)\
 DONE

ONCLOSE(NVS(0) + 1)\
 PRINT("Servo 1 close")\
 CLOSE(1)\
 DONE
ONTHROW(NVS(0) + 1)\
 PRINT("Servo 1 throw")\
 THROW(1)\
 DONE

ONCLOSE(NVS(0) + 2)\
 PRINT("Servo 2 close")\
 CLOSE(2)\
 DONE
ONTHROW(NVS(0) + 2)\
 PRINT("Servo 2 throw")\
 THROW(2)\
 DONE

ONCLOSE(NVS(0) + 3)\
 PRINT("Led 1 off")\
 RESET(16)\
 DONE
ONTHROW(NVS(0) + 3)\
 PRINT("Led 1 on")\
 SET(16)\
 DONE

ONCLOSE(NVS(0) + 4)\
 PRINT("Led 2 off")\
 RESET(17)\
 DONE
ONTHROW(NVS(0) + 4)\
 PRINT("Led 2 on")\
 SET(17)\
 DONE

ONCLOSE(NVS(0) + 5)\
 PRINT("Led 1 and 2 off")\
 RESET(16)\
 RESET(17)\
 DONE
ONTHROW(NVS(0) + 5)\
 PRINT("Led 1 and 2 on")\
 SET(16)\
 SET(17)\
 DONE

ONCLOSE(NVS(0) + 6)\
 PRINT("Leds flashing off")\
 RESET(16)\
 RESET(17)\
 DONE
ONTHROW(NVS(0) + 6)\
 PRINT("Leds flashing on")\
 BLINK(16, NVS(9), NVS(10))\
 DELAY(NVS(9))\
 BLINK(17,NVS(11), NVS(12))\
 DONE

ONCLOSE(NVS(0) + 7)\
 PRINT("Aux off")\
 RESET(15)\
 DONE
ONTHROW(NVS(0) + 7)\
 PRINT("Aux on")\
 SET(15)\
 DONE



/*
NOTES:

NVSTable[]
0 = base address
1 = Servo 1 active position    100 - 500
2 = Servo 1 inactive position  100 - 500
3 = Servo 1 profile            Instant = 0, Fast = 1, Medium = 2, Slow = 3
4 = Servo 1 description        "A string value"

5 = Servo 2 active position    100 - 500
6 = Servo 2 inactive position  100 - 500
7 = Servo 2 profile            Instant = 0, Fast = 1, Medium = 2, Slow = 3
8 = Servo 2 description        "A string value"

9= Led 1 on time
10= Led 1 off time
11= Led 2 on time
12= Led 2 off time

13= Start delay
14= Hold delay

Led 1 pin 16
Led 2 pin 17
Aux pin 15

*/

#endif

