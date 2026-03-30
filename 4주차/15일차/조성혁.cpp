#include <iostream>
#include <queue>
#include <algorithm>

#define LIMIT 2001

using namespace std;

int dist[LIMIT][LIMIT]; // dist[i][j]  = k : 현재 길이는 i, j 길이 복사하고 있는 상태에서 최소 횟수는 k

int main() {
	int n;
	cin>>n;

	for(int i=0;i<LIMIT;i++) {
		fill(dist[i],dist[i]+LIMIT,2e9);
	}

	queue<pair<int,int>> q; // 복사한 이모티콘 길이, 현재 이모티콘 길이
	q.push({0,1});
	dist[1][0]=0;

	while(!q.empty()) {
		int copied=q.front().first;
		int cur=q.front().second;
		q.pop();

		// 붙여넣기
		if(cur+copied<=2000&&copied>0) {
			if(dist[cur+copied][copied]>dist[cur][copied]+1) {
				dist[cur+copied][copied]=dist[cur][copied]+1;
				q.push({copied,cur+copied});
			}
		}

		// 삭제
		if(cur-1>=1) {
			if(dist[cur-1][copied]>dist[cur][copied]+1) {
				dist[cur-1][copied]=dist[cur][copied]+1;
				q.push({copied,cur-1});
			}
		}

		// 복사
		if(dist[cur][cur]>dist[cur][copied]+1) {
			dist[cur][cur]=dist[cur][copied]+1;
			q.push({cur,cur});
		}
	}

	int ans=2e9;
	for(int i=0;i<=n;i++) {
		ans=min(ans,dist[n][i]);
	}
	cout<<ans;
}
