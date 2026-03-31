#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n;
int di[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};

int dir = 0;

int board[15][15]; // 스위치 위치와 켜진곳 저장
// 스위치 1, 켜진 곳 2
// 켤 때는 1은 건들지말기

inline int getpos(int initial, int time) {
	initial = (initial + time) % (2 * n);
	if (initial >= n) {
		initial = 2 * n - initial - 1;
	}
	return initial;
}

vector<int> zjs[15];

int ci = 0, cj = 0;

int main() {
	cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	string move;
	cin >> n >> move;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			switch (str[j]) {
			case 'S':
				board[i][j] = 1;
				break;
			case 'Z':
				zjs[j].push_back(i);
				break;
			}
		}
	}
	for (int time = 1; time <= move.size(); time++) {
		int ni = ci + di[dir];
		int nj = cj + dj[dir];
		switch (move[time - 1]) {
		case 'F':
			if (ni < 0 || ni >= n)ni = ci;
			if (nj < 0 || nj >= n)nj = cj;
			ci = ni;
			cj = nj;
			break;
		case 'L':
			dir = (dir + 3) % 4;
			break;
		case 'R':
			dir = (dir + 1) % 4;
			break;
		}
		if (board[ci][cj] == 1) {
			board[ci][cj] = 2;
			for (int k = 0; k < 8; k++) {
				int ni = ci + di[k];
				int nj = cj + dj[k];
				if (ni >= 0 && ni < n&&nj >= 0 && nj < n && board[ni][nj] == 0) {
					board[ni][nj] = 2;
				}
			}
		}
		if (board[ci][cj] == 0) {
			for (int x : zjs[cj]) {
				if (ci == getpos(x, time) || (time > 1 && ci == getpos(x, time - 1))) {
					cout << "Aaaaaah!";
					return 0;
				}
			}
		}
	}
	cout << "Phew...";
}
