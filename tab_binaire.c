#include <stdio.h>
#include <stdbool.h>


int main() {
    int tableau[] = {6,6,1,2,1,3,1,4,1,5}; // Déclaration et initialisation du tableau

 // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);

    // Afficher le nombre d'éléments
    printf("Nombre d'éléments dans le tableau : %d\n", n);
    // Pour afficher les éléments du tableau :
    printf("Contenu du tableau: ");
    for (int i = 0; i < n; i++) {
        //printf("Élément %d : %d\n", i, tableau[i]);
        printf("%d ", tableau[i]);
    }
// Déclaration et initialisation d'un tableau dynamique pour stocker les éléments uniques
    int tableau_elements_uniques[n];
    int taille_elements_uniques = 0;

    // Parcourir le tableau d'origine
    for (int i = 0; i < n; i++) {
        bool est_unique = true;

        // Vérifier si l'élément existe déjà dans le tableau des éléments uniques
        for (int j = 0; j < taille_elements_uniques; j++) {
            if (tableau[i] == tableau_elements_uniques[j]) {
                est_unique = false;
                break;
            }
        }

        // Si l'élément est unique, l'ajouter au tableau des éléments uniques
        if (est_unique) {
            tableau_elements_uniques[taille_elements_uniques++] = tableau[i];
        }
    }
    int wtu[taille_elements_uniques];

  printf("\n");
  printf("Éléments uniques: ");
    for (int i = 0; i < taille_elements_uniques; i++) {
        printf("%d ", tableau_elements_uniques[i]);
    }
    printf("\n");
    int r=0;
    // Les positions paires représentent le début d'une arête et impaires la fin de celle-ci
    for (int i=0;i<taille_elements_uniques;i++){
        for (int j=0;j<n;j++){
            if (tableau_elements_uniques[i]==tableau[j]){
                printf("%d      %d ", j,tableau_elements_uniques[i]);
                if (j % 2 == 0){
                    printf("pair ");
                    printf(" %d ", tableau[j+1]);
                    r = tableau[j+1];
                }
                    else {
                    printf("impair ");
                    printf(" %d ", tableau[j-1]);
                    r = tableau[j-1];
                    }
                printf("couple %d %d      ", tableau[j],r); 
                for (int k = 0; k<taille_elements_uniques;k++){
                    if (k+1 == r || k+1 == tableau_elements_uniques[i]){
                        wtu[k]=1;
                    }
                        else {
                        wtu[k]=0;
                        }
                    printf(" %d ", wtu[k]);
                }
printf("\n");
            }
        } 
    }
    printf("\n");
    
    return 0;
}
