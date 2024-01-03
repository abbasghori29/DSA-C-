#include<iostream>
#include<vector>
using namespace std;
int main(){
	int arr[]={1,2,3,4,5,6,7};
	int n=(sizeof(arr)/sizeof(arr[0]));
	int start=0;
	int end=n-1;
	int target=7;
//	Algorithm
while(start<=end){
	int mid = (start+end)/2;
	if(arr[mid]==target){
		cout<<mid;
		break;
	}
	else if(target>arr[mid]){
		start=mid+1;
	}
	else if(target < mid){
		end=mid-1;
	}
}
	
}

