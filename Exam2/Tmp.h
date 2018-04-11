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
