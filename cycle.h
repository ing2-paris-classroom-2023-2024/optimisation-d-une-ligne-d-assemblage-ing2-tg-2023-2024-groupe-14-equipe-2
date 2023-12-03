//
// Created by David on 12/3/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_CYCLE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_CYCLE_H

// Structure pour représenter une opération
typedef struct {
    int operation;
    int duration;
} Operation;


int Contrainte_Temps_Cycle(Operation* operations, int operations_total, int temps_cycle);


#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_GROUPE_14_EQUIPE_2_CYCLE_H
