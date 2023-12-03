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
}arbre;

typedef enum{
    false,
    true
}Bool;

typedef struct QueueElement{ /// structure qui va nous permettre de pouvoir remonter notre sommet d'analyse jusqu'a la base et de creer une liste de ces sommet
    arbre value;
    struct QueueElement *next;
}QueueElement, *Queue;

typedef struct QueueElement_G{ /// structure qui va nous permettre d'enregistrer les différente liste mentionner plus haut
    int sommet_initiale;
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


typedef struct En_avant_toute{ //structure qui vous nous permttre d'analyse l'avant de notre sommet analyse et de pouvoir rééllement commencer a travailler sur notre optimisation de station
    arbre value;
    struct En_avant_toute *next;
}En_avant_toute, *En_avant;

typedef struct En_avant_toute_G{ //structure qui va nous permettre stocké les station
    int sommet_initiale;
    float temp_list;
    En_avant_toute *first;
    En_avant_toute *last;
    struct En_avant_toute_G *next;
    int nb_element;
}En_avant_toute_G, *En_avant_G;


static En_avant_toute *first_a = NULL;
static En_avant_toute *last_a = NULL;
static int nb_element_a = 0;

static En_avant_toute_G *first_AG = NULL;
static En_avant_toute_G *last_AG = NULL;
static int nb_element_AG = 0;



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
void push_queue_I(arbre x, QueueElement_G *repere, float temp_list);


Bool is_empty_queue_a(void);
void print_queue_a(void);
void push_queue_a(arbre x);
void pop_queue_a(void);
void clear_queue_a(void);

Bool is_empty_queue_AG(void);
void print_queue_AG(void);
void push_queue_AG(float temp_list);
void pop_queue_AG(void);
void clear_queue_AG(void);

void push_queue_AI(arbre x, En_avant_toute_G *repere, float temp_list);


void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_POINT_H_EMILE_H
