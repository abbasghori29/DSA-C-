#include<iostream>
using namespace std;
	void heapifyMax(int *arr,int i,int n){
		int largest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<n && arr[left]>arr[largest]){
			largest=left;
		}
		if(right<n && arr[right]>arr[largest]){
			largest=right;
		}
		if(largest!=i){
			swap(arr[largest],arr[i]);
			heapifyMax(arr,largest,n);
			
		}
	}
int main(){
	    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
	    int n=sizeof(arr)/sizeof(arr[0]);
	    for (int i=n/2-1;i>=0;i--){
	    	heapifyMax(arr,i,n);
		}
		for (int i=0;i<n;i++){
	    	cout<<arr[i]<<" ";
		}
}
