#include<stdio.h>
int main(){
	int ph;
	
	printf("Enter Ph Value: ");
	scanf("%d", &ph);
	printf("\n");
	if (ph > 7){
		if (ph < 12){
			printf("Alkaline");
		}else{
			printf("Very Alkaline");
		}
	}
	else if(ph == 7){
		printf("neutral");
	}else if(ph > 2 && ph < 7){
		printf("Acidic");
	}else{
		printf("very acidic");
	}
}