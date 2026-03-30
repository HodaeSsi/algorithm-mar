#include <iostream>
#include <queue>

using namespace std;

int visited[4][1000001]; // 위, 오른쪽, 아래, 왼쪽

int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	for(int i=0;i<4;i++) {
		for(int j=0;j<=d;j++) {
			visited[i][j]=2e9;
		}
	}

	queue<pair<int,int>> q;

	// 처음엔 위쪽 바라보고 있다고 가정
	q.push({0,0});
	visited[0][0]=0;

	while(!q.empty()) {
		int dir=q.front().first;
		int x=q.front().second;
		q.pop();

		if(dir==0&&x==d) {
			cout<<visited[0][x];
			return 0;
		}

		if(x+a<=d&&visited[(dir+3)%4][x+a]>visited[dir][x]+1) {
			visited[(dir+3)%4][x+a]=visited[dir][x]+1;
			q.push({(dir+3)%4,x+a});
		}

		if(x+b<=d&&visited[(dir+1)%4][x+b]>visited[dir][x]+1) {
			visited[(dir+1)%4][x+b]=visited[dir][x]+1;
			q.push({(dir+1)%4,x+b});
		}

		if(x+c<=d&&visited[(dir+2)%4][x+c]>visited[dir][x]+1) {
			visited[(dir+2)%4][x+c]=visited[dir][x]+1;
			q.push({(dir+2)%4,x+c});
		}
	}

	cout<<-1;
}
