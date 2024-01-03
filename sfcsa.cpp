#include <iostream>
#include <vector>
using namespace std;
struct maxIndexes{
	int r,c;
};

maxInedxes findMax(int arr[][3]){
	int maxi,maxj,maxEl=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(arr[i][j]>maxEl){
				maxEl=arr[i][j];
				maxi=i;
				maxj=j
			}
		}
	}
	maxIndexes res;
	res.r=maxi;
	res.c=maxj;
	
	return res;
}
int main() {
    int i,j,k;
    int arr[3][3] = {
        {5, 2, 9},
        {1, 8, 4},
        {7, 6, 3}
    };
    for(int col=0;col<3;col++){
    maxIndexes max=	findMax(arr);
	
}
//Sorting 2D array Column Wise Using Bubble Sort
//for(int col=0;col<3;col++){
//	for(i=0;i<3;i++){
//		for(j=0;j<3-i-1;j++){
//			if(arr[j][col]>arr[j+1][col]){
//				swap(arr[j][col],arr[j+1][col]);
//			}
//		}
//	}
//}
	for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  	  cout<<arr[i][j]<<" ";
	  }
	  cout<<"\n";
}
  
  
}

