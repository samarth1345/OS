#include<bits/stdc++.h>
using namespace std;
void worstfit(vector<int> process,vector<int> blocks)
{
    sort(blocks.begin(),blocks.end());
    vector<int> allocated,left;
    for(int i=0;i<process.size();i++)
    {
        int j=blocks.size()-1;
        while(j>=0 && process[i]>blocks[j])
        j--;
        if(j>=0)
        {
            allocated.push_back(blocks[j]);
            left.push_back(blocks[j]-process[i]);
            blocks.erase(blocks.begin()+j);
        }
        else
        {
            allocated.push_back(-1);
            left.push_back(-1);
        }
    }
    for(int i=0;i<process.size();i++)
    {
        cout<<"block allocated to "<<process[i]<<" is "<<allocated[i]<<" and left is "<<left[i]<<endl;
    }
}
int main()
{
    int n,m;
    cout<<"Enter no of processes\n";
    cin>>n;
    cout<<"Enter no of blocks\n";
    cin>>m;
    vector<int> process(n),blocks(m);
    for(int i=0;i<n;i++)
    cin>>process[i];
    for(int i=0;i<m;i++)
    cin>>blocks[i];
    worstfit(process,blocks);
}