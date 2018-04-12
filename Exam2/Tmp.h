#include"Header.h"
void Control(int X,int Y,int size) 
{
	int en = 0;
	int x = X;
	int y = Y;
	do 
	{
		switch (en)
		{
		case 80:
			x++;
			if (x == size )
				x = 0;
			Color(x, y);
			break;
		case 72:
			x--;
			if (x == 0)
				x = size - 1;
			Color(x, y);
			break;
		case 75:
			y--;
			if (y == 0)
				y = size - 1;
			Color(x, y);
			break;
		case 77:
			y++;
			if (y == size - 1)
				y = 0;
			Color(x, y);
			break;
		case 13:
			enter(x, y);
			Color(x, y);
			break;
		case 32:
			probel(x, y);
			Color(x, y);
			break;
		default:
			break;
		}
		
		

	} while (en = _getch());
}
void enter(int x, int y) 
{
	printf("%5d %5d", x, y);
}
void probel(int x, int y) 
{
	printf("%5d %5d", x, y);
}
void Color(int x, int y)
{

}
void Sound(int zvuk) 
{
	PlaySound("",NULL,SND_ASYNC);
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
	
}
void fprintpole() 
{
	FILE *file = fopen("Place mine.txt", "a");
	for(int i=0;i<size;i++)
	{
		for (int j = 0; j < size; j++)
		{
			fprintf(file, "%3d", pole[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
	fclose(file);

}
//bool Check(int row, int col) {
//
//	pole[row][col] += 500; // выводим содержание €чейки под курсором после Ёнтер
//
//	if (pole[row][col] >= 100) {
//		return false;
//	}
//	if (pole[row][col] == 0) {
//		for (int p = 0; p < 8; ++p) {
//			int x = mv[0][p];
//			int y = mv[1][p];
//			if ((row + y) >= 0 && (row + y) < zise && (col + x) >= 0 && (col + x) < zise) {
//				if (pole[row + y][col + x] < 0) {
//					Check(row + y, col + x);
//				}
//			}
//		}
//	}
//	return true;
//}
