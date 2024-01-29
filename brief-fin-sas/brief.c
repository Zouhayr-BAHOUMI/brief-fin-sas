#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>

//enum priorite{ low ,medium, high };


typedef struct {

   int annee;
   int mois;
   int jour;

} dateEcheance;


typedef struct{

    char nom[30];
    char description[30];
    dateEcheance date;
    int priorite;

}tache;


    void saisiInfos(tache * newTache ){
        printf("Entrer les information de la tache : \n");

            printf("entrer le nom de la tache : ");
            scanf(" %[^\n]s",newTache->nom);
            printf("entrer la description de la tache : ");
            scanf(" %[^\n]s", newTache->description);
            printf("entrer la date decheance de la tache : \n ");
            printf("Annee :  ");
            scanf(" %d",&newTache->date.annee);
            printf("mois   : ");
            scanf(" %d",&newTache->date.mois);
            printf("jour   : ");
            scanf(" %d",&newTache->date.jour);
            printf("entrer la priorite de la tache :\n ");
            printf("1.low\t 2. medium\t 3. high\t :");
            scanf(" %d", &newTache->priorite);

        }

    int ajouterTache(tache t[],int nb, tache newTache){

       if(nb < 100){
            t[nb]= newTache;
            nb++;
            printf("ajouter avec success . \n");
       }else{

            printf("somthing wrong .");
       }

       return nb;
    }

        void afficherTache (tache t[],int nb){
        int i;
        for(i=0;i<nb ; i++){
            printf("\n Tache N %d", i+1);
            printf("\n Nom est : %s", t[i].nom);
            printf("\n description est : %s", t[i].description);
            printf("\n prioritie est : %d", t[i].priorite);
            printf("\n Date d'echeance est : %d/%d/%d", t[i].date.jour, t[i].date.mois, t[i].date.annee);
            printf("\n ---------------------------------------------------------------------- \n");
        }
        }




int main () {

        tache t[100];
        int choice;
        int ordre;
        int nbrTache=0;
        tache newTache;

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
                saisiInfos(&newTache);
                nbrTache = ajouterTache(t,nbrTache,newTache);
                break;
    case 2:
                afficherTache(t,nbrTache);
                break;
    case 3:
                //modifierTache(t,nbrTache);
                break;
    case 4:
                //nbrTache = supprimerTache(t,&nbrTache);
                break;
    case 5:
            printf("Veuillez choisir l'ordre de tri : \n");
            printf("1. Croissant\n");
            printf("2. Decroissant\n");
            scanf("%d", &ordre);
            if (ordre == 1){
               // trierTacheCroissant(t,nbrTache);
            }else if(ordre == 2){
               // trierTacheDecroissant(t,nbrTache);
            }else
                printf("invalid choix");


            break;
    case 6:
               // filtrer();
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
