#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

char board[3][4] = { "abc","def","ghi" };
int row, column;
int turn;
int result;

int win_check() {

	for (row = 0; row < 3; row++) {
			if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
				return turn % 2;
		}
	}

	for (column = 0; column < 3; column++) {
			if (board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
				return turn % 2;	
		}
	}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			return turn % 2;
		}
	
	return 2;
}

int board_setup() {
		system("cls");
	printf("      1  2  3\n    ==========\n");
	for (row = 0; row < 3; row++) {
		printf("%d || ", row + 1);
		for (column = 0; column < 3; column++) {
			printf(" %c ", board[row][column]);
		}
		printf("\n\n");
	}
	return 0;
}

int action() {
	int x, y;
	srand((int)time(NULL));

	if (turn % 2 == 0) {
		printf("당신의 차례입니다.\n말을 둘 위치의 x좌표와 y좌표를 입력해주세요. :");
		scanf_s("%d %d", &x, &y);
		if (x < 1 || x>3 || y < 1 || y>3|| board[x - 1][y - 1] == 'O' || board[x - 1][y - 1] == 'X') {
			printf("잘못 입력하셨습니다. 다시 입력해주세요 :");
			scanf_s("%d %d", &x, &y);
		}
		board[x-1][y-1] = 'O';
	}

	else {
		printf("컴퓨터의 차례입니다.");
		Sleep(500);
		do {
			x = rand() % 3;
			y = rand() % 3;
		} while (board[x][y] == 'O' || board[x][y] == 'X');
		board[x][y] = 'X';
		}	
	return 0;
	}
	
int main() {

	for (turn = 0; turn < 9; turn++) {
		board_setup();
		action();
		board_setup();
		result = win_check();
		if (result == 0) {
			printf("축하합니다! 당신의 승리입니다!");
			return 0;
		}
		else if (result == 1) {
			printf("당신의 패배입니다..");
			return 0;
		}
	}
	printf("무승부 입니다!");
	return 0;
}