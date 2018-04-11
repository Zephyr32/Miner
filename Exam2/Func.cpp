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
void Draw() {
	int flag = 10;
	for (int i = 0; i <= zise * 2; ++i) {
		for (int j = 0; j <= zise * 2; ++j) {
			if (i == 0 && j == 0)
				cout << char(0xda);
			else if (i == 0 && j == zise * 2)
				cout << char(0xbf);
			else if (i == zise * 2 && j == 0)
				cout << char(0xc0);
			else if (i == zise * 2 && j == zise * 2)
				cout << char(0xd9);
			else if (i == 0 && j % 2 == 0)
				cout << char(0xc2);
			else if (i == zise * 2 && j % 2 == 0)
				cout << char(0xc1);
			else if (j == 0 && i % 2 == 0)
				cout << char(0xc3);
			else if (j == zise * 2 && i % 2 == 0)
				cout << char(0xb4);
			else if (i % 2 == 0 && j % 2 == 0)
				cout << char(0xc5);
			else if (i % 2 == 0)
				cout << char(0xc4);
			else if (j % 2 == 0)
				cout << char(0xb3);
			else if (pole[i / 2][j / 2] >= 5000) // рисует курсор
				cout << "+";
			else if (pole[i / 2][j / 2] >= 2500)
				cout << "X";
			else if (pole[i / 2][j / 2] >= 1500)
				cout << "F";
			else if (pole[i / 2][j / 2] >= 100) // рисует мину-смайл
				cout << char(1);
			else if (pole[i / 2][j / 2] > 0)
				cout << pole[i / 2][j / 2];
			else if (pole[i / 2][j / 2] == 0)
				cout << "."; // свободное место без мин и цифр
			else {
				cout << ' '; // межъ€чеечное пространство таблицы
			}

		}
		cout << endl;
	}
	cout << endl << flag << " flags left";
}

