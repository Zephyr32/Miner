#pragma once
class Miners
{
public:
	const int zise = 10;
	int pole[zise][zise];
	Miners()
	{
		void SetMine();
		void clearfield();
		int Rand(int min, int max);
		int RandMines(int CountMiners);
		void PrintPole();
	}
private:

	
	void clearfield()
	{


	}
	void SetMine()
	{
		cout << RandMines(10) << endl;
		system("pause");
		PrintPole();
	}
	int RandMines(int CountMiners)
	{
		int pp = 0;
		for (int i = 0; i < CountMiners; i++)
		{
			int X = Rand(1, 10) - 1;
			int Y = Rand(1, 10) - 1;
			if (pole[X][Y] == 0)
			{
				pp++;
				pole[X][Y] = 1;
			}
			else --i;
		}
		return pp;
	}
	void PrintPole()
	{
		for (int i = 0; i < zise; i++)
		{
			for (int j = 0; j < zise; j++)
			{
				cout << pole[i][j];
			}
			cout << endl;
		}
	}
	int Rand(int min, int max)
	{
		int tmp = rand() % ((max + 1) - min) + min;
		return tmp;
	}
};