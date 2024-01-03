#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word,int start,int end){
	if(start>=end){
		return true;
	}
	if(word.at(start)!=word.at(end)){
		return false;
	}
	if(word.at(start)==word.at(end)){
		return isPalindrome(word,start+1,end-1);
	}

}

int main(){
	string word="abba";
	int start=0;
	int end=word.length()-1;
	bool palindrome=isPalindrome(word,start,end);
	if(palindrome){
	cout<<"Given String Is Palindrome";
	}
	else{
		cout<<"Given String Is Not Palindrome";
	}

	
}
