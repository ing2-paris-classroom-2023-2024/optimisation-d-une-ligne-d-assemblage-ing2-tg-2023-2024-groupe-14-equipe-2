#include "point_h_emile.h"

int main() {
    FILE *fichier;
    FILE *fichier_2;
    char caractere;
    int numero_du_sommet = 0;
    int nombre_de_sommet = 1; // il y a forcement 1 sommet à la base
    int nb_precedence_arbre = 0; // mais il peut y avoir 0 predecésseur
    float temps;
    int sommet_1 = 0;
    int sommet_2 = 0;
    int successeur = 0;
    fichier = fopen("operation.txt", "r");
    fichier_2 = fopen("precedence.txt", "r");

    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_de_sommet++;
        }
    }
    rewind(fichier);
    printf("\nordre du graphe : [%d]\n\n", nombre_de_sommet);

    arbre* monArbre[nombre_de_sommet];

    for (int j = 0; j < nombre_de_sommet; j++) {
        monArbre[j] = (arbre*)malloc(sizeof(arbre));
        if (monArbre[j] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int j = 0; j < nombre_de_sommet; j++) {
        fscanf(fichier, "%d%f", &numero_du_sommet, &temps);
        monArbre[j]->sommet = numero_du_sommet;
        monArbre[j]->temps_execution = temps;
    }

    rewind(fichier);
    for (int i = 0; i < nombre_de_sommet; i++) {
        printf("\n[%d] = [%f]\n", monArbre[i]->sommet, monArbre[i]->temps_execution);
    }



    while ((caractere = fgetc(fichier_2)) != EOF) {
        if (caractere == '\n') {
            nb_precedence_arbre++;
        }
    }
    printf("\ntaille du graphe : [%d]\n\n", nb_precedence_arbre);
    rewind(fichier_2);
    for (int i = 0; i < nombre_de_sommet; i++ ) {
        monArbre[i]->nb_predecesseur = 0;
        monArbre[i]->nb_successeur = 0;
    }

    for (int i = 0; i < nombre_de_sommet; i++) {
        for (int j = 0; j < nb_precedence_arbre; j++) {
            fscanf(fichier_2, "%d%d", &sommet_1, &sommet_2);
            if(monArbre[i]->sommet == sommet_1){
                monArbre[i]->nb_successeur++;
            }
            else if(monArbre[i]->sommet == sommet_2){
                monArbre[i]->nb_predecesseur++;
            }
        }
    }

    for (int i = 0; i < nombre_de_sommet; i++) {
        printf("\nnombre de successeur avec le sommet [%d] = [%d]\n", monArbre[i]->sommet, monArbre[i]->nb_successeur);
        printf("\nnombre de predecesseur avec le sommet [%d] = [%d]\n", monArbre[i]->sommet, monArbre[i]->nb_predecesseur);
    }


    return 0;
}







