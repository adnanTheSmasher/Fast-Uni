#include<iostream>
using namespace std;

class Rectangle{
	private:
		int length;
		int width;
	public:
		void setLength(int l){
			length = l;
		}
		void setWidth(int w){
			width = w;
		}
		
		int getLength(){
			return length;
		}
		int getWidth(){
			return width;
		}
			
		void area(int l, int w){
			setLength(l);
			setWidth(w);
			l = getLength();
			w = getWidth();
			cout<<"The Area is: "<<l*w<<endl;
		}
};

int main(){
	int l, w, area;
	Rectangle rec;
	
	cout<<"Enter Length: ";
	cin>>l;
	
	cout<<"Enter Width: ";
	cin>>w;
	
	rec.area(l,w);
}