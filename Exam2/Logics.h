#pragma once
class Miners
{
	
public:
	string name;
	short size = 10; //размер игрового поля
	short **pole = new short*[size];//поле с минами
	char **fow = new char*[size]; //поле скрытия
	short Xcursor,Ycursor;//Положение курсора
	short StepCount;
	short LifeCount;
	short Score;
	short CountLucky;
	short Mines;
	short MinesConst;
	short MinesFlags;
	bool Game;
	bool boolDrowField;
	bool boolDrowBar;
	bool boolDrowEndGame;
	clock_t t0 = clock();
	clock_t t1;
	double TimeRound;
	short Minets = 0;
	double TimeRoundTmp;

	Miners(int CountMiners, int SizeField) //Конструктор
	{
		cout << "Введите ваше имя " << endl;
		cin >> name;
		size = SizeField;
		for (int i = 0; i < size; i++) pole[i] = new short[size];
		for (int i = 0; i < size; i++) fow[i] = new char[size];
		StepCount = 0;
		LifeCount = 3;
		Score = 0;
		CountLucky = 0;
		MinesFlags = 0;
		Mines = CountMiners;
		MinesConst = CountMiners;
		Game = true;
		boolDrowField = true;
		boolDrowBar = true;
		boolDrowEndGame = false;
		Xcursor = 0;
		Ycursor = 0;
		Init(CountMiners);
	}
	void Update()
	{
		Control(Xcursor, Ycursor, size);
		CheckStatus();
		ClockChek();
		if (boolDrowField) DrowField();
		if (boolDrowBar) DrowBar();
		if (boolDrowEndGame) DrowEnd();
	}
	bool GetBool()
	{
		if (!Game) return false;
		return true;
	}
private:
	void Init(int CountMiners) //Инициализация
	{
		ClearField();
		Initfow();
		RandMines(CountMiners);

		Sound(4);
		

	}
	void Initfow() 
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				fow[i][j] = '#';
			}
			cout << endl;
		}
		
	}
	void RandMines(int CountMiners)//Получает количество мин и генерирует их
	{
		for (int i = 0; i < CountMiners; i++)
		{
			int X = Rand(1, size) - 1;
			int Y = Rand(1, size) - 1;
			if (pole[X][Y] == 0)
			{
				pole[X][Y] = 1;
			}
			else --i;
		}
	}
	void ClearField() // Забивает поле нулями
	{
		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				pole[i][j] = 0;
			}
			cout << endl;
		}
		system("cls");
	}
	int Rand(int min, int max) //Рандом
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
	void Control(int x, int y, int size)//Управление курсором
	{
		if (kbhit())
		{
			boolDrowField = true;
			switch (getch())
			{
			case 80:
				x++;
				if (x == size)
					x = 0;
				break;
			case 72:
				x--;
				if (x < 0)
					x = size - 1;
				break;
			case 75:
				y--;
				if (y < 0)
					y = size - 1;
				break;
			case 77:
				y++;
				if (y == size)
					y = 0;
				break;
			case 13:
				enter(x, y);
				break;
			case 32:
				probel(x, y);
				break;
			default:
				break;
			}
		}
		Xcursor = x;
		Ycursor = y;
	}
	void enter(int x, int y)//при нажатии энтер
	{
		boolDrowBar = true;
		if(fow[x][y] == '#')//проверка не открывалась ли раньше ячейка
		{
			if (pole[x][y] == 1)//если там мина
			{
				fow[x][y] = '*';//вывод на первый план мины
				LifeCount--;//отнимаеться жизнь 
				StepCount++;
				Score -= 5;//минус
				Mines--;
				MinesFlags++;
				Blood();
			}
			else
			{
				Score += ScoreCalc();
				char CheckTmp = Check(x, y) + '0';
				fow[x][y] = CheckTmp;
				CountLucky++;
				StepCount++;
			}
		}
	}
	int Check(int x,int y) // проверка на мины в округе
	{
		short chekp = 0;

			for (int i = y - 1; i <= y + 1; i++)
			{
				for (int j = x - 1; j <= x + 1; j++)
				{
					if (i >= 0 && i < size)
					{
						if (j >= 0 && j < size) if (pole[j][i] == 1)chekp++;
					}
				}
			}
		return chekp;
	}
	void probel(int x, int y)//при нажатии пробел
	{
		if (fow[x][y] == 'f') 
		{
			fow[x][y] = '#';
		}
		else 
		{
			fow[x][y] = 'f';
			if (pole[x][y] == 1) MinesFlags++;
		}
	}
	void CheckStatus()
	{
		if (MinesFlags==MinesConst) win(); //////////WIIIIN
		if (StepCount == 25 || LifeCount == 0)
		{
			deth();
		}
	}
	void DrowBar()
	{
		gotoxy(0, 0);
		if (TimeRound > 59)
		{
			Minets++;
			t0 = clock();
			TimeRound = 0;
			system("cls");
			boolDrowField = true;
		}
		
		cout << "Ходов : " << StepCount << " Жизней : " << LifeCount <<" Очки : "<< Score <<" Осталось мин : "<< Mines << " Время раунда : "<<Minets<<":"<< TimeRound;
		boolDrowBar = false;
	}
	void DrowField()
	{
		int Xcord = 14;
		int Ycord = 1;
		gotoxy(Xcord, Ycord);
		for (int i = 0; i < size; i++)
		{
			int tmp = 0;
			for (int j = 0; j < size; j++)
			{
				gotoxy(Xcord+((j*4)+1), Ycord + ((i + 3)*2));
				if (i == Xcursor && j == Ycursor)
				{
					SetColor(1, 15);
					cout <<" "<< fow[i][j] << " ";
					SetColor(7);
				}
				else cout <<" "<< fow[i][j] << " ";
			}
			cout << endl;
			//gotoxy(Xcord, Ycord + (i+1));
		}

		boolDrowField = false;
	}
	void ClockChek()
	{
		t1 = clock();
		TimeRoundTmp = (double)(t1 - t0) / CLOCKS_PER_SEC;
		if ((int)TimeRoundTmp > TimeRound)
		{
			TimeRound = (int)TimeRoundTmp;
			boolDrowBar = true;
		}
	}
	int ScoreCalc()
	{
		int result;
		int tmp;
		result = ((int)(CountLucky / 5));
		if (result == 0) return 5;
		if (result >= 1) result++;
		return 5 * result;

	}
	void win()
	{
		system("cls");
		cout << "ПОБЕДА!!" << endl;
		Sound(3);
		system("pause");
		
		boolDrowEndGame = true;
	}
	void deth()
	{
		system("cls");
		cout << "Продул!!" << endl;
		Sound(5);
		system("pause");
		boolDrowEndGame = true;
	}
	void DrowEnd()
	{
		fprintpole();
		scorefprint();
		Sound(1);
	}
	void Sound(int zvuk)
	{
		PlaySound("", NULL, SND_ASYNC);
		if (zvuk == 1)
		{//main
			PlaySound("main.wav", NULL, SND_ASYNC);
		}
		if (zvuk == 2)
		{//bang
			PlaySound("Bang.wav", NULL, SND_ASYNC);
		}
		if (zvuk == 3)
		{//win
			PlaySound("Win.wav", NULL, SND_ASYNC);
		}
		if (zvuk == 4)
		{//game
			PlaySound("Game.wav", NULL, SND_ASYNC);
		}
		if (zvuk == 5)
		{//lose
			PlaySound("lose.wav", NULL, SND_ASYNC);
		}
		if (zvuk == 0)
		{
			PlaySound("", NULL, SND_ASYNC);
		}
	}
	void fprintpole()
	{
		FILE *file = fopen("Place mine.txt", "a");
		fprintf(file, "%10s %5s : %5s %5s \n", "Имя","Мин","Сек","Очки");
		fprintf(file, "%10s %5d : %5.2f %5d \n", name.c_str(), Minets, TimeRound, Score);
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				fprintf(file, "%3d", pole[i][j]);
			}
			fprintf(file, "\n");
		}
		fprintf(file, "\n");
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				fprintf(file, "%3c", fow[i][j]);
			}
			fprintf(file, "\n");
		}
		fprintf(file, "\n");
		fclose(file);

	}

	void Blood()
	{
		Sound(2);
		Sleep(500);
		system("cls");
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				SetColor(4, 4);
				cout << "\t";
			}
		}
		Sleep(1500);
		Sound(4);
		SetColor(7);
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				cout << "\t";
			}
		}
		boolDrowField = true;
		boolDrowBar = true;
	}
	void scorefprint()
	{

		FILE *file = fopen("scores.txt", "a");
		fprintf(file, "%10s %10s %11s %12s %20s %10s %10s \n", "Имя", "Очки", "Очки жизни", "Размер поля", "Количество мин", "Минуты", "Секунды");
		fprintf(file, "%10s %10d %11d %12d %20d %10d %10.2f \n", name.c_str(), Score, LifeCount, size, MinesConst, Minets, TimeRound);
		fclose(file);
	}

};