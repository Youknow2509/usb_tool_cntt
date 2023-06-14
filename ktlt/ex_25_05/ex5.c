
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    char ten_tep[20];

    scanf("%s", ten_tep);

    FILE* inp = fopen(ten_tep , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int cols, rows;

    fscanf(inp, "%d %d", &rows, &cols);

    float **arr = (float**)malloc(rows*sizeof(float*));
    for (int i = 0; i < rows; i++){
        arr[i] = (float*)malloc(cols*sizeof(float));
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            fscanf(inp, "%f", arr[i][j]);
        }
    }

    float *sum_cols = (float*)malloc(cols*sizeof(float*));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            sum_cols[j] += arr[i][j];
        }
    }

    for (int i = 0; i < cols; i++){
        fprintf(out, "Tong cac phan tu cua cot %d la: %f\n", i + 1, sum_cols[i]);
    }

    fclose(inp);
    fclose(out);
    free(arr);

    return 0;
}