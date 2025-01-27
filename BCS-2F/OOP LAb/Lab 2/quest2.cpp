#include<iostream>
#include<cstring>
using namespace std;

int countVowelFunc(char* str){
	int count = 0;
    while (*str) {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

int main(){
	int num;
	cout<<"Enter number of string: ";
	cin>>num;
	cin.ignore();
	
	char** strings = new char*[num];
	for(int i=0;i<num;i++)
	{
		strings[i] = new char(100);
		cout<<"Enter String["<<i+1<<"]: ";
		cin.getline(strings[i], 100);
	}
	
	int maxVowel = 0;
	int index = 0;
	for(int i=0; i<num;i++)
	{
		int count = countVowelFunc(strings[i]);
		if(count > maxVowel)
		{
			maxVowel = count;
			index = i;
		}
	}
	cout<<"String With Most vowel: "<<strings[index]<<endl;
	float total_length = 0;
	for(int i=0; i<num; i++)
	{
		total_length += strlen(strings[i]);
	}
	float average_length = total_length/num;
	
	
	char temp;
	for(int i=0; i<num;i++)
	{
		int len = strlen(strings[i]);
		for(int j=0; j<len/2; j++)
		{
			temp = strings[i][j];
			strings[i][j] = strings[i][len-1-j];
			strings[i][len-1-j] = temp;
		}
		
	}
	
	
	cout<<"Average string Length: "<<average_length<<endl;
	cout<<"\nString in reverse order\n";
	for(int i=0; i<num; i++)
	{
		cout<<strings[i]<<endl;
	}
}