#include<iostream>
using namespace std;

void fill_array(int** arr, int rows, int cols){
     for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout<< "enter element["<<i+1<<"]["<<j+1<<"]: ";
            cin>>arr[i][j];
        }
    }
}

int calculate_highest(int* arr, int rows, int& index){
    int highest = arr[0];
    index = 0; 
    for (int i = 1; i < rows; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
            index = i; 
        }
    }
    return highest;
}

void deallocate_array(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void print_array(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void calculate_sum(int** arr, int rows, int cols){
    cout << endl;
    int totalSum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            totalSum += arr[i][j];
        }
    }
    cout << "Sum of all elements: "<< totalSum<< endl;
}



void display_row_col_details(int** arr, int rows, int cols){
    int* rows_sum = new int[rows]();
    int* cols_sum = new int[cols]();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rows_sum[i] += arr[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cols_sum[i] += arr[j][i];
        }
    }
    cout<<"Row sums: ";
    for (int i = 0; i < rows; ++i) {
        cout << rows_sum[i] << ", ";
    }
    cout<<"\nCol sums: ";
    for (int i = 0; i < cols; ++i) {
        cout << cols_sum[i] << ", ";
    }

    int highest_row_index, highest_col_index;
    int highest_row = calculate_highest(rows_sum, rows, highest_row_index);
    int highest_col = calculate_highest(cols_sum, cols, highest_col_index);
    cout<<"\nRow with highest sum: Row "<< highest_row_index+1;
    cout<<"\nColumn with highest sum: Col "<< highest_col_index+1;

    delete[] rows_sum;
    delete[] cols_sum;
}


void transposing_matrix(int** arr, int rows, int cols){
    int** transpose_matric = new int*[cols];
    for(int i=0; i<cols; i++){
        transpose_matric[i] = new int[rows];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            transpose_matric[j][i] = arr[i][j];
        }
    }
    cout<<"\n---- Matrix after Transposing ---\n";
    print_array(transpose_matric, cols, rows);
    cout<<"\n------------------------------\n";
    deallocate_array(transpose_matric, cols);
}





int main(){
    int rows, cols;
    cout<<"Enter the number of Rows: ";
    cin>>rows;
    cout<<"Enter the number of Cols: ";
    cin>>cols;
    
    int** arr = new int*[rows];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    fill_array(arr, rows, cols);

    cout<<"\n--- Inserted Array ---\n";
    print_array(arr, rows, cols);
    cout<<"\n----------------------\n";
    calculate_sum(arr, rows, cols);
    display_row_col_details(arr, rows, cols);
    transposing_matrix(arr, rows, cols);
    deallocate_array(arr, rows);

}
