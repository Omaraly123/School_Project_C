/** 
 * File: mTime.h
 * Author: Eng- Mohamed Mokhtar
 * Group: Online16
 * Date: 2024,Feb
 * Description: ...
 * Version: 1.0
 */

#ifndef __SUPPORT_LIBS_INC_MTIME_H__
#define __SUPPORT_LIBS_INC_MTIME_H__ 

/***************_APP_INCLUDES_*****************************/
#include "../../std_Headers/std_Utility.h"

/***************_Standard_INCLUDES_************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   // Windows API header
#include <time.h>	   // Time API header
	
/***************_Types_Define_*****************************/


/***************_cmd_Handler.c_FUNCTION_PROTOTYPE_*********/
void Time_delayMilliseconds(u32 apu32milliseconds);
void Time_Take_START_Snap(void);
f64 Time_Take_END_Snap(void);

#endif /* __SUPPORT_LIBS_INC_MTIME_H__ */