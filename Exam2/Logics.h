#pragma once
class Miners
{
	
public:
	short size = 10; //размер игрового поля
	short **pole = new short*[size];//поле с минами
	char **fow = new char*[size]; //поле скрытия
	short Xcursor,Ycursor;//Положение курсора
	short StepCount;
	short LifeCount;
	short Score;
	short CountLucky;
	short Mines;
	short MinesFlags;
	bool steps;
	bool life;
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
		size = SizeField;
		for (int i = 0; i < size; i++) pole[i] = new short[size];
		for (int i = 0; i < size; i++) fow[i] = new char[size];
		StepCount = -100;
		LifeCount = 3;
		Score = 0;
		CountLucky = 0;
		MinesFlags = 0;
		Mines = CountMiners;
		steps = false;
		life = false;
		boolDrowField = true;
		boolDrowBar = true;
		boolDrowEndGame = true;
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
	}
	bool ChechGame()
	{
		if (steps || life) return false;
		return true;
	}
private:
	void Init(int CountMiners) //Инициализация
	{
		ClearField();
		Initfow();
		RandMines(CountMiners);

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
	int Rand(int min, int max) //рандом
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
	void Control(int x, int y, int size)//управление курсором
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
		if(fow[x][y] == '#')
		{
			if (pole[x][y] == 1)
			{
				fow[x][y] = '*';
				LifeCount--;
				StepCount++;
				Score -= 5;
				Mines--;
			}//займёмся ей потом
			else
			{
				char CheckTmp = Check(x, y) + '0';
				fow[x][y] = CheckTmp;

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
		if (MinesFlags==20) //////////WIIIIN
		if (StepCount == 25 || LifeCount == 0) life = true;
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
		Score += ScoreCalc();
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
	void DrowEndGame()
	{
		system("cls");
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
		if (CountLucky < 0) return result = 5 * 1;
		else
		{
			return result = 5 * ((int)(CountLucky / 5));
		}

	}
};