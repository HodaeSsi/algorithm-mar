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

queue<int> q;


int cnt[1001];
int pr[1001];
vector<pair<int,int>> e[1001];
int dist[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		e[a].push_back({ b,v });
		cnt[b]++;
	}
	queue<int> q;
	q.push(1);
	cnt[1] = 0;

	while (q.size()) {
		int v = q.front();
		q.pop();
		for (auto x : e[v]) {
			int nv = x.first;
			int nw = x.second + dist[v];
			if (nw > dist[nv]) {
				dist[nv] = nw;
				pr[nv] = v;
			}
			if (--cnt[nv] == 0) {
				q.push(nv);
			}
		}
	}
	cout << dist[1] << "\n1 ";
	stack<int> st;
	st.push(1);
	int now = pr[1];
	while (now != 1) {
		st.push(now);
		now = pr[now];
	}
	while (st.size()) {
		cout << st.top() << " ";
		st.pop();
	}
}
