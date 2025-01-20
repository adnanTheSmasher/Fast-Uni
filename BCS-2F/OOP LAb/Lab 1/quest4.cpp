#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int height[] = {1,8,6,2,5,4,8,3,7};
	int left_index = 0;
	int heightArr_size = sizeof(height) / sizeof(height[0]);
	int right_index = heightArr_size - 1;
	int max_area = 0;
	
	while(left_index < right_index)
	{
		int current_area = min(height[left_index], height[right_index]) * (right_index - left_index);
		max_area = max(max_area, current_area);
		
		if(height[left_index] < height[right_index])
			left_index++;
		else
			right_index--;
		
	}
	
	cout<<"Max Area: " << max_area;
	
}
