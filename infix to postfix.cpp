#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int precedence(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='/' || c=='*'){
		return 2;
	}
	else if(c=='-' || c=='+'){
		return 1;
	}
	return -1;
}
bool isOperator(char c){
	return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^');
}
string infixToPrefix(string exp){
	stack <char> op;
	string ans;
	for(int i=0;i<exp.length();i++){
	if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
		ans+=exp[i];
	}
	else if(exp[i]=='('){
		op.push(exp[i]);
	}
	if(exp[i]==')'){
		while(!op.empty() && op.top()!='('){
			ans+=op.top();
			op.pop();
		}
		if(!op.empty() && op.top()=='('){
			op.pop();
		}
	}
	if(isOperator(exp[i])){
		if(!op.empty() && precedence(exp[i])<=precedence(op.top())){
			ans += op.top();
			op.pop();
			op.push(exp[i]);
		}
		else{
		op.push(exp[i]);	
		}
	}	
}
while(!op.empty()){
	ans+=op.top();
	op.pop();
}

return ans;
}
int main(){
	string exp= "a+b*(k+L)-c";
	cout<<infixToPrefix(exp);
}



