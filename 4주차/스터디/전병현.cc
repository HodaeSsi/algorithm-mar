#include <bits/stdc++.h>
using namespace std;


int n;

priority_queue<pair<int,int>> pq;
int group[100001];
int len[100001];
int nums[100001];

int find(int v)
{
    if (v!=group[v])return group[v] = find(group[v]);
    return group[v];
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums[i] = x;
        pq.push({x, i});
        group[i] = -1;
        len[i] = 1;
    }

    int ans = 0;
    while (pq.size())
    {
        int val = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        // 사용 설정
        group[idx] = idx;
        if (idx>0 && group[idx-1]!=-1)
        {
            // 왼쪽으로 합병
            int r = find(idx-1);
            group[idx] = r;
            len[r]++;
        }
        if (idx<n-1 && group[idx+1]!=-1)
        {
            //오른쪽으로 합병
            int r = find(idx+1);
            group[r] = find(idx);
            len[find(idx)]+=len[r];
        }
        ans = max(ans, len[find(idx)]*val);
    }
    cout<<ans;
}





















