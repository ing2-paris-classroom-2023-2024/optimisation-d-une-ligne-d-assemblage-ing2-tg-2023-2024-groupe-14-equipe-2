//
// Created by koan9 on 24/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H

#include <stdio.h>
#include <stdlib.h>

/* Structure d'un arc*/
struct Arc
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
typedef struct Sommet_ex
{
    struct Arc* arc;
    int valeur;
    char couleur;/// B=blanc     N=Noir  G=gris

}S_Exclu;

/* Alias de pointeur sur un Sommet */
typedef S_Exclu* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe_exclu
{
    int taille;
    int orientation;
    int ordre;
    pSommet *pSommet;
} G_Exclu;

// créer le graphe
G_Exclu * Crea_G_exclu(int ordre);

/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
G_Exclu * lect_graphe_exclu(char * nomFichier);

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* Arete_exclu(pSommet* sommet,int s1,int s2);

/* affichage des successeurs du sommet num*/
void print_successif(pSommet * sommet, int num);

/*affichage du graphe avec les successeurs de chaque sommet */
void print_G_exclu(G_Exclu * graphe);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_STRUC_EXCLU_H
