#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_POINT_H_EMILE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_POINT_H_EMILE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    int sommet;
    int *predecesseur;
    int nb_predecesseur;
    int *successeur;
    int nb_successeur;
    float temps_execution;
    int ordre;
    int taille;
}arbre;

typedef enum{
    false,
    true
}Bool;

typedef struct QueueElement{
    arbre value;
    struct QueueElement *next;
}QueueElement, *Queue;

static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_element = 0;

void clear_queue(void);
void pop_queue(void);
void push_queue(arbre x);
void print_queue(void);
Bool is_empty_queue(void);
void pop_last(void);

void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier);
void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_POINT_H_EMILE_H
