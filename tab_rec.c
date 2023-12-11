#include <stdio.h>
#include <stdbool.h>

void tab_print(int tab[],int i){
    if(i<10){
        printf(" %d",tab[i]);
        tab_print(tab,i+1);
    }
        else {
            printf("\n");
            return;
        }

    }

int main() {
    int tab[10] ={1,2,3,4,7,5,89,8,2,10} ;
    tab_print(tab,0);

    }

