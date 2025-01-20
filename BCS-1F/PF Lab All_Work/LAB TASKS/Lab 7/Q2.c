#include <stdio.h>

int main(){
	char message[50];
	int a_Count = 0, e_Count = 0, i_Count = 0, o_Count = 0,u_Count = 0;
	printf("Enter your message: ");
	gets(message);
	for(int i = 1; i<=50;i++){
		if(message[i] == 'a' || message[i] == 'A'){
			a_Count += 1;
		}
		if(message[i] == 'e' || message[i] == 'E')
			e_Count += 1;
		if(message[i] == 'i' || message[i] == 'I')
			i_Count += 1;
		if(message[i] == 'o' || message[i] == 'O')
			o_Count += 1;
		if(message[i] == 'u' || message[i] == 'U')
			u_Count += 1;
	}
	
	printf("a = %d, e = %d, i = %d, o = %d, u = %d", a_Count, e_Count, i_Count, o_Count, u_Count);
	
}
