#include <stdio.h>

int main()
{
    int mat1[3][3], mat2[3][3], result[3][3];
    int sum = 0;
    printf("Enter elements for matrix 1\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter element [%d][%d]: ",i+1,j+1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter elements for matrix 2\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter element [%d][%d]: ",i+1,j+1);
            scanf("%d", &mat2[i][j]);
        }
    }
    
    
    // Multiplying 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++)
                result[i][j] = (mat1[i][k] * mat2[k][j]);
        }
    }
    
    //Subtracting
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        result[i][j] = result[i][j] - mat1[i][j];
        }
    }
    
    printf("Resultant matrix is...\n ");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}