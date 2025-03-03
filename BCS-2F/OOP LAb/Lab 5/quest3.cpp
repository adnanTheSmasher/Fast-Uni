#include<iostream>
#include<string>
using namespace std;

class ValidateString
{
	private:
		string letters;
		bool mutable is_valid;
		int lengthString;
	
	public:
		ValidateString(string _stings): letters(_stings){
			lengthString = letters.length();
		};
		
		
	
	    // This function does not modify any member variables, hence it is marked as const.
    	// If we do not make this function constant, we would not be able to call it on const instances of the class.

		
		void checkingString () const
		{
			for(int i=0; i<lengthString; i++)
			{
				if(!isalpha(letters[i])){
					is_valid = false;
					break;
				}
				is_valid = true;
			}
		}
		
		
		bool getValid(){
			return is_valid;
		}
		
		void display_result(){
			if(is_valid)
				cout<< "the String: " << letters << " is Valid"<<endl;
			if(!is_valid)
				cout<< "the String: " << letters << " is not Valid"<<endl;
		}
};

int main(){
	ValidateString s1("Adnan");
	ValidateString s2("Adnan13242");
	
	s1.checkingString();
	s1.display_result();
	s2.checkingString();
	s2.display_result();
	
}