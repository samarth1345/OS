#include<bits/stdc++.h>
using namespace std;
void FCFS(int size,int *tracks,int initial_pointer)
{
    int total_movement=0;
    for(int i=0;i<size;i++)
    {
        total_movement+=abs(initial_pointer-tracks[i]);
        initial_pointer=tracks[i];
    }
    cout<<"Total movement is "<<total_movement<<endl;
}
int main()
{
    int size;
    cout<<"Enter no of tracks"<<endl;
    cin>>size;
    int tracks[size];
    cout<<"Enter value of tracks"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>tracks[i];
    }
    int initial_pointer;
    cout<<"Enter starting point"<<endl;
    cin>>initial_pointer;
    FCFS(size,tracks,initial_pointer);
}