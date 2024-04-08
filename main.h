#ifndef MAIN_H_
#define MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>   // Windows API header
#include <time.h>
#include <stdbool.h>
/***************_File_Management_INCLUDES_*****************/
#include "ShapesDesign/Design.h"

/***************_DEDINES_************************/
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
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_S 115
#define   ESC                     27
#define   ENTER                   13	
#define   Menu3_Total_Options     4
#define   Menu3_Opt_Length        7
#define   Menu3_XPos              78
#define   Menu3_YPos              30
#define   ESC                      27
#define   R                        114
#define   B                        98
#define   ENTER                    13	
#define   Menu2_Total_OptionsG     2
#define   Menu2_Opt_LengthG        70
#define   Menu2_XPosG              12
#define   Menu2_YPosG              22
#define TEXT_Highlight 14
#define  BELL             7
#define  BLOCK          (177)
#define   Menu1_Total_Options     9
#define   Menu1_Opt_Length        19
#define   Menu1_XPos              65
#define   Menu1_YPos              22
#define   Add_StudentsXPos             16
#define   Add_StudentsYPos             3
#define   au16WIDTH             190
#define   au16HEIGHT             40
#define FILENAME "data.txt"
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 COORD cursorPos; 
 u16 YPos=0;
 u16 XPos=0;
 u16 YMAXLIMIT=0;
 u16 XMAXLIMIT=0;
 u16 YMINLIMIT=0;
 u16 XMINLIMIT=0;

/***************_main.c_FUNCTION_PROTOTYPE_****************/
typedef struct 
{
    char name[20];
	char phone[12];
	 int age;

}person_t;
struct student
{
	int studentID;
    char name[20];
    int age;
    char grade;
	char phone[12];
	person_t father;
	person_t mother;
	int Nbrothers;
	person_t *brothers;

};
u32 compareStudents(const void *a, const void *b);
void RemoveStudent(void);
void removeStudentByID(struct student* students, u16* NumberOfStudents, int studentID) ;
void Sort_studentsByName(void);
void sortStudentsByName(struct student* students, u16 NumberOfStudents);
void saveUserData( u16 NumberOfStudents) ;
void loadUserData( u16 *NumberOfStudents);
void saveDataOnExit( u16 NumberOfStudents);
void saveDataOnExitWrapper(void);
void print_students(struct student* students, u16 NumberOfStudents);
void str_scan(char *str);
void Edit_student(void);
void printOne_student(void);
void Call_student(void);
struct student student_scan(u32 studentID);
struct student* Add_students(void);
struct student*  AddOne_student(void);
person_t Parents_scan1(void);
person_t Parents_scan3(void);
person_t Parents_scan33(void);
person_t Parents_scan(void);
#endif /* MAIN_H_ */
