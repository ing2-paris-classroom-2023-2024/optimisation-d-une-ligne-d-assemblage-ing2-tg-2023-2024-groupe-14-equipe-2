//
// Created by koan9 on 24/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_INFO 60
#define BUFF_TRI 10
//structure de infos de sommet et de degree assigner
typedef struct deg_ex{
    int sommet;
    int station;
    int deg;
    int *tab;
}Deg_E;
/* Structure d'un arc*/
struct Arc_ex
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int valeur;
    Deg_E s_info;
    struct Arc_ex* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc_ex* pArcE;

/* Structure d'un sommet*/
typedef struct Sommet_ex
{
    struct Arc_ex* pArcE;
    int sommet;
    int station;/// 1, 2, 3, etc.

}S_Exclu;

/* Alias de pointeur sur un Sommet */
typedef S_Exclu* pSE;

/* Alias d'un Graphe */

typedef struct G_exclu2{
    int taille,
    ordre;
    int **mat;
    Deg_E *tab;

}G;





#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
