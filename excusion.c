//
// Created by koan9 on 22/11/2023.
//

#include "excusion.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
G * lect_graphe_exclu(char * file)
{
    G * g_pt;
    FILE * ifs = fopen(file,"r");
    int taille=1, ordre=0, s1, s2, i=0, j=0;
    //int *tab_connex[ordre];
    int info[BUFFER_INFO][2];
    //int deg;


    if (!file)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    while ( fscanf(ifs,"%d %d",&s1,&s2)!=EOF){
        taille++;

        info[i][j+1]=s2;

        info[i][j]=s1;



        i++;
    }
    fclose(ifs);
    taille=taille-1;

    int max = 0;
    int cnt=0;
    while(cnt<taille) {
        if(info[cnt][j]>max)
            max=info[cnt][j];
        else if(info[cnt][j+1]>max)
            max=info[cnt][j+1];
        cnt++;

    }
    ordre=max;


    g_pt=Crea_G_exclu(ordre);



    int tab[ordre][ordre];

    for (int m = 0; m < ordre; ++m) {

        for ( j = 0; j < ordre; ++j) {
            tab[m][j]=0;

        }
    }

    ///initialisation des parametres
    g_pt->ordre=ordre;
    g_pt->taille=taille;


    for (int m = 0; m < taille; ++m) {


        s1=info[m][0]-1;
        s2=info[m][1]-1;

        tab[s2][s1]=1;
        tab[s1][s2]=1;


    }

    for (int m = 0; m < ordre; ++m) {

        for (int j = 0; j < ordre; ++j) {



        }
    }


    for (int k = 0; k < ordre; ++k) {
        g_pt->tab[k].sommet=k+1;
        g_pt->tab[k].deg=0;
        g_pt->tab[k].station=0;
        int deg=0;
        for (int l = 0; l < ordre; ++l) {
            if(tab[k][l]!=0){



                g_pt->tab[k].tab[deg]=l+1;
                deg++;

                g_pt->tab[k].deg++;


            }

        }

    }


    system("cls");
    return g_pt;
}
#pragma clang diagnostic pop

G * Crea_G_exclu(int ordre)//creation du graphe d'exclu avec retour du graphe
{
    G * Newg=(G *)malloc(sizeof(G ));

    Newg->tab = (Deg_E *) malloc(sizeof(Deg_E)*ordre);
    for(int i=0; i<ordre; i++) {
        Newg->tab[i].sommet = i;
        Newg->tab[i].tab = NULL;
        Newg->tab[i].deg= 1;
        Newg->tab[i].tab=(int*) malloc(sizeof(int*)*Newg->tab->deg);
    }




    return Newg;
}
void print_successif(Deg_E pt)
{

    for (int j = 0; j < pt.deg; ++j){

    }

}
void print_G_exclu(G * pt)//affiche les informations de chaques sommets
{


    for (int i=0; i<pt->ordre; i++)
    {

        print_successif(pt->tab[i]);

    }
}
Deg_E *tri_sommet_par_deg(Deg_E *pt,int order)

{
    Deg_E temporary;
    for (int i = 0; i < BUFF_TRI; ++i) {
        for (int k = 0; k < BUFF_TRI; ++k) {
            for (int j = 1; j < order; ++j) {
                if(pt[j-1].deg<pt[j].deg && j<=order-1){
                    temporary=pt[j-1];
                    pt[j-1]=pt[j];
                    pt[j]=temporary;
                }
            }
        }


        for (int j = 0; j < order; ++j) {

        }
    }
    system("cls");

    return pt;
}
Deg_E *tri_sommet_croissants(Deg_E *pt,int order)
//tri les sommets de manière croissante pour l'affichage
{
    Deg_E temporary;
    for (int i = 0; i < BUFF_TRI; ++i) {
        for (int k = 0; k < BUFF_TRI; ++k) {
            for (int j = 1; j < order; ++j) {
                if(pt[j-1].sommet>pt[j].sommet && j<=order-1){
                    temporary=pt[j-1];
                    pt[j-1]=pt[j];
                    pt[j]=temporary;
                }
            }
        }


        for (int j = 0; j < order; ++j) {

        }
    }
    system("cls");

    return pt;
}
int check_correspondance_station(int t1,int t2,Deg_E *pt)
//check si les sommets sont dans la meme station
//retourne 1 si oui, 0 si non
{
    if(pt[t1-1].station==pt[t2-1].station)//check si meme couleure
        return 1;
    else
        return 0;
}
G *colorisation_Welsh_Powell(Deg_E *graphe,int ordre,G * g) {
    int color = 1;
    int adj;
    int t=0;
    int tab_color[ordre][ordre];
    //g->tab_station = (int **) malloc(sizeof(int ) * ordre);

    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            tab_color[i][j]=0;

        }
    }
    //g->tab_station[color].num = 0;
    for (int l = 0; l < ordre; ++l) {
        g->tab[l].station = 0;


        while (t<l){
            adj = adjacence(g->tab[l], g->tab[t]);
            if (adj == 0 && g->tab[l].station == 0 ) {
                g->tab[l].station = color;
                g->tab[t].station = color;
            } else if (adj == 1 && g->tab[l].station != 0 ) {
                g->tab[l].station = color;
                g->tab[t].station = color+1;
            } else if(adj == 1 && g->tab[l].station == 0){
                g->tab[l].station = color;
                g->tab[t].station = color;
            } else if(g->tab[l].deg==0)tab_color[1][g->tab[l].sommet] = 1;

            if(g->tab[t].station==g->tab[l].station)
            {
                adj= adjacence(g->tab[t],g->tab[l]);
                if(adj==0 && g->tab[t].station==g->tab[l].station)
                {
                    color=check_color(g->tab[t],g->tab[l]);
                    g->tab[t].station=color+1;

                }
            }
            if(g->tab[l].deg!=0)
                tab_color[color][g->tab[l].sommet] = 1;
            t++;
            color=color+1;
        }
        //color=color+1;
    }
    g->tab[0].station = 1;
    for (int i = 0; i < ordre; ++i) {
        if(g->tab[i].deg==0) {
            g->tab[i].station = 1;
            //color=color-1;
            tab_color[0][g->tab[i].sommet] = 1;
        }

        //for (int m = 0; m < graphe->deg; ++m) {

        for (int j = 0; j < g->tab[i].deg; ++j) {

        }


    }

    for (int i = 0; i < color; ++i) {

        for (int j = 0; j < ordre; ++j) {

        }

    }
    int color_max=color;
    system("cls");

    //reorganisation des sommets par station avec consideration des connexions
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            if(j!=i){
                if(adjacence(g->tab[i],g->tab[j])==1 && g->tab[i].station==g->tab[j].station) {
                    color = check_color(g->tab[i], g->tab[j]);
                    if (g->tab[i].station == 1)
                        color = color+1;
                    else if (g->tab[i].station == 2)
                        color = color+1;
                    else if (g->tab[i].station == 3)
                        color = color-2;
                    g->tab[i].station = color+1;
                }


            }
        }
    }
    for (int i = 0; i < ordre; ++i) {
        if(g->tab[i].deg>0) {
            for (int j = 0; j < color_max; ++j) {
                tab_color[j][g->tab[i].sommet] = 0;
            }
            //graphe[i].station = 1;
            //color=color-1;
            tab_color[g->tab[i].station-1][g->tab[i].sommet] = 1;
        }

        //for (int m = 0; m < graphe->deg; ++m) {

        for (int j = 0; j < g->tab[i].deg; ++j) {

        }


    }
    //color=3;

    for (int i = 0; i < color_max; ++i) {

        for (int j = 0; j < ordre; ++j) {

        }

    }



    return g;

}
int adjacence(Deg_E pt1,Deg_E pt2)
//check si les sommets sont adjacents renvoie 1 si non et 0 si oui
{
    int adj=0;
    for (int i = 0; i < pt1.deg; ++i) {
        for (int j = 0; j < pt2.deg; ++j) {
            if(pt1.sommet==pt2.tab[j] || pt2.sommet==pt1.tab[j])
                adj=1;
        }

    }
    return adj;
}
int check_color(Deg_E pt1,Deg_E pt2)
//revoie la nouvelle couleure du sommet pt1
{
    int color=0;
    if(pt1.station==pt2.station)
        color=pt2.station-1;
    else if(pt1.station!=pt2.station)
        color=pt1.station;

    return color;
}
Deg_E *tri_par_station(Deg_E *pt,int order){
    Deg_E temporary;
    for (int i = 0; i < BUFF_TRI; ++i) {
        for (int k = 0; k < BUFF_TRI; ++k) {
            for (int j = 1; j < order; ++j) {
                if(pt[j-1].station>pt[j].station && j<=order-1){
                    temporary=pt[j-1];
                    pt[j-1]=pt[j];
                    pt[j]=temporary;
                }
            }
        }


        for (int j = 0; j < order; ++j) {

        }
    }

    return pt;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////MAIN OF EXCLUDE/////////////////////////////
//////////////////////////////////////////////////////////////////////
G* main_ex(char * filename){
    fflush(stdin);//libere memoire
    G *ptE;
    ptE = lect_graphe_exclu(filename);
    //system("cls");

    print_G_exclu(ptE);

    ptE->tab=tri_sommet_par_deg(ptE->tab,ptE->ordre);
    //ajout des fonctions de colorisations
    //print_G_exclu(ptE);
    system("cls");
    ptE=colorisation_Welsh_Powell(ptE->tab,ptE->ordre,ptE);
    tri_sommet_croissants(ptE->tab,ptE->ordre);
    print_G_exclu(ptE);
    ptE->tab=tri_par_station(ptE->tab,ptE->ordre);
    print_G_exclu(ptE);
    return ptE;
}
