#include<iostream>
using namespace std;

int main()
{
	int element_num;
	float sum = 0;
	float avg = 0;
	int count = 0;
	
	cout<<"Enter the number of element: ";
	cin>>element_num;
	
	float* arr = new float[element_num];
	
	for(int i = 0; i<element_num; i++)
	{
		cout<<"Enter element [" << i+1 << "]: ";
		cin>>arr[i];
		sum += arr[i];
	}
	
	avg = sum/element_num;
	
	 float closest = arr[0]; 
    float min_diff = (arr[0] > avg) ? (arr[0] - avg) : (avg - arr[0]); 

    for (int i = 1; i < element_num; i++) {
        float diff = (arr[i] > avg) ? (arr[i] - avg) : (avg - arr[i]);
        if (diff < min_diff) {
            min_diff = diff;
            closest = arr[i];
        }
    }
    
	cout<<"Average Number: "<<avg<<endl;
	cout<<"Number Closet to Average: " << closest;
		
	
}