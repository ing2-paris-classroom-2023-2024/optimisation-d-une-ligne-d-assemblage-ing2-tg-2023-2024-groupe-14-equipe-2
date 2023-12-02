#include "point_h_emile.h"

int main() {
    FILE *fichier;
    FILE *fichier_2;
    FILE *fichier_3;
    char caractere;
    int numero_du_sommet = 0;
    int nombre_de_sommet = 1; // il y a forcement 1 sommet à la base
    int nb_precedence_arbre = 0; // mais il peut y avoir 0 predecésseur
    float temps;
    int sommet_1 = 0;
    int sommet_2 = 0;
    int indentation_successeur = 0;
    int indentation_predecesseur = 0;
    float cycle = 0;

    fichier = fopen("test_operation.txt", "r");
    fichier_2 = fopen("test_precedence.txt", "r");
    fichier_3 =  fopen("test_cycle.txt", "r");

    fscanf(fichier_3, "%f", &cycle);

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
        for (int j = 0; j <= nb_precedence_arbre; j++) {
            fscanf(fichier_2, "%d%d", &sommet_1, &sommet_2);
            //printf("\n [%d]  [%d]\n",monArbre[i]->sommet, sommet_1);
            if(monArbre[i]->sommet == sommet_1){
                monArbre[i]->nb_successeur++;

            }
            else if(monArbre[i]->sommet == sommet_2){
                monArbre[i]->nb_predecesseur++;
            }
        }
        rewind(fichier_2);
    }
/*
    for (int i = 0; i < nombre_de_sommet; i++) {
        printf("\nnombre de successeur avec le sommet [%d] = [%d]\n", monArbre[i]->sommet, monArbre[i]->nb_successeur);
        printf("\nnombre de predecesseur avec le sommet [%d] = [%d]\n", monArbre[i]->sommet, monArbre[i]->nb_predecesseur);
    }
*/
    for (int i = 0; i < nombre_de_sommet; i++) {
        monArbre[i]->successeur = (int*)malloc(sizeof(int)*monArbre[i]->nb_successeur);
        monArbre[i]->predecesseur = (int*)malloc(sizeof(int)*monArbre[i]->nb_predecesseur);
    }

    rewind(fichier_2);


    for (int i = 0; i < nombre_de_sommet; i++) {
        for (int j = 0; j <= nb_precedence_arbre; j++) {
            fscanf(fichier_2, "%d%d", &sommet_1, &sommet_2);
            //printf("\n [%d]  [%d]\n",monArbre[i]->sommet, sommet_1);
            if(monArbre[i]->sommet == sommet_1){
                monArbre[i]->successeur[indentation_successeur] = sommet_2;
                indentation_successeur++;
            }
            else if(monArbre[i]->sommet == sommet_2){
                monArbre[i]->predecesseur[indentation_predecesseur] = sommet_1;
                indentation_predecesseur++;
            }
        }
        indentation_successeur = 0;
        indentation_predecesseur = 0;
        rewind(fichier_2);
    }

    optimisation_de_la_chaine(monArbre, nb_precedence_arbre, nombre_de_sommet, cycle);

    return 0;
}







