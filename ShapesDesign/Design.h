#ifndef __SHAPESDESIGN_DESIGN_H__
#define __SHAPESDESIGN_DESIGN_H__

/***************_APP_INCLUDES_*****************************/
#include "../std_Headers/std_Utility.h"


/***************_Support_Libs_INCLUDES_********************/
 #include "../Support_Libs/Inc/cmd_Handler.h"
#include "../Support_Libs/Inc/ShapeDraw.h"
#include "../Support_Libs/Inc/Terminal.h"
#include "../Support_Libs/Inc/mTime.h"

/***************_Standard_INCLUDES_************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>   // Windows API header
#include <time.h>
#include <stdbool.h>
/*************************DEFINES**************************/
#define ALPHA_FIGS         "///"
#define Frame_Height         30
#define Frame_Width      134
#define Frame_XPos         15
#define Frame_YPos          2
#define TTTopLeftCorner (177)
#define BBBotLeftCorner (177)
#define TTTopRightCorner (177)
#define BBBotRightCorner (177)
#define HHH_line (220)
#define VVV_line (219)
#define TEXT_Highlight 14
#define  BELL             7
#define  BLOCK          (177)
#define   au16WIDTH             190
#define   au16HEIGHT             40
#define   Add_StudentsXPos             16
#define   Add_StudentsYPos             3



void Entry_Frame(u8);
void vid_Initialize_Game_Frame(void);
void vid_S_Frame(u8); 
void vid_Letter_Space();
void vid_C_Frame(u8 au8Scale);
void vid_O_Frame(u8 au8Scale);
void vid_H_Frame(u8 au8Scale);
void vid_L_Frame(u8 au8Scale);
void highlightCursor(int x, int y);
void print_initial_screen(void);
void highlightString(const char *str,u8 au8Color);
void hideCursor();
void print_NewStudent_screen(void);
void print_EditStudent_screen(void);
void print_CallStudent_screen(void);




#endif/*__SHAPE_DESIGN_DESIGN_H__*/