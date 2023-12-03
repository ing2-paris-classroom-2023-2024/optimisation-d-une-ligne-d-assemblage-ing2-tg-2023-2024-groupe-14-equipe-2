//
// Created by David on 11/23/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_RELIE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_RELIE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int num_sommet;
    int poids;
    int adjacence;
}sommet;

typedef struct {
    int poids_du_chemin;
    int numero_du_chemin;
}chemin;

typedef struct{
    sommet **matrice_ajacence;
    int ordre_graphe;
    int taille;

}graphe;

typedef struct QueueElement{
    int value;
    int nb_influent;
    struct QueueElement *next;
}QueueElement, *Queue;

static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_element = 0;

typedef enum{
    false,
    true
}Bool;
void clear_queue(void);
void pop_queue(void);
void push_queue(int x);
void print_queue(void);

int trouvTaille(char filename[50]);
int trouvOrdre(char nom_fichier[50]);
void ouverture_du_fichier(graphe* precedences, char nom_du_fichier[50]);
void libererMatriceAdjacence(graphe* graphe, int ordre);


#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_RELIE_H
