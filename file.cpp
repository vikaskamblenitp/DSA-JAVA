#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			v.push_back(v[i]+1);
			cout<<__builtin_popcount(v[i])<<" ";	
		}
		cout<<"\n";
		for(auto num : v) cout<<num<<" ";
		cout<<"\n"<<*max_element(v.begin(), v.end())<<" "<<*min_element(v.begin(), v.end());	
	}
	

	return 0;
}
