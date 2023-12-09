#include <stdio.h>
#include <stdbool.h>

// VERSION ITERATIVE avec fonctions

void couples_binaires(int ed[], int ted, int e_cour, int e_suiv, int wtf[ted])
{
    int k = 0;
    while (k < ted)
    {
        if (ed[k] == e_suiv || ed[k] == e_cour)
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
void affichage_tableau(int ted, int wt_0[ted])
{
    printf("      ");
    int i = 0;
    while (i < ted)
    {
        printf(" %d ", wt_0[i]);
        i++;
    }
    printf("\n");
}
int construction_ed(int n, int tab[n], int ed[n])
{
    int ted = 0;
    int i = 0;
    while (i < n)
    {
        bool est_distinct = true;

        // Vérifier si l'élément existe déjà dans le tableau des éléments uniques
        for (int j = 0; j < ted && est_distinct; j++)
        {
            if (tab[i] == ed[j])
            {
                est_distinct = false;
            }
        }
        if (est_distinct) // Si l'élément est unique, l'ajouter au tableau des éléments uniques
        {
            ed[ted++] = tab[i];
        }
        i++;
    }
    return ted;
}
int main()
{
    // int tab[] = {2, 15, 4, 3, 2, 3}; // Déclaration et initialisation du tableau - connexe
    //  int tab[] = {2, 15, 3, 2}; // Déclaration et initialisation du tableau - connexe
    // int tab[] = {19, 2, 3, 90, 4, 3, 4, 5, 5, 2}; // Déclaration et initialisation du tableau - connexe
    // int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Déclaration et initialisation du tableau - pas connexe
    // int tab[] = {16, 16, 7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16, 12, 12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3, 20, 20}; // pas connexe
    int tab[] = {16, 16, 7, 8, 11, 12, 3, 4, 9, 10, 5, 6, 13, 14, 15, 1, 16, 12, 12, 13, 8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 14, 15, 2, 3, 15, 20}; // connexe

    // Calculer le nombre d'éléments dans le tableau
    int n = sizeof(tab) / sizeof(tab[0]);
    int fin = 1;              // compteur pour afficher le nombre de fois que le tableau est parcouru
    int somme = 0;            // permet de vérifier la connexité
    int somme_old = 0;        // permet de définir la condition d'arrêt si pas de connexité
    bool est_connexe = false; // résultat produit connexe ou pas (true/false)
    int merge = 0;            // permet de fait l'union conditionnelle entre wt_0 et wt_1
    // Afficher le nombre d'éléments
    printf("Nombre d'éléments dans le tableau : %d\n", n);
    // Pour afficher les éléments du tableau :
    printf("Contenu du tableau: ");
    affichage_tableau(n, tab); // affichage en notation binaire
    int ed[n];                 // déclaration et initialisation d'un tableau pour stocker les éléments distincts
    int ted = 0;
    ted = construction_ed(n, tab, ed); // construction tableau des valeurs distinctes
    int wt_0[ted];
    int wt_1[ted];
    couples_binaires(ed, ted, tab[0], tab[1], wt_0);
    printf("\n");
    printf("nombre d'éléments distincts : %d \n", ted);
    printf("Éléments distincts: ");
    affichage_tableau(ted, ed);
    printf("\n"); // affichage tableau Les positions paires représentent le début d'une arête et impaires la fin de celle-ci
    // parcourir le tableau initial avec les pairs et les impairs et comparer le courant avec le suivant
    printf("TOUR %d: \n", fin);
    int z = 0; // initialisation de la boucle
    while (z < n && !est_connexe)
    {
        couples_binaires(ed, ted, tab[z], tab[z + 1], wt_1);
        for (int j = 0; j < ted; j++) // recherche d'éléments communs entre wt_0 et wt_1
        {
            if (wt_0[j] == wt_1[j] && wt_0[j] == 1) // condition d'élément commun entre wt_0 et wt_1
            {
                merge = 1;
                j = ted;
            }
        }
        if (merge == 1) // fusion entre wt_0 et wt_1 s'il y a un élément commun entre les 2 couples
        {
            for (int k = 0; k < ted; k++)
            {
                if (wt_1[k] == 1)
                {
                    wt_0[k] = 1;
                }
            }
            merge = 0;
        }
        affichage_tableau(ted, wt_0); // affichage en notation binaire
        somme = 0;
        /* calcul de la somme des éléments de wt_0 après fusion avec wt_1*/
        for (int i = 0; i < ted; ++i)
        {
            somme += wt_0[i];
        }
        if (somme == ted) // condition de connexité
        {
            printf("\n ce graphe est connexe \n");
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
            printf("\n ce graphe n'est pas connexe \n");
            z = n;
        };
        z = z + 2;
    }
    return est_connexe;
}