#include <stdio.h>

int main() {
    int tableau[] = {10, 20, 30, 40, 50, 60}; // Déclaration et initialisation du tableau

    // Pour afficher les éléments du tableau :
    printf("Contenu du tableau :\n");
    for (int i = 0; i < 6; i++) {
        printf("Élément %d : %d\n", i, tableau[i]);
    }

    return 0;
}
