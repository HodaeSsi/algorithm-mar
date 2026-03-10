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

int tree[1024*1024*2+1];

int pull(int rank) {
	int pos = 1;
	int prevsize = 0;
	while (pos <= 1024 * 1024) {
		if (prevsize + tree[pos * 2] >= rank) {
			pos = pos*2;
		}
		else {
			prevsize += tree[pos * 2];
			pos = pos*2+1;
		}
	}
	int ans = pos - 1024 * 1024;
	tree[pos] -= 1;
	while ((pos /= 2) != 0) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
	return ans;
}

void insert(int taste, int size) {
	int pos = taste + (1024 * 1024);
	tree[pos] += size;
	while ((pos /= 2) != 0) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			cout << pull(b) << "\n";
		}
		else {
			int b, c;
			cin >> b >> c;
			insert(b, c);
		}
	}
}
