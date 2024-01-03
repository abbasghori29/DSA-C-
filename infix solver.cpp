#include<iostream>
#include<stack>
#include<string>
#include <cctype>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
int infixSolver(string exp){
	stack <int> num;
	stack <int> op;
	for(int i=0;i<exp.length();i++){
		if(isdigit(exp[i])){
			num.push(exp[i]-'0');
		}
		else if(exp[i]=='('){
			op.push(exp[i]);
		}
		else if(exp[i]==')'){
			while(!op.empty() && op.top()!='('){
				char opr=op.top();
				op.pop();
				int n1=num.top();
				num.pop();
				int n2=num.top();
				num.pop();
				switch(opr){
					case '+':
						num.push(n1+n2);
						break;
					case '-':
						num.push(n1-n2);
						break;
					case '*':
						num.push(n1*n2);
						break;
					case '/':
						num.push(n1/n2);
						break;
				}
			}
			op.pop();
		}
		else if(exp[i]=='-'|| exp[i]=='+' || exp[i]=='*' || exp[i]=='/'){
			while(!op.empty() && precedence(exp[i])>=op.top()){
				char opr=op.top();
				op.pop();
				int n1=num.top();
				num.pop();
				int n2=num.top();
				num.pop();
				switch(opr){
					case '+':
						num.push(n1+n2);
						break;
					case '-':
						num.push(n1-n2);
						break;
					case '*':
						num.push(n1*n2);
						break;
					case '/':
						num.push(n1/n2);
						break;
				
			}
			}
			op.push(exp[i]);
		}
		
	}
	while(!op.empty()){
		char opr=op.top();
				op.pop();
				int n1=num.top();
				num.pop();
				int n2=num.top();
				num.pop();
				switch(opr){
					case '+':
						num.push(n1+n2);
						break;
					case '-':
						num.push(n1-n2);
						break;
					case '*':
						num.push(n1*n2);
						break;
					case '/':
						num.push(n1/n2);
						break;
	}
	return num.top();
}
}
int main(){
	string exp="1*2+3*(2+4)-4";
	cout<<infixSolver(exp);
}
