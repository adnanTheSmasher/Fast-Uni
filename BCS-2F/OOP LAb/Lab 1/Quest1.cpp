#include<iostream>
using namespace std;

int main()
{
    int num;
    bool is_prime = false;

    cout<<"Enter a number: ";
    cin>>num;

    if(num <= 1 ){
        is_prime = true;
    }

    for(int i=2; i<num - 1; i++)
    {
        if(num % i == 0){
            is_prime = false;
        }
    }

    if(is_prime){
    cout<<num<<" is Prime";
    }
    else if(!is_prime){
    cout<<num<<" is not Prime";
    }


}
