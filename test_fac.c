#include <stdio.h>
#include <stdbool.h>

/* RECURSIVITE TERMINALE*/
long long fac(long long z,int f){
    if (z == 0){
    return f;
    }
    else {
    return z*fac(z-1,f);
    }
}

int main() {

int z = 49;
printf("\n %lld" ,fac(z,1)); 


}