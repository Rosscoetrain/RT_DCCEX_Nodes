/*
 *
 * test myAutomation.h for DCC-EX nodes.
 * 
 * 
 * 
 * 
 * 
 */

HAL_IGNORE_DEFAULTS

#ifndef DCCEX_NODE
AUTOSTART
SET_TRACK(A,MAIN)  // Set Track A to DCC MAIN
SET_TRACK(B,MAIN)  // Set Track B to DCC MAIN
SET_POWER(A, ON)
SET_POWER(B, ON)

#ifdef EXCSB1_WITH_EX8874
SET_TRACK(C,MAIN)  // Set Track C to DCC MAIN
SET_TRACK(D,MAIN)  // Set Track D to DCC MAIN
SET_POWER(C, ON)
SET_POWER(D, ON)

#endif

DONE
#endif



#ifdef DCCEX_NODE

NODE_SHARE_SCREEN0(20)

#if defined(DCCEX_NODE_DUAL) || defined(DCCEX_NODE_NANO_DUAL)
#include "myAutomation_Nodes_Dual.h"
#endif

#if defined(DCCEX_NODE_KATO) || defined(DCCEX_NODE_NANO_KATO)
#include "myAutomation_Nodes_Kato.h"
#endif

#if defined(DCCEX_NODE_SERVO) || defined(DCCEX_NODE_NANO_SERVO)
#include "myAutomation_Nodes_Servo.h"
#endif

#if defined(DCCEX_NODE_SIGNAL) || defined(DCCEX_NODE_NANO_SIGNAL)
#include "myAutomation_Nodes_Signals.h"
#endif

#if defined(DCCEX_NODE_MASTER)
#include "myAutomation_Nodes_Master.h"
#endif

#ifdef DCCEX_NODE_XING
#include "myAutomation_Nodes_Xing.h"
#endif

#ifdef DCCEX_NODE_NANO_EXTURNTABLE
#include "myAutomation_Nodes_Turntable.h"
#endif

#ifdef DCCEX_NODE_TESTER
#include "myAutomation_Nodes_Tester.h"
#endif

#endif
