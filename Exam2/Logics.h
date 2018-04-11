#pragma once
class Miners
{
	
public:
	int size = 10;
	int **pole = new int*[size];
	Miners(int CountMiners, int SizeField) //�����������
	{
		size = SizeField;
		for (int i = 0; i < size; i++) pole[i] = new int[size];
		Init(CountMiners);
	}

private:
	void Init(int CountMiners) //�������������
	{
		ClearField();
		RandMines(CountMiners);
		PrintPole();
	}
	void RandMines(int CountMiners)//�������� ���������� ���
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

	void PrintPole() // ������������� �������
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << pole[i][j]<<" ";
			}
			cout << endl;
		}
	}
	int Rand(int min, int max) //������
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
};