#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<int> graph[200001];
vector<int> rev_graph[200001];
vector<int> visited;
stack<int> order;
vector<vector<int>> sccs;
int able[200001]; // i번 SCC가 자체 커버되는지 여부
int nodeToSCC[200001]; // nodeToSCC[i] = j : i번 노드는 j번 SCC에 속함
int inDegree[200001]; // SCC 간 inDegree

void dfs(int x) {
	visited[x]=1;

	for(auto y:graph[x]) {
		if(!visited[y]) dfs(y);
	}

	order.push(x);
}

void rev_dfs(int x,vector<int>& v,int idx) {
	visited[x]=1;
	v.push_back(x);
	nodeToSCC[x]=idx;

	for(auto y:rev_graph[x]) {
		if(!visited[y]) rev_dfs(y, v, idx);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n,m;
	cin>>n>>m;

    for (int i=0;i<m;i++) {
	    int a,b;
    	cin>>a>>b;

    	graph[a].push_back(b);
    	rev_graph[b].push_back(a);
    }

	visited.assign(n+1,0);
	for(int i=1;i<=n;i++) {
		if(!visited[i]) dfs(i);
	}

	visited.assign(n+1,0);
	int idx=0;
	while(!order.empty()) {
		int x=order.top();
		order.pop();

		if(!visited[x]) {
			sccs.push_back({});
			rev_dfs(x,sccs.back(),idx++);
		}
	}

	// 자체적으로 커버 가능한 SCC들을 판별한다.
	// SCC 내 노드의 수를 V, 간선의 수를 E라고 할 때(방향 무시)
	// E >= V인 경우 자체적으로 커버 가능하다.
	for(int i=0;i<sccs.size();i++) {
		int node_cnt=sccs[i].size();
		set<pair<int,int>> undirected_edges;

		for(auto x:sccs[i]) {
			for(auto y:graph[x]) {
				if(nodeToSCC[y]==i) {
					undirected_edges.insert({min(x,y),max(x,y)});
				}
			}
		}

		if(undirected_edges.size()>=node_cnt)
			able[i]=1;
	}

	// 모든 간선을 순회하며 SCC의 inDegree 계산
	for(int i=1;i<=n;i++) {
		for(auto j:graph[i]) {
			int x=nodeToSCC[i];
			int y=nodeToSCC[j];

			if(x!=y) {
				inDegree[y]++;
			}
		}
	}

	for(int i=0;i<sccs.size();i++) {
		if(!able[i]&&!inDegree[i]) {
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES";
}
