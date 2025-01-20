#include<iostream>
using namespace std;

int main()
{
	int arr[] = {2,7,11,15};
	int target = 18;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	
	for(int i = 0; i < arr_size; i++){
		for(int j = 1; j < arr_size; j++){
			if(arr[i] + arr[j] == target){
				cout<<"[" << i << ", " << j <<"]";
				return 0;
			}
		}
	}
		
}
