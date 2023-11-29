//
// Created by koan9 on 22/11/2023.
//

#include "excusion.h"

G_Exclu * lect_graphe_exclu(char * file)
{
    G * g_pt;
    FILE * ifs = fopen(file,"r");
    int taille, ordre, s1, s2;
    int *tab_connex;
    int deg;

    if (!file)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }


    ordre=find_order(ifs);
    fseek(ifs, 0, SEEK_SET);//retour du pt ifs au debut du fichier
    g_pt=Crea_G_exclu(ordre); // création du graphe d'exclusion avec l'ordre
    taille=find_taille(ifs);
    fseek(ifs, 0, SEEK_SET);
    fclose(ifs);
    ifs=fopen(file,"r");

    int tab[ordre+1][taille];
    printf("\n");
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < taille; ++j) {
            tab[i][j]=0;
            printf("0");
        }printf("\n");
    }

    ///initialisation des parametres
    g_pt->ordre=ordre;
    g_pt->taille=taille;
    int i=0;
    while ( fscanf(ifs,"%d%d",&s1,&s2)!=EOF){

            printf("%d %d\n",s1,s2);
            tab[s1][i]=s2;
            tab[s2][i]=s1;
        i++;
    }
    system("cls");
    g_pt->mat=tab;

    struct deg_ex *matrice;
    int deg_max=0;
    int matrix[ordre][deg_max];

    for (int i = 0; i < ordre; ++i) {
        deg=0;
        for (int j = 0; j < taille; ++j) {
            if(tab[i][j]==0)printf("");
            else
            {

                deg++;
                printf("(%d,%d) : %d ",i,j,tab[i][j]);
                //creer fonction qui retire les 0 de la matrice
                if(deg>deg_max)deg_max=deg;
                printf("\tdeg_max : %d",deg_max);
                printf("\n");
                matrix[i][deg-1]=tab[i][j];
            }
        }
    }



    /*for (int i = 0; i < ordre; ++i) {
        deg=matrice[i].deg;
        printf("sommet %d :  ");
        for (int j = 0; j < deg; ++j) {
            printf("%d ",matrice[i].tab[j]);
        }
    }*/
    g_pt->tab=tab;//ajout tab des deg de chaque sommets

    return g_pt;
}
/*struct deg_ex *reduction_de_matrice(int **tab,int ordre,int taille){
    struct deg_ex *pt;
    printf("\nreduction de matrice\n");
    for (int i = 0; i < ordre; ++i) {
        pt[i].deg=0;
        printf("%d,%d\n",pt[i].deg,i+1);//=0;
        printf("done");
        pt[i].tab=tab[i];
    }
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < taille; ++j) {
            printf("%d ",pt[i].tab[j]);
        }
    }
    return pt;
}*/
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
    int deg;

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
/*G * Crea_G_exclu(int ordre,int **matrice_deg,int **matrix)//creation du graphe d'exclu avec retour du graphe
{
    G * Newg=(G_Exclu *)malloc(sizeof(G_Exclu ));
    //Newg->pSE = (pSE*)malloc(ordre*sizeof(pSE));
    for(int i=0; i<ordre; i++) {
        Newg->pSE[i] = (pSE) malloc(sizeof(S_Exclu));
        Newg->pSE[i]->station = i;
        Newg->pSE[i]->pArcE = NULL;
    }
    return Newg;
}*/
void print_successif(int *tab,int num,int deg)//pSE * sE, int num)
{
    printf(" sommet %d :\n",num);
    int i=0;
    //pArcE arc=tab[num];

    while(tab[i]!=NULL)
    {
        printf("d",tab[i]);
        i++;
       /* int deg=arc->s_info.deg;
        for (int i = 0; i < deg; ++i) {
            int smt=arc[i].sommet;
            printf("%d ",smt);
        }

        arc=arc->arc_suivant;*/
    }

    
}
void print_G_exclu(G * pt)
{
    printf("Affichage du graphe d'exclusion :\n");
    printf("ordre = %d\n",pt->ordre);
    printf("listes d'adjacence :\n");

    for (int i=1; i<=pt->ordre; i++)
    {
        print_successif(pt->tab[i].tab, i,pt->tab[i].deg);
        printf("\n");
    }
}
pSE* Arete_exclu(pSE* sE,int sE1,int sE2)//crations des aretes qui connectes les somets
{
    if(sE[sE1]->pArcE==NULL)
    {
        pArcE Newarc=(pArcE )malloc(sizeof(struct Arc_ex));
        Newarc->s_info.tab[Newarc->s_info.deg] =sE2;
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
    G_Exclu *ptE;
    ptE = lect_graphe_exclu(filename);
    print_G_exclu(ptE);
}