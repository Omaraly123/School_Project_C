
#include "main.h"
#define MAX_STUDENTS 50
u16 NumberOfStudents=0;
struct student* students = NULL;
u8 au8SortFlag=0;




void main(void)
{

    cmdSetScreenDim(au16WIDTH, au16HEIGHT);
    vid_Initialize_Game_Frame();
    Entry_Frame(4);

    u8 Option=0;
    u8 MENU_1_[Menu1_Total_Options][Menu1_Opt_Length]= {"Add All Students","Add New Student","Edit student",
                                                        "Print All students","Print Student","Call Student",
                                                        "Sort","Remove Student","Exit"
                                                       };

    u8 KeyBoard_Input=0;

    XPos=Menu1_XPos;
    YPos=Menu1_YPos;
    XMINLIMIT= XPos;
    YMINLIMIT= YPos;
    cmdGoToXY(XPos, YPos);

    cmdSetConsoleColour(0x76);
    printf("%s", MENU_1_[0]);
    cmdResetConsoleColour();



    for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
    {
        cmdGoToXY(XPos, ++YPos);
        printf("%s", MENU_1_[MenuOpt_Count]);
    }

    hideCursor();
    YMAXLIMIT=YPos;
    YPos= YMINLIMIT;
    cmdGoToXY(XPos, YPos);




    students = (struct student*)malloc(MAX_STUDENTS * sizeof(struct student));

    if (students == NULL)
    {
        // Handle memory allocation failure
        cmdGoToXY(70,20);
        cmdSetConsoleColour(TEXT_Red);
        printf("Memory allocation failed for students.");
        cmdResetConsoleColour();
        return;
    }
   
  loadUserData( &NumberOfStudents);
    while(KeyBoard_Input!=ESC)
    {

        KeyBoard_Input=0;
        KeyBoard_Input= _getch();

        highlightString(MENU_1_[YPos-YMINLIMIT], TEXT_DWhite);

        switch (KeyBoard_Input)
        {
        case KEY_UP:
            YPos--;
            if (YPos < YMINLIMIT)
            {
                YPos = YMAXLIMIT;
            }
            break;
        case KEY_DOWN:
            YPos++;
            if (YPos > YMAXLIMIT)
            {
                YPos = YMINLIMIT;
            }
            break;
        default:
            /*DO NOTHING*/
            break;
        }

        YPos =  ( YPos %( Menu1_Total_Options+2) ) + YMINLIMIT;
        cmdGoToXY(XMINLIMIT, YPos);
        highlightString(MENU_1_[YPos-YMINLIMIT], 0x76);



        if(KeyBoard_Input == ENTER)
        {
            cmdResetConsoleColour();
            if( strcmp(MENU_1_[YPos-YMINLIMIT], "Add All Students") == 0 )
            {

                Add_students();
                cmdClearScreen();
                vid_Initialize_Game_Frame();
                Entry_Frame(4);
                KeyBoard_Input=0;
                XPos=Menu1_XPos;
                YPos=Menu1_YPos;
                XMINLIMIT= XPos;
                YMINLIMIT= YPos;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(0x76);
                printf("%s", MENU_1_[0]);
                cmdResetConsoleColour();
                for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("%s", MENU_1_[MenuOpt_Count]);
                }

                hideCursor();
                YMAXLIMIT=YPos;
                YPos= YMINLIMIT;
                cmdGoToXY(XPos, YPos);
              

            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Add New Student") == 0 )
            {

                cmdClearScreen();
                AddOne_student();
                cmdClearScreen();
                vid_Initialize_Game_Frame();
                Entry_Frame(4);
                KeyBoard_Input=0;
                XPos=Menu1_XPos;
                YPos=Menu1_YPos;
                XMINLIMIT= XPos;
                YMINLIMIT= YPos;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(0x76);
                printf("%s", MENU_1_[0]);
                cmdResetConsoleColour();
                for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("%s", MENU_1_[MenuOpt_Count]);
                }

                hideCursor();
                YMAXLIMIT=YPos;
                YPos= YMINLIMIT;
                cmdGoToXY(XPos, YPos);
               


            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Edit student") == 0 )
            {

                system("cls") ;
                Edit_student();
                cmdClearScreen();
                vid_Initialize_Game_Frame();
                Entry_Frame(4);
                KeyBoard_Input=0;
                XPos=Menu1_XPos;
                YPos=Menu1_YPos;
                XMINLIMIT= XPos;
                YMINLIMIT= YPos;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(0x76);
                printf("%s", MENU_1_[0]);
                cmdResetConsoleColour();
                for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("%s", MENU_1_[MenuOpt_Count]);
                }

                hideCursor();
                YMAXLIMIT=YPos;
                YPos= YMINLIMIT;
                cmdGoToXY(XPos, YPos);
                 

            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Print All students") == 0 )
            {

                print_students( students,NumberOfStudents);
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos+20, ++YPos);
                printf("Press 'b' to go back :");
                cmdSetConsoleColour(TEXT_DYellow);
                KeyBoard_Input=_getch();
                if(KeyBoard_Input == 'b' )
                {
                    cmdClearScreen();
                    vid_Initialize_Game_Frame();
                    Entry_Frame(4);
                    KeyBoard_Input=0;
                    XPos=Menu1_XPos;
                    YPos=Menu1_YPos;
                    XMINLIMIT= XPos;
                    YMINLIMIT= YPos;
                    cmdGoToXY(XPos, YPos);
                    cmdSetConsoleColour(0x76);
                    printf("%s", MENU_1_[0]);
                    cmdResetConsoleColour();
                    for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("%s", MENU_1_[MenuOpt_Count]);
                    }

                    hideCursor();
                    YMAXLIMIT=YPos;
                    YPos= YMINLIMIT;
                    cmdGoToXY(XPos, YPos);
                    
                }
                else
                {
                    //DO NOTHING
                }


            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Print Student") == 0 )
            {
                printOne_student();
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos+20, ++YPos);
                printf("Press 'b' to go back :");
                cmdSetConsoleColour(TEXT_DYellow);
                KeyBoard_Input=_getch();
                if(KeyBoard_Input == 'b' )
                {
                    cmdClearScreen();
                    vid_Initialize_Game_Frame();
                    Entry_Frame(4);
                    KeyBoard_Input=0;
                    XPos=Menu1_XPos;
                    YPos=Menu1_YPos;
                    XMINLIMIT= XPos;
                    YMINLIMIT= YPos;
                    cmdGoToXY(XPos, YPos);
                    cmdSetConsoleColour(0x76);
                    printf("%s", MENU_1_[0]);
                    cmdResetConsoleColour();
                    for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("%s", MENU_1_[MenuOpt_Count]);
                    }

                    hideCursor();
                    YMAXLIMIT=YPos;
                    YPos= YMINLIMIT;
                    cmdGoToXY(XPos, YPos);
                    
                }
                else
                {
                    //DO NOTHING
                }


            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Call Student") == 0 )
            {

                system("cls") ;
                Call_student();
                cmdClearScreen();
                vid_Initialize_Game_Frame();
                Entry_Frame(4);
                KeyBoard_Input=0;
                XPos=Menu1_XPos;
                YPos=Menu1_YPos;
                XMINLIMIT= XPos;
                YMINLIMIT= YPos;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(0x76);
                printf("%s", MENU_1_[0]);
                cmdResetConsoleColour();
                for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("%s", MENU_1_[MenuOpt_Count]);
                }

                hideCursor();
                YMAXLIMIT=YPos;
                YPos= YMINLIMIT;
                cmdGoToXY(XPos, YPos);
                 

            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Sort") == 0 )
            {

                system("cls") ;
                Sort_studentsByName();
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos+16, ++YPos-10);
                printf("Press 'b' to go back :");
                cmdSetConsoleColour(TEXT_DYellow);
                KeyBoard_Input=_getch();
                if(KeyBoard_Input == 'b' )
                {
                    cmdClearScreen();
                    vid_Initialize_Game_Frame();
                    Entry_Frame(4);
                    KeyBoard_Input=0;
                    XPos=Menu1_XPos;
                    YPos=Menu1_YPos;
                    XMINLIMIT= XPos;
                    YMINLIMIT= YPos;
                    cmdGoToXY(XPos, YPos);
                    cmdSetConsoleColour(0x76);
                    printf("%s", MENU_1_[0]);
                    cmdResetConsoleColour();
                    for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("%s", MENU_1_[MenuOpt_Count]);
                    }

                    hideCursor();
                    YMAXLIMIT=YPos;
                    YPos= YMINLIMIT;
                    cmdGoToXY(XPos, YPos);
                     
                }
                else
                {
                    //DO NOTHING
                }


            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Remove Student") == 0 )
            {

                system("cls") ;
                RemoveStudent();
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos+16, ++YPos-11);
                printf("Press 'b' to go back :");
                cmdSetConsoleColour(TEXT_DYellow);
                KeyBoard_Input=_getch();
                if(KeyBoard_Input == 'b' )
                {
                    cmdClearScreen();
                    vid_Initialize_Game_Frame();
                    Entry_Frame(4);
                    KeyBoard_Input=0;
                    XPos=Menu1_XPos;
                    YPos=Menu1_YPos;
                    XMINLIMIT= XPos;
                    YMINLIMIT= YPos;
                    cmdGoToXY(XPos, YPos);
                    cmdSetConsoleColour(0x76);
                    printf("%s", MENU_1_[0]);
                    cmdResetConsoleColour();
                    for( u8 MenuOpt_Count=1; MenuOpt_Count < Menu1_Total_Options; MenuOpt_Count++ )
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("%s", MENU_1_[MenuOpt_Count]);
                    }

                    hideCursor();
                    YMAXLIMIT=YPos;
                    YPos= YMINLIMIT;
                    cmdGoToXY(XPos, YPos);
                     
                }
                else
                {
                    //DO NOTHING
                }



            }
            else if( strcmp(MENU_1_[YPos-YMINLIMIT], "Exit") == 0 )
            {
                atexit(saveDataOnExitWrapper);
                system("cls") ;
                exit(0);

            }
            else
            {
                /*DO NOTHING*/
            }
        }
        else if(KeyBoard_Input == ESC)
        {
          atexit(saveDataOnExitWrapper);
            exit(0);

        }
        else
        {
            /*DO NOTHING*/
        }
    }
    cmdResetConsoleColour();

   // atexit(saveDataOnExit);




}
struct student* Add_students(void)
{


    u8 input=0;
    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos;
    cmdGoToXY(XPos, YPos);
    print_initial_screen();


    printf("Please Enter Number of Students:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&NumberOfStudents);
    if(NumberOfStudents>MAX_STUDENTS)
    {
        cmdSetConsoleColour(TEXT_DWhite);
        printf("School capacity is %d Add less Students",MAX_STUDENTS);
        cmdSetConsoleColour(TEXT_DYellow);
        scanf("%d",&NumberOfStudents);
    }
    else
    {
        students = (struct student*)malloc(NumberOfStudents * sizeof(struct student)); //SCHOOL MAX STUDENTS 50 STUDENTS
        u16 i;
        cmdGoToXY(XPos, ++YPos);

        //init_Y=  YPos;
        //init_X  =XPos;

        for ( i = 0; i < NumberOfStudents; i++)
        {
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DWhite);
            printf("Add Student %d:", i+1);
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DYellow);
            students[i] = student_scan(i+1);
            cmdSetConsoleColour(TEXT_DWhite);

            while(input!=ESC)
            {
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos+20, ++YPos);
                printf("Press 'b' to go BACK or 's' to SAVE adding or 'c: to CONTINUE");
                cmdSetConsoleColour(TEXT_DYellow);
                input=_getch();

                if ( input=='s')
                {
                    return students;

                    // Break the loop to indicate going back
                }
                else if(input == 'b' )
                {

                    free(students); // Free the allocated memory
                    return NULL; // Return NULL to indicate going back without saving

                }
                else if(input == 'c' )
                {

                    cmdSetConsoleColour(TEXT_DWhite);
                    system("cls");
                    print_initial_screen();
                    break;

                }
                else
                {
                    //DO NOTHING
                }
                cmdSetConsoleColour(TEXT_DWhite);
                system("cls");
                print_initial_screen();

            }
        }
    }

    cmdResetConsoleColour();
    //return NumberOfStudents;

}

struct student* AddOne_student(void)
{

    print_NewStudent_screen();
    u8 input = 0;
    XPos = Add_StudentsXPos;
    YPos = Add_StudentsYPos + 7;
    cmdGoToXY(XPos, YPos);

    NumberOfStudents += 1;
    if (NumberOfStudents > MAX_STUDENTS)
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("School capacity is FULL");
        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(XPos + 20, ++YPos);
            printf("Press 'b' to go BACK");
            input = _getch();
            if (input == 'b')
            {
                return NULL; // Return to indicate going back without saving
            }
        }
    }
    else
    {
        // Reallocate memory for one additional student
        struct student *temp = (struct student*)realloc(students, (NumberOfStudents + 1) * sizeof(struct student));
        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            return NULL;
        }
        students = temp;

        // Update the last element of the array with the new student data
        cmdGoToXY(XPos, ++YPos);
        cmdSetConsoleColour(TEXT_DWhite);
        printf("Add Student %d:", NumberOfStudents);
        cmdGoToXY(XPos, ++YPos);
        cmdSetConsoleColour(TEXT_DYellow);
        students[NumberOfStudents - 1] = student_scan(NumberOfStudents);
        cmdSetConsoleColour(TEXT_DWhite);

        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(XPos + 20, ++YPos);
            printf("Press 'b' to go BACK or 's' to SAVE");
            cmdSetConsoleColour(TEXT_DYellow);
            input = _getch();
            if (input == 's')
            {
                // Optionally, you can save the updated student array to a file or perform any other necessary actions here
                return students; // Return to indicate saving
            }
            else if (input == 'b')
            {
                return NULL; // Return to indicate going back without saving
            }
        }
    }

    cmdResetConsoleColour();

}

void Call_student(void)
{

    print_CallStudent_screen();
    u8 input = 0;
    XPos = Add_StudentsXPos;
    YPos = Add_StudentsYPos + 7;
    cmdGoToXY(XPos, YPos);
    u16 au16ID=0;
    printf("Please Enter ID of Students:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&au16ID);

    if (au16ID > MAX_STUDENTS || au16ID < 1 || au16ID > NumberOfStudents)
    {
        cmdGoToXY(68, 15);
        cmdSetConsoleColour(TEXT_Red);
        printf("Sudent ID doesnt EXIST!!");
        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(68, 16);
            printf("Press 'b' to go BACK");
            input = _getch();
            if (input == 'b')
            {
                return; // Return to indicate going back without saving
            }
        }
    }
    if (au8SortFlag==0)
    {


        u16 i =0;
        u16 au8SqXPos=60,au16SqYPos=9,au16Height=22,au8Width=25;
        XPos = Add_StudentsXPos+50;
        YPos = Add_StudentsYPos + 12;
        for(i=0; i<=au8Width+1; i++)
        {
            cmdGoToXY(au8SqXPos +i, au16SqYPos);
            printf("%c", FOLDED_MIDDOWN);
            cmdGoToXY(au8SqXPos +i, au16SqYPos+au16Height);
            printf("%c", FOLDED_MIDUP);
        }
        for(i=1; i<au16Height; i++)
        {
            cmdGoToXY(au8SqXPos, au16SqYPos+i);
            printf("%c", FOLDED_LEFT);
            cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos+i);
            printf("%c", FOLDED_RIGHT);
        }
        cmdGoToXY(72,10);
        printf("%c%c%c%c",223,248,248,248);
        cmdGoToXY(61,28);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196  );
        cmdGoToXY(72,29);
        printf("%c%c",219,219 );



        cmdGoToXY(XPos, YPos);
        cmdSetConsoleColour(TEXT_DWhite);
        printf("Calling %s", students[au16ID-1].name);
        cmdGoToXY(XPos, ++YPos);
        cmdSetConsoleColour(TEXT_DYellow);
        printf("%s", students[au16ID-1].phone);
        cmdSetConsoleColour(TEXT_DWhite);
        for(u8 i=0; i<10; i++)
        {
            if(i%2==0)
            {
                XPos = Add_StudentsXPos+50;
                YPos = Add_StudentsYPos + 12;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Calling %s", students[au16ID-1].name);
                cmdSetConsoleColour(TEXT_DYellow);
                cmdGoToXY(XPos, ++YPos);
                printf("%s", students[au16ID-1].phone);
                cmdSetConsoleColour(TEXT_DWhite);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
            }
            else
            {
                XPos = Add_StudentsXPos+50;
                YPos = Add_StudentsYPos + 12;
                cmdGoToXY(XPos,YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Calling %s", students[au16ID-1].name);
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_DYellow);
                printf("%s", students[au16ID-1].phone);
                cmdSetConsoleColour(TEXT_DWhite);
                printf(" ");

                printf(" ");

                printf(" ");
                printf(" ");

            }


        }

        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(XPos-3, ++YPos+5);
            printf("Press 'b' to go BACK ");
            cmdSetConsoleColour(TEXT_DYellow);
            input = _getch();

            if (input == 'b')
            {
                return;
            }
        }
    }

    else if (au8SortFlag==1)
    {


        u16 i =0;
        u16 au8SqXPos=60,au16SqYPos=9,au16Height=22,au8Width=25;
        XPos = Add_StudentsXPos+50;
        YPos = Add_StudentsYPos + 12;
        for(i=0; i<=au8Width+1; i++)
        {
            cmdGoToXY(au8SqXPos +i, au16SqYPos);
            printf("%c", FOLDED_MIDDOWN);
            cmdGoToXY(au8SqXPos +i, au16SqYPos+au16Height);
            printf("%c", FOLDED_MIDUP);
        }
        for(i=1; i<au16Height; i++)
        {
            cmdGoToXY(au8SqXPos, au16SqYPos+i);
            printf("%c", FOLDED_LEFT);
            cmdGoToXY(au8SqXPos+au8Width+1, au16SqYPos+i);
            printf("%c", FOLDED_RIGHT);
        }
        cmdGoToXY(72,10);
        printf("%c%c%c%c",223,248,248,248);
        cmdGoToXY(61,28);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196  );
        cmdGoToXY(72,29);
        printf("%c%c",219,219 );


     for(u8 i=0;i<NumberOfStudents;i++)
	 {
          if(au16ID==students[i].studentID)
		  {
			cmdGoToXY(XPos, YPos);
        cmdSetConsoleColour(TEXT_DWhite);
        printf("Calling %s", students[i].name);
        cmdGoToXY(XPos, ++YPos);
        cmdSetConsoleColour(TEXT_DYellow);
        printf("%s", students[i].phone);
        cmdSetConsoleColour(TEXT_DWhite);
        for(u8 j=0; j<10; j++)
        {
            if(j%2==0)
            {
                XPos = Add_StudentsXPos+50;
                YPos = Add_StudentsYPos + 12;
                cmdGoToXY(XPos, YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Calling %s", students[i].name);
                cmdSetConsoleColour(TEXT_DYellow);
                cmdGoToXY(XPos, ++YPos);
                printf("%s", students[i].phone);
                cmdSetConsoleColour(TEXT_DWhite);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
                printf(".");
                Time_delayMilliseconds(1000);
            }
            else
            {
                XPos = Add_StudentsXPos+50;
                YPos = Add_StudentsYPos + 12;
                cmdGoToXY(XPos,YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Calling %s", students[i].name);
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_DYellow);
                printf("%s", students[i].phone);
                cmdSetConsoleColour(TEXT_DWhite);
                printf(" ");
                printf(" ");
                printf(" ");
                printf(" ");

            }


        }

        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(XPos-3, ++YPos+5);
            printf("Press 'b' to go BACK ");
            cmdSetConsoleColour(TEXT_DYellow);
            input = _getch();

            if (input == 'b')
            {
                return;
            }
        }
		  }

	 }
        
    }


    cmdResetConsoleColour();

}

void Edit_student(void)
{

    print_EditStudent_screen();
    u8 input = 0;
    XPos = Add_StudentsXPos;
    YPos = Add_StudentsYPos + 7;
    cmdGoToXY(XPos, YPos);
    u16 au16ID=0;
    printf("Please Enter ID of Students:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&au16ID);

    if (au16ID > MAX_STUDENTS || au16ID < 1)
    {
        cmdSetConsoleColour(TEXT_Red);
        printf("Sudent ID doesnt EXIST!!");
        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(XPos + 20, ++YPos);
            printf("Press 'b' to go BACK");
            input = _getch();
            if (input == 'b')
            {
                return; // Return to indicate going back without saving
            }
        }
    }
    if (au8SortFlag==0)
    {
        if(au16ID==students[au16ID-1].studentID)
        {
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DWhite);
            printf("Edit Student %d:", au16ID);
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DYellow);
            students[au16ID - 1] = student_scan(au16ID);
            cmdSetConsoleColour(TEXT_DWhite);

            while (input != ESC)
            {
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos + 20, ++YPos);
                printf("Press 'b' to go BACK or 's' to SAVE");
                cmdSetConsoleColour(TEXT_DYellow);
                input = _getch();
                if (input == 's')
                {
                    // Optionally, you can save the updated student array to a file or perform any other necessary actions here
                    return; // Return to indicate saving
                }
                else if (input == 'b')
                {
                    return; // Return to indicate going back without saving
                }
            }
        }


    }
     if (au8SortFlag==1)
    {
        for(u16 i=0;i<NumberOfStudents;i++)
        {
            if(au16ID==students[i].studentID)
        {
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DWhite);
            printf("Edit Student %d:", au16ID);
            cmdGoToXY(XPos, ++YPos);
            cmdSetConsoleColour(TEXT_DYellow);
            students[i] = student_scan(au16ID);
            cmdSetConsoleColour(TEXT_DWhite);

            while (input != ESC)
            {
                cmdSetConsoleColour(TEXT_LYellow);
                cmdGoToXY(XPos + 20, ++YPos);
                printf("Press 'b' to go BACK or 's' to SAVE");
                cmdSetConsoleColour(TEXT_DYellow);
                input = _getch();
                if (input == 's')
                {
                    // Optionally, you can save the updated student array to a file or perform any other necessary actions here
                    return; // Return to indicate saving
                }
                else if (input == 'b')
                {
                    return; // Return to indicate going back without saving
                }
            }
        }

        }
        


    }

    cmdResetConsoleColour();

}


struct student student_scan(u32 studentID)
{

    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos+9;
    cmdGoToXY(XPos, YPos);
    cmdSetConsoleColour(TEXT_DYellow);
    struct student s;
    s.studentID = studentID;
     for (u16 i = 0; i < NumberOfStudents; i++)
    {
        if (students[i].studentID == s.studentID)
        {
            s.studentID += 1; // Increment the student ID
            break;
        }
    }
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter name:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%s",&s.name);
    cmdSetConsoleColour(TEXT_DWhite);
    fflush(stdin);
    cmdGoToXY(XPos, ++YPos);
    printf("enter age:");
    cmdSetConsoleColour(TEXT_DYellow);
    scanf(" %d",&s.age);
    cmdSetConsoleColour(TEXT_DWhite);
    fflush(stdin);
    cmdGoToXY(XPos, ++YPos);
    printf("enter grade:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf(" %[^\n]",&s.grade);
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DWhite);
    cmdGoToXY(XPos, ++YPos);
    printf("enter phone number:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%13s",&s.phone);
    fflush(stdin);
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DWhite);
    cmdGoToXY(XPos, ++YPos);
    fflush(stdin);
    printf("enter father's info:\n");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    s.father= Parents_scan();
    cmdSetConsoleColour(TEXT_DWhite);
    cmdGoToXY(XPos, ++YPos);
    printf("enter mother's info:\n");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    s.mother= Parents_scan1();
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DWhite);
    cmdGoToXY(XPos, ++YPos);
    printf("enter number of brothers:");
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&s.Nbrothers);
    fflush(stdin);
    cmdResetConsoleColour();

    if(s.Nbrothers==0)
    {
        s.brothers = NULL;
    }
    else
    {
       
        s.brothers=(person_t*)malloc(s.Nbrothers * sizeof(person_t));
        for(u8 i=0; i<s.Nbrothers; i++)
        {
            if(s.Nbrothers==1)
            {
                cmdGoToXY(XPos, ++YPos);
                printf("Enter Brother %d info:",i+1);
                cmdGoToXY(XPos, ++YPos);
                fflush(stdin);
                s.brothers[i]= Parents_scan3();
                fflush(stdin);
                cmdGoToXY(XPos, ++YPos);
                fflush(stdin);
            }
            else
            {
                if(i==0)
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("Enter Brother %d info:",i+1);
                    cmdGoToXY(XPos, ++YPos);
                    fflush(stdin);
                    s.brothers[i]= Parents_scan3();
                    fflush(stdin);
                    cmdGoToXY(XPos, ++YPos);
                    fflush(stdin);
                }
                else
                {

                    cmdSetConsoleColour(TEXT_DWhite);
                    system("cls"); 				//To write in new page when first page is full
                    printf("Enter Brother %d info:",i+1);
                    cmdGoToXY(XPos, ++YPos);
                    print_initial_screen();
                    fflush(stdin);
                    s.brothers[i]= Parents_scan33();
                    fflush(stdin);
                    fflush(stdin);
                }

            }
        }

    }


    return s;
}
void str_scan(char *str)
{
    XPos=Add_StudentsXPos+11;
    YPos=Add_StudentsYPos+9;
    cmdGoToXY(XPos, YPos);
    int i=0;
    fflush(stdin);
    scanf(" %c",&str[i]);
    for(; str[i]!='\n';)
    {
        i++;
        fflush(stdin);
        scanf("%c",&str[i]);
    }
    YPos++;
    str[i]=0;
}
person_t Parents_scan(void)
{

    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos+14;
    cmdGoToXY(XPos, YPos);


    cmdSetConsoleColour(TEXT_DWhite);

    person_t s;
    printf("enter name:");

    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    cmdGoToXY(XPos+11, YPos);
    scanf("%s",&s.name);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter age:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&s.age);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter Phone number:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%s",&s.phone);
    cmdResetConsoleColour();
    return s;
}
person_t Parents_scan1(void)
{

    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos+18;
    cmdGoToXY(XPos, YPos);


    cmdSetConsoleColour(TEXT_DWhite);

    person_t s;
    printf("enter name:");

    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    cmdGoToXY(XPos+11, YPos);
    scanf("%s",&s.name);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter age:");

    cmdSetConsoleColour(TEXT_DYellow);
    fflush(stdin);
    scanf("%d",&s.age);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter Phone number:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%s",&s.phone);
    fflush(stdin);
    cmdResetConsoleColour();
    return s;
}
person_t Parents_scan3(void)
{

    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos+23;
    cmdGoToXY(XPos, YPos);


    cmdSetConsoleColour(TEXT_DWhite);

    person_t s;
    printf("enter name:");

    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    cmdGoToXY(XPos+11, YPos);
    scanf("%s",&s.name);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter age:");

    cmdSetConsoleColour(TEXT_DYellow);
    fflush(stdin);
    scanf("%d",&s.age);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter Phone number:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%s",&s.phone);
    fflush(stdin);
    cmdResetConsoleColour();
    return s;
}
person_t Parents_scan33(void)
{

    XPos=Add_StudentsXPos;
    YPos=Add_StudentsYPos+9;
    cmdGoToXY(XPos, YPos);


    cmdSetConsoleColour(TEXT_DWhite);

    person_t s;
    printf("enter name:");

    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    cmdGoToXY(XPos+11, YPos);
    scanf("%s",&s.name);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter age:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&s.age);
    cmdGoToXY(XPos, ++YPos);
    cmdSetConsoleColour(TEXT_DWhite);
    printf("enter Phone number:");
    fflush(stdin);
    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%s",&s.phone);
    cmdResetConsoleColour();
    return s;
}



void print_students(struct student* students, u16 NumberOfStudents)
{
    cmdClearScreen() ;
    XPos = Add_StudentsXPos;
    YPos = Add_StudentsYPos ;

   if(NumberOfStudents>=1)
   {
      u16 auPrintFrameHight=(NumberOfStudents*Frame_Height)-5;
    cmdSetConsoleColour(TEXT_Cyan);
    ShapeDraw_Square(Frame_XPos,Frame_YPos, Frame_Width/2, auPrintFrameHight);
    printf("\n");
    cmdResetConsoleColour();

    cmdGoToXY(XPos, YPos);
	 for (u16 i = 0; i < NumberOfStudents; i++)
    {

        printf("Student ID:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %d", students[i].studentID);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Name:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s", students[i].name);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Age:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %d", students[i].age);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Grade:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %c", students[i].grade);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Phone Number:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s", students[i].phone);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Father's Info:");
        cmdGoToXY(XPos, ++YPos);
        printf("Name:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s",students[i].father.name);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Age:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %d",students[i].father.age);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Phone:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s",students[i].father.phone);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Mother's Info:");
        cmdGoToXY(XPos, ++YPos);
        printf("Name:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s", students[i].mother.name);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Age:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %d", students[i].mother.age);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Phone:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %s", students[i].mother.phone);
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
        printf("Number of Brothers:");
        cmdSetConsoleColour(TEXT_DYellow);
        printf(" %d", students[i].Nbrothers);
        cmdResetConsoleColour();

        if (students[i].Nbrothers > 0)
        {
            cmdGoToXY(XPos, ++YPos);
            printf("Brothers:");
            for (int j = 0; j < students[i].Nbrothers; j++)
            {
                cmdGoToXY(XPos, ++YPos);
                printf("Brother %d Name: ", j + 1);
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].brothers[j].name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Brother %d Age: ", j + 1);
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[i].brothers[j].age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Brother %d Phone: ", j + 1);
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].brothers[j].phone);
                cmdResetConsoleColour();
            }
        }
        cmdGoToXY(XPos, ++YPos);
        cmdSetConsoleColour(TEXT_Cyan);
        ShapeDraw_Line(XPos,YPos, Frame_Width/2,0) ;
        cmdResetConsoleColour();
        cmdGoToXY(XPos, ++YPos);
    }
   }
   else if(NumberOfStudents==0)
   {
	 u16 auPrintFrameHight=(Frame_Height)-10;
    cmdSetConsoleColour(TEXT_Cyan);
    ShapeDraw_Square(Frame_XPos,Frame_YPos, Frame_Width/2, auPrintFrameHight);
    printf("\n");
    cmdResetConsoleColour();
	  cmdGoToXY(XPos + 20, ++YPos);
        cmdSetConsoleColour(TEXT_Red);
        printf("School Is EMPTY");
		return;
   }


}

void printOne_student(void)
{
    cmdClearScreen() ;
    u16 auPrintFrameHight=(Frame_Height)-5;
    cmdSetConsoleColour(TEXT_Cyan);
    ShapeDraw_Square(Frame_XPos,Frame_YPos, Frame_Width/2, auPrintFrameHight);
    printf("\n");
    cmdResetConsoleColour();

    XPos = Add_StudentsXPos;
    YPos = Add_StudentsYPos ;
    cmdGoToXY(XPos, YPos);
    u16 au16ID=0;
    u8 input=0;
    printf("Please Enter ID of Students:");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&au16ID);

    if (au16ID > MAX_STUDENTS || au16ID < 1 || au16ID >NumberOfStudents)
    {
		cmdGoToXY(XPos + 20, ++YPos);
        cmdSetConsoleColour(TEXT_Red);
        printf("Sudent ID doesnt EXIST!!");
        
    }
    if (au8SortFlag==1)
    {
        for(u16 i=0; i<NumberOfStudents; i++)
        {
            if(au16ID==students[i].studentID)
            {
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Student ID:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[i].studentID);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[i].age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Grade:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %c", students[i].grade);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone Number:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Father's Info:");
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s",students[i].father.name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d",students[i].father.age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s",students[i].father.phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Mother's Info:");
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].mother.name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[i].mother.age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[i].mother.phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Number of Brothers:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[i].Nbrothers);
                cmdResetConsoleColour();

                if (students[au16ID-1].Nbrothers > 0)
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("Brothers:");
                    for (int j = 0; j < students[i].Nbrothers; j++)
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Name: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %s", students[i].brothers[j].name);
                        cmdResetConsoleColour();
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Age: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %d", students[i].brothers[j].age);
                        cmdResetConsoleColour();
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Phone: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %s", students[i].brothers[j].phone);
                        cmdResetConsoleColour();
                    }
                }
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_Cyan);
                ShapeDraw_Line(XPos,YPos, Frame_Width/2,0) ;
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
            }
        }


    }
	else if (au8SortFlag==0)
    {
        
            if(au16ID==students[au16ID-1].studentID)
            {
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_DWhite);
                printf("Student ID:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[au16ID-1].studentID);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[au16ID-1].name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[au16ID-1].age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Grade:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %c", students[au16ID-1].grade);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone Number:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[au16ID-1].phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Father's Info:");
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s",students[au16ID-1].father.name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d",students[au16ID-1].father.age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s",students[au16ID-1].father.phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Mother's Info:");
                cmdGoToXY(XPos, ++YPos);
                printf("Name:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[au16ID-1].mother.name);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Age:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[au16ID-1].mother.age);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Phone:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %s", students[au16ID-1].mother.phone);
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
                printf("Number of Brothers:");
                cmdSetConsoleColour(TEXT_DYellow);
                printf(" %d", students[au16ID-1].Nbrothers);
                cmdResetConsoleColour();

                if (students[au16ID-1].Nbrothers > 0)
                {
                    cmdGoToXY(XPos, ++YPos);
                    printf("Brothers:");
                    for (int j = 0; j < students[au16ID-1].Nbrothers; j++)
                    {
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Name: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %s", students[au16ID-1].brothers[j].name);
                        cmdResetConsoleColour();
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Age: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %d", students[au16ID-1].brothers[j].age);
                        cmdResetConsoleColour();
                        cmdGoToXY(XPos, ++YPos);
                        printf("Brother %d Phone: ", j + 1);
                        cmdSetConsoleColour(TEXT_DYellow);
                        printf(" %s", students[au16ID-1].brothers[j].phone);
                        cmdResetConsoleColour();
                    }
                }
                cmdGoToXY(XPos, ++YPos);
                cmdSetConsoleColour(TEXT_Cyan);
                ShapeDraw_Line(XPos,YPos, Frame_Width/2,0) ;
                cmdResetConsoleColour();
                cmdGoToXY(XPos, ++YPos);
            }
        


    }


}



void Sort_studentsByName(void)
{
	au8SortFlag=1;
    sortStudentsByName(students,NumberOfStudents);
    cmdSetConsoleColour(TEXT_Cyan);
    ShapeDraw_FoldSquare(60,10,62,10);
    cmdGoToXY(61,15);
    cmdSetConsoleColour(TEXT_Highlight);
    printf("Sort Done By Name For All Students Check in Print All Studens ");
    cmdResetConsoleColour();
}


u32 compareStudents(const void *a, const void *b)
{
    const struct student *studentA = (const struct student *)a;
    const struct student *studentB = (const struct student *)b;
    return strcmp(studentA->name, studentB->name);
}

void sortStudentsByName(struct student* students, u16 NumberOfStudents)
{

    qsort(students, NumberOfStudents, sizeof(struct student), compareStudents);
}

void RemoveStudent(void)
{
    
    u16 au16ID=0;
    u8 input=0;
    cmdSetConsoleColour(TEXT_Cyan);
    ShapeDraw_FoldSquare(60,10,62,10);
    cmdGoToXY(68,15);
    cmdSetConsoleColour(TEXT_Highlight);
    printf("Please Enter ID of Student To REMOVE ");

    cmdSetConsoleColour(TEXT_DYellow);
    scanf("%d",&au16ID);
    cmdGoToXY(61,15);
    printf("                                                      ");
    if (au16ID > MAX_STUDENTS || au16ID < 1 || au16ID >students[NumberOfStudents-1].studentID)
    {
		 cmdGoToXY(68, 15);
        cmdSetConsoleColour(TEXT_Red);
        printf("Sudent ID doesnt EXIST!!");
        while (input != ESC)
        {
            cmdSetConsoleColour(TEXT_LYellow);
            cmdGoToXY(68, 16);
            printf("Press 'b' to go BACK");
            input = _getch();
            if (input == 'b')
            {
                return; // Return to indicate going back without saving
            }
        }
    }
    else 
    {
        removeStudentByID(students, &NumberOfStudents, au16ID);
        cmdSetConsoleColour(TEXT_Cyan);
        ShapeDraw_FoldSquare(60,10,62,10);
        cmdGoToXY(61,15);
        cmdSetConsoleColour(TEXT_Highlight);
        printf("Student REMOVED Successfully !! ");
        cmdResetConsoleColour();
    }

}
void removeStudentByID(struct student* students, u16* NumberOfStudents, int studentID)
{

    for (u16 i = 0; i < *NumberOfStudents; i++)
    {
        if (students[i].studentID == studentID)
        {
                
            // Shift the remaining elements to the left
            for (u16 j = i; j < *NumberOfStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*NumberOfStudents)--;
            break;
        }
    }

}

// Function to load student data from a file
void loadUserData(u16 *NumberOfStudents) {
    FILE *file = fopen("student_data.bin", "rb"); // Open file for reading in binary mode
    if (file != NULL) {
        fread(NumberOfStudents, sizeof(u16), 1, file); // Read the number of students
        if (*NumberOfStudents > 0) {
            students = (struct student*)malloc(*NumberOfStudents * sizeof(struct student)); // Allocate memory for the students array
            fread(students, sizeof(struct student), *NumberOfStudents, file); // Read the student data
        }
        fclose(file);
    } else {
        printf("Data file not found, creating a new file\n");
        // Create a new file and initialize the number of students to 0
        *NumberOfStudents = 0;
        file = fopen("student_data.bin", "wb"); // Open file for writing in binary mode
        if (file != NULL) {
            fwrite(NumberOfStudents, sizeof(u16), 1, file); // Write the number of students
            fclose(file);
        } else {
            perror("Error creating file for writing");
        }
    }
}

void saveDataOnExit(u16 NumberOfStudents) {
    saveUserData(NumberOfStudents);
    for (int i = 0; i < NumberOfStudents; i++) {
        if (students[i].Nbrothers > 0) {
            free(students[i].brothers);
            // Free the memory for the brothers array of each student
        }
    }
    free(students); // Free the memory allocated for the students array
}



void saveUserData(u16 NumberOfStudents) {
    FILE *file = fopen("student_data.bin", "wb"); // Open file for writing in binary mode
    if (file != NULL) {
        fwrite(&NumberOfStudents, sizeof(u16), 1, file); // Write the number of students
        if (NumberOfStudents > 0) {
            fwrite(students, sizeof(struct student), NumberOfStudents, file); // Write the student data
        }
        fclose(file);
    } else {
        perror("Error opening file for writing");
    }
}
void saveDataOnExitWrapper() {
    saveDataOnExit( NumberOfStudents);
}