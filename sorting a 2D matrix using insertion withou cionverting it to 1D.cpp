#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i,j,k;
    int arr[3][3] = {
        {5, 2, 9},
        {1, 8, 4},
        {7, 6, 3}
    };

for(int col=0;col<3;col++){
	for(i=1;i<3;i++){
		int key=arr[i][col];
		j=i-1;
		while(j>=0 && key>arr[j][col]){
			arr[j+1][col]=arr[j][col];
			j--;
		}
		arr[j+1][col]=key;
		
	}
	
  }
	for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  	  cout<<arr[i][j]<<" ";
	  }
	  cout<<"\n";
}
  
  
}

