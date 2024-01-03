#include<iostream>
using namespace std;
int sum=0;
int reverseNum(int n){
	if(n==0){
		return 0;
	}
	int rem=n%10;
	sum=sum*10+rem;
	return reverseNum(n/10);
}
bool palindrome(int n){
	reverseNum(n);
	if(n==sum){
		return true;
	}
	return false;
}
int main(){
	if(palindrome(12421)){
		 cout<<"True";
	}
   
}
