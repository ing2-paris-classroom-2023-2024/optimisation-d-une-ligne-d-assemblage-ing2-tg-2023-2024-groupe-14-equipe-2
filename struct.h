//
// Created by David on 12/3/2023.
//

#ifndef OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H
#define OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H

//**********************************************************************

#define BUFFER_INFO 60
#define BUFF_TRI 10

//structure de infos de sommet et de degree assigner
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

typedef struct QueueElement{
    arbre value;
    struct QueueElement *next;
}QueueElement, *Queue;

typedef struct QueueElement_G{
    int sommet_initiale;
    float temp_list;
    QueueElement *first;
    QueueElement *last;
    struct QueueElement_G *next;
    int nb_element;
}QueueElement_G, *Queue_G;


#endif //OPTIMISATIONLIGNE_ING2G14E2_FINAL_STRUCT_H
