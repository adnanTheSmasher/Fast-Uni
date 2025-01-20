#include<stdio.h>
#include<math.h>

struct space_2D{
	int X_Coord;
	int Y_Coord;
};

float distance(struct space_2D Coord[2]){
	return sqrt(pow(Coord[1].X_Coord - Coord[0].X_Coord, 2) + pow(Coord[1].Y_Coord - Coord[0].Y_Coord, 2));
}

int boundary_Checker(struct space_2D Coord1, struct space_2D bottomLeft, struct space_2D topRight){
	return  (Coord1.X_Coord>=bottomLeft.X_Coord && Coord1.Y_Coord>=bottomLeft.Y_Coord) &&
				(Coord1.X_Coord<=topRight.X_Coord && Coord1.Y_Coord<=topRight.Y_Coord) ;
}

int main(){
	struct space_2D point[2];
	float dis;
	
	for(int i=0; i<2;i++){
		printf("Enter the X Coordinate for Point %d: ", i+1);
		scanf("%d", &point[i].X_Coord);
		printf("Enter the Y Coordinate for Point %d: ", i+1);
		scanf("%d", &point[i].Y_Coord);
	}
	
	dis = distance(point);
	printf("Total Distance is %.2f\n", dis);
	
	struct space_2D bottomLeft, topRight;

    printf("Enter bottom left corner of rectangle (X Y): ");
    scanf("%d %d", &bottomLeft.X_Coord, &bottomLeft.Y_Coord);
    printf("Enter top right corner of rectangle (X Y): ");
    scanf("%d %d", &topRight.X_Coord, &topRight.Y_Coord);
	
	for(int i=0;i<2;i++){
		if(boundary_Checker(point[i], bottomLeft, topRight) == 1){
			printf("The Point (%d,%d) is in Rectangle.\n", point[i].X_Coord, point[i].Y_Coord);
		}
		else{
			printf("The Point (%d,%d) is not in Rectangle.\n", point[i].X_Coord, point[i].Y_Coord);
		}
	}
}