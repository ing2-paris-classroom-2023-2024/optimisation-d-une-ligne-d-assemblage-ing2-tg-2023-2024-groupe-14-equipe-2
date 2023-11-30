#include "point_h_emile.h"

int main() {

    FILE *fichier;
    char caractere;
    int numero_du_sommet =0;
    int nombre_de_ligne = 0;
    fichier = fopen("operation.txt", "r");

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_de_ligne++;
        }
    }
    rewind(fichier);

    arbre* monArbre[nombre_de_ligne];

    for (int j = 0; j < nombre_de_ligne; j++) {
        monArbre[j] = (arbre*)malloc(sizeof(arbre));
        if (monArbre[j] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int j = 0; j < nombre_de_ligne; j++) {
        fscanf(fichier, "%d", &numero_du_sommet);
        monArbre[j]->sommet = numero_du_sommet;
        while ((caractere = fgetc(fichier)) != '\n' && caractere != EOF) {
            // Ignorer les caractères restants sur la ligne
        }


    }

    rewind(fichier);

    for (int j = 0; j < nombre_de_ligne; j++) {
        printf("numero du sommet : %d\n", monArbre[j]->sommet);
    }


    //ouverture_de_fichier(monArbre, nombre_de_ligne, fichier);




    return 0;
}







