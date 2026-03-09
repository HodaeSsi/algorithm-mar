#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> s_pos, h_pos;
bool visited[1000][1000];
char A[1000][1000];
int s_to_f_dis[1000], f_to_h_dis[1000];
int fish_idx[1000][1000];
int fish_cnt = 1;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'S')
            {
                s_pos = {i, j};
                A[i][j] = 'E';
            }
            if (A[i][j] == 'H')
            {
                h_pos = {i, j};
                A[i][j] = 'E';
            }
            if(A[i][j] == 'F'){
                fish_idx[i][j] = fish_cnt++;
            }
        }
    }
}

void find_s_to_f_dis()
{
    queue<pair<int, int>> q;
    q.push(s_pos);
    visited[s_pos.first][s_pos.second] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            auto f = q.front();
            q.pop();
            if(A[f.first][f.second] == 'F'){
                s_to_f_dis[fish_idx[f.first][f.second]] = cnt;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = f.first + dx[i], ny = f.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] != 'D')
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        cnt++;
    }
}

void find_f_to_h_dis(){
    queue<pair<int, int>> q;
    q.push(h_pos);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    visited[h_pos.first][h_pos.second] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            auto f = q.front();
            q.pop();
            if(A[f.first][f.second] == 'F'){
                f_to_h_dis[fish_idx[f.first][f.second]] = cnt;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = f.first + dx[i], ny = f.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] != 'D')
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        cnt++;
    }
}

void solve()
{
    int ans = INT32_MAX;
    find_s_to_f_dis();
    find_f_to_h_dis();
    for(int i=0;i<fish_cnt;i++){
        if(s_to_f_dis[i] != 0 && f_to_h_dis[i] != 0) ans = min(ans, s_to_f_dis[i] + f_to_h_dis[i]);
    }
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}