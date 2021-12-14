// C++ implementation to create a file
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
fstream file;
file.open("Gfg.txt",ios::out);
if(!file)
{
	cout<<"Error in creating file!!!";
	return 0;
}
cout<<"File created successfully.";
file.close();
return 0;
}
