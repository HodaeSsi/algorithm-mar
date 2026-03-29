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

int dist[2001];
priority_queue<pair<int, int>> pq;

int main() {cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	pq.push({ 0 , 1 });
	for (int i = 0; i < 2001; i++) {
		dist[i] = 2147483647;
	}
	while (pq.size()) {
		int nd = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dist[v] <= nd) {
			continue;
		}
		dist[v] = nd;
		if (v == n) {
			cout << nd;
			return 0;
		}
		for (int i = 1; v - i >= 2; i--) {
			if (dist[v - i] <= nd + i)
				break;
			pq.push({ -nd - i, v - i });
		}
		for (int i = 1; v + i * v <= 2000; i++) {
			if (dist[v + i * v] > nd + i + 1) {
				pq.push({ -nd - i - 1, v + i * v });
			}
		}
	}
}
