#include <iostream>
#include <string>
using namespace std;

string ReverseString(string word,int start,int end){
	if(start==end){
		return word;
	}
	 swap(word.at(start),word.at(end));  // there is builtin function of swap in std library
	 start++;
	 end--;
	 

	return ReverseString(word,start,end);
	
}

int main(){
	string word="PAKISTAN ZINDABAD";
	int start=0;
	int end=word.length()-1;
	string reverse=ReverseString(word,start,end);
	cout<<reverse;
	
}
