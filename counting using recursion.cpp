#include<iostream>
using namespace std;
void fact(int n){
	if(n<1){
		return;
	}
	fact(n-1);
	cout<<n;
}
int main(){
	fact(5);
}
