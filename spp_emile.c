#include "point_h_emile.h"

void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier){


    char caractere;
    int nb_successeur = 0;
    int nb_predecesseur = 0;
    int numero_du_sommet =0;
    int i = 0;

    for (int j = 0; j < nombre_de_ligne; j++) {
        tab_sommet[j] = (arbre*)malloc(sizeof(arbre));
        if (tab_sommet[j] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }
    }


    while (fscanf(fichier, "%d", &numero_du_sommet) == 1) {
        tab_sommet[i]->sommet = numero_du_sommet;
        i++;
    }

    rewind(fichier);

    for (int j = 0; j < nombre_de_ligne; j++) {
        printf("numero du sommet : %d\n", tab_sommet[i]->sommet);
    }

}