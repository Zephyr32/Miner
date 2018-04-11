#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<ctime>
#include<string>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define SPACE 32
#define ENTER 13
using namespace std;
struct game 
{
	string name;
	int score;
	int healt;
	int complication;
	int minedefused;
	int remainingmines;
	int elapsed_times;

};
void gotoxy(short x, short y);
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black);
//#include "Logics.h";
void score(game *&player);
