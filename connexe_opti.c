#include <stdio.h>
#include <stdbool.h>

// VERSION ITERATIVE avec fonctions

void couples_binaires(int e_uni[], int taille_e_uni, int e_cour, int e_suiv, int wtf[taille_e_uni])
{
    int k = 0;
    while (k < taille_e_uni)
    {
        if (e_uni[k] == e_suiv || e_uni[k] == e_cour)
        {
            wtf[k] = 1;
        }
        else
        {
            wtf[k] = 0;
        }
        printf(" %d ", wtf[k]);
        k++;
    }
}

void affichage_tableau(int taille_elements_uniques, int wt_0[taille_elements_uniques])
{
    printf("      ");
    int i = 0;
    while (i < taille_elements_uniques)
    {
        printf(" %d ", wt_0[i]);
        i++;
    }
    printf("\n");
}

int construction_tableau_elements_uniques(int n, int tableau[n], int tableau_elements_uniques[n])
{
    int taille_elements_uniques = 0;
    int i = 0;
    while (i < n)
    {
        bool est_unique = true;

        // Vérifier si l'élément existe déjà dans le tableau des éléments uniques
        for (int j = 0; j < taille_elements_uniques && est_unique; j++)
        {
            if (tableau[i] == tableau_elements_uniques[j])
            {
                est_unique = false;
            }
        }
        if (est_unique) // Si l'élément est unique, l'ajouter au tableau des éléments uniques
        {
            tableau_elements_uniques[taille_elements_uniques++] = tableau[i];
        }
        i++;
    }
    return taille_elements_uniques;
}
int main()
{
    // int tableau[] = {2, 15, 4, 3, 2, 3}; // Déclaration et initialisation du tableau - connexe
    //  int tableau[] = {2, 15, 3, 2}; // Déclaration et initialisation du tableau - connexe
    // int tableau[] = {19, 2, 3, 2, 4, 3, 4, 5, 5, 90}; // Déclaration et initialisation du tableau - connexe
    // int tableau[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Déclaration et initialisation du tableau - pas connexe
    //int tableau[] = {16, 16, 7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16, 12, 12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3, 20, 20}; // pas connexe
     int tableau[] = {16, 16, 7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16, 12, 12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3, 15, 20}; // connexe

    // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tableau) / sizeof(tableau[0]);
    int fin = 1;              // compteur pour afficher le nombre de fois que le tableau est parcouru
    int somme = 0;            // permet de vérifier la connexité
    int somme_old = 0;        // permet de définir la condition d'arrêt si pas de connexité
    bool est_connexe = false; // résultat produit connexe ou pas (true/false)
    int merge = 0;            // permet de fait l'union conditionnelle entre wt_0 et wt_1
    // Afficher le nombre d'éléments
    printf("Nombre d'éléments dans le tableau : %d\n", n);
    // Pour afficher les éléments du tableau :
    printf("Contenu du tableau: ");
    affichage_tableau(n, tableau);   // affichage en notation binaire
    int tableau_elements_uniques[n]; // déclaration et initialisation d'un tableau pour stocker les éléments distincts
    int taille_elements_uniques = 0;
    taille_elements_uniques = construction_tableau_elements_uniques(n, tableau, tableau_elements_uniques); // construction tableau des valeurs distinctes
    int wt_0[taille_elements_uniques];
    int wt_1[taille_elements_uniques];

    printf("\n");
    printf("nombre d'éléments distincts : %d \n", taille_elements_uniques);
    printf("Éléments distincts: ");
    affichage_tableau(taille_elements_uniques, tableau_elements_uniques);
    printf("\n"); // affichage tableau Les positions paires représentent le début d'une arête et impaires la fin de celle-ci
    // parcourir le tableau initial avec les pairs et les impairs et comparer le courant avec le suivant
    printf("TOUR %d: \n", fin);

    for (int z = 0; z < n && !est_connexe; z = z + 2) // on parcourt le tableau par pas de 2
    {
        couples_binaires(tableau_elements_uniques, taille_elements_uniques, tableau[z], tableau[z + 1], wt_1);
        for (int j = 0; j < taille_elements_uniques; j++) // recherche d'éléments communs entre wt_0 et wt_1
        {
            if (wt_0[j] == wt_1[j] && wt_0[j] == 1) // condition d'élément commun entre wt_0 et wt_1
            {
                merge = 1;
                j = taille_elements_uniques;
            }
        }
        if (somme_old == 0) // cas particulier du premier couple qui est d'office mergé avec wt_0
        {
            for (int j = 0; j < taille_elements_uniques; j++) // wt_0 remplacé par wt_1 pour le premier
            {
                wt_0[j] = wt_1[j];
                somme_old = somme_old + wt_1[j];
            }
        }
        if (merge == 1) // fusion entre wt_0 et wt_1 s'il y a un élément commun entre les 2 couples
        {
            for (int k = 0; k < taille_elements_uniques; k++)
            {
                if (wt_1[k] == 1)
                {
                    wt_0[k] = 1;
                }
            }
            merge = 0;
        }
        affichage_tableau(taille_elements_uniques, wt_0); // affichage en notation binaire
        somme = 0;
        /* calcul de la somme des éléments de wt_0 après fusion avec wt_1*/
        for (int i = 0; i < taille_elements_uniques; ++i)
        {
            somme += wt_0[i];
        }
        if (somme == taille_elements_uniques) // condition de connexité
        {
            printf("ce graphe est connexe \n");
            est_connexe = true;
        }
        else if (z == n - 2 && somme != somme_old) // condition pour recommencer le parcours
        {
            z = 0;
            fin = fin + 1;
            printf("\n");
            printf("TOUR %d: \n", fin);
            somme_old = somme;
        }
        else if (z == n - 2) // condition d'absence de connexité
        {
            printf("ce graphe n'est pas connexe \n");
            z = n;
        };
    }
    printf("\n");

    return est_connexe;
}