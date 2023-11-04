#include <stdio.h>
#include <stdbool.h>
// VERSION NETTOYEE AVEC BUG A CORRIGER
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
    int tableau[] = {1, 2, 3, 2, 4, 3, 4, 5, 5, 9}; // Déclaration et initialisation du tableau
    //int tableau[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Déclaration et initialisation du tableau
    //int tableau[] = {16,16,7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16,12,12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3,15,20}; // Déclaration et initialisation du tableau

 // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);
    int fin=0;
    int somme = 0;
    int somme_old=0;
    bool est_connexe;
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
    int wt_0[taille_elements_uniques];
    int wt_1[taille_elements_uniques];

  printf("\n");
  printf("nombre d'éléments uniques : %d \n", taille_elements_uniques);
  printf("Éléments uniques: ");
    for (int i = 0; i < taille_elements_uniques; i++) {
        printf("%d ", tableau_elements_uniques[i]);
    }
    printf("\n");
    int r=0;
    // Les positions paires représentent le début d'une arête et impaires la fin de celle-ci
    
  //parcourir le tableau initiale avec les pairs et les impairs et comparer le courant avec le suivant

    couples_binaires(taille_elements_uniques,tableau, 0,tableau[1],wt_1);
  // dupliquer le wt_1 dans le wt_0
    for(int i = 0; i < taille_elements_uniques; ++i) {
        wt_0[i]=wt_1[i];
    }
    printf("\n");
    //wt_0=couples_binaires(taille_elements_uniques,tableau, 0,tableau[1],wt_1);
    //comparaison entre wt_0 et wt_1
    //wt_0 = wt_1 =1 alors fusionner les uns
    int merge =0;
  for (int z=2; z < n;z=z+2){
    couples_binaires(taille_elements_uniques,tableau, z,tableau[z+1],wt_1);
//comparaison entre wt_0 et wt_1 pour voir s'il y a des positions communes contenant un 1
// si c'est le cas on fusionne les positions en 1
// si non le nouveau wt_1 devient et écrase le wt_0 et devient la nouvelle référence
    for (int j=0;j<taille_elements_uniques;j++){
        if (wt_0[j]==wt_1[j] && wt_0[j] ==1){
            
            j = taille_elements_uniques;
            merge=1;
        }
        }
    //fusion entre wt_0 et wt_1
    if (merge ==1) {
        for (int k=0; k < taille_elements_uniques;k++){
            if (wt_1[k]==1){
                    wt_0[k]=1;
            }
            merge=0;
        }
    }
    printf("      ");
    //affichage en notation binaire
    for (int i = 0;i<taille_elements_uniques;i++){
        printf(" %d ", wt_0[i]); 
    }
    printf("\n"); 
    somme=0;
    for (int i = 0; i < taille_elements_uniques; ++i) {
        somme += wt_0[i];
        //printf("\n somme : %d\n", somme);
        merge=0;
    }
    if (somme==taille_elements_uniques){
        printf("ce graphe est connexe \n");
        est_connexe = true;
        break;
    }
    else if (z==n-2 && somme != somme_old){
        //if (z==n-2 && somme!=taille_elements_uniques){
             z=-2;
             printf("Tour SUIVANT %d \n",fin);
             somme_old=somme;
             fin=fin+1;
             //if (fin==4) {
             /*printf("ce graphe n'est pas connexe \n");
             est_connexe = false;*/
            //break;
             }
    else if (z==n-2){
        printf("ce graphe n'est pas connexe \n");
             est_connexe = false;
             break;
    };
     
    }
     printf("\n"); 
    
    return est_connexe;
    }

