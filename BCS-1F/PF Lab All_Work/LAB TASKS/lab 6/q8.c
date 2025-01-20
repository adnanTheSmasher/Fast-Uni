#include<stdio.h>
int main(){
	for(int i=65; i<=69 ;i++){
		if (i==65 || i==69){
			printf("%C %C %C %C %C \n",i,i+1,i+2,i+3,i+4);
		}
		else if(i==66 || i==68){
			printf("  %C   %c\n", i+1,i+4);
		}
		else{
			printf("    %C   \n", i+2);
		}	
	}
}
