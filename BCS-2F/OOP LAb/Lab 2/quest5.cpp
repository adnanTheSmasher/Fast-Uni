#include<iostream>
#include<string.h>  
using namespace std;


char* ShiftingCharacter(char* str, int num){
    if(num == 0)
        return str;

    int len = strlen(str);
    char* afterShiftArray = new char[len+1];

    strncpy(afterShiftArray, str+len-num, num);
    strncpy(afterShiftArray + num, str, len - num);
    
    return afterShiftArray;

}

int main(){
    cout<<"Enter The String: ";
    char* str = new char[100];
    cin.getline(str, 100);

    int numTotShift = 0;
    cout<<"\nEnter numbebr of characters to shifts: ";
    cin>>numTotShift;

    char* finalArray = ShiftingCharacter(str, numTotShift);

    cout<<"\nAfter Shifting Element: "<<finalArray;
    
    delete[] finalArray;
    delete[] str;
}