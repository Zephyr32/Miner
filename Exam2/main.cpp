#include"Header.h"

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
void Game(int cmp)
{
	int mini;
	int pole;
	int steps;
	switch (cmp)
	{
	case 1:
		mini = 3;
		pole = 5;
		steps = 24;
		system("mode con cols=50 lines=22");
		break;
	case 2:
		mini = 10;
		pole = 10;
		steps = 95;
		system("mode con cols=70 lines=32");
		break;
	case 3:
		mini = 20;
		pole = 15;
		steps = 205;
		system("mode con cols=90 lines=42");
		break;
	default:
		break;
	}
	GameStatus = true;
	Miners* miners = new Miners(mini, pole);
	miners->set_Steps(steps);
	miners->Init();
		
		while (GameStatus)
		{
			miners->Update();
			GameStatus = miners->GetBool();
		}
	system("mode con cols=70 lines=32");
}
void PrintScore(int SizeScore,Score *&player,FILE *sizescore) 
{
	ifstream fin;
	fin.open("scores.txt", ios_base::in);
	
	for (int i = 0; i < SizeScore; i++)
	{
		fin >> player[i].name;
		fin >> player[i].score;
		fin >> player[i].lifecount;
		fin >> player[i].sizepole;
		fin >> player[i].countMines;
		fin >> player[i].Minets;
		fin >> player[i].sec;
	}
	fin.close();
	printf("%10s %5s %10s %11s %13s %6s %7s \n",
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
		printf("%10s %5d %10d %11d %13d %6d %7d \n",
			player[i].name,
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
	system("mode con cols=70 lines=32");
	srand(time(0));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *sizescore = fopen("sizescore.txt", "r");
	int SizeScore = 0;
	fscanf(sizescore, "%d", &SizeScore);
	fclose(sizescore);
	sizescore = fopen("scores.txt", "r");
	Score *player = new Score[SizeScore];
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
				do
				{
				
				Game(3);
				
				system("cls");
				cout << "Если хочешь ещё нажми Enter" << endl;
				
				} while (_getch() == 13);
				system("pause");
				system("cls");
			}
			if (k == 2)
			{
				PrintScore(SizeScore,player,sizescore);
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
