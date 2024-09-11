#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct DateNaissance {
    int day;
    int month;
    int year;
}Date;

typedef struct ToutEtudiant {
    int ID;
    char nom [50];
    char prenom [50];
    Date Naissance;
    char Departement [50];
    float NoteGenerale;

}etudiant;
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
                printf ("we finde name %s \n", TEtudiant[i].nom);
                return i;
            }
        }
        i++;
     }
     return;
}

 /*if (strcasecmp (node->Departement, nameORdepar) == 0){
            printf ("we finde Departement %s \n", node->Departement);
            return node;
        }
        node = node->Next;

    printf ("we cant finde!\n");
    return NULL;*/





//-------------------------------------------------------------------------------------------------


void Modifier_ou_supprimer (bool b){
    int chose, i, j, k;
    char name [50];
    char name1 [50];
    char pname [50];


    if (b == true){
            do{
        printf ("modifier :\n\t. enter name the Etudiant : ");
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
                        printf ("enter new nom : ");
                        scanf ("%49s", TEtudiant[i].nom);
                        break;
                    case 2:
                        printf ("enter new prenom : ");
                        scanf ("%s", TEtudiant[i].prenom);
                        break;
                    case 3:
                        printf ("enter new ID : ");
                        scanf ("%d", &TEtudiant[i].ID);
                        break;
                    case 4:
                        printf ("enter day : ");
                        scanf ("%d", &TEtudiant[i].Naissance.day);
                        printf ("enter mont : ");
                        scanf ("%d", &TEtudiant[i].Naissance.month);
                        printf ("enter year : ");
                        scanf ("%d", &TEtudiant[i].Naissance.year);
                        break;
                    case 5:
                        printf ("enter new Note Generale : ");
                        scanf ("%f", &TEtudiant[i].NoteGenerale);
                        break;
                    default :
                        printf ("you shod enter from 1 -> 5");
                        break;
                }
                printf ("do you want to chose again if you don't wantn chose 0 : ");
                scanf ("%d", &chose);
            }while (chose != 0);
        }

      else {
            printf ("enter name of Etudiant that you want to delete it : ");
            scanf ("%49s", name1);

            j = search_etudiant (name1);

            k = j+1;
            for (i = j; i < NomberTotalEtudian-1; i++){
                strcpy (TEtudiant[i].nom, TEtudiant[k].nom);
                strcpy (TEtudiant[i].Departement, TEtudiant[k].Departement);
                strcpy (TEtudiant[i].prenom, TEtudiant[k].prenom);
                TEtudiant[i].ID = TEtudiant[k].ID;
                TEtudiant[i].Naissance.day = TEtudiant[k].Naissance.day;
                TEtudiant[i].Naissance.month = TEtudiant[k].Naissance.month;
                TEtudiant[i].Naissance.year = TEtudiant[k].Naissance.year;
                k++;
            }
            NomberTotalEtudian--;
      }

}








//-------------------------------------------------------------------------------------------------
void  Ajouter_de_nouveaux_etudiants (){
    int NewET, i, C;



    printf ("how many The students you want to add : ");
    scanf ("%d", &NewET);

    TEtudiant = (etudiant*) realloc (TEtudiant, (NomberTotalEtudian + NewET) * sizeof(etudiant));
    if (TEtudiant == NULL){
        printf ("error at Declaration!\n");
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
                printf ("day de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.day);
            }while (TEtudiant[i].Naissance.day > 31 ||  TEtudiant[i].Naissance.day < 1);

            do{
                printf ("month de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.month);
            }while (TEtudiant[i].Naissance.month > 12 ||  TEtudiant[i].Naissance.month < 1);

           do{
                printf ("year de naissance : ");
                scanf ("%d", &TEtudiant[i].Naissance.year);
            }while (TEtudiant[i].Naissance.year > 2010 ||  TEtudiant[i].Naissance.year < 1910);

                                //Département

            printf ("enter Departement : ");
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
            printf ("you want to chose anther Departement if 0 if you don't want : ");
            scanf ("%d", &anther);
        }while (anther);
    }
    else{
        for (i = 0; i < NomberTotalEtudian; i++)
            sum += TEtudiant [i].NoteGenerale;
        moyan = sum / NomberTotalEtudian;

        printf ("\n\t\t.moyenne generale de universite : %.2f\n\n", moyan);
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
    int i, j = 0;
    int Top3i [2] = {-1, -1};
    float Top;


    do{
        Top = TEtudiant [0].NoteGenerale;
        for (i = 0; i < NomberTotalEtudian; i++){
            if (Top3i[0] == i || Top3i[1] == i)
                continue;
            if (TEtudiant [i].NoteGenerale > Top){
                Top = TEtudiant [i].NoteGenerale;
                Top3i[j] = i;
            }
        }
        printf ("Top note %d is %.2f\n", j+1, Top);
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


int main(){
    int again, chos, MoSu;
    int deNumber;

    Ajouter_de_nouveaux_etudiants ();

    do{
        printf ("1. ajouter etudian\n");
        printf ("2. aficher\n");
        printf ("3. Modifier ou supprimer un etudiant\n");
        printf ("4. Calculer la moyenne générale \n");
        printf ("5. Statistiques \n");
        printf ("enter : ");
        scanf ("%d", &chos);

        switch (chos){
        case 1:
             Ajouter_de_nouveaux_etudiants ();
             break;
        case 2:
            Afficher_les_details_un_etudiant ();
            break;
        case 3:
            printf ("1. Modifier\n");
            printf ("2. supprimer\n");
            printf ("enter : ");
            scanf ("%d", &MoSu);
            switch (MoSu){
                case 1:
                     Modifier_ou_supprimer (true);
                     break;
                case 2:
                     Modifier_ou_supprimer (false);
                     break;
                default:
                    printf ("switch 1 -> 2\n");
                    break;
            }
            break;
            case 4:
                printf ("1. la moyenne generale de chaque departement\n");
                printf ("2. la moyenne generale de universite\n");
                printf ("enter : ");
                scanf ("%d", &MoSu);
                switch (MoSu){
                    case 1:
                         Calculer_la_moyenne_generale (true);
                         break;
                    case 2:
                         Calculer_la_moyenne_generale (false);
                         break;
                    default:
                        printf ("switch 1 -> 2\n");
                        break;
                }
                break;
                case 5:
                    printf ("1. Afficher le nombre total detudiants inscrits.\n");
                    printf ("2. Afficher le nombre d etudiants dans chaque departement.\n");
                    printf ("3. Afficher les etudiants ayant une moyenne generale superieure à un certain seuil.\n");
                    printf ("4. Afficher les 3 etudiants ayant les meilleures notes.\n");
                    printf ("5. Afficher le nombre d etudiants ayant reussi dans chaque departement (ceux ayant une note superieure ou egale a 10/20).\n");
                    printf ("enter : ");
                    scanf ("%d", &MoSu);
                    switch (MoSu){
                        case 1:
                             printf ("total detudiants inscrits %d", NomberTotalEtudian);
                             break;
                        case 2:
                            deNumber = etudiants_dans_chaque_departement ();
                            printf ("le nombre d etudiants dans chaque departement %d", deNumber);
                            break;
                        case 3:
                            etudiants_ayant_une_moyenne_generale_superieure_a_un_certain_seuil ();
                            break;
                        case 4:
                            Afficher_les_etudiants_ayant_les_meilleures_notes ();
                            break;
                        case 5:
                            Afficher_le_nombre_detudiants_ayant_Top_eussi_dans_chaque_departement ();
                            break;
                        default:
                            printf ("switch 1 -> 2\n");
                            break;
                        }
                break;

        default:
            printf ("switch 1 -> 3\n");
            break;
        }
        printf ("\n");
        printf ("again   0: no, any number: yes \nenter : ");
        scanf ("%d", &again);
        printf ("\n\n\n");
    }while (again);


    free(TEtudiant);
    return 0;
}
