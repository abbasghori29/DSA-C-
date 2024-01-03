#include <iostream>
using namespace std;
int findWays(int n){
if(n==0){
	return 1;
}
if(n<0){
	return 0;
}
return findWays(n-1)+findWays(n-2);
}
int main(){
	int n;
	cin>>n;
	int waysCount=findWays(n);
	cout<<waysCount;
}
