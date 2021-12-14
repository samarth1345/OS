#include<bits/stdc++.h>
using namespace std;
int start_point(int size,vector<int> tracks,int initial_pointer)
{
    int Min=INT_MAX,min_index=-1;
    for(int i=0;i<size;i++)
    {
        if(abs(tracks[i]-initial_pointer) < Min)
        {
            Min=abs(tracks[i]-initial_pointer);
            min_index=i;
        }
    }
    return min_index;
}
void SSTF(int size,vector<int> tracks,int initial_pointer)
{
    sort(tracks.begin(),tracks.end());
    //index to start with
    int start_index=start_point(size,tracks,initial_pointer);
    //to calculate total movements
    int total_movement=abs(tracks[start_index]-initial_pointer);
    for(int i=0;i<size-1;i++)
    {
        int temp=start_index;
        //if there is no left
        if(temp-1<0)
            start_index+=1;
        //if there is no right
        else if(temp+1>=tracks.size())
            start_index-=1;
        //if diff between left neighbour is less than right neighbour
        else if(abs(tracks[temp]-tracks[temp-1])<abs(tracks[temp]-tracks[temp+1]))
            start_index-=1;
        //if diff between rightt neighbour is less than left neighbour
        else
            start_index+=1;
        total_movement+=abs(tracks[start_index]-tracks[temp]);
        //when there is no left, if we move right and erase 0th index 
        //we will again come at 0th index but we have made it 1 at line no. 28
        if(temp-1<0)
            start_index=0;
        tracks.erase(tracks.begin()+temp);
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
    int initial_pointer;
    cout<<"Enter starting point"<<endl;
    cin>>initial_pointer;
    SSTF(size,tracks,initial_pointer);
}