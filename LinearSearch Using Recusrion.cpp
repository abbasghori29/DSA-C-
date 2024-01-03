#include <iostream>
using namespace std;
int linearSearch(int *arr,int target,int size,int index){
	if(arr[0]==target){
		return index;
	}
	return (linearSearch(arr+1,target,size-1,index+1));
}
int main(){
	int arr[]={2,5,6,8,9};
	int target=8;
	int index=0; 
	int size=(sizeof(arr)/sizeof(arr[0]))-1; // it give the accurate size
	int ans=linearSearch(arr,target,size,index);
	cout<<ans;
}
