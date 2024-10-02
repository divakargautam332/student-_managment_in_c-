#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
typedef struct
{
    char name[20],branch[20],course[20];
    int roll,s_no;
    float cgpa,mobile_no;
}Student;
#define MAX_STUDENT 100
int studentcount=1;
int rollnumber=1;
Student students[MAX_STUDENT];
void again_call_add();
void clrscr(void);
void student_information_first_page();
void gotoxy(int x,int y);
void add_student_information();
void view_student_information();
void search_student_information();
void delete_student_information();
void exit_pro();
int main(){
    system("cls");
    FILE *fptr;
    fptr = fopen("student.txt","r");
    int n=1;
    int count=0;
    for (int i = 1; i <=MAX_STUDENT; i++)
    {
    
    fscanf(fptr," %s\n",        &students[i].name     );
    fscanf(fptr," %d\n",        &students[i].roll     );
    fscanf(fptr," %s\n",        &students[i].course   );
    fscanf(fptr," %s\n",        &students[i].branch   );
    fscanf(fptr," %f\n",        &students[i].cgpa     );
    fscanf(fptr," %f\n",        &students[i].mobile_no);
    if (i==students[i].roll)
    {
    count++;
    n++;
    }
    }
    if (count<MAX_STUDENT)
    {
        fscanf(fptr," %d\n",        &students[count].roll     );
    if (count==students[count].roll)
    {
        rollnumber=students[count].roll;
    }
    }
    fclose(fptr);
    rollnumber++;
    student_information_first_page();


    return 0;
}








void add_student_informatin(){
    system("cls");
    FILE *fptr;
    fptr =fopen("student.txt","a");
    fclose(fptr);
}
void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void student_information_first_page(){
    system("cls");
    int n;
    gotoxy(50,1);
    printf("|<------------------STUDENT MANAGMENT SYSTEM------------------->|\n ");
    gotoxy(50,2);
    printf("|_______________________________________________________________|\n");
    gotoxy(50,3);
    printf("|                        <--:student:-->                        |\n");
    gotoxy(50,4);
    printf("|                                                               |\n");
    gotoxy(50,5);
    printf("|                                                               |\n");
    gotoxy(50,6);
    printf("|                                                               |\n");
    gotoxy(50,7);
    printf("|              1.  add student information.                     |\n");
    gotoxy(50,8);
    printf("|                                                               |\n");
    gotoxy(50,9);
    printf("|              2.  view student information.                    |\n");
    gotoxy(50,10);
    printf("|                                                               |\n");
    gotoxy(50,11);
    printf("|              3.  search student informaion.                   |\n");
    gotoxy(50,12);
    printf("|                                                               |\n");
    gotoxy(50,13);
    printf("|              4.  delete student information.                  |\n");
    gotoxy(50,14);
    printf("|                                                               |\n");
    gotoxy(50,15);
    printf("|              5.  exit.                                        |\n");
    gotoxy(50,16);
    printf("|                                                               |\n");
    gotoxy(50,17);
    printf("|_______________________________________________________________|");
    gotoxy(50,18);
    printf("choice any option.");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
            add_student_information();
            break;
            case 2:
            view_student_information();
            break;
            case 3:
            search_student_information();
            break;
            // case 4:
            // delete_student_information();
            // break;
        default:exit_pro();
                break;
    }
}








void add_student_information(){
    system("cls");
    if (studentcount>=MAX_STUDENT)
    {
        printf("student list is full \n");
        return;
    }
    FILE *fptr;
    int n=0;
    int i=0;
    char another;
    do
    {
        fptr =fopen("student.txt","a");
    i++;
    n++;
    Student s;
    printf("<------enter %d student record-------> \n\n",rollnumber);
    printf("student name :");
    scanf("%s",&s.name);
    s.roll=rollnumber;
    printf("student roll number : %d\n",s.roll);
    printf("course of student :");
    scanf("%s",&s.course);
    printf("branch of student :");
    scanf("%s",&s.branch);
    printf("student cgpa :");
    scanf("%f",&s.cgpa);
    printf("student phone number :");
    scanf("%f",&s.mobile_no);
    fprintf(fptr," %s\n",        s.name     );
    fprintf(fptr," %d\n",        s.roll     );
    fprintf(fptr," %s\n",        s.course   );
    fprintf(fptr," %s\n",        s.branch   );
    fprintf(fptr," %f\n",        s.cgpa     );
    fprintf(fptr," %f\n",        s.mobile_no);
    printf("________________________________________________\n");
    students[studentcount]=s;
    studentcount++;
    rollnumber++;
    fclose(fptr);
    printf("do you want add another student record(y/n) :");
    scanf("%s",&another);
    } 
    while (another=='y'||another=='y');
    printf("\n\n");
    char y; 
    printf("do you wnat to reach menu baar enter (y/n) :");
    scanf("%s",&y);
    if (y==y)
    {
        student_information_first_page();
    }
}








void view_student_information(){
    system("cls");
    FILE *fptr;
    fptr = fopen("student.txt","r");
    int v;
    printf("enter the number of student to check record :");
    scanf("%d",&v);
    studentcount=v;
    int n=1;
    int count=0;
    for (int i = 1; i <=studentcount; i++)
    {
    
    fscanf(fptr," %s\n",        &students[i].name     );
    fscanf(fptr," %d\n",        &students[i].roll     );
    fscanf(fptr," %s\n",        &students[i].course   );
    fscanf(fptr," %s\n",        &students[i].branch   );
    fscanf(fptr," %f\n",        &students[i].cgpa     );
    fscanf(fptr," %f\n",        &students[i].mobile_no);
    if (i==students[i].roll)
    {
    count++;
    printf("\n\n\n\n<------%d student record-------> \n\n",n);
    printf("student name     : %s\n",        students[i].name     );
    printf("student roll     : %d\n",        students[i].roll     );
    printf("student course   :%s\n",         students[i].course   );
    printf("student branch   :%s\n",         students[i].branch   );
    printf("student cgpa     : %f\n",        students[i].cgpa     );
    printf("student phone no : %f\n",        students[i].mobile_no);
    n++;
    }
    }
    if (count<v)
    {
        fscanf(fptr," %d\n",        &students[count].roll     );
    if (count==students[count].roll)
    {
        printf("\nONLY %d STUDENT RECORD AVAILBLE",students[count].roll);
    }
    }
    fclose(fptr);
    char y; 
    printf("\n\ndo you wnat to reach menu baar enter (y/n) :");
    scanf("%s",&y);
    if (y==y)
    {
        student_information_first_page();
    }
}









void search_student_information()
{
    system("cls");
    FILE *fptr;
    fptr = fopen("student.txt","r");
    int r,count=0;
    printf("enter the student roll no :");
    scanf("%d",&r);
    int n=1;
    for (int i = 1; i <=MAX_STUDENT; i++)
    {
    fscanf(fptr," %s\n",        &students[i].name     );
    fscanf(fptr," %d\n",        &students[i].roll     );
    fscanf(fptr," %s\n",        &students[i].course   );
    fscanf(fptr," %s\n",        &students[i].branch   );
    fscanf(fptr," %f\n",        &students[i].cgpa     );
    fscanf(fptr," %f\n",        &students[i].mobile_no);
    if (i==students[i].roll)
    {
    count++;
    n++;
    }
    if (students[i].roll==r)
    {
    printf("<------roll no %d student record-------> \n\n",r);
    printf("student name     : %s\n",        students[i].name     );
    printf("student roll     : %d\n",        students[i].roll     );
    printf("student course   :%s\n",         students[i].course   );
    printf("student branch   :%s\n",         students[i].branch   );
    printf("student cgpa     : %f\n",        students[i].cgpa     );
    printf("student phone no : %f\n",        students[i].mobile_no);
    break;
    }
    }
    if (count<r)
    {
        printf("this student not availble");
    }
    fclose(fptr);
    char y; 
    printf("\n\ndo you wnat to reach menu baar enter (y/n) :");
    scanf("%s",&y);
    if (y==y)
    {
        student_information_first_page();
    }
}








void exit_pro(){
    exit(0);
}
