#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[1001][1001];

void input(){
    cin >> n;
}

int solve(){
    queue<pair<int,int>> q; // value, copy_value
    q.push({1,0}); 
    visited[1][0] = true;
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front();
            int value = f.first, copy_value = f.second;
            q.pop();

            if(value == n) return ans;
            // 복사
            if(!visited[value][value]){ 
                visited[value][value] = true;
                q.push({value, value});
            }
            // 붙여넣기
            if(value + copy_value <= 1000 && !visited[value+copy_value][copy_value]){
                visited[value+copy_value][copy_value] = true;
                q.push({value+copy_value, copy_value});
            }
            //  하나 삭제
            if(value > 1 && !visited[value-1][copy_value]){
                visited[value-1][copy_value] = true;
                q.push({value-1, copy_value});
            }
        }
        ans++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}