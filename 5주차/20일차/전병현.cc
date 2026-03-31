#include <bits/stdc++.h>
// icpc.me/16954
using namespace std;

int board[9][8][8];

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

int main()
{
    for (int i=0;i<8;i++)
    {
        string x;
        cin>>x;
        for (int j=0;j<8;j++)
            if (x[j]=='#')
                for (int ni = 0;i+ni<8;ni++)
                {
                    board[ni][i+ni][j] = 2;
                }
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0, {7,0}});
    while (q.size())
    {
        int dep = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        if (board[dep][i][j])continue;
        board[dep][i][j] |= 1;
        for (int k=0;k<9;k++)
        {
            int ndep = min(8, dep+1);
            int ni = i+di[k];
            int nj = j+dj[k];
            if (ni>=0&&ni<8&&nj>=0&&nj<8&&board[dep][ni][nj]<2&&board[ndep][ni][nj]==0)
            {
                q.push({ndep, {ni, nj}});
            }
        }
    }
    cout<<board[8][0][7];
}





















