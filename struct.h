//
// Created by David on 12/3/2023.
//

#ifndef OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H
#define OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H

//**********************************************************************

#define BUFFER_INFO 60
#define BUFF_TRI 10

typedef struct deg_ex{
    int sommet;
    int station;
    int deg;
    int *tab;
}Deg_E;

/* Structure d'un sommet*/
typedef struct Sommet_ex
{
    struct Arc_ex* pArcE;
    int sommet;
    int station;/// 1, 2, 3, etc.

}S_Exclu;

/* Alias de pointeur sur un Sommet */
typedef S_Exclu* pSE;

typedef struct Station{
    int num;
    int *tab;
}station;

/* Alias d'un Graphe */

typedef struct G_exclu2{
    int taille,
            ordre,color_max,deg_max;
    //int **mat;
    int **tab_station;
    Deg_E *tab;

}G;

//**********************************************************************

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

//**********************************************************************



#endif //OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H
