#include<iostream>
#include"conio2.h"
#include"quiz.h"
#include<cstring>
#include<fstream>
using namespace std;
#include<string>
void User::setUserDetails(char *userid,char *name,char *pwd,char *type)
{
    strcpy(this->userid,userid);
    strcpy(this->pwd,pwd);
    strcpy(this->uname,name);
    strcpy(this->type,type);
}
void Admin::create_admin(char*u,char*p,char*t)
{
    fstream fout("D:\\User.bin",ios::binary|ios::in);
        if(fout)
        {
            cout<<"File exist";
            fout.close();
        }
        else
            fout.open("D:\\User.bin",ios::out|ios::binary);
        User adminUser;
        adminUser.setUserDetails(u,"Abhi",p,"Admin");
        fout.write((char*)&adminUser,sizeof(User));
        fout.close();
}
int User::input()
{
    clrscr();
    textcolor(RED);
    gotoxy(40,1);
    cout<<"Quiz application";
    gotoxy(1,6);
    textcolor(GREEN);
      int i;
for(i=1;i<90;i++)
    {
    cout<<"*";
    }
    gotoxy(1,14);
    for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
    textcolor(GREEN);
    gotoxy(70,1);
    cout<<"Press 0 to exit";
    textcolor(YELLOW);
    gotoxy(40,8);
    cout<<"Enter user id: ";
    cin.ignore();
    cin.getline(userid,20);
    if(strcmp(userid,"0")==0)
    {
        return 0;
    }
        gotoxy(40,9);
        cout<<"Enter your password:";
        for(i=0;;i++)
        {
            pwd[i]=getch();
            if(pwd[0]=='0')
            {
                clrscr();
                return 0;
            }
            if(pwd[i]=='\r')
            break;
            cout<<"*";
        }
        pwd[i]='\0';
    return 1;
    }
    int User::checkUserExist(char *t)
    {
        if(strcmp(t,"student")==0)
        {
              Student s;
              int i,j;
      ifstream fin;
      fin.open("D:\\student.dat",ios::in|ios::binary);
      while(1)
      {
          fin.read((char *)&s,sizeof(s));
          if(fin.eof()==true)
            break;
          i= strcmp(s.userid,userid);
          j=strcmp(s.pwd,pwd);
          if(i==0)
            break;
      }
      fin.close();
       if(i!=0)
       {
            gotoxy(1,21);
         textcolor(LIGHTRED);
        cout<<endl;
        cout<<"user id should be wrong";
        return 0;
      }
           if(j==0)
           {
               textcolor(GREEN);
               cout<<endl<<"LOGIN SUCCESSFULL.....";
               getch();
               return 1;
           }
           if(j!=0)
           {
                gotoxy(1,21);
             textcolor(LIGHTRED);
            cout<<endl<<"password incorrect";
            return 0;
           }
           }
           //return 1;

        if(strcmp(t,"admin")==0)
           {
      User s;
      ifstream fin;
      fin.open("D:\\user.bin",ios::in|ios::binary);
      fin.read((char *)&s,sizeof(s));
      int i= strcmp(s.userid,userid);
      int j=strcmp(s.pwd,pwd);
      fin.close();
       if(i!=0)
       {
            gotoxy(1,21);
         textcolor(LIGHTRED);
        cout<<endl;
        cout<<"user id should be wrong";
        return 0;
      }
           if(j==0)
           {
               textcolor(GREEN);
               cout<<endl<<"LOGIN SUCCESSFULL.....";
               getch();
               return 1;
           }
           if(j!=0)
           {
                gotoxy(1,21);
             textcolor(LIGHTRED);
            cout<<endl<<"password incorrect";
            return 0;
           }
           }
           return 1;
    }
    void Question::add()
    {
     char uchoice;
     fstream fout("D:\\Question.bin",ios::binary|ios::app);
    if(fout.is_open()==false)
    {
    cout<<"file not exist";
    }
    fout.seekp(0,ios::end);
    if(fout.tellg()==0)
    {
     quesid=1;
     }
     else
     {
      quesid=fout.tellg()/sizeof(Question);
      quesid++;
      }
      do
        {
            clrscr();
      gotoxy(37,2);
      textcolor(LIGHTRED);
      cout<<"QUIZ APP";
      textcolor(LIGHTGREEN);
      gotoxy(1,3);
      for(int i=0; i<80; i++)
        {
            cout<<"*";
      }
      textcolor(WHITE);
      gotoxy(25,5);
cout<<"***** ADD QUESTION DETAILS *****";
gotoxy(1,8);
textcolor(YELLOW);
cout<<"Enter question:";
cin.ignore();
textcolor(WHITE);
cin.getline(ques,500,'*');
textcolor(LIGHTGREEN);
cout<<endl<<"OPTIONS"<<endl<<endl;
textcolor(YELLOW);
cout<<"(a) ";
cin.ignore();
textcolor(WHITE);
cin.getline(op1,100);
textcolor(YELLOW);
cout<<"(b) ";
textcolor(WHITE);
cin.getline(op2,100);
textcolor(YELLOW);
cout<<"(c) ";
textcolor(WHITE);
cin.getline(op3,100);
textcolor(YELLOW);
cout<<"(d) ";
textcolor(WHITE);
cin.getline(op4,100);
textcolor(YELLOW);
cout<<endl<<"Enter correct ans :";
textcolor(WHITE);
cin>>ans;
fout.write((char *)this,sizeof(Question));
quesid++;
gotoxy(34,30);
textcolor(LIGHTGREEN);
cout<<"QUESTION ADDEDD SUCCESSFULLY"<<quesid;
getch();
gotoxy(1,32);
textcolor(LIGHTRED);
cout<<endl<<"Do you want to add more questions(Y/N) :";
textcolor(WHITE);
cin>>uchoice;
}
while(uchoice=='Y'||uchoice=='y');
fout.close();
}
    void Admin::addQuestion()
    {
       Question a;
       a.add();

    }
    void Question::viewQuestion()
{
ifstream fout("D:\\Question.bin",ios::in|ios::binary);
if(!fout)
{
cout<<"File Not Exist! Please try again!";
getch();
add();
}
Question quesobjr;
clrscr();
while(1)
{
gotoxy(37,2);
textcolor(LIGHTRED);
cout<<"QUIZ APP";
textcolor(LIGHTGREEN);
gotoxy(1,3);
for(int i=0; i<80; i++)
{
cout<<"*";
}
textcolor(WHITE);
gotoxy(25,5);
cout<<"***** SHOW QUESTION DETAILS *****";
gotoxy(1,7);
textcolor(LIGHTGREEN);
for(int i=1; i<=80; i++)
cout<<"*";
fout.read((char*)&quesobjr,sizeof(Question));
if(fout.eof())

{
cout<<endl;
textcolor(LIGHTRED);
gotoxy(35,10);
cout<<"NO MORE QUESTIONS";
getch();
break;
}
if(fout.fail())
{
cout<<"Reading failed!";
break;
}
else
{
quesobjr.show();
getch();
clrscr();
}
}
fout.close();
}
void Question::show()
{
cout<<endl;
textcolor(YELLOW);
cout<<"Q."<<quesid<<" ";
cout<<ques<<"?"<<endl;
cout<<"a. "<<op1<<endl<<"b. "<<op2<<endl<<"c. "<<op3<<endl<<"d. "<<op4<<endl;
textcolor(LIGHTGREEN);
cout<<endl<<"Correct Option : "<<ans;
}
       void  Admin::viewQuestion()
        {
        Question quesobj;
        quesobj.viewQuestion();
        clrscr();
        }
void Student::add()
{
char uchoice;
int id;
char stu[10]="STU-";
char stuid[3];
fstream fout("D:\\Student.dat",ios::binary|ios::app);
if(!fout)
{
cout<<"error";
getch();
}
fout.seekg(0,ios::end);
if(fout.tellg()==0)
{
id=1;
sprintf(stuid,"%d",id);
strcat(stu,stuid);
strcpy(userid,stu);
strcpy(stu,"STU-");
}
else
{
id=fout.tellg()/sizeof(Student);
id++;
sprintf(stuid,"%d",id);
strcat(stu,stuid);
strcpy(userid,stu);
strcpy(stu,"STU-");
}
do
{
clrscr();
gotoxy(37,2);
textcolor(LIGHTRED);
cout<<"QUIZ APP";
textcolor(LIGHTGREEN);
gotoxy(1,3);
for(int i=0; i<80; i++)
{
cout<<"~";
}
textcolor(WHITE);
gotoxy(25,5);
cout<<"***** ADD STUDENT DETAILS *****";
gotoxy(1,8);
textcolor(YELLOW);
cout<<"Enter Student Name:";
cin.ignore();
textcolor(WHITE);
cin.getline(uname,20);
textcolor(YELLOW);
cout<<"Enter Student Password:";
textcolor(WHITE);
cin.getline(pwd,20);
fout.write((char *)this,sizeof(Student ));
gotoxy(30,15);
textcolor(LIGHTGREEN);
cout<<"STUDENT ADDED SUCCESSFULLY";
cout<<endl<<" STUDENT ID IS: "<<userid;
getch();
gotoxy(1,20);
textcolor(LIGHTRED);
cout<<"Do You WANT TO ADD MORE STUDENT(Y/N) :";
cin>>uchoice;
id++;
sprintf(stuid,"%d",id);
strcat(stu,stuid);
strcpy(userid,stu);
strcpy(stu,"STU-");
}
while(uchoice=='Y'||uchoice=='y');
fout.close();
}
void Admin::addStudent()
{
Student studobj;
studobj.add();
}
void Student::showStudentDetails()
{
clrscr();
Student studobjr;
ifstream fout("D:\\Student.dat",ios::in|ios::binary);
if(!fout)
{
textcolor(LIGHTRED);
cout<<"NO STUDENT ENROLLED!";
cout<<"Press any key to continue";
add();
}
while(1)
{
gotoxy(37,2);
textcolor(LIGHTRED);
cout<<"QUIZ APP";
textcolor(LIGHTGREEN);
gotoxy(1,2);
for(int i=0; i<80; i++)
{
cout<<"*";
}
textcolor(WHITE);
gotoxy(27,5);
cout<<"***** SHOW STUDENT DETAILS *****";
textcolor(LIGHTGREEN);
gotoxy(1,7);
for(int i=0; i<80; i++)
cout<<"*";
fout.read((char*)&studobjr,sizeof(Student));
if(fout.eof())
{
textcolor(LIGHTRED);
gotoxy(25,10);
cout<<"*******NO MORE RECORDS TO SHOW*******";
getch();
break;
}
if(fout.fail())
{
cout<<"Reading failed!";
getch();
break;
}
else
{
studobjr.show();
getch();
clrscr();
}
}
fout.close();
}
void User::show()
{
textcolor(YELLOW);
cout<<endl;
cout<<"User Name is: ";
textcolor(LIGHTGREEN);
cout<<uname<<endl;
textcolor(YELLOW);
cout<<"UserId is: ";
textcolor(LIGHTGREEN);
cout<<userid<<endl;
textcolor(YELLOW);
cout<<"Password is: ";
textcolor(LIGHTGREEN);
cout<<pwd<<endl;
}
void Admin::viewStudent()
{
        Student studobj;
        studobj.showStudentDetails();
        clrscr();
}
    char* User::getName(char *u)
    {
        static char name[20];
        ifstream fout("D:\\Student.dat",ios::in|ios::binary);
        User check;
        while(1)
        {
            fout.read((char*)&check,sizeof(check));
            if(fout.eof())
                break;
           int j= strcmp(u,check.userid);
            if(j==0)
            {
                fout.close();
                strcpy(name,check.uname);
                return name;
            }

        }

    }
    int Question::Questioncount()
    {
        static int count=0;
        ifstream fout("D:\\Question.bin",ios::in|ios::binary);
if(!fout)
{
cout<<"File Not Exist! Please try again!";
getch();
add();
}
Question quesobjr;
clrscr();
while(1)
{
    fout.read((char*)&quesobjr,sizeof(Question));
    if(fout.eof())
    break;
    count++;
}
fout.close();
return count;
    }
 int Question::starttest()
 {
     int count=0;
                    ifstream fout("D:\\Question.bin",ios::in|ios::binary);
if(!fout)
{
cout<<"File Not Exist! Please try again!";
getch();
}
while(1)
{
    fout.read((char *)this,sizeof(Question));
    if(fout.eof()==true)
    {
        cout<<"Question over";
        break;
    }
    textcolor(GREEN);
    cout<<endl;
    cout<<this->quesid;
    cout<<". ";
    cout<<this->ques;
    cout<<"?";
    cout<<endl;
    textcolor(WHITE);
    cout<<"a."<<this->op1;
    cout<<endl;
    cout<<"b."<<this->op2;
    cout<<endl;
    cout<<"c."<<this->op3;
    cout<<endl;
    cout<<"d."<<this->op4;
    textcolor(RED);
    cout<<endl<<"Enter your option: ";
    textcolor(YELLOW);
    char c;
    cin>>c;
    if(this->ans==c)
        count=count+10;
        clrscr();
 }
 return count;
 }
   void Perfomance::setmarkdetail(int tm,int gm,char *id)
   {
       Perfomance put;
       strcpy(put.id,id);
       put.gainmark=gm;
       put.totalmarks=tm;
       fstream fout;
       fout.open("D:\\perfomance.dat",ios::binary|ios::app);
       fout.write((char*)&put,sizeof(put));
       fout.close();
   }

void Student:: quiz()
{
   char *name;
   name= getName(userid);
   Question quesobj;
   int a= quesobj.Questioncount();
   getch();
   textcolor(RED);
   clrscr();
   gotoxy(40,1);
   cout<<"Quizapp";
   gotoxy(1,3);
   textcolor(YELLOW);
   int i;
   for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                textcolor(WHITE);
                gotoxy(1,4);
                cout<<"Total question ="<<a;
                gotoxy(70,4);
                cout<<name;
                gotoxy(1,5);
                textcolor(YELLOW);
                 for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                   int r= quesobj.starttest();
                   int totalmark;
                   totalmark=a*10;
                   Perfomance detail;
                   detail.setmarkdetail(totalmark,r,userid);
                   getch();



}
void Perfomance::viewdetails(char *id)
{
         fstream fout;
         Perfomance q ;
         clrscr();
         textcolor(RED);
         gotoxy(43,1);
         cout<<"QUIZ APP";
         gotoxy(1,2);
         int i;
         textcolor(GREEN);
         for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    textcolor(YELLOW);
                    gotoxy(38,3);
                    cout<<"****VIEW REPORT CARD****";
                    cout<<endl;
                    for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    gotoxy(1,5);
                    cout<<"USER ID: ";
                    cout<<id;
                    textcolor(GREEN);
                    cout<<endl;
                    gotoxy(1,7);
                    cout<<"SNO\t\t\tMARK OBTAINED\t\t\tTOTAL MARKS";
                    cout<<endl;
       fout.open("D:\\perfomance.dat",ios::binary|ios::in);
       if(fout.is_open()==false)
       {
           cout<<"Sorry file should not open";
           return;

       }
       int j=1;

       while(1)
       {
           fout.read((char *)&q,sizeof(q));
           if(fout.eof()==true)
            break;
            if(strcmp(q.id,id)==0)
            {
                cout<<j<<"."<<"\t\t\t"<<q.gainmark<<"\t\t\t\t"<<q.totalmarks<<endl;
                j++;
            }

       }
       textcolor(YELLOW);
         for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    textcolor(RED);
                    cout<<endl;
                    cout<<"\t\t\t\t\t";
                    cout<<"NO MORE RECORD";
       fout.close();
}




void Student::viewPerfomance()
{
    Perfomance spobj;
    //cout<<userid;
    spobj.viewdetails(userid);
}


