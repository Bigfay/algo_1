#include <stdio.h>
#include <stdbool.h>

#define MAX_EDGES 6 // Nombre maximal de valeurs dans le tableau d'arêtes

bool visite[MAX_EDGES] = {false}; // Pour marquer les noeuds déjà visités

// Fonction récursive pour parcourir le graphe
void visiter(int graphe[], int taille, int noeud) {
    for (int i = 0; i < taille; i += 2) {
        if (!visite[i / 2] && (graphe[i] == noeud || graphe[i + 1] == noeud)) {
            visite[i / 2] = true; // Marque l'arête comme visitée

            // Visiter le noeud suivant qui n'est pas égal au noeud courant
            int prochainNoeud = (graphe[i] == noeud) ? graphe[i + 1] : graphe[i];
            visiter(graphe, taille, prochainNoeud);
        }
    }
}

bool estConnexe(int graphe[], int taille, int nbNoeuds) {
    visiter(graphe, taille, graphe[0]); // Commence par le premier noeud

    // Vérifie si toutes les arêtes ont été visitées
    for (int i = 0; i < taille / 2; i++) {
        if (!visite[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int graphe[MAX_EDGES] = {2, 15, 4, 3, 2, 3}; // Votre graphe

    if (estConnexe(graphe, MAX_EDGES, 16)) { // 16 est le nombre total de noeuds (supposé)
        printf("Le graphe est connexe.\n");
    } else {
        printf("Le graphe n'est pas connexe.\n");
    }

    return 0;
}
