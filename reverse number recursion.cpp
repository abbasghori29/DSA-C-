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
int main(){
    reverseNum(43);
    cout<<sum;
}
