#include <stdio.h>

int main() {
    int matrix[3][3];

    // Input the 3x3 matrix
    printf("Enter the elements of a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
	
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++){
    		int saddlePoint = 1;
    		
    		for(int k=0;k<3;k++){
    			if(matrix[i][k] < matrix[i][j]){
					saddlePoint = 0;
					break;
				}
			}
			
			if(saddlePoint){
				for(int k=0;k<3;k++){
    				if(matrix[k][j] > matrix[i][j]){
						saddlePoint = 0;
						break;
					}
				}	
			}
    		
    		if(saddlePoint){
    			printf("[%d, %d]: %d", i,j,matrix[i][j]);
			}
		}
	}
    
    
    
    return 0;
}