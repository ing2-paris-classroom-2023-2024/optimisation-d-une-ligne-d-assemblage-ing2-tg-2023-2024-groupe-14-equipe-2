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
        printf("\ndone\t");
        //printf("%d %d\n",s1,s2);
        info[i][j+1]=s2;
        //info[i][j]=0;
        info[i][j]=s1;
        //info[i][j+1]=0;


        printf("%d %d\n",info[i][j],info[i][j+1]);
        //printf("%d\n",info[i+1]);
        i++;
    }
    fclose(ifs);
    taille=taille-1;
    printf("\ntaille : %d\n",taille);
    //printf("%d %d\n",info[2],info[3]);
    int max = 0;
    int cnt=0;
    printf("pr max\n\n");
    while(cnt<taille) {
        printf("%d %d\n",info[cnt][j],info[cnt][j+1]);
        if(info[cnt][j]>max)
            max=info[cnt][j];
        else if(info[cnt][j+1]>max)
            max=info[cnt][j+1];
        cnt++;
        printf("\n max : %d\t",max);
        //i++;
    }
    ordre=max;
    //ordre=find_order(info,taille*2);
    //fseek(ifs, 0, SEEK_SET);//retour du pt ifs au debut du fichier
    g_pt=Crea_G_exclu(ordre); // création du graphe d'exclusion avec l'ordre
    //printf("\ngraphe done");
    //taille=find_taille(ifs);//retour de la taille du graphe
    //rewind(ifs);

    //ifs=fopen(file,"r");

    //int deg_max=0;
    //int matrix[ordre][deg_max];

    //int **tab;
    int tab[ordre][ordre];
    printf("\n");
    for (int m = 0; m < ordre; ++m) {
        //printf("%d\t",i+1);
        for ( j = 0; j < ordre; ++j) {
            tab[m][j]=0;
            //printf("%d",tab[i][j]);
        }//printf("\n");
    }printf("initialisation de matrice (pas) finie");

    ///initialisation des parametres
    g_pt->ordre=ordre;
    g_pt->taille=taille;
    //int m=0;
    printf("\nremplissage de la matrice\n");
    for (int m = 0; m < taille; ++m) {
        //printf("%d\t",i+1);

            s1=info[m][0]-1;
            s2=info[m][1]-1;
            printf("\n%d %d\n",s1,s2);
            tab[s2][s1]=1;
            tab[s1][s2]=1;
        printf("%d,%d :%d,%d",s1,s2,tab[s1][s2],tab[s2][s1]);
        //printf("\n");
    }
    printf("fin remplisage\n");
    for (int m = 0; m < ordre; ++m) {
        //printf("%d\t",i+1);
        for (int j = 0; j < ordre; ++j) {
            //tab[m][j]=0;
            printf("%d ",tab[m][j]);

        }printf("\n");
    }
    //fscanf(ifs,"%d %d",&s1,&s2);
    //printf("%d %d",s1,s2);
    /*while ( fscanf(ifs,"%d %d",&s1,&s2)!=EOF){
        printf("\ndone");
            printf("%d %d\n",s1,s2);
            tab[s1][m]=s2;
            tab[s2][m]=s1;
        m++;
    }*/
    //system("cls");
    /*for (int k = 0; k < taille; ++k) {
        g_pt->mat[k][j]=info[k][j];
        g_pt->mat[k][j+1]=info[k][j+1];
    }*/
/*
    for (i = 0; i < ordre; ++i) {
        deg=0;
        matrice[i].sommet=i;
        for (int j = 0; j < 2; ++j) {
            if(info[i][j]==0)printf("");
            else
            {

                deg++;
                printf("(%d,%d) : %d ",i,j,info[i][j]);
                //creer fonction qui retire les 0 de la matrice
                if(deg>deg_max)deg_max=deg;
                printf("\tdeg_max : %d",deg_max);
                printf("\n");
                matrix[i][deg-1]=tab[i][j];
            }
            matrice[i].deg=deg;
        }
        matrice[i].tab=matrix[i];
    }*/
    //system("cls");



    for (int k = 0; k < ordre; ++k) {
        g_pt->tab[k].sommet=k+1;
        g_pt->tab[k].deg=0;
        g_pt->tab[k].station=0;
        int deg=0;
        for (int l = 0; l < ordre; ++l) {
            if(tab[k][l]!=0){

                //printf("%d",g_pt->tab[k].deg);
                printf("sommet : %d\t%d:%d\t",k+1,g_pt->tab[k].deg+1,l);
                g_pt->tab[k].tab[deg]=l+1;
                deg++;
                //printf("try");
                g_pt->tab[k].deg++;printf("deg : %d\n",g_pt->tab[k].deg);
                //printf("done\n");
            }

        }
        //g_pt->tab[k].tab=tab_connex[k];
    }
    printf("fin de construction du tableau de connexe");
    /*g_pt->mat=tab;//ajout tab des deg de chaque sommets
    for (int k = 0; k < ordre; ++k) {
        for (int l = 0; l < ordre; ++l) {
            g_pt->mat[k][l]=tab[k][l];
            printf("%d ",g_pt->mat[k][l]);
        }printf("\n");
    }
    //printf("\nmat done\n");
    //print_G_exclu(g_pt);//affichage du graphe*/
    system("cls");
    return g_pt;
}
#pragma clang diagnostic pop
/*
int find_order(int *tab,int taille_tab)//trouve l'ordre du graphe d'exclu
{
    //system("cls");
    int max = 0,i=0;
    while(i<taille_tab*2) {
        printf("%d %d\n",tab[i],tab[i+1]);
        //if(tab[i]>max)
          //  max=tab[i];
        i++;
        //i++;
    }
   /* if (tab == NULL) {
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
}*/
/*int find_taille(FILE * file)//trouve la taille du graphe d'exclu
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
    //printf("\ntaille");
    printf("\nLa taille du graphe est : %d\n", taille);
    return taille;
}*/
G * Crea_G_exclu(int ordre)//creation du graphe d'exclu avec retour du graphe
{
    G * Newg=(G *)malloc(sizeof(G ));
    //Newg->pSE = (pSE*)malloc(ordre*sizeof(pSE));
    Newg->tab = (Deg_E *) malloc(sizeof(Deg_E)*ordre);
    for(int i=0; i<ordre; i++) {
        Newg->tab[i].sommet = i;
        Newg->tab[i].tab = NULL;
        Newg->tab[i].deg= 1;
        Newg->tab[i].tab=(int*) malloc(sizeof(int*)*Newg->tab->deg);
    }

    //Newg->mat=(int **) malloc(sizeof (int*)*ordre);

    printf("\nGraphe créer");
    return Newg;
}
void print_successif(Deg_E pt)//pSE * sE, int num)
{

    for (int j = 0; j < pt.deg; ++j){
        printf("\t%d",pt.tab[j]);
    }

}
void print_G_exclu(G * pt)//affiche les informations de chaques sommets
{

    pt->tab= tri_sommet_croissants(pt->tab,pt->ordre);
    printf("Affichage du graphe d'exclusion :\n");
    //printf("ordre = %d\n",pt->ordre);
    printf("listes d'adjacence :\n\n");
    for (int i=0; i<pt->ordre; i++)
    {
        printf("sommet %d (station : %d) :\t",pt->tab[i].sommet,pt->tab[i].station);
        print_successif(pt->tab[i]);
        printf("\n");
    }
}
Deg_E *tri_sommet_par_deg(Deg_E *pt,int order)
//tri les sommet par degrer pour faire la colorisation W et P
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

        printf("\n");
        for (int j = 0; j < order; ++j) {
            printf("sommet : %d\tdeg : %d\n",pt[j].sommet,pt[j].deg);
        }
    }
    system("cls");
    printf("tri crissant des sommets par degree fini\n");
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

        printf("\n");
        for (int j = 0; j < order; ++j) {
            printf("sommet : %d\n",pt[j].sommet);
        }
    }
    system("cls");
    printf("\ntri de maniere croissantes des taches fini\n\n");
    return pt;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////MAIN OF EXCLUDE/////////////////////////////
//////////////////////////////////////////////////////////////////////
void main_ex(char * filename){
    fflush(stdin);//libere memoire
    G *ptE;
    ptE = lect_graphe_exclu(filename);
    //system("cls");
    printf("\nexecution affichage");
    print_G_exclu(ptE);
    printf("\nlancement tri par sommets");
    ptE->tab=tri_sommet_par_deg(ptE->tab,ptE->ordre);
    //ajout des fonctions de colorisations
    print_G_exclu(ptE);
}

