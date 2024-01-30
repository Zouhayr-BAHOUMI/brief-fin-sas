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
    char priorite[30];

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
            scanf(" %[^\n]s", newTache->priorite);

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
            printf("\n prioritie est : %s", t[i].priorite);
            printf("\n Date d'echeance est : %d/%d/%d", t[i].date.jour, t[i].date.mois, t[i].date.annee);
            printf("\n ---------------------------------------------------------------------- \n");
        }
        }

void modifierTache(tache t[],int nb){
    char Nom[30];
    int existe=0;

    printf(" entrer le nom que vous modifier :");
    scanf(" %[^\n]s",Nom);

    for(int i=0; i<nb; i++){
        if(strcmp(t[i].nom, Nom) == 0){
            saisiInfos(&t[i]);
            existe=1;
            break;
        }
    }
    if (existe == 1) {
        printf("Modifier avec succ s.\n");
    } else {
        printf("somthing wrong.\n");
    }
}

int supprimerTache( tache t[],int *nb){
     char Nom[30];
    int existe=0;

    printf(" entrer le nom de la tache   supprimer :");
    scanf(" %[^\n]s",Nom);

    for(int i=0; i<*nb; i++){
        if(strcmp(t[i].nom, Nom) == 0){
            for(int j=i; j<*nb-1; j++){
            strcpy(t[j].nom,t[j+1].nom);
            strcpy(t[j].description,t[j+1].description);
            strcpy(t[j].priorite,t[j+1].priorite);
            t[j].date.jour=t[j+1].date.jour;
            t[j].date.mois=t[j+1].date.mois;
            t[j].date.annee=t[j+1].date.annee;
            }
            existe=1;
            break;
        }
    }
    if (existe == 1) {
        printf("supprimer avec success.\n");
        (*nb)--;
    } else {
        printf("somthing wrong.\n");
    }
    return *nb;
}

void trierTacheCroissant(tache t[], int nb){

   int i,j;
   tache temp;
   for(i=0; i<nb; i++){
      for(j=i+1; j<nb ; j++){
        if( t[i].date.annee > t[j].date.annee ||  (t[i].date.annee == t[j].date.annee && t[i].date.mois > t[j].date.mois )
            || ( t[i].date.mois == t[j].date.mois && t[i].date.jour > t[j].date.jour) ){
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;
        }
      }
   }

   printf("les tache apres trie croissant : \n");

       for(i=0; i<nb ; i++){
            printf("\n Tache N %d", i+1);
            printf("\n Nom est : %s", t[i].nom);
            printf("\n description est : %s", t[i].description);
            printf("\n prioritie est : %s", t[i].priorite);
            printf("\n Date d'echeance est : %d/%d/%d", t[i].date.jour, t[i].date.mois, t[i].date.annee);
            printf("\n ---------------------------------------------------------------------- \n");
       }
}


void trierTacheDecroissant(tache t[], int nb){

   int i,j;
   tache temp;
   for(i=0; i<nb; i++){
      for(j=i+1; j<nb ; j++){
        if( t[i].date.annee < t[j].date.annee ||  (t[i].date.annee == t[j].date.annee && t[i].date.mois < t[j].date.mois )
            || ( t[i].date.mois == t[j].date.mois && t[i].date.jour < t[j].date.jour) ){
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;
        }
      }
   }

   printf("les tache apres trie decroissant : \n");

       for(i=0; i<nb ; i++){
            printf("\n Tache N %d", i+1);
            printf("\n Nom est : %s", t[i].nom);
            printf("\n description est : %s", t[i].description);
            printf("\n prioritie est : %s", t[i].priorite);
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
                modifierTache(t,nbrTache);
                break;
    case 4:
                nbrTache = supprimerTache(t,&nbrTache);
                break;
    case 5:
            printf("Veuillez choisir l'ordre de tri : \n");
            printf("1. Croissant\n");
            printf("2. Decroissant\n");
            scanf("%d", &ordre);
            if (ordre == 1){
                trierTacheCroissant(t,nbrTache);
            }else if(ordre == 2){
                trierTacheDecroissant(t,nbrTache);
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
