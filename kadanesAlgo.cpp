#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int res=arr[0],sum=arr[0];

	for(int i=1;i<n;i++){
		if(sum+arr[i]< arr[i]) sum = arr[i];
		else sum+=arr[i];
		res = max(res,sum);
	}

	cout<<res<<endl;	
	return 0;
}
