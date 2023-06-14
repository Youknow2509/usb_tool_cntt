
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct SV{
    char name[20];
    float point_m, point_p, point_c, sum_point;
};

void find_students(char * name_find, struct SV *arr, int n){    
    scanf("%s", find_students);
    for (int i = 0; i < n; i++){
        if (name_find == arr[i].name){
            printf ("Name: %s, point math %f, point physical %f, point chymistry %f\n");
            return;
        }
    }
    printf("Dont have name students in list\n");
}



int main(){

    char ten_tep[20];

    scanf("%s", ten_tep);

    FILE* inp = fopen(ten_tep , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int n;
    float diem_chuan;

    struct SV *arr = (struct SV *)malloc(n*sizeof(struct SV));
    struct SV *arr_solve = (struct SV *)malloc(n*sizeof(struct SV));
    
    for (int i = 0; i < n; i++){
        fgetc(inp);
        fscanf(inp, "%f %f %f", &arr[i].point_m, &arr[i].point_p, &arr[i].point_c);
    }
    
    fscanf("%f", &diem_chuan);

    char name_find[20];
    find_students(name_find, arr, n);

    int index = 0;

    for (int i = 0; i < n; i++){
        if (arr[i].point_c + arr[i].point_m + arr[i].point_p > diem_chuan){
            arr_solve[index].name = arr[i].name;
            arr_solve[index].point_c = arr[i].point_c;
            arr_solve[index].point_m = arr[i].point_m;
            arr_solve[index].point_p= arr[i].point_p;
        }
    }   

    // ss
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr_solve[i].sum_point < arr_solve[i].sum_point){
               struct SV temp;
               temp = arr_solve;
               arr_solve = temp; 
            }
        }
    }
    // in ds
    

    fclose(inp);
    fclose(out);
    free(arr);

    return 0;
}