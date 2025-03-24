#define _USE_MATH_DEFINES
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Shape
{
    protected:
        string position;
        string color;
        float borderThickness;
    public:
        Shape(): position("(0,0)"), color("Black"), borderThickness(0){};
        Shape(string pos, string col, float thickness): position(pos), color(col), borderThickness(thickness){};

        virtual void draw(){};
        virtual void calculateArea(){};
        virtual void calculatePerimeter(){};
    
};

class Circle: virtual Shape
{
    private:
        string centerPosition;
        float radius;
        float area;
        float perimeter;
    public:
        Circle(): Shape("(0,0)", "Black", 0), centerPosition("(0,0)"), radius(0), area(0), perimeter(0){};    
        Circle(string pos, string col, float thickness, string centerpos, float rad): Shape(pos, col, thickness), centerPosition(centerpos), radius(rad){
            area = 0;
            perimeter = 0;
        };    
        void draw() override
        {
            calculateArea();
            calculatePerimeter();
            cout<< "\n---Drawing the Shape circle---"<<endl;
            cout<< "Thickness: "<< borderThickness<<endl;
            cout<< "Radius: "<< radius<<endl;
            cout<< "Perimeter: "<< perimeter<<endl;
            cout<< "Area: "<< area<< endl;
            cout<< "At position: "<< centerPosition<<endl;
        }
        void calculateArea() override
        {
            area = M_PI * pow(radius, 2);
        }
        void calculatePerimeter() override
        {
            perimeter = 2 * M_PI * radius;
        }
};

class Rectangle: virtual Shape
{
    private:
        string topLeftPosition;
        float width;
        float height;
        float perimeter;
        float area;
    public:
        Rectangle(): Shape(), topLeftPosition("(0,0)"), width(0), height(0),area(0), perimeter(0){};    
        Rectangle(string pos, string col, float thickness, string topleftpos, float w, float h): Shape(pos, col, thickness), topLeftPosition(topleftpos), width(w), height(h){
            area = 0;
            perimeter = 0;
        };    
        void draw() override
        {
            calculateArea();
            calculatePerimeter();
            cout<< "\n---Drawing the Shape Rectangle---"<<endl;
            cout<< "Thickness: "<< borderThickness<<endl;
            cout<< "Width: "<< width<<endl;
            cout<< "Heigth: "<< height<<endl;
            cout<< "Perimeter: "<< perimeter<<endl;
            cout<< "Area: "<< area<<endl;
            cout<< "At position: "<< topLeftPosition<<endl;
        }
        void calculateArea() override
        {
            area = width * height;
        }
        void calculatePerimeter() override
        {
            perimeter = (2*width) + (2*height);
        }
};

class Polygon: public Shape
{
    protected:
        int numberOfSides;
        float area;
        float perimeter;
    public:
        Polygon(): Shape(), numberOfSides(0), area(0), perimeter(0){};
        Polygon(string pos, string col, float thickness, int sides): Shape(pos, col, thickness), numberOfSides(sides) {
            area = 0;
            perimeter = 0;
        };

        void draw() override
        {
            calculateArea();
            calculatePerimeter();
            cout << "\n---Drawing a Polygon---" << endl;
            cout << "Thickness: " << borderThickness << endl;
            cout << "Number of Sides: " << numberOfSides << endl;
            cout << "At position: " << position << endl;
        }
        void calculateArea() override
        {
            cout<< "Calculating Area"<< endl;
        }
        void calculatePerimeter() override
        {
            cout<< "Calculating Perimeter"<< endl;
        }
};

class Triangle: public Shape
{
    private:
        float base;
        float height;
        float area;
        float perimeter;
    public:
        Triangle(): Shape(), base(0), height(0), area(0), perimeter(0){};
        Triangle(string pos, string col, float thickness, float b, float h ): Shape(pos, col, thickness), base(b), height(h) {
            area = 0;
            perimeter = 0;
        };

        void draw() override
        {
            calculateArea();
            calculatePerimeter();
            cout << "\n---Drawing the Shape Triangle---" << endl;
            cout << "Thickness: " << borderThickness << endl;
            cout << "Base: " << base << endl;
            cout << "Height: " << height << endl;
            cout << "Perimeter: " << perimeter << endl;
            cout << "Area: " << area << endl;
            cout << "At position: " << position << endl;
        }
        void calculateArea() override
        {
            area = 0.5 * base * height;
        }
        void calculatePerimeter() override
        {
            perimeter = 3 * base;
        }
};

int main() {
   
    Circle circle("Circle Position", "Red", 2.0, "(1,1)", 5.0);
    circle.draw(); // Call the draw method for Circle

   
    Rectangle rectangle("Rectangle Position", "Blue", 1.5, "(2,2)", 4.0, 6.0);
    rectangle.draw(); 

    
    Polygon polygon("Polygon Position", "Green", 1.0, 5);
    polygon.draw(); 

    
    Triangle triangle("Triangle Position", "Yellow", 1.2, 3.0, 4.0);
    triangle.draw(); 

    return 0;
}