#include "SSP.h"

//
// Created by David on 11/27/2023.
//

void rouge () {
    printf("\033[1;31m");
}
void vert () {
    printf("\033[1;32m");
}
void jaune (){
    printf("\033[1;33m");
}
void bleu () {
    printf("\033[1;34m");
}
void rose () {
    printf("\033[1;35m");
}
void cyan () {
    printf("\033[1;36m");
}
void bgRouge () {
    printf("\033[0;41m");
}
void resetCouleur () {
    printf("\033[0m");
}

void menu(char * exclu) {
    int fin;
    fin = 0;
    while(!fin) {
        int rep1, rep2, rep3;
        /* affichage menu */
        system("cls");
        printf("\t\t\t*********************************************\n");
        printf("\t\t\t**  \033[1;36mOPTIMISATION D'UNE LIGNE D'ASSEMBLAGE\033[0m  **\n");
        printf("\t\t\t*********************************************\n");
        cyan();
        printf("\t\t\t    EMILE.G CONSTANCE.S DAVID.S CHARINA.L \n");
        resetCouleur();
        printf("\t\t\t*********************************************\n");
        printf("\t\t\t\tENTREZ VOTRE CHOIX\n\n\n");
        printf("\t\t\t\t1-\033[1;36mSEULEMENT TRI SOMMET\033[0m\n");
        printf("\t\t\t\t2-\033[1;36mSEULEMENT PRECEDENCE\033[0m\n");
        printf("\t\t\t\t3-\033[1;36mTOUTES FONCTIONS REUNIES\033[0m\n");
        printf("\t\t\t*********************************************\n\n\n");
        printf("\033[0m");
        resetCouleur();


        rep1 = getchar();
        if (rep1 != '\n' && rep1 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }
        switch (rep1) {
            case '1':
                system("cls");
                resetCouleur();
                G* retourMenu1;
                main_ex(exclu);
                printf("\nAppuyez sur Entree pour retourner au menu principal...");
                getchar();
                system("cls");
                break;

            case '3':
                system("cls");
                resetCouleur();
                mainEm();
                printf("\nAppuyez sur Entree pour retourner au menu principal...");
                getchar();
                system("cls");
                break;

        }
    }
}