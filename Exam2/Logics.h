#pragma once
class Miners
{
	
public:
	int size = 10;
	int **pole = new int*[size];
	char **fow = new char*[size];
	int Xcursor,Ycursor;
	Miners(int CountMiners, int SizeField) //Конструктор
	{
		size = SizeField;
		for (int i = 0; i < size; i++) pole[i] = new int[size];
		for (int i = 0; i < size; i++) fow[i] = new char[size];

		Xcursor = 0;
		Ycursor = 0;
		Init(CountMiners);
	}
	void Update()
	{
		Control(Xcursor, Ycursor, size);
		PrintPole();
	}
private:
	void Init(int CountMiners) //Инициализация
	{
		ClearField();
		Initfow();
		RandMines(CountMiners);
		PrintPole();
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
		system("cls");
	}
	void RandMines(int CountMiners)//Получает количество мин
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

	void PrintPole() // распечатывает матрицу
	{
		system("cls");
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == Xcursor && j == Ycursor)
				{
					SetColor(1, 15);
					cout << fow[i][j] << " ";
					SetColor(7);
				}
				else cout << fow[i][j] << " ";
			}
			cout << endl;
		}
	}
	int Rand(int min, int max) //рандом
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
	void Control(int x, int y, int size)
	{
		if (kbhit())
		{
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
	void enter(int x, int y)
	{
		
		if (pole[x][y] == 1) 
		{ 
			fow[x][y] = '*';
		}//займёмся ей потом
		else 
		{
			fow[x][y] = Check(x,y)+'0';
		}
	}
	int Check(int x,int y)
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
	void probel(int x, int y)
	{
		if (fow[x][y] == 'f') 
		{
			fow[x][y] = '#';
		}
		else 
		{
			fow[x][y] = 'f';
		}
	}
	void Color(int x, int y)
	{
		
	}
};