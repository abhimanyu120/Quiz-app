#include <iostream>
#include "conio2.h"
#include "quiz.h"
using namespace std;
int main()
{
    Admin::create_admin("uadmin","abc","admin");
    clrscr();
    textcolor(GREEN);
    int i;
for(i=1;i<90;i++)
    {
    cout<<"*";
    }
    textcolor(RED);
    gotoxy(40,2);
    cout<<"QUIZ APPLICATION";
     textcolor(GREEN);
     gotoxy(1,3);
    for(i=1;i<90;i++)
    {
    cout<<"*";
    }
    textcolor(YELLOW);
    gotoxy(33,7);
    cout<<"WELCOME TO TEST - QUIZ APPLCATION";
    textcolor(GREEN);
    gotoxy(33,10);
    cout<<"TEST YOUR SKILLS! IMPROVE YOUR KNOWLEDGE";
    cout<<endl;
    textcolor(WHITE);
    gotoxy(20,14);
    cout<<"Press any key to continoue....";
    gotoxy(1,13);
    getch();
    clrscr();
    gotoxy(1,1);
    int choice;
    do
    {
        textcolor(RED);
        gotoxy(40,1);
        cout<<"Quiz Application";
        cout<<endl;
        textcolor(GREEN);
     for(i=1;i<90;i++)
    {
    cout<<"*";
    }
    gotoxy(1,12);
    for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }

    textcolor(YELLOW);
    gotoxy(40,4);
    cout<<"1.ADMIN"<<endl;
    gotoxy(40,6);
    cout<<"2.STUDENT"<<endl;
    textcolor(RED);
    gotoxy(40,8);
    cout<<"Select a choice: ";
    textcolor(WHITE);
    cin>>choice;
    if(choice==1)
    {
       User inf;
       int i=inf.input();
       if(i==0)
       {
           clrscr();
        cout<<"user want to exit";
        exit;
       }
       if(i==1)
       {
         int k=inf.checkUserExist("admin");
         if(k==0)
            exit;
            if(k==1)
            {
                clrscr();
                while(1)
                {
                    clrscr();
                textcolor(RED);
                gotoxy(40,1);
                cout<<"QUIZ APPLICATION";
                textcolor(GREEN);
                gotoxy(42,3);
                cout<<"ADMIN MENU";
                cout<<endl;
                for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    gotoxy(1,15);
                    for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    textcolor(YELLOW);
                    gotoxy(42,6);
                    cout<<"1. Add Question";
                    gotoxy(42,7);
                    cout<<"2. Add Student";
                    gotoxy(42,8);
                    cout<<"3. Show Question";
                    gotoxy(42,9);
                    cout<<"4. Show Student";
                    gotoxy(42,10);
                    cout<<"5. Exit";
                    gotoxy(42,12);
                    textcolor(RED);
                    cout<<"Enter a choice: ";
                    int choice;
                    textcolor(WHITE);
                    cin>>choice;
                    if(choice==5)
                        break;
                        if(choice==1)
                        {
                            Admin que;
                            que.addQuestion();

                        }
                        if(choice==2)
                        {
                            Admin ad;
                            ad.addStudent();

                        }
                        if(choice==3)
                        {
                            Admin  obj;
                            obj.viewQuestion();

                        }

                        if(choice==4)
                        {
                            Admin vs;
                        vs.viewStudent();
                        }



            }


       }
       }
    }
    else if (choice==2)
    {
       Student st;
       int x=st.input();
       if(x==1)
       {
       int l=st.checkUserExist("student");
       if(l==1)
       {
           while(1)
           {
           clrscr();
           textcolor(RED);
                gotoxy(40,1);
                cout<<"QUIZ APPLICATION";
                textcolor(GREEN);
                gotoxy(42,3);
                cout<<"STUDENT MENU";
                cout<<endl;
                for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }
                    gotoxy(1,15);
                    for(i=1;i<90;i++)
                    {
                     cout<<"*";
                    }

                    textcolor(YELLOW);
                    gotoxy(42,6);
                    cout<<"1. Start quiz";
                    gotoxy(42,7);
                    cout<<"2. view perfomance";
                    gotoxy(42,8);
                    cout<<"3. exit";
                    cout<<endl<<endl;
                    textcolor(RED);
                    cout<<"\t\t\t\tEnter Your choice: ";
                    textcolor(YELLOW);
                    int choice;
                    cin>>choice;
                    if(choice==3)
                        break;
                    if(choice==1)
                    {
                        st.quiz();
                        int qc;
                        getch();
                    }
                    if(choice==2)
                    {
                        st.viewPerfomance();
                        getch();
                    }

       }
       }
       }
    }
    else
        cout<<"Wrong choice";
        getch();
        clrscr();
    }while(choice!=1||choice!=2);

    return 0;
}

