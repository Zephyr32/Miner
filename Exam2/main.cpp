#include"Header.h"
struct score
{
	string name;
	short score;
	short lifecount;
	short sizepole;
	short countMines;
	short Minets;
	float sec;
};
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void SetColor(int text, int background = Black)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
#include "Logics.h";
bool GameStatus = true;
void Game()
{
	Miners miners(2, 5);
	while (GameStatus)
	{
		miners.Update();
		GameStatus = miners.GetBool();
	}
}
void PrintScore() 
{
	
	FILE *sizescore = fopen("sizescore.txt", "r");
	int SizeScore;
	fscanf(sizescore, "%d", SizeScore);
	fclose(sizescore);
	sizescore = fopen("scores.txt", "r");
	score *player = new score[SizeScore];
	for (int i = 0; i < SizeScore; i++)
	{
		fscanf(sizescore, "%10s %5d %10d %11d %13d %6d %7d",
			player[i].name.c_str(),
			player[i].score,
			player[i].lifecount,
			player[i].sizepole,
			player[i].countMines,
			player[i].Minets,
			player[i].sec
		);
	}
	printf("%10s %5d %10d %11d %13d %6d %7d",
		"Имя",
		"Очки",
		"Очки жизни",
		"Размер поля",
		"Количество мин",
		"Минуты",
		"Секунды"
	);
	for (int i = 0; i < SizeScore; i++)
	{
		printf("%10s %5d %10d %11d %13d %6d %7d",
			player[i].name.c_str(),
			player[i].score,
			player[i].lifecount,
			player[i].sizepole,
			player[i].countMines,
			player[i].Minets,
			player[i].sec
		);
	}
}
void main()
{
	system("mode con cols=122 lines=56");
	srand(time(0));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	size = 10;
	int k = 1;
	char en = 0;
	PlaySound("main.wav", NULL, SND_ASYNC);
	do
	{

		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 5)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 4;
		}
		if (en == 13)
		{
			if (k == 1)
			{
				//Начать игру
				Game();
				//system("pause");
				system("cls");
				system("pause");

			}
			if (k == 2)
			{
				//Список Рекордов считывать
				
				PrintScore();
				system("pause");

				system("cls");
			}
			if (k == 3)
			{
				//Настройки
				
				
				system("pause");
				system("cls");

			}
			if (k == 4)
			{
				//Выход
				system("cls");
				cout << "MADE BY!" << endl;
				SetColor(13);
				cout << "________       _______       ________                                    ________   " << endl;
				cout << "       /       |            |        |      |         |   \\        /    |        | " << endl;
				cout << "      /        |            |        |      |         |    \\      /     |        | " << endl;
				cout << "     /         |            |        |      |         |     \\    /      |        | " << endl;
				cout << "    /          |______      |________|      |_________|      \\  /       |________|        " << endl;
				cout << "   /           |            |               |         |        /        |    \\      " << endl;
				cout << "  /            |            |               |         |       /         |     \\     " << endl;
				cout << " /             |            |               |         |      /          |      \\     " << endl;
				cout << "/_______       |______      |               |         |     /           |       \\   " << endl;
				SetColor(7);
				system("pause");
				exit(0);
			}
		}
		gotoxy(28, 0);
		SetColor(11);
		cout << "Miner";
		SetColor(7);
		if (k == 1)
			SetColor(13);
		gotoxy(15, 2);
		cout << "1. Начать игру" << endl;
		SetColor(7);
		if (k == 2)
			SetColor(13);
		gotoxy(15, 3);
		cout << "2. Список рекордов" << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(15, 4);
		cout << "3. Настройки " << endl;
		SetColor(7);
		if (k == 4)
			SetColor(13);
		gotoxy(15, 5);
		cout << "4. Выход" << endl;
		SetColor(7);
	} while (en = _getch());
	system("pause");
	
}
