#include <time.h>

int main(){
    float temp;
    clock_t begin = clock();

    //Code

    clock_t end = clock();

    unsigned long temps = (float)(end-begin)/CLOCKS_PER_SEC;
    print("%ld\n", temps);
    return 0;
}