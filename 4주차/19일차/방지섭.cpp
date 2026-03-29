#include <bits/stdc++.h>
using namespace std;

long long n, total_sum;

vector<pair<long long, long long>> ans_pair;

void solve(long long idx)
{
    long long m;
    cin >> m;
    vector<long long> v(m), pre_sum(m + 1);             // 배열, 누적합
    vector<pair<long long, long long>> min_pair(m + 1); // 누적 min의 value, idx
    pre_sum[0] = 0;
    min_pair[0] = {0, 0};
    for (long long i = 0; i < m; i++)
    {
        cin >> v[i];
        pre_sum[i + 1] = pre_sum[i] + v[i];
        
        if(min_pair[i].first > pre_sum[i+1]){ // 지금까지 최소값보다 더 작은 누적합이 나올 때
            min_pair[i+1] = {pre_sum[i+1], i+1};
        }
        else if(min_pair[i].first < pre_sum[i+1]){ // 더 큰 누적합은 그냥 이전 껄로
            min_pair[i+1] = min_pair[i];
        }
        else{ // 같으면 길이가 짧을 수록 좋으니 idx가 커질 수록 좋음.
            min_pair[i+1] = min_pair[i];
            min_pair[i+1].second = i+1;
        }
    }

    long long mx_value = INT32_MIN;
    long long mn_size = INT32_MAX;
    pair<long long, long long> idx_pair;
    for (long long i = 1; i < m + 1; i++)
    {
        long long value = pre_sum[i] - min_pair[i - 1].first;
        long long sz = i - min_pair[i - 1].second + 1;
        if (mx_value < value)
        { // 최대가 되는 경우
            mn_size = sz;
            mx_value = value;
            idx_pair = {min_pair[i - 1].second, i};
        }
        else if (mx_value == value)
        {
            if (mn_size > sz)
            { // 최대가 되는 경우가 여럿이면, 구매한 보석들의 총 개수가 최소가 되는 방법
                idx_pair = {min_pair[i - 1].second, i};
                mn_size = sz;
            }
            else if (mn_size == sz)
            { // 이와 같은 경우도 여럿이라면, 출력한 n×2개의 수들을 하나의 수열로 생각하여, 사전식으로 가장 앞에 오는 경우를 출력
                idx_pair = min(idx_pair, {min_pair[i - 1].second, i});
            }
        }
    }
    total_sum += mx_value;
    ans_pair[idx] = idx_pair;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    ans_pair.resize(n);
    for (long long i = 0; i < n; i++)
    {
        ans_pair[i] = {INT32_MAX, INT32_MAX};
        solve(i);
    }
    cout << total_sum << "\n";
    for (long long i = 0; i < n; i++)
    {
        cout << ans_pair[i].first + 1 << " " << ans_pair[i].second << "\n";
    }

    return 0;
}