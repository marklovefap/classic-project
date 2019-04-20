#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<conio.h>
#include<windows.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
using namespace std;
void score(int sc){
    gotoxy(69,21);
    cout<<sc*10;
void status(char *s,int c=1){
    gotoxy(69,22);
    textcolor(c);
    int x;
    for(x=0;x<strlen(s);x++)
    	cout<<s[x];
    for(;x<8;x++)
        cout<<" ";
    textcolor(7);
}
