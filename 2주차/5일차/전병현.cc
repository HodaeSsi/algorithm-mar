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

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };

int n, m;

char board[1001][1001];
int disth[1001][1001];
int dists[1001][1001];

void bfs(int i, int j, int (&dist)[1001][1001]) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {i, j} });
	memset(dist, -1, sizeof dist);
	dist[i][j] = 0;
	while (q.size()) {
		int ndist = q.front().first;
		int pi = q.front().second.first;
		int pj = q.front().second.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = pi + di[k];
			int nj = pj + dj[k];
			if (ni >= 0 && nj >= 0 && ni < n&&nj < m&&board[ni][nj] != 'D'&&dist[ni][nj] == -1) {
				dist[ni][nj] = ndist + 1;
				q.push({ ndist + 1, {ni, nj} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	pair<int, int> s, h;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			switch (board[i][j] = str[j]) {
			case 'H':
				h = { i, j };
				break;
			case 'S':
				s = { i, j };
				break;
			}
		}
	}

	bfs(s.first, s.second, dists);
	bfs(h.first, h.second, disth);

	int mini = 2147483647;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F'&&dists[i][j]!=-1&&disth[i][j]!=-1) {
				mini = min(mini, dists[i][j] + disth[i][j]);
			}
		}
	}
	if (mini == 2147483647) {
		cout << -1;
	}
	else {
		cout << mini;
	}
}
