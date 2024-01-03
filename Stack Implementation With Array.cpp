#include<iostream>
using namespace std;
template <typename T>
class Stack{
	private:
	T arr[100];
	int maxSize=100;
	int top;
	public:
		int s;
	Stack(){
		top=-1;
		s=0;
	}
	void push(T data){
		if(top<maxSize){
			top++;
			arr[top]=data;
			s++;
		}
		else{
			cout<<"Stack Overflow";
			return;
		}
	}
	bool isEmpty(){
		return (top==-1);
	}
	T pop(){
		if(!isEmpty()){
			int el=arr[top];
			top--;
			return el;
		}
		else{
			cout<<"Stack Is Empty Can't Pop More Elements";
		}
	}
	T peek(){
		if(!isEmpty){
			return arr[top];
		}
		else{
			cout<<"Stack Is Empty";
		}
	}
	int size(){
		return s;
	}
	
};
int main(){
	Stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	for(int i=0;i<s.size();i++){
		cout<<s.pop();
	}

}
