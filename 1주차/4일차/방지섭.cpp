#include <bits/stdc++.h>
using namespace std;

string s;
long long s_size;
map<char, long long> oper_rank;

void input()
{
    cin >> s;
    s_size = s.size();
    oper_rank['+'] = oper_rank['-'] = 0;
    oper_rank['*'] = oper_rank['/'] = 1;
}

long long oper(long long a, long long b, char c)
{
    if (c == '+')
    {
        return a + b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    else if (c == '*')
    {
        return a * b;
    }
    else if (c == '/')
    {
        return a / b;
    }
}

void solve()
{
    long long temp1, temp2;
    long long i = 0, j = s_size - 1;
    char oper1, oper2;
    stack<long long> st1, st2;
    if (s[0] == '-')
    {
        temp1 = 0;
        i = 1;
        while (i < s_size && s[i] >= '0' && s[i] <= '9')
        {
            temp1 *= 10;
            temp1 += s[i] - '0';
            i++;
        }
        st1.push(-temp1);
    }   
    else
    {
        temp1 = 0;
        while (i < s_size && s[i] >= '0' && s[i] <= '9')
        {
            temp1 *= 10;
            temp1 += s[i] - '0';
            i++;
        }
        st1.push(temp1);
    }

    temp2 = 0;
    long long tens = 1;
    while (j >= 0 && s[j] >= '0' && s[j] <= '9')
    {
        temp2 += tens * (s[j] - '0');
        tens *= 10;
        j--;
    }
    st2.push(temp2);
    if(i > j){
        cout << st1.top();
        return;
    }

    while (i <= j)
    {
        if (i == j)
        { // 마지막 연산
            cout << oper(st1.top(), st2.top(), s[i]);
            break;
        }
        oper1 = s[i++];
        oper2 = s[j--];
        if (oper_rank[oper1] > oper_rank[oper2])
        {
            temp1 = 0;
            while (i < s_size && s[i] >= '0' && s[i] <= '9')
            {
                temp1 *= 10;
                temp1 += s[i] - '0';
                i++;
            }
            long long t = st1.top();
            st1.pop();
            st1.push(oper(t, temp1, oper1));
            j++;
        }
        else if (oper_rank[oper1] < oper_rank[oper2])
        {
            temp2 = 0;
            tens = 1;
            while (j >= 0 && s[j] >= '0' && s[j] <= '9')
            {
                temp2 += tens * (s[j] - '0');
                tens *= 10;
                j--;
            }
            long long t = st2.top();
            st2.pop();
            st2.push(oper(temp2, t, oper2));
            i--;
        }
        else{ // 우선 순위가 같음 -> 계산 결과가 큰 걸로
            long long ii = i, jj = j;
            temp1 = 0;
            while (ii < s_size && s[ii] >= '0' && s[ii] <= '9')
            {
                temp1 *= 10;
                temp1 += s[ii] - '0';
                ii++;
            }
            long long t = st1.top();
            long long left_result = oper(t, temp1, oper1);
           
            temp2 = 0;
            tens = 1;
            while (jj >= 0 && s[jj] >= '0' && s[jj] <= '9')
            {
                temp2 += tens * (s[jj] - '0');
                tens *= 10;
                jj--;
            }
            t = st2.top();
            long long right_result = oper(temp2, t, oper2);

            if(left_result >= right_result){ // 왼쪽꺼 연산
                i = ii;
                st1.pop();
                st1.push(left_result);
                j++;
            }
            else{
                j = jj;
                st2.pop();
                st2.push(right_result);
                i--;
            }
        }
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}