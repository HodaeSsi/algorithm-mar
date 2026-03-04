// 18513

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>

using namespace std;
int n, m, k;
bool visited[1001];
vector<pair<int, int>> e[1001];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		pq.push({ 0, x });
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({ v, w });
		e[v].push_back({ u, w });
	}
	int cnt = 0;
	while (pq.size()) {
		int w = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (visited[v])continue;
		visited[v] = true;
		cnt += w;
		for (auto x : e[v]) {
			if (!visited[x.first]) {
				pq.push({ - x.second, x.first });
			}
		}
	}
	cout << cnt;
}
