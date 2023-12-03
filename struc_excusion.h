#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCUSION_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCUSION_H

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

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCUSION_H
