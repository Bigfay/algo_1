#include <stdio.h>
#include <stdbool.h>

// VERSION ITERATIVE

void couples_binaires(int e_uni[],int taille_e_uni,int e_cour, int e_suiv,int wtf[taille_e_uni]) {
    for (int k = 0;k<taille_e_uni;k++){
                    if (e_uni[k] == e_suiv || e_uni[k] == e_cour){
                        wtf[k]=1;
                    }
                        else {
                        wtf[k]=0;
                        }
                    printf(" %d ", wtf[k]);
    }
}

void affichage_binaire(int taille_elements_uniques,int wt_0[taille_elements_uniques]) {
    for (int i = 0;i<taille_elements_uniques;i++){
        printf(" %d ", wt_0[i]); 
    }
}

int construction_tableau_elements_uniques(int n,int tableau[n],int tableau_elements_uniques[n]) {
    int taille_elements_uniques = 0;
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
    return taille_elements_uniques;
}
int main() {
    //int tableau[] = {2, 15, 4, 3, 2, 3}; // Déclaration et initialisation du tableau - connexe
    //int tableau[] = {2, 15, 3, 2}; // Déclaration et initialisation du tableau - connexe
    //int tableau[] = {19, 2, 3, 2, 4, 3, 4, 5, 5, 90}; // Déclaration et initialisation du tableau - connexe
    //int tableau[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Déclaration et initialisation du tableau - pas connexe
    int tableau[] = {16,16,7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16,12,12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3,20,20}; // pas connexe
    //int tableau[] = {16,16,7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16,12,12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3,15,20}; // connexe


 // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);
    int fin=1;
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

//début construction tableau des valeurs distinctes
taille_elements_uniques= construction_tableau_elements_uniques(n,tableau,tableau_elements_uniques);
   //fin construction tableau des valeurs distinctes

    int wt_0[taille_elements_uniques];
    int wt_1[taille_elements_uniques];

  printf("\n");
  printf("nombre d'éléments uniques : %d \n", taille_elements_uniques);
  //int check_taille_elements_uniques= taille_elements_uniques;
  //taille_elements_uniques=9;

  printf("Éléments uniques: ");
    for (int i = 0; i < taille_elements_uniques; i++) {
        printf("%d ", tableau_elements_uniques[i]);
    }
    printf("\n");
    // Les positions paires représentent le début d'une arête et impaires la fin de celle-ci
    
  //parcourir le tableau initial avec les pairs et les impairs et comparer le courant avec le suivant
            printf("TOUR %d: \n",fin);
            //fin=fin+1;
   // couples_binaires(tableau_elements_uniques,taille_elements_uniques, tableau[0],tableau[1],wt_1);
  // dupliquer le wt_1 dans le wt_0 pour le premier élément
   /* for(int i = 0; i < taille_elements_uniques; ++i) {
        wt_0[i]=wt_1[i];
    }*/
    printf("\n");
    int merge =0;
  
  for (int z=0; z < n;z=z+2){
    couples_binaires(tableau_elements_uniques,taille_elements_uniques,tableau[z],tableau[z+1],wt_1);
/*comparaison entre wt_0 et wt_1 pour voir s'il y a des positions communes contenant un 1
 si c'est le cas on fusionne les positions en 1*/
        
        
        for (int j=0;j<taille_elements_uniques;j++){
            if (wt_0[j]==wt_1[j] && wt_0[j] ==1){          
                j = taille_elements_uniques;
                merge=1;
            }   
        }
        if(somme_old==0){
            for (int j=0;j<taille_elements_uniques;j++){
                wt_0[j]=wt_1[j];
                somme_old=somme_old+wt_1[j];
            }

        }
    //fusion entre wt_0 et wt_1 s'il y a un élément commun entre les 2 couples
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
    affichage_binaire(taille_elements_uniques,wt_0);
    
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
             z=0;
             printf("TOUR %d: \n",fin);
             somme_old=somme;
             fin=fin+1;
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

