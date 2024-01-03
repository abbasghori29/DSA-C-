#include<iostream>
#include<vector>
using namespace std;
int findMax(vector<int> arr,int start,int end){
	int i,max=0,maxInd=0;
	for(i=start;i<=end;i++){
		if(arr[i]>max){
			max=arr[i];
			maxInd=i;
		}
	}
	return maxInd;
}
void selectionSort(vector<int> &arr){
	int i;
	for(i=0;i<arr.size();i++){
		int start=0;
		int end=arr.size()-i-1;
		int maxIndex=findMax(arr,start,end);
		swap(arr[end],arr[maxIndex]);
	}
}
int main(){
	int arr[5]={5, 4, 3, 2, 1};
vector<int> temp;
int j;
	for(j=0;j<5;j++){
		temp.push_back(arr[j]);
	}
	selectionSort(temp);
	for(j=0;j<5;j++){
		cout<<temp[j]<<" ";
	}
}

