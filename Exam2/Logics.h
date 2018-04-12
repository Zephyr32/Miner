#pragma once
class Miners
{
	
public:
	int size = 10; //������ �������� ����
	int **pole = new int*[size];//���� � ������
	char **fow = new char*[size]; //���� �������
	int Xcursor,Ycursor;//��������� �������
	short StepCount;
	short LifeCount;
	bool steps;
	bool life;
	bool boolDrowField;
	bool boolDrowBar;
	bool boolDrowEndGame;

	Miners(int CountMiners, int SizeField) //�����������
	{
		size = SizeField;
		for (int i = 0; i < size; i++) pole[i] = new int[size];
		for (int i = 0; i < size; i++) fow[i] = new char[size];
		StepCount = 0;
		LifeCount = 3;
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
		if (boolDrowField) DrowField();
		if (boolDrowBar) DrowBar();
	}
	bool ChechGame()
	{
		if (steps || life) return false;
		return true;
	}
private:
	void Init(int CountMiners) //�������������
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
	void RandMines(int CountMiners)//�������� ���������� ��� � ���������� ��
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
	void ClearField() // �������� ���� ������
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
	int Rand(int min, int max) //������
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
	void Control(int x, int y, int size)//���������� ��������
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
	void enter(int x, int y)//��� ������� �����
	{
		boolDrowBar = true;
		if (pole[x][y] == 1) 
		{ 
			fow[x][y] = '*';
			LifeCount--;
			
		}//������� �� �����
		else 
		{
			char CheckTmp = Check(x, y)+'0';
			fow[x][y] = CheckTmp;
			StepCount++;
		}
	}
	int Check(int x,int y) // �������� �� ���� � ������
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
	void probel(int x, int y)//��� ������� ������
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
	void CheckStatus()
	{
		if (StepCount == 25 || LifeCount == 0) life = true;
	}
	void DrowBar()
	{
		gotoxy(0, 1);
		cout << "����� :" << StepCount << " ������ :" << LifeCount;
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
};