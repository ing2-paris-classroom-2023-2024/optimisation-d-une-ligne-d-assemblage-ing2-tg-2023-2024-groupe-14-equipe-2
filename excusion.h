//
// Created by koan9 on 22/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_EXCUSION_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_EXCUSION_H

#include "struc_exclu.h"

void main_ex(char * filename);

//////////////////////////////////////////////////////
///           fonctions lecture fichier            ///
//////////////////////////////////////////////////////
G_Exclu * lect_graphe_exclu( char* file);
int find_order(FILE * file);
int find_taille(FILE * file);

//////////////////////////////////////////////////////
///          fonctions construction graphe         ///
//////////////////////////////////////////////////////
G_Exclu * Crea_G_exclu(int ordre);// créer le graphe
pSE* Arete_exclu(pSE* sE,int sE1,int sE2);// Ajouter l'arête entre sE1 et sE2 du Graphe
void print_successif(pSE * sE, int num);//print des successeurs du sommet num
void print_G_exclu(G_Exclu * graphe);//print du graphe avec les succs de chaque sE

//////////////////////////////////////////////////////
///             fonctions colorisation             ///
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
///         fonctions tris + organisation          ///
//////////////////////////////////////////////////////



#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_EXCUSION_H
