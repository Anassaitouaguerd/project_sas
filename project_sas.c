#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int numeroservice,heure, minute, jeur, id;
char titre[50],description[500];
int sizetache = 0, i, j, sizetab = 0;
int cont = 0, status;
int finalle,debute,D[100] ;


typedef struct
{
    int mois;
    int jeur;
    int annee;
    int jeur2;


} deadline;



typedef struct
{
    int id;
    char titre[50];
    char description[500];
    char status[40];
    deadline dead;

} task;

task tache[100];
;

void Ajouter_taches()
{
    printf("entrez le nombre de les tache ajouter : ");
    scanf("%d",&sizetache);
    for (i = 0 ; i < sizetache ; i++)
    {
        printf("\n\t --> entrez le titre de tache [%d]: ",i+1);
        getchar();
        gets(tache[cont].titre);
        printf("\n\t --> entrez le description de tache : ");
        gets(tache[cont].description);
        tache[cont].id = cont+2;
        printf("\n\n \t\t ******entrez la date final : ******\n ");
        printf("\t---> entrez le jeur: ");
        scanf("%d",&tache[cont].dead.jeur);
        printf("\t---> entrez le mois: ");
        scanf("%d",&tache[cont].dead.mois);


        do
        {
            printf("\n\n\t\t ****** entrez status ******\n\n");
            printf("\t\t ------------------------------------\n");
            printf("\t\t |-->> 1 - realiser                 |\n");
            printf("\t\t |-->> 2 - en cours de realisation  |\n");
            printf("\t\t |-->> 3 - finalisee                |\n");
            printf("\t\t ------------------------------------\n");
            printf("\t\t ---------->>>> entrez le numero de status : ");
            scanf("%d",&status);
            switch(status)
            {
            case 1 :
                strcpy(tache[cont].status,"realiser");
                break;
            case 2 :
                strcpy(tache[cont].status,"en cours de realisation");
                break;
            case 3 :
                strcpy(tache[cont].status,"finalisee");
                break;
            }

        }
        while(status !=1 && status != 2 && status !=3);
        cont ++;

    }
}
void DeadLine()
{


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    for( i = 0 ; i < cont ; i++)
    {

        tache[i].dead.jeur = tache[i].dead.jeur - tm.tm_mday;



        if(tache[i].dead.mois == tm.tm_mon+1)
        {
            continue;
        }
        else if (tache[i].dead.mois!= tm.tm_mon+1)
        {
            tache[i].dead.jeur  = (tache[i].dead.mois * 30) - ((tm.tm_mon+1) * 30) + tache[i].dead.jeur ;
        }


    }

}
void tableaux()
{
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("|        titre        |     description        |     deadline     |       idantifiant            |         status  |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}



void tableauCase()
{

    int i;
    for (i = 0; i < cont; i++)
    {


        printf("|    %s    |    %5s |   %02d jeur    |   %d  |    %s    |\n\n",tache[i].titre,tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
    }

}


void Afficher_liste()
{
    int reponse ;
    task tri_alphabet;
    task tri_deadline;
    printf("entrez le nombre de choix : \n");
    printf(" 1 - ALPHABET ***\n");
    printf(" 2 - deadline ***\n");
    scanf("%d",&reponse);
    DeadLine();

    switch(reponse)
    {
    case 1 :
        for(i = 0 ; i < cont ; i++)
        {
            for (j = i + 1 ; j < cont ; j++)
            {
                if(strcmp(tache[i].titre, tache[j].titre)>0)
                {

                    tri_alphabet = tache[i];
                    tache[i] = tache[j];
                    tache[j] = tri_alphabet;

                }
            }
        }
        tableaux();
        tableauCase();
        break ;
    case 2 :
        for(i = 0 ; i < cont ; i++)
        {
            for( j = i + 1 ; j < cont ; j++)
            {
                if(tache[i].dead.jeur > tache[j].dead.jeur)
                {
                    tri_deadline = tache[i] ;
                    tache[i] = tache[j] ;
                    tache[j] = tri_deadline;
                }
            }
        }
        tableaux();
        tableauCase();
        break ;
    }


}
void Modifier_tache()
{
    int md;
    tableaux();
    tableauCase();

    printf("entrez le identifiant de tache :");
    scanf("%d",&md);
    for ( i = 0 ; i < cont ; i++)
    {
        if (tache[i].id == md)
        {
            printf("\n\t --> entrez le titre de tache : ");
            getchar();
            gets(tache[i].titre);
            printf("\n\t --> entrez le description de tache : ");
            gets(tache[i].description);

            tache[i].id = cont + 2;

            printf("\n\n \t\t ******entrez la date final : ******\n ");
            printf("\t---> entrez le jeur: \n");
            scanf("%d",&tache[i].dead.jeur );
            printf("\t---> entrez le mois: ");
            scanf("%d",&tache[i].dead.mois);

        }
    }
    DeadLine();

}
void Rechercher_taches()
{
    int rep, K,exist = 0;
    int N;
    char Tit[50];

    printf("\n\t\t\t----------------------------\n");
    printf("\t\t\t |1 - chercher par Identifiant  |\n");
    printf("\t\t\t |2 - chercher par titre        |\n");
    printf("\n\t\t\t----------------------------\n");
    scanf("%d",&rep);
    switch(rep)
    {
    case 1 :
        printf("entrez le idantifiant : ");
        scanf("%d",&N);
        for(i=0; i<cont; i++)
        {
            if(tache[i].id == N)
            {
                exist = 1;
                tableaux();
                printf("\n |    %s    |    %5s |   %02d jeur  |   %d  |    %s    |\n",tache[i].titre, tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
            }
            if(exist == 0)
            {
                printf("!!!! le idantifiant no disponible !!!!!!!");
            }
        }
        break ;

    case 2 :
        printf("entrez le titre de tache :");
        scanf("%s", Tit);
        for( i = 0 ; i < cont ; i++)
        {
            K = strcmp(tache[i].titre, Tit);
            if(K == 0)
            {
                exist = 1;

                tableaux();
                printf("\n |    %s    |    %5s |   %02d jeur  |   %d  |    %s    |\n",tache[i].titre, tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
            }
            if(exist == 0)
            {
                printf("!!!! le titre no disponible !!!!!!!");
            }
        }
        break;
    default :
        printf("!!!!!!! --> le nombre de choix no disponible!!! <--");
    }

}
void Supprimer_tache()
{
    int index, exist = 0;
    tableaux();
    tableauCase();
    printf("\t ------ >> entrez le identifiant de la tache : ");
    scanf("%d",&index);
    for( i = 0 ; i < cont ; i++)
    {
        if(index == tache[i].id)
        {
            exist = 1;
            tache[i] = tache[i+1];
            cont --;
        }
        if(exist == 0)
        {
            printf("------ !!!! le identifiant no disponible !!!! ---- ");
        }
    }


}
void Statistiques()
{
    int temp = cont ;
    char incomplete[50] = "realiser";
    char complete [50] =   "finalisee";
    int longeure=0, longeure2=0;

    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches est : %d           \n",temp);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
    for(i =0 ; i < cont ; i++)
    {
        if(strcmp(complete, tache[i].status)==0)
        {
            longeure++;
        }
    }
    for(i =0 ; i < cont ; i++)
    {
        if(strcmp(incomplete, tache[i].status)==0)
        {
            longeure2++;
        }
    }
 printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches complete : %d           \n",longeure);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches incomplete : %d           \n",longeure2);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
}





int main()
{


    do
    {
        printf("\n\n\t\t\t\t**************** liste de services: ****************\n");
        printf("\t\t\t\t\t  -------------------------------------------\n ");
        printf("\t\t\t\t\t | 1 --> Ajouter nouvelles taches            |\n ");
        printf("\t\t\t\t\t | 2 --> Afficher la liste d\'taches         |\n ");
        printf("\t\t\t\t\t | 3 --> Modifier une tache                 |\n ");
        printf("\t\t\t\t\t | 4 --> Rechercher les taches              |\n ");
        printf("\t\t\t\t\t | 5 --> Supprimer une tache                |\n ");
        printf("\t\t\t\t\t | 6 --> Statistiques                       |\n ");
        printf("\t\t\t\t\t  ------------------------------------------\n ");
        printf("\n\n \t\t--------> entrez le numero de service  :    ");
        scanf("%d",&numeroservice);
        system("cls");
        switch(numeroservice)
        {
        case 1 :
            Ajouter_taches();
            break;

        case 2 :
            Afficher_liste();
            break;
        case 3 :
            Modifier_tache ();
            break;

        case 4 :
            Rechercher_taches();
            break;

        case 5 :
            Supprimer_tache();
            break;

        case 6 :
            Statistiques();
            break;


        default :
            printf("\n\n \t\t -->>>>!!le numero service n\'existe pas ! <<---\n\n\n\n");


        }

    }
    while(numeroservice !=0 && numeroservice <=10);

    return 0;
}
