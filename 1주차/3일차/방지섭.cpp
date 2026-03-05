#include <bits/stdc++.h>
using namespace std;

struct node{
    int room; // 0 : A방, 1 : B방
    int team_idx; // 팀 index
    int dis; // 해당 방까지의 거리
    int dif; // 해당 팀이 각 방의 가는 거리의 차

    bool operator<(const node other) const{
        if(dif == other.dif) return dis > other.dis; 
        return dif < other.dif;
    }
};

void solve(){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,A,B;
    for(;;){
        cin >> N >> A >> B;
        if(N == 0 && A == 0 && B == 0) break;
        vector<int> left_balloon(N);
        priority_queue<node> pq;
        for(int i=0;i<N;i++){
            int k,a,b; cin >> k >> a >> b;
            left_balloon[i] = k;
            pq.push({0,i,a, abs(a-b)});
            pq.push({1,i,b, abs(a-b)});
        }
        int ans = 0;
        int left_team = N;
        while(!pq.empty()){
            node t = pq.top(); pq.pop();
            if(left_balloon[t.team_idx] == 0) continue;
            if(t.room == 0){ // A방 방문
                if(A == 0) continue;
                if(A >= left_balloon[t.team_idx]){ // A방에 풍선이 충분할 때
                    ans += t.dis * left_balloon[t.team_idx];
                    A -= left_balloon[t.team_idx];
                    left_balloon[t.team_idx] = 0;
                    left_team--;
                }
                else{ // A방에 풍선이 부족할 때
                    ans += t.dis * A;
                    left_balloon[t.team_idx] -= A;
                    A = 0;
                }
            }
            else if(t.room == 1){ // B방
                if(B == 0) continue;
                if(B >= left_balloon[t.team_idx]){ // B방에 풍선이 충분할 때
                    ans += t.dis * left_balloon[t.team_idx];
                    B -= left_balloon[t.team_idx];
                    left_balloon[t.team_idx] = 0;
                    left_team--;
                }
                else{ // B방에 풍선이 부족할 때
                    ans += t.dis * B;
                    left_balloon[t.team_idx] -= B;
                    B = 0;
                }
            }
            if(left_team == 0) break;
        }
        cout << ans << "\n";
    }

    return 0;
}