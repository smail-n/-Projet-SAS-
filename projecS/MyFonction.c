#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "Hider.h"


etudiant *TEtudiant = NULL;
int NomberTotalEtudian = 0;



int search_etudiant (char name[]){
    char what, Prenom [50];
    int i = 0;

        printf ("enter prenom : ");
        scanf ("%49s", Prenom);

    while(i < NomberTotalEtudian){
        if (strcasecmp (TEtudiant[i].nom, name) == 0){
            if (strcasecmp (TEtudiant[i].prenom, Prenom) == 0){
                printf ("Nous trouvons le nom %s \n", TEtudiant[i].nom);
                return i;
            }
        }
        i++;
     }
     printf ("Nous ne pouvons pas trouver\n");//
     return;
}




void Modifier_ou_supprimer (bool b){
    int chose, i, j, k;
    char name [50];
    char name1 [50];
    char pname [50];


    if (b == true){
            do{
        printf ("modifier :\n\t. Entrez le nom de etudiant : ");
        scanf ("%49s", name);

        i = search_etudiant (name);

                printf ("1. name \n");
                printf ("2. prenom \n");
                printf ("3. ID \n");
                printf ("4. Date de Naissance \n");
                printf ("5. Note Generale \n");
                printf ("enter : ");
                scanf ("%d", &chose);
                 switch (chose) {
                    case 1:
                        printf ("Entrez un nouveau nom : ");
                        scanf ("%49s", TEtudiant[i].nom);
                        break;
                    case 2:
                        printf ("Entrez un nouveau prenom : ");
                        scanf ("%s", TEtudiant[i].prenom);
                        break;
                    case 3:
                        printf ("Entrez un nouveau ID : ");
                        scanf ("%d", &TEtudiant[i].ID);
                        break;
                    case 4:
                        printf ("Entrez un nouveau day : ");
                        scanf ("%d", &TEtudiant[i].Naissance.day);
                        printf ("Entrez un nouveau mont : ");
                        scanf ("%d", &TEtudiant[i].Naissance.month);
                        printf ("Entrez un nouveau year : ");
                        scanf ("%d", &TEtudiant[i].Naissance.year);
                        break;
                    case 5:
                        printf ("Entrez un nouveau Note Generale : ");
                        scanf ("%f", &TEtudiant[i].NoteGenerale);
                        break;
                    default :
                        printf ("Vous devez entrer de 1 a 5\n");
                        break;
                }
                printf ("do you want to chose again if you don't wantn chose 0 : ");
                scanf ("%d", &chose);
            }while (chose != 0);
        }

      else {
            printf (" chose a name to delete it : ");
            scanf ("%49s", name1);

            j = search_etudiant (name1);


            for (i = j; i < NomberTotalEtudian-1; i++){
                strcpy (TEtudiant[i].nom, TEtudiant[j+1].nom);
                strcpy (TEtudiant[i].Departement, TEtudiant[j+1].Departement);
                strcpy (TEtudiant[i].prenom, TEtudiant[j+1].prenom);
                TEtudiant[i].ID = TEtudiant[j+1].ID;
                TEtudiant[i].Naissance.day = TEtudiant[j+1].Naissance.day;
                TEtudiant[i].Naissance.month = TEtudiant[j+1].Naissance.month;
                TEtudiant[i].Naissance.year = TEtudiant[j+1].Naissance.year;
                TEtudiant[i].NoteGenerale = TEtudiant[j+1].NoteGenerale;
            }
            NomberTotalEtudian--;
      }

}






void  Ajouter_de_nouveaux_etudiants (){
    int NewET, i, C;



    printf ("Combien d'etudiants voulez-vous ajouter? ");
    scanf ("%d", &NewET);

    TEtudiant = (etudiant*) realloc (TEtudiant, (NomberTotalEtudian + NewET) * sizeof(etudiant));
    if (TEtudiant == NULL){
        printf ("Erreur a la declaration!\n");
        return;
    }


    for (i = NomberTotalEtudian; i < NomberTotalEtudian + NewET ; i++){
            printf ("-----------Etudiant %d-------\n\n", i+1);

                                // nom d'un etudion
            printf ("nom : ");
            scanf ("%49s", TEtudiant[i].nom);
            printf ("prenom : ");
            scanf ("%49s", TEtudiant[i].prenom);

                                //Numéro unique
                printf ("ID : ");
                scanf ("%d", &TEtudiant[i].ID);


                                //Date de naissance
            do{
                printf ("Jour de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.day);
            }while (TEtudiant[i].Naissance.day > 31 ||  TEtudiant[i].Naissance.day < 1);

            do{
                printf ("Mois de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.month);
            }while (TEtudiant[i].Naissance.month > 12 ||  TEtudiant[i].Naissance.month < 1);

           do{
                printf ("Annee de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.year);
            }while (TEtudiant[i].Naissance.year > 2010 ||  TEtudiant[i].Naissance.year < 1910);

                                //Département

            printf ("Entrez le departement : ");
            scanf ("%49s", TEtudiant[i].Departement);

                                //Note generale
            do{
                printf ("Note generale : ");
                scanf ("%f", &TEtudiant[i].NoteGenerale);
            }while (TEtudiant[i].NoteGenerale > 20 ||  TEtudiant[i].NoteGenerale < 1);
    }
    NomberTotalEtudian += NewET;
}


void Afficher_les_details_un_etudiant (){
    int i;


    for (i = 0; i < NomberTotalEtudian; i++){
        printf ("-----------Etudiant %d-------\n\n", i+1);
        printf ("\tnom : %s\n", TEtudiant[i].nom);
        printf ("\tprenom :%s\n", TEtudiant[i].prenom);
        printf ("\tID : %d\n", TEtudiant[i].ID);
        printf ("\tDate de naissance %d/ %d/ %d\n", TEtudiant[i].Naissance.day, TEtudiant[i].Naissance.month, TEtudiant[i].Naissance.year);
        printf ("\t Departement %s \n", TEtudiant[i].Departement);
        printf ("\tNote generale %.2f\n", TEtudiant[i].NoteGenerale);
    }

}


void Calculer_la_moyenne_generale (bool Q){
    float sum = 0, moyan;
    int i, j = 0, anther;
    char T [50];



    if (Q){

        do{
                j = 0;  sum = 0;
            printf ("enter Departement : ");
            scanf ("%49s", T);
            for (i = 0; i < NomberTotalEtudian; i++){
                    if (strcasecmp(TEtudiant [i].Departement, T) == 0){
                        sum += TEtudiant [i].NoteGenerale;
                        j++;
                    }
                       moyan = sum / j;
            }
            printf ("\t\t.moyenne generale de Departement %s : %.2f\n\n", T, moyan);
            printf ("Voulez-vous choisir un autre département ? Tapez 0 si vous ne le souhaitez pas : ");
            scanf ("%d", &anther);
        }while (anther);
    }
    else{
        for (i = 0; i < NomberTotalEtudian; i++)
            sum += TEtudiant [i].NoteGenerale;
        moyan = sum / NomberTotalEtudian;

        printf ("\n\t\t.Moyenne generale de l'universite: %.2f\n\n", moyan);
    }
}

int etudiants_dans_chaque_departement (){
    char departement [50];
    int i, total = 0;

    printf ("enter departement : ");
    scanf ("%49s", departement);

    for (i = 0; i < NomberTotalEtudian; i++){
        if (strcasecmp (TEtudiant [i].Departement, departement) == 0)
            total++;
    }
    return total;
}

void etudiants_ayant_une_moyenne_generale_superieure_a_un_certain_seuil (){
    int seuil, i;

        printf ("enter un certain seuil : ");
        scanf ("%d", &seuil);

    for (i = 0; i < NomberTotalEtudian; i++){
        if (TEtudiant [i].NoteGenerale >= seuil)
            printf ("etudiant : %s %s\nNote generale : %.2f\n", TEtudiant [i].nom, TEtudiant [i].prenom, TEtudiant [i].NoteGenerale);
    }
}

void Afficher_les_etudiants_ayant_les_meilleures_notes (){
    int i, j = 0, k;
    int Top3i [3] = {-1, -1, -1};
    float Top = TEtudiant [0].NoteGenerale;


    do{

        for (i = 0; i < NomberTotalEtudian; i++){
            if (Top3i[0] != i && Top3i[1] != i && k ==0 ){
                Top = TEtudiant [i].NoteGenerale;
                k++;
            }

            if (Top3i[0] == i || Top3i[1] == i)
                continue;

            if (TEtudiant [i].NoteGenerale >= Top){
                Top = TEtudiant [i].NoteGenerale;
                Top3i[j] = i;
            }
        }
        printf ("Top note %d is %.2f\n", j+1, TEtudiant [Top3i[j]].NoteGenerale);
        k = 0;
        j++;
    }while (j != 3);


}

void Afficher_le_nombre_detudiants_ayant_Top_eussi_dans_chaque_departement (){
    int i;
    char Cherdepartement [50];
    float seuil;

    printf ("enter departement : ");
    scanf ("%49s", Cherdepartement);
    printf ("note superieure? ");
    scanf ("%f", &seuil);

    for (i = 0; i < NomberTotalEtudian; i++){
            if (TEtudiant [i].NoteGenerale >= seuil && strcasecmp (TEtudiant [i].Departement, Cherdepartement) == 0){
                printf ("not : %.2f\n", TEtudiant [i].NoteGenerale);
            }
    }


}

void changeTowElemant(int A, int B){
    etudiant Te;

                            // TEtudiant [i+1] ---> Te
    strcpy (Te.Departement, TEtudiant[B].Departement);
    Te.ID = TEtudiant [B].ID;
    Te.Naissance.day = TEtudiant[B].Naissance.day;
    Te.Naissance.month = TEtudiant [B].Naissance.month;
    Te.Naissance.year = TEtudiant [B].Naissance.year;
    strcpy (Te.nom, TEtudiant[B].nom);
    Te.NoteGenerale =  TEtudiant [B].NoteGenerale;
    strcpy (Te.prenom, TEtudiant [B].prenom);

                            // TEtudiant [i] ----> TEtudiant [i+1]
    strcpy (TEtudiant[B].Departement , TEtudiant[A].Departement);
    TEtudiant [B].ID = TEtudiant [A].ID;
    TEtudiant [B].Naissance.day = TEtudiant [A].Naissance.day;
    TEtudiant [B].Naissance.month = TEtudiant [A].Naissance.month;
    TEtudiant [B].Naissance.year = TEtudiant [A].Naissance.year;
    strcpy (TEtudiant [B].nom , TEtudiant [A].nom);
    TEtudiant [B].NoteGenerale =  TEtudiant [A].NoteGenerale;
    strcpy (TEtudiant [B].prenom , TEtudiant [A].prenom);

                            //Te ----> TEtudiant [i]
    strcpy (TEtudiant[A].Departement , Te.Departement);
    TEtudiant [A].ID = Te.ID;
    TEtudiant [A].Naissance.day = Te.Naissance.day;
    TEtudiant [A].Naissance.month = Te.Naissance.month;
    TEtudiant [A].Naissance.year = Te.Naissance.year;
    strcpy (TEtudiant [A].nom , Te.nom);
    TEtudiant [A].NoteGenerale =  Te.NoteGenerale;
    strcpy (TEtudiant [A].prenom , Te.prenom);

}

void Tri_alphabetique (){
    int Long, i;


    for (Long = 0; Long < NomberTotalEtudian-1; Long++){
        for (i = Long; i >= 0; i--){
            if (strcasecmp (TEtudiant [i].nom, TEtudiant [i+1].nom) == 1){
                changeTowElemant(i, i+1);
            }
            else
                continue;
        }
    }
    printf ("--------Tri_alphabetique Good----------\n");


}

void Tri_par_du_plus (bool a){
    int Long, i;

    if (a){
        for (Long = 0; Long < NomberTotalEtudian-1; Long++){
            for (i = Long; i >= 0; i--){
                if (TEtudiant [i].NoteGenerale < TEtudiant [i+1].NoteGenerale){
                    changeTowElemant(i, i+1);
                }
                else
                    continue;
            }
        }
        printf ("--------plus eleve au plus faible ------------\n");
    }
    else{
        for (Long = 0; Long < NomberTotalEtudian-1; Long++){
            for (i = Long; i >= 0; i--){
                if (TEtudiant [i].NoteGenerale > TEtudiant [i+1].NoteGenerale){
                    changeTowElemant(i, i+1);
                }
                else
                    continue;
            }
        }
        printf ("--------plus faible au plus eleve ------------\n");
    }
}


void Tri_des_etudiants_selon_leur_statut_de_reussite (){
    int i, j;

    for (i = NomberTotalEtudian-1; i >= 0; i--){
         if (TEtudiant [i].NoteGenerale >= 10){
            for (j = 0; j < i; j++){
                if (TEtudiant [j].NoteGenerale < 10)
                    changeTowElemant(i, j);
                else{
                    if (TEtudiant [j].NoteGenerale < TEtudiant [i].NoteGenerale){
                        changeTowElemant(i, j);
                    }
                }
            }
        }
    }

    for (i = 0; i < NomberTotalEtudian; i++){
        if (TEtudiant [i].NoteGenerale >= 10){
            printf ("etudiant : %s %s\nNote generale : %.2f\n", TEtudiant [i].nom, TEtudiant [i].prenom, TEtudiant [i].NoteGenerale);
        }
         else
            break;
    }

}
