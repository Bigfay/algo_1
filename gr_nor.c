#include <stdio.h>

int main() {
    int tableau[] = {1,2,1,3,1,4,1,5,6,6}; // Déclaration et initialisation du tableau

 // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);

    // Afficher le nombre d'éléments
    printf("Nombre d'éléments dans le tableau : %d\n", n);
    // Pour afficher les éléments du tableau :
    printf("Contenu du tableau :\n");
    for (int i = 0; i < n; i++) {
        printf("Élément %d : %d\n", i, tableau[i]);
    }


 
    return 0;
}
