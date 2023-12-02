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
G * lect_graphe_exclu( char* file);
int find_order(int *tab,int taille_tab);
//int find_taille(FILE * file);

//////////////////////////////////////////////////////
///          fonctions construction graphe         ///
//////////////////////////////////////////////////////
G * Crea_G_exclu(int ordre);// créer le graphe
void print_successif(struct deg_ex pt);//print des successeurs du sommet num
void print_G_exclu(G * graphe);//print du graphe avec les succs de chaque sE

//////////////////////////////////////////////////////
///             fonctions colorisation             ///
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
///         fonctions tris + organisation          ///
//////////////////////////////////////////////////////
Deg_E *tri_sommet_par_deg(Deg_E *pt,int order);
Deg_E *tri_sommet_croissants(Deg_E *pt,int order);

int check_correspondance_station(int t1,int t2,Deg_E *pt);





#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_EXCUSION_H
