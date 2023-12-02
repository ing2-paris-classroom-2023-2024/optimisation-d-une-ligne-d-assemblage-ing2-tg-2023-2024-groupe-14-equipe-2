#include "point_h_emile.h"

void try_a_bulle(arbre* monArbre[], int ordre, int taille){
    arbre* tmp;

    for (int i=0 ; i < ordre-1; i++){
        for (int j=0 ; j < ordre-i-1; j++){
            if (monArbre[j]->nb_successeur < monArbre[j+1]->nb_successeur){
                tmp = monArbre[j];
                monArbre[j] = monArbre[j+1];
                monArbre[j+1] = tmp;
            }
        }
    }
}

int collorisation(){
    return  1 ;
}


void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier){


    char caractere;
    int nb_successeur = 0;
    int nb_predecesseur = 0;
    int numero_du_sommet =0;
    int i = 0;

    for (int j = 0; j < nombre_de_ligne; j++) {
        tab_sommet[j] = (arbre*)malloc(sizeof(arbre));
        if (tab_sommet[j] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }
    }


    while (fscanf(fichier, "%d", &numero_du_sommet) == 1) {
        tab_sommet[i]->sommet = numero_du_sommet;
        i++;
    }

    rewind(fichier);

    for (int j = 0; j < nombre_de_ligne; j++) {
        printf("numero du sommet : %d\n", tab_sommet[i]->sommet);
    }

}



void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle){

    int nb_sommet_initiale = 0;
    float temps_list = 0;
    int potentiel_sommet = 0;
    float potentiel_temps_list =0;
    int nb_predecesseur = 0;
    arbre* sommet_analyse = NULL;

    try_a_bulle(monArbre, ordre, taille);
    for (int i = 0; i < ordre; i++) {
        if(monArbre[i]->nb_predecesseur == 0){
            nb_sommet_initiale++;
        }
    }
    printf("\n nombre de sommet initiale : [%d]", nb_sommet_initiale);
    int sommet_initiale[nb_sommet_initiale];
    for (int i = 0; i < nb_sommet_initiale; i++) {
        for (int j = 0; j < ordre; j++) {
            if(monArbre[j]->nb_predecesseur == 0){
                sommet_initiale[i] = monArbre[j]->sommet;
            }
        }
    }




    ///affichage des informations
    printf("\nTri par nb successeur\n");
    for (int i = 0; i < ordre; i++) {
        printf("\n[%d] = [%f]\n", monArbre[i]->sommet, monArbre[i]->temps_execution);
    }
    for (int i = 0; i < ordre; i++) {
        printf("\nMon sommet [%d] : ", monArbre[i]->sommet);
        for (int j = 0; j < monArbre[i]->nb_predecesseur; j++) {
            printf(" predecesseur [%d] ", monArbre[i]->predecesseur[j]);
        }
    }

    sommet_analyse = monArbre[0];

    ///Vrai algorithme d'optimisation qui commence

    nb_predecesseur = sommet_analyse->nb_predecesseur;
    temps_list = temps_list + sommet_analyse->temps_execution;

    if(sommet_analyse->nb_predecesseur > 0 ){
        ///première phase de l'algorithme on viens créer les base de la list general pour pouvoir par la suite traiter chaque list

        for (int i = 0; i < nb_predecesseur; i++) {
            push_queue(*sommet_analyse);
            if(collorisation()){

                potentiel_sommet = sommet_analyse->predecesseur[i];
                printf("\n\nle potentiel sommet [%d]\n", potentiel_sommet);

                //on viens convertir le potentielle sommet en donné utilisable pour le mettre des les crochet d'un tableau
                for (int j = 0; j < ordre; j++) { // enfaite on va venir comparer le nom du sommet avec sa position dans l'arbre et on lui attribue cette position par la suite
                    if(monArbre[j]->sommet == potentiel_sommet){
                        potentiel_sommet = j;
                        break;
                    }
                }

                potentiel_temps_list = temps_list + monArbre[potentiel_sommet]->temps_execution;
                printf("\nle potentiel temp de list [%f]\n", potentiel_temps_list);

                if(potentiel_temps_list <= cycle){
                    push_queue(*monArbre[potentiel_sommet]);
                    push_queue_G(potentiel_temps_list);
                    temps_list = potentiel_temps_list;

                }
                else{
                    printf("\nLe cycle a ete sature\n\n");
                    print_queue();
                    exit(EXIT_SUCCESS);
                }
            }
        }
        print_queue_G();
        printf("\n");

        /// on analyse les sommet qui sommet qui sont dans list à l'interrieur de la liste generale, l'analyse de chaque chemin

        QueueElement_G *temp_G = first_G;

        for (int i = 0; i < nb_element_G; i++) { //boucle qui va servir a nous deplacer sur notre list general de first_G à last_G
            if(i != 0){  //il ne faut pas sauter le premier point de la list general
                temp_G = temp_G->next;
            }
            QueueElement *temp = temp_G->last; // permet d'aller chercher le derneière element de la list

            *sommet_analyse = temp->value; // permet de selectionner le sommet d'analyse, qui est de type arbre, mais on a egalement a l'interreieur de queue element un type abre

            if(sommet_analyse->nb_predecesseur > 0){
                for (int j = 0; j < sommet_analyse->nb_predecesseur; j++) { // on va venir analyser tous les predecesseur du sommet_analyse
                    if(j == 0 && collorisation()) { // le première element peut directement etre palacé en dernière de notre liste initialement creer

                            //ici on viens en quelque sorte reproduire notre schéma un peu plus haut avec l'histoire de devoir convertir nos sommet etc...
                            // mais on a une difference, pour cette partie on viens push directement dans la file a l'interrieur de notre files general
                            potentiel_sommet = sommet_analyse->predecesseur[j];

                            for (int k = 0; k < ordre; k++) {
                                if(monArbre[k]->sommet == potentiel_sommet){
                                    potentiel_sommet = k;
                                    break;
                                }
                            }
                            potentiel_temps_list = temp_G->temp_list + monArbre[potentiel_sommet]->temps_execution;

                            if(potentiel_temps_list <= cycle){
                                push_queue_I(*monArbre[potentiel_sommet], temp_G, potentiel_temps_list);
                            }
                            else{
                                printf("pour la file avec comme boucle d indentaion [%d] on a un cycle saturer", j);
                                print_queue_G();
                                exit(EXIT_SUCCESS);
                            }

                    }
                    else if (collorisation()){                                                         // mais pour les autre element on va devoir creer d'autre liste tous en reprenant notre list initiale et les aujouter a notre liste generale
                        QueueElement *temp_cc = temp_G->first;    //temp_cc sera utiliser pour copier et coller la liste dans une nouvelle liste pour venir la palcer a la fin
                        int valeur_arret = 0; //okay alors moi je vois ça comme un detour ce qui va ce passer avec la boucle for et le while
                        while (temp_cc != temp){ // je vais venir compter une valeur d'arret pour savoir quand est ce que je dois m'arreter sur ma list a copier
                            valeur_arret++;
                            temp_cc = temp_cc->next;
                        }
                        valeur_arret++; // ici je remet un ++ car le while s'arret avent d'avoir atteind la vrai fin du copier coller
                        float temps_intermediaire = 0;
                        temp_cc = temp_G->first; //on remet le temp_cc a jour

                        for (int k = 0; k < valeur_arret; k++) { // et ici je copie colle la list
                            push_queue(temp_cc->value);                                              // on push nos different element dans une list en preparation list_p
                            temps_intermediaire = temps_intermediaire + temp_cc->value.temps_execution; // pour povoir récupéré le temps de notre list
                            temp_cc = temp_cc->next;
                        }


                        //push_queue_G(temps_intermediaire);                                       // et la c'est bon on a copier notre list dans la list generale
                        //print_queue_G();
                       // exit(EXIT_SUCCESS);          // on reprend le shema pour insérer des sommet dans notre list a l'interrieur de la list generale
                        potentiel_sommet = sommet_analyse->predecesseur[j];

                        //printf("le sommet analyse : [%d]", sommet_analyse->sommet);
                        //exit(EXIT_SUCCESS);
                        for (int k = 0; k < ordre; k++) {
                            if (monArbre[k]->sommet == potentiel_sommet) {
                                potentiel_sommet = k;
                                break;
                            }
                        }
                        potentiel_temps_list = temps_intermediaire + monArbre[potentiel_sommet]->temps_execution;

                        if(potentiel_temps_list <= cycle){
                            push_queue(*monArbre[potentiel_sommet]);
                        }else{
                            printf("pour la file avec comme boucle d indentaion [%d] on a un cycle saturer", j);
                            print_queue_G();
                            exit(EXIT_SUCCESS);
                        }
                    }
                }
            }
            else{
                printf("\nOn a atteind le sommet initiale\n");
                print_queue_G();
                exit(EXIT_SUCCESS);
            }
        }
        push_queue_G(potentiel_temps_list);
        printf("\nLa premiere partie du code a ete faite \n");
        print_queue_G();
    }
    else{
        printf("\n Le sommet d'origine est pris comme point de depart\n");
    }
}




Bool is_empty_queue(void) {
    if (first_p == NULL && last_p == NULL)
        return true;

    return false;
}


void print_queue(void){
    if(is_empty_queue()){
        printf("Rein a afficher, la files est vide\n");
        return;
    }
    QueueElement *temp = first_p;
    while(temp != NULL){
        printf(" [[%d]] ", temp->value.sommet);
        temp = temp->next;
    }
}

void push_queue(arbre x){
    QueueElement *element;
    element = malloc(sizeof(*element));

    element->value = x;
    element->next = NULL;

    if(is_empty_queue()){
        first_p = element;
        last_p = element;
    }else{
        last_p->next = element;
        last_p= element;
    }
    nb_element_p++;
}

void pop_last(){
    if(is_empty_queue()){
        printf("la file est vide, aucun dernier element a retirer\n");
        return;
    }

    QueueElement *temp = first_p;


    if(first_p == last_p){
        first_p = NULL;
        last_p = NULL;
    }
    else{
        while (temp->next != last_p){
            temp = temp->next;
        }
        temp->next = NULL;
        last_p->next = temp;
        last_p = temp;

    }
    free(temp->next);
    nb_element_p--;
}

void pop_queue(void){
    if(is_empty_queue()){
        printf("\nla file est vide, il n'y a rien à retirer\n");
        return;
    }

    QueueElement *temp = first_p;

    if(first_p == last_p){
        first_p = NULL;
        last_p = NULL;
    }
    else{
        first_p = first_p -> next;
    }
    free(temp);
    nb_element_p--;
}

void clear_queue(void){
    if(is_empty_queue()){
        printf(" \nrien a supprimer, la file est vide\n");
        return;
    }
    while (!is_empty_queue()){
        pop_queue();
    }
}



Bool is_empty_queue_G(void) {
    if (first_G == NULL && last_G == NULL)
        return true;

    return false;
}

void print_queue_G(void){
    if(is_empty_queue_G()){
        printf("Rein a afficher, la files generale est vide\n");
        return;
    }
    printf("\nAffichage de la file generale\n");
    QueueElement_G *temp_G = first_G;
    while(temp_G != NULL){
        QueueElement *temp = temp_G->first;
        while (temp != NULL) {
            printf(" [[%d]] ", temp->value.sommet);
            temp = temp->next;
        }
        printf("  [%f]", temp_G->temp_list);
        printf("\n");
        temp_G = temp_G ->next;
    }
}

void push_queue_G(float temp_list){
    QueueElement_G *element;
    element = malloc(sizeof(*element));
    if(is_empty_queue()){
        printf("\nFile vide, on ne peut peut pas inserer de nouvelle file dans la file generale\n");
        return;
    }
    element->first = first_p;
    first_p = NULL;
    element->last = last_p;
    last_p = NULL;

    element->next = NULL;

    element->nb_element = nb_element_p;
    nb_element_p = 0;

    element->temp_list = temp_list;

    if(is_empty_queue_G()){
        first_G = element;
        last_G = element;
    }else{
        last_G->next = element;
        last_G = element;
    }
    nb_element_G++;
} //En réaliter on n'a pas vraiment d'élément à ajouter, on relie plutot le first et le last de notre list simple a ce de la structure de la list_General

void pop_queue_G(void){
    if(is_empty_queue_G()){
        printf("\nRien a supprimer, la file generale est vide\n");
    }

    QueueElement_G *temp_G = first_G;
    if( last_G == first_G) {
        first_G = NULL;
        last_G = NULL;
    }
    else{
        while(temp_G->nb_element != 0){
            QueueElement *temp = temp_G->first;
            if(temp_G->first == temp_G->last){
                temp_G->first = NULL;
                temp_G->last = NULL;
            }
            else{
                temp_G->first = temp_G->first -> next;
            }
            free(temp);
            temp_G->nb_element--;
        }
        first_G = first_G->next;
    }
    free(temp_G);
    nb_element_G--;
} // si on doit vidé un point de notre list Général il Faut vidé tous les points à l'intérrieur du last et du first de notre list elle meme dans la list général

void clear_queue_G(void){
    if(is_empty_queue_G()){
        printf(" \nrien a supprimer, la file est vide\n");
        return;
    }
    while (!is_empty_queue_G()){
        pop_queue_G();
    }
}



void push_queue_I(arbre x, QueueElement_G *repere, float temp_list){ //fonction qui va nous permettre de push à l'interrieur des list de la liste générale
    QueueElement *element;
    element = malloc(sizeof(*element));

    element->value = x;
    element->next = NULL;

    repere->temp_list = temp_list;

    repere->last->next = element;
    repere->last = element;

    repere->nb_element++;
}