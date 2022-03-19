#include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>>& adjList,vector<int>&vis,int index){
	if(vis[index]==1) return;
	vis[index] = 1;
	for(int i : adjList[index]){
		DFS(adjList,vis,i);
	}
	cout<<index<<" ";
	return;
}

int main(){
	int v,e,count=0;
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
		for(int it : adjList[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	vector<int> vis(v+1,0);
	for(int i=1;i<=v;i++){
		if(vis[i]==0){
			count++;
			DFS(adjList,vis,i);
		}
	}
	
    cout<<"\n No of connected components:" <<count<<endl;
	return 0;
}
