#include<bits/stdc++.h>
using namespace std;
void NGR(vector<int> arr,int n){
	stack<int> s;
	vector<int> res(n);

	for(int i=n-1;i>=0;i--){
		if(s.empty()){
			res[i]=n;
			s.push(i);
		}
		else if(arr[i]>=arr[s.top()]){
			while(!s.empty() && arr[i]>=arr[s.top()]) 
				s.pop();
			if(s.empty()) res[i]=n;
			else res[i]=s.top();
			s.push(i);
		}
		else if(arr[i]<arr[s.top()]){
			res[i]=s.top();
			s.push(i);
		}
	}

	for(int i=0;i<n;i++) cout<<arr[res[i]]<<" ";
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	NGR(arr,n);	
	return 0;
}