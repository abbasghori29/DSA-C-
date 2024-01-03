#include<iostream>
#include<vector>
using namespace std;
int main(){
		int i,j,left,right,total,num2,num3;
	vector<int> arr;
	vector<vector<int> > ans;
	arr.push_back(-1);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(-1);
	arr.push_back(4);
	//sort array
		for(i=0;i<arr.size()-1;i++){
		for(j=0;j<arr.size()-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	// 3sum
	for(i=0;i<arr.size();i++){
		left=i+1;
		right=arr.size();
		while(left<right){
			total=arr[i]+arr[left]+arr[right];
			if(total>0){
				right--;
			}
			else if(total<0){
				left++;
			}
			else{
			vector<int> triplet;
                triplet.push_back(arr[i]);
                triplet.push_back(arr[left]);
                triplet.push_back(arr[right]);
                ans.push_back(triplet);
			}
		}
		
	}
//	  for(i=0;i<3;i++){
//	  	for(j=0;j<2;j++){
//	  		cout<<ans[i][j];
//		  }
//	  }
	
}
