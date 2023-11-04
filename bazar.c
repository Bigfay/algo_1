#include <stdio.h>
#include <stdbool.h>
// VERSION QUI MARCHE
void couples_binaires(int a,int nombre[], int counter, int fer,int wtf[a]) {
    //int wtf[a];
    for (int k = 0;k<a;k++){
                    if (k+1 == fer || k+1 == nombre[counter]){
                        wtf[k]=1;
                    }
                        else {
                        wtf[k]=0;
                        }
                    printf(" %d ", wtf[k]);
    }
    //printf("       \n");
}


int main() {
    int tableau[] = {1,2,2,3,5,5,1,4,4,6}; // Déclaration et initialisation du tableau

 // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);
    int fin=0;

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
    int wt_0[taille_elements_uniques];
    int wt_1[taille_elements_uniques];


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

                    couples_binaires(taille_elements_uniques,tableau, j,r,wt_0);
                    printf("\n");               
                }
//printf("\n");
            }
        }  
//    printf("\n");
  //parcourir le tableau initiale avec les pairs et les impairs et comparer le courant avec le suivant

    couples_binaires(taille_elements_uniques,tableau, 0,tableau[1],wt_1);
  // dupliquer le wt_1 dans le wt_0
    for(int i = 0; i < taille_elements_uniques; ++i) {
        wt_0[i]=wt_1[i];
        //printf("wt_0  wt_1%d %d  ", wt_0[i],wt_1[i]); 
    }
    printf("\n");
    //wt_0=couples_binaires(taille_elements_uniques,tableau, 0,tableau[1],wt_1);
    //comparaison entre wt_0 et wt_1
    //wt_0 = wt_1 =1 alors fusionner les uns
    int merge =0;
  for (int z=2; z < n;z=z+2){
  //for (int z=2; z < n-2;z=z+2){
    //printf("premier couple %d %d  ", tableau[z],tableau[z+1]); 
    couples_binaires(taille_elements_uniques,tableau, z,tableau[z+1],wt_1);
    for (int j=0;j<taille_elements_uniques;j++){
        if (wt_0[j]==wt_1[j] && wt_0[j] ==1){
            
            j = taille_elements_uniques;
            merge=1;
        }
        }
    
    if (merge ==1) {
        //printf("\n"); 
        //printf("wt_0  :  ");
        for (int k=0; k < taille_elements_uniques;k++){
            if (wt_1[k]==1){
                    wt_0[k]=1;
            }
        }
    }
        else {
            merge =0;
            for (int k=0; k < taille_elements_uniques;k++){
            wt_0[k]=wt_1[k];
            }
        }
    printf("      ");
    for (int i = 0;i<taille_elements_uniques;i++){
        printf(" %d ", wt_0[i]); 
    }
    printf("\n"); 

    int somme = 0;

    for (int i = 0; i < taille_elements_uniques; ++i) {
        somme += wt_0[i];
        merge=0;
    }
    if (somme==taille_elements_uniques){
        printf("ce graphe est connexe \n");
        break;
    }
    else {
         if (z==n-2 && somme!=taille_elements_uniques){
             z=-2;
             printf("DEUXIEME T3UR %d \n",fin);
             fin=fin+1;
             if (fin==3) {
             printf("ce graphe n'est pas connexe \n");
             break;
             }
         };
     }

    }
    //printf("    deuxième couple    %d %d  ", tableau[z+2],tableau[z+3]); 
    //couples_binaires(taille_elements_uniques,tableau, z+2,tableau[z+3],wt_1);
     printf("\n"); 
    
    return 0;
    }

