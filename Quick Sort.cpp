#include<iostream>
using namespace std;
void quickSort(int *arr,int low,int high){
	if(low>=high){
		return;
	}
	int start=low;
	int end=high;
	int mid=start+(end-start)/2;
	int pivot=arr[mid];
	while(start<=end){
		while(arr[start]<pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		if(start<=end){
			swap(arr[start],arr[end]);
			start++;
			end--;
		}
	}
	quickSort(arr,start,high);
	quickSort(arr,low,end);
	
}
int main(){
	int arr[]={5,4,3,2,1};
	quickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		cout<<arr[i];
	}
}
