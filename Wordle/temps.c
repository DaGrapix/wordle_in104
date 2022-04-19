#include <time.h>

int main(){
    float temp;
    clock.t t1, t2;
    t1 = clock()

    t2 = clock()

    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    print("%f\n", temps);
    return 0;
}