#include"Header.h"

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void score(game *player) 
{
	FILE *file = fopen("scores.txt", "a");
	fprintf(file, "%s %d %d %d %d %d %d",player->name.c_str(),player->score,player->healt,player->complication,player->minedefused,player->remainingmines,player->elapsed_times);

}

