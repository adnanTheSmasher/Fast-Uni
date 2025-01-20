#include<stdio.h>
int main(){
	for(int i=65; i<=70 ;i++){
		if (i==65 || i==70){
			printf("%C %C %C %C %C \n",i,i+1,i+2,i+3,i+4);
		}
		else{
			printf("%C       %c\n", i,i+4);
		}	
	}
}
