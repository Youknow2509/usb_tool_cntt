
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct diem{
    float x, y;
};

int main(){

    FILE* inp = fopen("Show_screen/INP.TXT" , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int n; fscanf(inp, "%d", &n);

    struct diem *arr = (struct diem *)malloc(n*sizeof(struct diem));

    float s = 0;

    for (int i = 0; i < n; i++){
        fscanf(inp, "%f %f", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < n - 1; i++){
        s += sqrt(pow(arr[i].x - arr[i+1].x, 2) + pow(arr[i].y - arr[i+1].y, 2));
    }

    fprintf(out, "Do dai duong gap khuc qua cac diem tu 1, 2, 3, ..., n la: %f\n", s);

    fclose(inp);
    fclose(out);
    free(arr);

    return 0;
}