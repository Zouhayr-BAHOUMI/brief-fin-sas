#include <stdio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

enum priorite{ low ,medium, high };


typedef struct {

   int annee;
   int mois;
   int jour;

} dateEcheance;


typedef struct{

    char nom[30];
    char description[30];
    dateEcheance date;
    enum priorite pr;

}tache;


    void saisiInfos(tache t[], int taille){
        printf("entrer les information de chaque tache :");

        int i;
        for(i=0;i<taille; i++){

            printf("entrer le nom de  %d tache : ",i+1);
            scanf(" %[^\n]s",&t[i].nom);
            printf("entrer la date decheance de %d tache : ",i+1);
            printf("Annee :  ",i+1);
            scanf(" %d",&t[i].date.annee);
            printf("mois   : ",i+1);
            scanf(" %d",&t[i].date.mois);
            printf("jour   : ",i+1);
            scanf(" %d",&t[i].date.jour);
        }

    }

    int ajouterTache()

    int main () {

        int choice;
        int ordre;

    while(1){

    printf("........ 1 ajouter votre tache ..........\n ");
    printf("........ 2 afficher votre tache ..........\n ");
    printf("........ 3 modifier la tache ....................\n ");
    printf("........ 4 supprimer la tache ....................\n ");
    printf("........ 5 trier votre les tache  ...............................\n ");
    printf("........ 6 filtrer votre taches...............................\n ");
    printf("........ 7 Quitter  ...............................\n ");

    printf("Entrez votre choix: ");
    scanf("%d", &choice);

    switch(choice){
    case 1:
                ajouterTache();
                break;
    case 2:
                afficher();
                break;
    case 3:
                modifier();
                break;
    case 4:
                supprimer();
                break;
    case 5:
            printf("Veuillez choisir l'ordre de tri : \n");
            printf("1. Croissant\n");
            printf("2. Decroissant\n");
            scanf("%d", &ordre);
            trier();
            break;
    case 6:
                filtrer();
                break;
    case 7:
                exit(0);
    default:
                printf("invalide choix ");
                break;
    }//end switch

    }//end while
    return 0;
}
