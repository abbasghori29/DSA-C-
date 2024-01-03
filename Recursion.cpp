#include <iostream>
using namespace std;
int factorial(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return n;
	}
	return n*factorial(n-1);
}
int main(){
	int n;
	cout<<"Enter Number To Calculate Factorial: ";
	cin>>n;
	int ans;
	ans=factorial(n);
	cout<<"Factorial Of Given Number Is: "<<ans;
	
}
