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

vector<vector<int>> e{ 101 };
int group[101];
int dist[101][101];
int n;

pair<int,int> getmini(int v, int gid) {
	group[v] = gid;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[v][i] != 1000000009) {
			sum = max(sum, dist[v][i]);
		}
	}
	pair<int, int> x = {sum, v};
	for (int nv : e[v]) {
		if (group[nv] == 0) {
			x = min(x, getmini(nv, gid));
		}
	}
	return x;
}

int main() {
	cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = 1000000009;
		}
	}
	cin >> n;
	int k;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			for (k = 1; k <= n; k++) {
				if (i == k || j == k)continue;
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	int gsize = 0;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (group[i] == 0) {
			pq.push(-getmini(i, ++gsize).second);
		}
	}
	cout << pq.size() << "\n";
	while (pq.size()) {
		cout << -pq.top() << "\n";
		pq.pop();
	}
}
