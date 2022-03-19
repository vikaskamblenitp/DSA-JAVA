#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int res=arr[0],max_product = arr[0], min_product = arr[0];
	int flag = 0;
	for(int i=1;i<n;i++){
		if(arr[i] > 0){
			max_product *= arr[i];
			min_product *= arr[i];
		}
		else if(arr[i] < 0){

			int temp = max_product;
			max_product = min_product*arr[i];
			min_product = temp*arr[i];	
		}
		else {
			flag = 1;
			max_product=1;
			min_product=1;
		}
		res = max(res,max_product);
	}
	if(flag==1) cout<<0;
	else cout<<res<<endl;	
	return 0;
}
