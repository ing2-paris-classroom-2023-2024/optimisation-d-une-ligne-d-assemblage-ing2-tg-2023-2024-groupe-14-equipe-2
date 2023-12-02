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

typedef struct QueueElement_G{
    int valeur_du_point;
    float temp_list;
    QueueElement *first;
    QueueElement *last;
    struct QueueElement_G *next;
    int nb_element;
}QueueElement_G, *Queue_G;

static QueueElement *first_p = NULL;
static QueueElement *last_p = NULL;
static int nb_element_p = 0;

static QueueElement_G *first_G = NULL;
static QueueElement_G *last_G = NULL;
static int nb_element_G = 0;

//list classique
void clear_queue(void);
void pop_queue(void);
void push_queue(arbre x);
void print_queue(void);
Bool is_empty_queue(void);
void pop_last(void);

//list general qui va comprendre les list, il saura les écouter et les motivé pour qu'il réussise dans de bonne condition sans avoir MILLE TRUC A FAIRE PTN DE MERDE
Bool is_empty_queue_G(void);
void print_queue_G(void);
void push_queue_G(float temp_list);
void pop_queue_G(void);
void clear_queue_G(void);

// fonction qui va nous permettre de push a l'interrieur des list dans la list generale
void push_queue_I(arbre x, QueueElement_G *repere);

void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier);
void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_POINT_H_EMILE_H
