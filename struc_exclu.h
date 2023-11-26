//
// Created by koan9 on 24/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H

#include <stdio.h>
#include <stdlib.h>
//structure de infos de sommet et de degree assigner
typedef struct deg_ex{
    int sommet;
    int deg;
}Deg_E;
/* Structure d'un arc*/
struct Arc_ex
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc_ex* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc_ex* pArcE;

/* Structure d'un sommet*/
typedef struct Sommet_ex
{
    struct Arc_ex* pArcE;
    Deg_E s_info;
    int station;/// 1, 2, 3, etc.

}S_Exclu;

/* Alias de pointeur sur un Sommet */
typedef S_Exclu* pSE;

/* Alias d'un Graphe */
typedef struct Graphe_exclu
{
    int taille;
    int ordre;
    pSE *pSE;
} G_Exclu;





#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
