#include<iostream>
using namespace std;

class Square{
	private:
		float sideLength;
		float area;
		static float allareas;
		
	public:
		Square() {
			sideLength = 0;
		}
		
		Square(float side): sideLength(side){};
		
		void calculateArea()
		{
			area = sideLength*sideLength;
			allareas += area;
		}
		
		float getArea(){
			return area;
		}
		
		float getSideLength(){
			return sideLength;
		}
		
		float getAllAreas(){
			return allareas;
		}
		
		void setArea(float value){
			area = value;
		}
		
		void setSideLength(float value){
			sideLength = value;
		}
		
		void setAllAreas(float value){
			allareas = value;
		}
}; 

float Square:: allareas = 0;


int main(){
	Square s1(5);
	Square s2(3);
	Square s3(4);
	
	s1.calculateArea();
	cout<< "Square 1 area: "<< s1.getArea()  << ", Total Area Calculated: " << s1.getAllAreas() << endl;
	s2.calculateArea();
	cout<< "Square 2 area: "<< s2.getArea() << ", Total Area Calculated: " << s2.getAllAreas() << endl;
	s3.calculateArea();
	cout<< "Square 3 area: "<< s3.getArea() << ", Total Area Calculated: " << s3.getAllAreas()  << endl;
}