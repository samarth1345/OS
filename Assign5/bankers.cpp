#include<bits/stdc++.h>
using namespace std;
#define MAX 10
//to check if particular process can be allocated available resources
bool check(int p,int m,int Need[][MAX],int *Available)
{
    for(int i=0;i<m;i++)
    {
        if(Need[p][i]>Available[i])
            return false;
    }
    return true;
}
//if process can be allocated resources,freeing resources owned by process
void increaseAvailabe(int p,int m,int Need[][MAX],int *Available)
{
    for(int i=0;i<m;i++)
    {
        Available[i]+=Need[p][i];
    }
}
void bankers(int n,int m,int *Available,int Max[][MAX],int Allocated[][MAX])
{
    int Need[MAX][MAX],Finished=0;
    vector<int> safesequence;
    //calculating need for each process
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Need[i][j]=Max[i][j]-Allocated[i][j];
        }
    }
    //finding safe sequence
    int counter=0;
    while(Finished!=n && counter<=n)
    {
        for(int i=0;i<n;i++)
        {
            if(Need[i][0]!=-1 && check(i,m,Need,Available))
            {
                safesequence.push_back(i+1);
                increaseAvailabe(i,m,Need,Available);
                Need[i][0]=-1;
                Finished++;
            }
        }
        counter++;
    }
    if(counter>n)
    {
        cout<<"there is no safe sequence"<<endl;
        return;
    }
    cout<<"safe sequence: ";
    for(int i=0;i<n;i++)
    cout<<safesequence[i]<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    int Available[m];
    cout<<"Enter Available resources"<<endl;
    for(int i=0;i<m;i++)
    cin>>Available[i];
    int Max[MAX][MAX],Allocated[MAX][MAX];
    cout<<"Enter Max resources required by each process"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>Max[i][j];
        }
    }
    cout<<"Enter Allocated resources to each process"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>Allocated[i][j];
        }
    }
    bankers(n,m,Available,Max,Allocated);
}