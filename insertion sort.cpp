#include<iostream>
using namespace std;
int main(){
	int arr[11]={9,8,7,6,5,4,3,2,1,0};
	int i,j,key;
	int n=sizeof(arr)/sizeof(arr[0]);
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;		
	}
		for(i=1;i<n;i++){
			cout<<arr[i]<<" ";
}
}

