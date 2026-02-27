#include<iostream>
#include <cstring>
using namespace std;


char board[9][9];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };


void setting(int player, int x, int y, int time) {


	char p1; // 공격자
	char p2; // 수비자 


	// 흑돌
	if (player == 0) {
		p1 = '@';
		p2 = 'O';
	}
	else { // 백돌
		p1 = 'O';
		p2 = '@';
	}


	// 일단 놓기
	board[x][y] = p1;
	if (time < 3) {
		return;
	}


	// x,y 기준으로 8방향에 p2 p2 .. p1 패턴 있는지 찾기
	for (int i = 0; i <= 8; i++) {
		int nx = x;
		int ny = y;
		int cnt = 0;
		int flag = 1;

		while (true) {
			nx += dx[i];
			ny += dy[i];

			// 끝깢기 못찾음
			if (nx < 0 || ny < 0 || nx>8 || ny>8) break;
			if (board[nx][ny] == '_') break;
			if (board[nx][ny] == p2) {
				cnt++;
				continue;
			}

			if (board[nx][ny] == p1) {
				//찾았쥬?
				while (true) {
					nx -= dx[i];
					ny -= dy[i];
					if (nx == x && ny == y) {
						flag = 0;
						break;
					}
					board[nx][ny] = p1;

					cnt--;
				}
			}
			if (flag == 0) {
				break;
			}
		}
	}

	return;


}


int main() {
	memset(board, '_', sizeof(board));

	int d = -1;
	int N; cin >> N;
	int time = 0;
	for (int i = 0; i < N; i++) {
		int x; int y;
		cin >> x >> y;
		time += 1;
		setting(i % 2, x, y, time);

	}

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			cout << board[j][i];
		}
		cout << "\n";
	}

	return 0;
}