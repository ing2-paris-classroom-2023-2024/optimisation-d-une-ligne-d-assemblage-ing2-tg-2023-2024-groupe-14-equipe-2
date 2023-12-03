//
// Created by David on 12/3/2023.
//

#ifndef OPTIMISATIONLIGNE_ING2G14E2_FINAL_SSP_H
#define OPTIMISATIONLIGNE_ING2G14E2_FINAL_SSP_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "struct.h"



G* main_ex(char * filename);

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
G *colorisation_Welsh_Powell(Deg_E *graphe,int order,G *g);
int adjacence(Deg_E pt1,Deg_E pt2);
int check_color(Deg_E pt1,Deg_E pt2);

//////////////////////////////////////////////////////
///         fonctions tris + organisation          ///
//////////////////////////////////////////////////////
Deg_E *tri_sommet_par_deg(Deg_E *pt,int order);
Deg_E *tri_sommet_croissants(Deg_E *pt,int order);
Deg_E *tri_par_station(Deg_E *pt,int order);

int check_correspondance_station(int t1,int t2,Deg_E *pt);//check si les sommets sont dans la même station
//retourne 1 si oui, 0 si non



//**********************************************************************
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

void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier);
void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle);
//**********************************************************************

int mainEm();

void menu(char * exclu);

#endif //OPTIMISATIONLIGNE_ING2G14E2_FINAL_SSP_H
