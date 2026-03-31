#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[101];
int parent[101];
int daepyo[101];
int visited[101];

int Find(int x) {
	if(parent[x]==x) return x;
	return parent[x]=Find(parent[x]);
}

bool Union(int x,int y) {
	int px=Find(x);
	int py=Find(y);

	if(px!=py) {
		parent[px]=py;
		return true;
	}

	return false;
}

int main() {
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++) {
		parent[i]=i;
	}

	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);

		Union(a,b);
	}

	vector<vector<int>> areas(n+1);
	for(int i=1;i<=n;i++) {
		int area=Find(i);
		areas[area].push_back(i);
	}

	// 각 영역에서 최단 거리로 방문 가능한 루트를 찾는다.
	vector<int> ans;
	for(auto nodes:areas) {
		if(!nodes.empty()) {
			int minDist=2e9;
			int root=0;

			for(auto node:nodes) {
				int tmp=0; // 최단 거리 후보
				memset(visited,0,sizeof(visited));
				visited[node]=1;
				queue<int> q;
				q.push(node);

				while(!q.empty()) {
					int x=q.front();
					q.pop();

					tmp=max(tmp,visited[x]);

					for(auto y:graph[x]) {
						if(!visited[y]&&Find(x)==Find(y)) {
							visited[y]=visited[x]+1;
							q.push(y);
						}
					}
				}

				if(tmp<minDist) {
					minDist=tmp;
					root=node;
				}
			}

			ans.push_back(root);
		}
	}

	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(auto a:ans) {
		cout<<a<<"\n";
	}
}
