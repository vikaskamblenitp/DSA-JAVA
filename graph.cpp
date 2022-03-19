#include<bits/stdc++.h>
using namespace std;


int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<int> > adjList(v+1);
	for(int i=0;i<e;i++){
		int src,dest;
		cin>>src>>dest;
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	for(int i=1;i<=v;i++){
		cout<<i<<" : ";
		for(int it : adjList[i]) cout<<it<<" ";
		cout<<endl;	
	}
    
	return 0;
}
