#include <bits/stdc++.h>
using namespace std;
//with arrival time
//temp.first=burst time , temp.second=waiting time
//ans.first=TAT , ans.second=time when process was preemepted
void RR(int N, int *burst_time, int time_quantum)
{
    vector<pair<int, int>> temp,ans;
    int total_processes = N;
    for (int i = 0; i < N; i++)
    {
        pair<int, int> t,t1;
        t.first = burst_time[i];
        t.second = 0;
        t1.second=0;
        temp.push_back(t);
        ans.push_back(t1);
    }
    int total_time = 0;
    while (total_processes != 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (temp[i].first != 0)
            {
                if (temp[i].first >= time_quantum)
                {
                    temp[i].second += (total_time - ans[i].second);
                    total_time += time_quantum;
                    ans[i].second=total_time;
                    temp[i].first -= time_quantum;
                }
                else
                {
                    temp[i].second += (total_time - ans[i].second);
                    total_time += temp[i].first;
                    temp[i].first = 0;
                }
                if (temp[i].first == 0)
                {
                    total_processes--;
                    ans[i].first=total_time;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "TAT for process P" << i+1 << " is " << ans[i].first << " and waiting time is " << temp[i].second << endl;
    }
}
int main()
{
    int N, time_quantum;
    cin >> N >> time_quantum;
    int burst_time[N];
    for (int i = 0; i < N; i++)
    {
        cin >> burst_time[i];
    }
    RR(N, burst_time, time_quantum);
}