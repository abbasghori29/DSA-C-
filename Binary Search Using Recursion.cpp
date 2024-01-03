#include <iostream>
using namespace std;
int binarySearch(int *arr,int start, int end , int target){
	if(start<=end){
	
	int mid=start+(end-start)/2;
	if(arr[mid]==target){
		return mid;
	}
	if(target>arr[mid]){
		start=mid+1;
	return binarySearch(arr,start,end,target);
	}
	else if(target<arr[mid]){
		end=mid-1;
		return binarySearch(arr,start,end,target);
	}
}
return -1;
}

int main(){
	int arr[]={2,5,6,8,9,10,15};
	int start=0;
	int end=(sizeof(arr)/sizeof(arr[0]))-1; // it give the accurate size
	int target=9;
	int ans=binarySearch(arr,start,end,target);
	cout<<"Element Found At Index: "<<ans;
    
}
