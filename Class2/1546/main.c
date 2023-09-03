#include <stdio.h>

int main(){
    double a;
    scanf("%lf", &a);
    double *p = (double*)malloc(sizeof(double) * a);
    int x;
    for(x = 0; x < a; x++){
        scanf("%lf", &p[x]);
    }
    double max = 0;
    for(x = 0; x < a; x++){
        if (p[x] > max){
            max = p[x];
        }
    }
    for(x = 0; x < a; x++){
        p[x] = (p[x] / max) * 100;
    }
    double sum = 0;
    for(x = 0; x < a; x++){
        sum = sum + p[x];
    }
    double avr = sum / a;
    printf("%lf", avr);
    return 0;
}
