#include<iostream>
using namespace std;

int* remove_duplicate(int* arr, int size, int& newSize){
    int* temp_arr = new int[size]();
    bool is_duplicate = false;

    for(int i=0; i<size; i++){
        is_duplicate = false;
        for(int j=0; j<newSize; j++){
            if(arr[i] == temp_arr[j]){
                is_duplicate = true;
                break;
            }
        }
        if(!is_duplicate){
            temp_arr[i] = arr[i];
            newSize++;
        }
    }

    return temp_arr;
}

int main(){
    int totalElement;
    int newSize = 0;

    cout<<"Enter number of Element: ";
    cin>>totalElement;

    int* arr = new int[totalElement];

    for(int i=0; i<totalElement; i++){
        cout<<"Enter Element["<<i+1<<"]: ";
        cin>>arr[i];
    }

    int* uniqueArr = remove_duplicate(arr, totalElement, newSize);

    cout<<"\nUnique Elements in the array are: ";
    for(int i=0; i<newSize; i++){
        cout<<uniqueArr[i];
    }

    delete[] uniqueArr;
    delete[] arr;

}