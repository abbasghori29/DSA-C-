#include<iostream>
#include<vector>
using namespace std;
int main(){
	int i,j;
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(9);
	arr.push_back(1);
	
	for(i=0;i<arr.size()-1;i++){
		for(j=0;j<arr.size()-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	int gap=0;
	for(i=0;i<arr.size();i++){
		if(j+1<arr.size()-1 && j<arr.size()-2){
	     	if(arr[j+1]-arr[j]>gap){
			 gap=arr[j+1]-arr[j];
		}
		}
	}
	cout<<gap;
}
