#include<iostream>
#include<string>
using namespace std;
class Myclass{
	public:
		int age;
		string name;
		Myclass(string name,int age){
			this->name=name;
			this->age=age;
		}
		Myclass(Myclass &other){
			this->name=other.name;
			this->age=other.age;
		}
	void info(){
		cout<<"\nName is: "<<this->name;
		cout<<"\nAge is: "<<this->age<<"\n";
	}
	~Myclass(){
		cout<<"\nObjects Of My Class Destroyed";
	}

};
int main(){
	Myclass m1("Abbas",21);
	Myclass m2(m1);
	m1.info();
	m2.info();
}
