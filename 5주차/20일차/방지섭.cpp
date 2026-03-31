#include <bits/stdc++.h>
using namespace std;

char A[8][8];
void input(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> A[i][j];
        }
    }
}

void down(){
    for(int i=0;i<8;i++){
        for(int j=7;j>0;j--){
            A[j][i] = A[j-1][i];
        }
        A[0][i] = '.';
    }
}

int dx[] = {-1,-1,-1,0,0,0,1,1,1}, dy[] = {-1,0,1,-1,0,1,-1,0,1};
bool solve(){
    queue<pair<int,int>> q1, q2;
    q1.push({7,0});
    int cnt = 0;
    while(!q1.empty()){
        int size1 = q1.size();
        for(int i=0;i<size1;i++){
            auto f = q1.front(); q1.pop();
            if(A[f.first][f.second] != '#') q2.push(f);
        }

        bool visited[8][8];
        memset(visited, false, sizeof(visited));

        int size2 = q2.size();
        for(int i=0;i<size2;i++){
            auto f = q2.front();
            q2.pop();

            for(int j=0;j<9;j++){
                int nx = f.first + dx[j], ny = f.second + dy[j];
                if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && A[nx][ny] == '.' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q1.push({nx, ny});
                }
            }
        }

        cnt++;
        if(cnt == 8){
            if(q1.empty()) return false;
            return true;
        }
        down();
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    if(solve()) cout << 1;
    else cout << 0;

    return 0;
}

/*
행이 8 이니 최대 8턴까지만 벽에 부딪히지 않으면 생존(1)
bfs 구현
*/