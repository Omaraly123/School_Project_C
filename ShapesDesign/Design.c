#include "Design.h"
 extern CONSOLE_SCREEN_BUFFER_INFO csbi;
 extern  COORD cursorPos; 
 extern u16 YPos;
 extern u16 XPos;
 extern u16 YMAXLIMIT;
 extern u16 XMAXLIMIT;
 extern u16 YMINLIMIT;
 extern u16 XMINLIMIT;

void print_initial_screen(void){
	vid_Initialize_Game_Frame();
		XPos=Add_StudentsXPos;
         YPos=Add_StudentsYPos;
	cmdGoToXY(XPos, YPos); 
	cmdSetConsoleColour(TEXT_DYellow);
    printf(" __        __   _                            _          ____       _                 _   ____        _        _                    ");
    
    cmdGoToXY(XPos, ++YPos);
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   / ___|  ___| |__   ___   ___ | | |  _ \\  __ _| |_ __ _| |__   __ _ ___  ___ ");
    
    cmdGoToXY(XPos, ++YPos);
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  \\___ \\ / __| '_ \\ / _ \\ / _ \\| | | | | |/ _` | __/ _` | '_ \\ / _` / __|/ _ \\");
    
    cmdGoToXY(XPos, ++YPos);
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |  ___) | (__| | | | (_) | (_) | | | |_| | (_| | || (_| | |_) | (_| \\__ \\  __/");
    
    cmdGoToXY(XPos, ++YPos);
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |____/ \\___|_| |_|\\___/ \\___/|_| |____/ \\__,_|\\__\\__,_|_.__/ \\__,_|___/\\___|");
	cmdGoToXY(XPos, ++YPos);
	cmdGoToXY(XPos, ++YPos);
	cmdSetConsoleColour(TEXT_DWhite);
	
	
}
void print_NewStudent_screen(void)
{
    vid_Initialize_Game_Frame();
    XPos = Add_StudentsXPos+25;
    YPos = Add_StudentsYPos;

    	cmdGoToXY(XPos, YPos);
    cmdSetConsoleColour(TEXT_DYellow);
printf("      __   __           ___          __  ___       __   ___      ___");
cmdGoToXY(XPos, ++YPos);
printf(" /\\  |  \\ |  \\    |\\ | |__  |  |    /__`  |  |  | |  \\ |__  |\\ |  | ");
cmdGoToXY(XPos, ++YPos);
printf("/~~\\ |__/ |__/    | \\| |___ |\\/|    .__/  |  \\__/ |__/ |___ | \\|  | ");
cmdGoToXY(XPos, ++YPos);
cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
}
void print_EditStudent_screen(void)
{
    vid_Initialize_Game_Frame();
    XPos = Add_StudentsXPos+25;
    YPos = Add_StudentsYPos;

    	cmdGoToXY(XPos, YPos);
    cmdSetConsoleColour(TEXT_DYellow);
printf(".---------------------------------------------------------------.");
cmdGoToXY(XPos, ++YPos);
printf("| __|  _ \\ _ _| __ __|     __| __ __| |  | _ \\  __|   \\ | __ __||");
cmdGoToXY(XPos, ++YPos);
printf("| _|   |  |  |     |     \\__ \\    |   |  | |  | _|   .  |    |  |");
cmdGoToXY(XPos, ++YPos);
printf("|___| ___/ ___|   _|     ____/   _|  \\__/ ___/ ___| _|\\_|   _|  |");
cmdGoToXY(XPos, ++YPos);
printf("'---------------------------------------------------------------'");
cmdGoToXY(XPos, ++YPos);
cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
}

void print_CallStudent_screen(void)
{
    vid_Initialize_Game_Frame();
    XPos = Add_StudentsXPos+25;
    YPos = Add_StudentsYPos;

    	cmdGoToXY(XPos, YPos);
    cmdSetConsoleColour(TEXT_DYellow);
printf(".------------------------------------------------------------------.");
cmdGoToXY(XPos, ++YPos);
printf("|  __|    \\    |     |        __| __ __| |  | _ \\  __|   \\ | __ __||");
cmdGoToXY(XPos, ++YPos);
printf("| (      _ \\   |     |      \\__ \\    |   |  | |  | _|   .  |    |  |");
cmdGoToXY(XPos, ++YPos);
printf("|\\___| _/  _\\ ____| ____|   ____/   _|  \\__/ ___/ ___| _|\\_|   _|  |");
cmdGoToXY(XPos, ++YPos);
printf("'------------------------------------------------------------------'");
cmdGoToXY(XPos, ++YPos);
cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
}
void vid_Initialize_Game_Frame()
 {
	 cmdClearScreen() ;
	 cmdSetConsoleColour(TEXT_Cyan);	
	 ShapeDraw_Square(Frame_XPos,Frame_YPos, Frame_Width, Frame_Height);
	 printf("\n");
	  cmdResetConsoleColour();	
	 YPos=Frame_YPos+9;
     XPos=Frame_XPos+20; 
 } 
 
 void vid_Letter_Space()
  {
		XPos+=4;
	   cmdGoToXY(XPos, YPos);
  }
 

void vid_S_Frame(u8 au8Scale)
{
	 u16 lu16InitXPos=XPos;
	 u16 lu16InitYPos=YPos;
	 u16 lu16U_Width= au8Scale+1;
	         for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
			  }
			   cmdGoToXY(XPos, ++YPos);
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
				  cmdGoToXY(XPos, YPos++);
			  }
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  {
				   printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
		      XPos=cursorPos.X-2;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				   printf("%c%c",219,219);			  
			  }
			  cmdGoToXY(lu16InitXPos, YPos-1);
		      for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  { 
				  printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
			   XPos=cursorPos.X;
			   YPos=lu16InitYPos;
}

 
  


 void vid_C_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 au8Scale= (au8Scale*2)+1;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos+lu8CursorMov);
				  printf("%c%c",219,219);	
			  } 
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2;lu8CursorMov++)
			  {
				  XPos+=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			    XPos+=2;
				cmdGoToXY(XPos, ++YPos);
				printf("%c%c",219,219);	
				XPos+=2;
				lu16InitXPos =XPos;
				cmdGoToXY(XPos, ++YPos);
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale-4;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				  printf("%c%c",0,0);	
			  } 
			    XPos-=2;
			   cmdGoToXY(XPos, YPos++);
				printf("%c%c",219,219);	
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2;lu8CursorMov++)
			  {
				  XPos-=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 

			  XPos=  lu16InitXPos ;
			  YPos=  lu16InitYPos;
			  cmdGoToXY(XPos, lu16InitYPos); 
  }
 
  void vid_O_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 au8Scale= (au8Scale*2)+1;
		 	  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2+1;lu8CursorMov++)
			  {
				  XPos+=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			   XPos+=2;
			   lu16InitXPos=XPos;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos++);
				  printf("%c%c",219,219);	
			  } 
			  YPos--;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale/2+1;lu8CursorMov++)
			  {
				  XPos-=2;
				  cmdGoToXY(XPos, YPos);
				  printf("%c%c",219,219);	
			  } 
			   XPos-=2;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, YPos--);
				  printf("%c%c",219,219);	
			  } 
			  YPos++;

			  XPos=  lu16InitXPos ;
			  YPos=  lu16InitYPos;             
			  cmdGoToXY(XPos, lu16InitYPos); 
  }
 
  
void vid_H_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 u16 lu16U_Width= au8Scale+1;
		 au8Scale= (au8Scale*2)+1;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  printf("%c%c",219,219);
				  cmdGoToXY(XPos, YPos++);
			  }
			  printf("%c%c",219,219);
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  { 
				 printf("%c%c",' ',' ');
			  }
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width+5;lu8CursorMov++)
			  { 
		        cmdGoToXY(++XPos, YPos-5);
				 printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
			   XPos=cursorPos.X;
			 for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, --YPos);
				  printf("%c%c",219,219);  
			  }
			  cmdGoToXY(++XPos, YPos);
			  
  }

 
  void vid_L_Frame(u8 au8Scale)
  {
	  	 u16 lu16InitXPos=XPos;
		 u16 lu16InitYPos=YPos;
		 u16 lu16U_Width= au8Scale+1;
		 au8Scale= (au8Scale*2)+1;
			  for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  printf("%c%c",219,219);
				  cmdGoToXY(XPos, YPos++);
			  }
			  for(u8 lu8CursorMov=0; lu8CursorMov< lu16U_Width;lu8CursorMov++)
			  { 
				 printf("%c%c",219,219);
			  }
			  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);         //Get Current Cursor X axis location
              cursorPos = csbi.dwCursorPosition;
			   XPos=cursorPos.X;
			 for(u8 lu8CursorMov=0; lu8CursorMov< au8Scale;lu8CursorMov++)
			  {
				  cmdGoToXY(XPos, --YPos);
				  printf("%c%c",' ',' ');  
			  }
			  cmdGoToXY(++XPos, YPos);
			  
  }
 
void Entry_Frame(u8 au8Scale)
	 {
			 vid_Letter_Space();
			 cmdSetConsoleColour(TEXT_LYellow);	
			 vid_S_Frame( au8Scale );
			 vid_Letter_Space();
			 vid_C_Frame(au8Scale);
			 vid_Letter_Space();
			 vid_H_Frame( au8Scale);
			 vid_Letter_Space();
			 vid_O_Frame( au8Scale) ;
			 vid_Letter_Space();
			 vid_O_Frame( au8Scale);
			 vid_Letter_Space();
			 vid_L_Frame(au8Scale);
			 cmdResetConsoleColour();	
			
	 }
	 
 void highlightCursor(int x, int y) {
    // ANSI escape code for setting text attributes
    printf("\x1b[7m");  // This sets reverse video (background and foreground color are swapped)

    // Move the cursor to the desired position
    cmdGoToXY(x, y);

    // Print the highlighted content
   

    // Reset text attributes
    printf("\x1b[0m");
}
void highlightString(const char *str,u8 au8Color)
 {
	  cmdSetConsoleColour(au8Color);	
      printf("%s", str);                  // This will highlight the string in red
	  hideCursor();
	  cmdGoToXY(XMINLIMIT, YPos);
}

void hideCursor() 
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.dwSize=100;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}