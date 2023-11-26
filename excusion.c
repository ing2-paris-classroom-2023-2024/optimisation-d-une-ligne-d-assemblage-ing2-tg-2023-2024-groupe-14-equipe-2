//
// Created by koan9 on 22/11/2023.
//

#include "excusion.h"

G_Exclu * lect_graphe_exclu(char * file)
{
    G_Exclu * g_pt;
    FILE * ifs = fopen(file,"r");
    int taille, orientation, ordre, s1, s2;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    ordre=find_order(ifs);
    fseek(ifs, 0, SEEK_SET);//retour du pt ifs au debut du fichier
    g_pt=Crea_G_exclu(ordre); // création du graphe d'exclusion avec l'ordre
    taille=find_taille(ifs);

    g_pt->ordre=ordre;
    g_pt->taille=taille;


    for (int i=0; i<taille; ++i)    // créer les arêtes du graphe
    {
        fscanf(ifs,"%d%d",&s1,&s2);
        g_pt->pSE=Arete_exclu(g_pt->pSE, s1, s2);
    }
    return g_pt;
}
int find_order(FILE * file)//trouve l'ordre du graphe d'exclu
{
    int num;
    int max = -1;
    if (file == NULL) {
        printf("Erreur de pointeur dans fonction (find_order())\n");
        exit(1);
    }
    while (fscanf(file, "%d", &num) == 1) {
        if (num > max) {
            max = num;
        }
    }
    printf("L'ordre du graphe est : %d\n", max);
    return max;
}
int find_taille(FILE * file)//trouve la taille du graphe d'exclu
{
    int taille = 1;
    char saut_line;
    if (file == NULL)//buffer si erreur de pt car pas d'ouverture du fichier ici
    {
        printf("Erreur de pointeur dans fonction (find_taille())\n");
        return 1;
    }
    while ((saut_line = fgetc(file)) != EOF)//si saut de ligne +1 au compteur
    {
        if (saut_line == '\n') {
            taille++;
        }
    }
    fclose(file);
    printf("La taille du graphe est : %d\n", taille);
    return taille;
}
G_Exclu * Crea_G_exclu(int ordre)//creation du graphe d'exclu avec retour du graphe
{
    G_Exclu * Newg=(G_Exclu *)malloc(sizeof(G_Exclu ));
    Newg->pSE = (pSE*)malloc(ordre*sizeof(pSE));
    for(int i=0; i<ordre; i++)
    {
        Newg->pSE[i]=(pSE)malloc(sizeof(S_Exclu ));
        Newg->pSE[i]->s_info.sommet=i;
        Newg->pSE[i]->pArcE=NULL;
    }
    return Newg;
}
void print_successif(pSE * sE, int num)
{
    printf(" sommet %d :\n",num);

    pArcE arc=sE[num]->pArcE;

    while(arc!=NULL)
    {
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }
}
void print_G_exclu(G_Exclu * pt)
{
    printf("Affichage du graphe d'exclusion :\n");
    printf("ordre = %d\n",pt->ordre);
    printf("listes d'adjacence :\n");

    for (int i=1; i<=pt->ordre; i++)
    {
        print_successif(pt->pSE, i);
        printf("\n");
    }
}
pSE* Arete_exclu(pSE* sE,int sE1,int sE2)//crations des aretes qui connectes les somets
{
    if(sE[sE1]->pArcE==NULL)
    {
        pArcE Newarc=(pArcE )malloc(sizeof(struct Arc_ex));
        Newarc->sommet =sE2;
        Newarc->arc_suivant=NULL;
        sE[sE1]->pArcE=Newarc;
        return sE;
    }

    else
    {
        pArcE temp=sE[sE1]->pArcE;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        pArcE Newarc=(pArcE)malloc(sizeof(struct Arc_ex));
        Newarc->sommet=sE2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>sE2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=sE2;
            temp->arc_suivant=Newarc;
            return sE;
        }

        temp->arc_suivant=Newarc;
        return sE;
    }
}


//////////////////////////////////////////////////////////////////////
//////////////////////////MAIN OF EXCLUDE/////////////////////////////
//////////////////////////////////////////////////////////////////////
void main_ex(char * filename){
    G_Exclu *pt;
    unsigned int premier,choix=0;

    pt =lect_graphe_exclu(filename);

    /// afficher le graphe
    print_G_exclu(pt);
}