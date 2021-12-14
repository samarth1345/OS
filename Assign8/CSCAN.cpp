#include<bits/stdc++.h>
using namespace std;
int start_point(int size,vector<int> tracks,int initial_pointer)
{
    int Min=INT_MAX,min_index=-1;
    for(int i=0;i<size;i++)
    {
        int temp=tracks[i]-initial_pointer;
        if(temp > 0)
        {
            return i;
        }
    }
    return size-1;;
}
void CSCAN(int size,vector<int> tracks,int initial_pointer,int last_disc)
{
    int total_movement=0,store;
    //pushing last disc loaction into vector
    tracks.push_back(last_disc);
    sort(tracks.begin(),tracks.end());
    //finding first tracks larger than initial_pointer
    int starting_index=start_point(size,tracks,initial_pointer);
    store=starting_index;
    //going right in tracks
    for(int i=starting_index;i<=size;i++)
    {
        total_movement+=abs(initial_pointer-tracks[i]);
        initial_pointer=tracks[i];
    }
    //moving from last disc location to 0
    total_movement+=last_disc;
    initial_pointer=0;
    //moving right again from starting
    for(int i=0;i<store;i++)
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
    vector<int> tracks(size);
    cout<<"Enter value of tracks"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>tracks[i];
    }
    int initial_pointer,last_disc;
    cout<<"Enter starting point and last disc location"<<endl;
    cin>>initial_pointer>>last_disc;
    CSCAN(size,tracks,initial_pointer,last_disc);
}
