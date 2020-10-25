#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void point(int x)
{

	gotoxy(100, 1);
	printf("%d",x);
}

void drawstar(int x, int y)
{
	gotoxy(x, y);
	printf("*");

}

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}

void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("^");
	
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); printf(" ");
}
int main()
{
	int score=0;
	char ch = '.';
	int x = 38, y = 20;
	int bx, by, i;
	int bullet = 0;
	int stx[25], sty[25];
	srand(time(NULL));
	for (i = 1;i <= 20;i++)
	{
		stx[i] = rand() % 61 + 10;
		sty[i] = rand() % 4 + 2;
		drawstar(stx[i], sty[i]);
	}
	point(score);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 's') { draw_ship(++x, y); }
			if (bullet != 1 && ch == ' ') { bullet = 1; bx = x + 3; by = y - 1;Beep(200, 100); }
			fflush(stdin);
		}
		if (bullet == 1) {

			clear_bullet(bx, by);
			if (by == 2) { bullet = 0; }
			else
			if (cursor(bx, by - 1) == '*') 
			{ clear_bullet(bx, by - 1);
			bullet = 0; Beep(500, 100);
			for (i = 1;i <= 1;i++)
			{
				stx[i] = rand() % 61 + 10;
				sty[i] = rand() % 4 + 2;
				drawstar(stx[i], sty[i]);
				score++;
				point(score);
			}
	
			}
			else { draw_bullet(bx, --by); }
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}