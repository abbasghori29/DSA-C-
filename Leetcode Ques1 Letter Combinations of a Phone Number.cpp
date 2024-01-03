#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void makeCombinations(string targetString,string digits,vector <string> &ans,string numberValues[],int indexOfTraget,int indexOfAlphabet){
		 if(indexOfTraget>=targetString.length()){
	    	return;
		}
		int i;
	    
	   string finalString = string(1, targetString.at(indexOfTraget));
		for(i=1;i<digits.length();i++){
		
		string temp=numberValues[digits.at(i)-'0'];
		if(indexOfAlphabet<temp.length()){
			  finalString+=temp[indexOfAlphabet];
		}
		  
		
		}

		ans.push_back(finalString);
		indexOfTraget++;
	    
	   
		
			return makeCombinations(targetString,digits,ans,numberValues,indexOfTraget+1,indexOfAlphabet+1);	
		}
	
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        int i;
        string numberValues[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        	int	currentNumber=digits.at(0)-'0'; // to convert char to integer
	     	string targetString =numberValues[currentNumber];
	     makeCombinations(targetString,digits,ans,numberValues,0,0);
	     for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
        
    }
};

int main(){
	Solution s1;
	s1.letterCombinations("23");
}
