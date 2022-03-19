#include<bits/stdc++.h>
using namespace std;

vector<int> NGL(vector<int> arr, int n){
	stack<int> s;
	vector<int> res(n);

	for(int i=0;i<n;i++){
		if(s.empty()){
			res[i] = -1;
			s.push(i);
		}
		else if(arr[i] >= arr[s.top()]){
			while(!s.empty() and arr[i] >= arr[s.top()]){
				s.pop();
			}

			if(s.empty()){
				res[i] = -1;
			}
			else res[i] = s.top();
		}
		else {
			res[i] = s.top();
		}

		s.push(i);
	}

	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> res = NGL(arr,n);

	for(int index : res) cout<<arr[index]<<" ";

	return 0;
}
