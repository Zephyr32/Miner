#include"Header.h"
const int zise = 10;
int pole[zise][zise];
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void clearfield() 
{


}
void SetMine() 
{

}

