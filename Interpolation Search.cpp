#include<iostream>
#include<vector>
using namespace std;
int main(){
	int arr[]={1,2,3,4,5,6,7};
	int n=(sizeof(arr)/sizeof(arr[0]));
	int low=0;
	int high=n-1;
	int target=7;
//	Algorithm
while(low<=high){
	int pos = (low +(((high-low)*target-arr[low]))/(arr[high]-arr[low]));
	if(arr[pos]>target){
		low=low+1;
	}
	else if(arr[pos]<target){
		high=high-1;
	}
	else if(target==arr[pos]){
		cout<<pos;
		break;
	}
}
	
}

