#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, dir;
};

int n, cur_x = 0, cur_y = 0, cur_dir = 2;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; // 상, 우, 하, 좌
string s;
vector<node> zombies;
char A[15][15];
bool is_bright[15][15];

void input(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            if(A[i][j] == 'Z'){
                zombies.push_back({i,j,2});
            }
        }
    }
}

void turn_on_the_light(int x, int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nx = x+i, ny = y + j;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n) is_bright[nx][ny] = true;
        }
    }
}

void solve(){
    for(int i=0;i<s.size();i++){
        //cout << "me : "<< cur_x << " " << cur_y << "\n";
        // 아리 이동
        if(s[i] == 'L') cur_dir = (cur_dir + 3) % 4;
        else if(s[i] == 'R') cur_dir = (cur_dir + 1) % 4;
        else if(s[i] == 'F'){
            int nx = cur_x + dx[cur_dir], ny = cur_y + dy[cur_dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(A[nx][ny] == 'S'){
                    turn_on_the_light(nx, ny);
                }
                cur_x = nx, cur_y = ny;
            } 
        }

        for(int j=0;j<zombies.size();j++){
            int x = zombies[j].x, y = zombies[j].y, dir = zombies[j].dir;
            if(x == cur_x && y == cur_y && !is_bright[x][y]){
                cout << "Aaaaaah!";
                return;
            }
        }

        // 좀비 이동
        for(int j=0;j<zombies.size();j++){
            int x = zombies[j].x, y = zombies[j].y, dir = zombies[j].dir;
            int nx = x + dx[dir], ny = y + dy[dir];
            if(!(nx >= 0 && nx < n && ny >= 0 && ny < n)){
                dir = (dir + 2) % 4; // 벽에 부딪혀 뒤돌기.
                zombies[j] = {x, y, dir};
                continue;
            }
            //cout << "zombies : " << nx << " " << ny << "\n";
            zombies[j] = {nx, ny, dir}; 
        }

        for(int j=0;j<zombies.size();j++){
            int x = zombies[j].x, y = zombies[j].y, dir = zombies[j].dir;
            if(x == cur_x && y == cur_y && !is_bright[x][y]){
                cout << "Aaaaaah!";
                return;
            }
        }
    }
    cout << "Phew...";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}