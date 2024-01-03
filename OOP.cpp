#include <iostream>
#include <string>
using namespace std;
class Book{
	public:
		string name,author;
		int price;
		Book(string name,string author,int price){
			this->name=name;
			this->author=author;
			this->price=price;
		}
		
		Book(const Book& other){
			this->author=other.author;
			this->name=other.name;
			this->price=other.price;

		}
		
		 void showDetails() {
        cout << "\nBook Title: " << this->name;
        cout << "\nAuthor: " << this->author;
        cout << "\nPrice: " << this->price<<" PKR";
    }
		~Book(){
			cout<<"\n\nThe Book Object Has Destroyed";
		}
		
	 
};
int main(){
	int bn;
	Book b[2]={
    Book("Reclaim Your Heart","Yasmin Mogahed",1000),
	Book("Nineteen Eighty-Four","George Orwel",1200),
};
cout<<"Following Books Are Available: \n";
cout<<"\nBook 1: ";
b[0].showDetails();
cout<<"\n\nBook 2: ";
b[1].showDetails();
cout<<"Which Book Do You Wanna Purchase: ";
cin>>bn;
}
