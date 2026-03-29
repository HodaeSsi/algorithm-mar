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

int dist[4][1000001];
int price[4];
int n;

int main() {cin.tie(0);cout.tie(0)->sync_with_stdio(0);
	cin >> price[3] >> price[1] >> price[2] >> n;
	dist[3][price[3]] = 1;
	dist[1][price[1]] = 1;
	dist[2][price[2]] = 1;
	for (int i = 1; i < n; i++) {
		for (int np = 0; np < 4; np++) {
			if (dist[np][i] == 0)continue;
			int nowmove = dist[np][i];
			for (int k = 1; k < 4; k++) {
				if (i + price[k] > n)continue;
				if (dist[(np + k) % 4][i + price[k]] == 0)
					dist[(np + k) % 4][i + price[k]] = nowmove + 1;
				else {
					dist[(np + k) % 4][i + price[k]] = min(
						dist[(np + k) % 4][i + price[k]],
						nowmove + 1
					);
				}
			}
		}
	}
	if (dist[0][n] == 0) {
		cout << -1;
	}
	else {
		cout << dist[0][n];
	}
}
