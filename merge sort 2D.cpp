#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int> &first,vector<int> &second){
	vector<int> mix;
	int i=0,j=0;
	while(i<first.size() && j<second.size()){
		if(first[i]<second[j]){
			mix.push_back(first[i]);
			i++;
		}
		else{
			mix.push_back(second[j]);
			j++;
		}
	}
	while(i<first.size()){
		mix.push_back(first[i]);
		i++;
	}
	while(j<second.size()){
		mix.push_back(second[j]);
		j++;
	}
	
	return mix;
}
vector<int> mergeSort(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}
int main(){
int arr[3][5]={{5, 4, 3, 2, 1},
                    {9, 8, 7, 6, 5},
                    {2, 4, 1, 9, 6}};
vector<int> temp;
int i,j;
for(i=0;i<3;i++){
	for(j=0;j<5;j++){
		temp.push_back(arr[i][j]);
	}
}
temp=mergeSort(temp);
int k=0;
for(i=0;i<3;i++){
	for(j=0;j<5;j++){
		arr[i][j]=temp[k];
		k++;
	}
}
for(i=0;i<3;i++){
	for(j=0;j<5;j++){
		cout<<arr[i][j]<<" ";
}
cout<<"\n";
}
}
