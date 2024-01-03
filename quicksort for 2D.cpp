#include<iostream>
using namespace std;
void quickSort2D(int *arr,int low ,int high){
	if(low>=high){
		return;
	}
	int start=low;
	int end=high;
	int mid=(start+end)/2;
	int pivot=arr[mid];
	while(start<=end){
		while (pivot<arr[end]){
			end--;
		}
		while (pivot>arr[start]){
			start++;
		}
		if(start<=end){
			swap(arr[start],arr[end]);
			start++;
			end--;
		}
	}
	quickSort2D(arr,start,high);
	quickSort2D(arr,low,end);
	
}
int main(){
	int arr[3][5]={{5, 4, 3, 2, 1},
                    {9, 8, 7, 6, 5},
                    {2, 4, 1, 9, 6}};
        for(int i = 0 ; i<3; i++){
        	quickSort2D(arr[i],0,(sizeof(arr[i])/sizeof(arr[i][0]))-1);
		}
    int temp[3*5];
    int k=0;
    for(int i=0;i<3;i++){
    	for(int j=0;j<5;j++){
    		temp[k]=arr[i][j];
    		k++;
		}
	}
	quickSort2D(temp,0,(sizeof(temp)/sizeof(temp[0]))-1);
	k=0;
	for(int i=0;i<3;i++){
    	for(int j=0;j<5;j++){
    		arr[i][j]=temp[k];
    		k++;
    	}
    }
	
for(int i=0;i<3;i++){
    	for(int j=0;j<5;j++){
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<"\n";
    }
                    
}
