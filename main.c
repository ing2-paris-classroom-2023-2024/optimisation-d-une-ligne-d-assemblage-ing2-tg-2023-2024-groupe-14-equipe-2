#include "point_h_emile.h"

int main() {
    FILE *fichier;
    FILE *fichier_2;
    char caractere;
    int numero_du_sommet =0;
    int nombre_de_sommet = 0;
    int nb_precedence_arbre = 1;
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

    while ((caractere = fgetc(fichier_2)) != EOF) {
        if (caractere == '\n') {
            nb_precedence_arbre++;
        }
    }
    nb_precedence_arbre++;
    rewind(fichier_2);

    int tab_sommet_provisoir[nb_precedence_arbre][nb_precedence_arbre];
    for (int i = 0; i < nb_precedence_arbre; i++) {
        for (int j = 0; j < nb_precedence_arbre; j++) {
            tab_sommet_provisoir[i][j] = 0;
        }
    }
    for (int i = 0; i < nb_precedence_arbre; i++) {
            fscanf(fichier_2, "%d%d", &sommet_1, &sommet_2);
            tab_sommet_provisoir[sommet_1][sommet_2] = 12345;
        printf("\n on complete la case : [%d][%d]\n", sommet_1, sommet_2);
        }

    for (int i = 0; i < nb_precedence_arbre; i++) {
        printf("\n");
        for (int j = 0; j < nb_precedence_arbre; j++) {
            printf(" %d ", tab_sommet_provisoir[i][j]);
            if (tab_sommet_provisoir[i][j] == 12345){
               monArbre[i]->nb_successeur++;
            }
        }
        monArbre[i]->successeur = (int*)malloc(sizeof(int)*monArbre[i]->nb_successeur);
    }

    //printf("\n\ncase a probleme %d", tab_sommet_provisoir[26][28]);



    //reserve de l'espace mémoir pour les précédence et les succésseur

/*
    for (int i = 0; i < nombre_de_sommet; i++) {
        for (int j = 0; j < nb_precedence; j++) {
            fscanf(fichier_2, "%d", &sommet);
            if (sommet == monArbre[i]->sommet){
                successeur++;
            }
            while ((caractere = fgetc(fichier_2)) != '\n' && caractere != EOF) {
                // Ignorer les caractères restants sur la ligne
            }
        }
        monArbre[i]->nb_successeur = successeur;
        monArbre[i]->successeur = (int*)malloc(sizeof(int)*successeur);
        successeur = 0;
    }

*/
    for (int i = 0; i < nombre_de_sommet; i++) {
        printf("\n nombre de sucesseur du sommet [%d] : [%d]\n", monArbre[i]->sommet, monArbre[i]->nb_successeur);
    }




    return 0;
}







