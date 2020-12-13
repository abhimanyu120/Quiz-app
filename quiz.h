#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED
#include <string>
using namespace std;
class User
{
protected:
  char userid[20];
  char pwd[20];
  char type[10];
  char uname[20];
public:
    void setUserDetails(char *,char *,char *,char *);
    char * getName(char *);
    void show();
    int input();
    int checkUserExist(char *);
};
class Student:public User
{
public:
    void add();
    void showStudentDetails();
    void quiz();
    void viewPerfomance();
};
class Admin:public User
{
public:
    static void create_admin(char *,char *,char *);
    void addStudent();
    void viewStudent();
    void addQuestion();
    void viewQuestion();
};
class Question
{
    int quesid;
    char ques[100];
    char op1[30];
    char op2[30];
    char op3[30];
    char op4[30];
    char ans;
public:
    void add();
    void viewQuestion();
    void show();
    int Questioncount();
    int starttest();

};
class Perfomance
{
    char id[30];
    int totalmarks;
    int gainmark;
public:
    void setmarkdetail(int,int,char *);
    void viewdetails(char *);


};


#endif // QUIZ_H_INCLUDED
