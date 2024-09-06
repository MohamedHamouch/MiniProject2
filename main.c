#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char titre[10][20], auteur[10][20];
    int prix[10],stock[10];
    int i,j,l=200,t=0,choix,total=0,indice,nlivre=0,pos;
    char srchl[10];

    do{
        //aficher de menu
        printf("\n------------- MENU -------------\n");
        printf("Pour ajouter un livre .......................... tapez 1.\n");
        printf("Pour afficher tours les livres ................. tapez 2.\n");
        printf("Pour rechercher un livre par son titre ......... tapez 3.\n");
        printf("Pour mettre a jour la quantite d'un livre ...... tapez 4.\n");
        printf("Pour supprimer un livre du stock ............... tapez 5.\n");
        printf("Pour afficher le nombre total de livres en stock tapez 6.\n");
        printf("Pour terminer le programme ..................... tapez 0.\n");

        //recevoir le choix
        printf("Votre choix : ");
        scanf("%d",&choix);

        //traitement de choix
        switch (choix)
        {

        case 0://terminer
            printf("Programme terminer\nAu revoir.");
            break;

        case 1://ajouter
            fflush(stdin);
            printf("saisissez le titre :");
            gets(titre[nlivre]);

            printf("saisissez l'auteur :");
            gets(auteur[nlivre]);

            printf("saisissez le prix :");
            scanf("%d",&prix[nlivre]);

            printf("saisissez le la quantite :");
            scanf("%d",&stock[nlivre]);

            nlivre=nlivre+1;

            break;

        case 2://afficher

            if(nlivre==0)
            {
                printf("\nAucune livre trouver :(\n");
            }
            else
            {
                printf("----- La liste de tout les livres -----\n");
                for(i=0; i<nlivre; i++)
                {
                    printf("******||Livre n'%d||******\n",i+1);
                    printf("Titre : %s\n",titre[i]);
                    printf("Auteur : %s\n",auteur[i]);
                    printf("Prix :% dDH\n",prix[i]);
                    printf("Quantite en stock : %d\n",stock[i]);
                }
            }
            break;

        case 3://rechercher

            printf("saisissez le titre a rechercher :\n");
            //fflush(stdin);
            gets(srchl);
            gets(srchl);
            indice=0;

            for (i=0; i<=nlivre; i++)
            {
                 if (strcmp(titre[i],srchl)==0)
                {
                    t++;
                    indice = 1;
                }
                }


            if(indice==0){
                printf("\nAucune livre trouvez");
            }else
            {
             printf("\nle titre existe %d fois.",t);
            }
                if(t>=2){
                        do{
                    printf("\ncombien de version de \"%s\" vous voulez afficher",srchl);
                    scanf("%d",&l);
                    if(l>t){
                    printf("\nimpossibe, il ya moin de %d de \"%s\" ",l,srchl);


                    }

                }while(l>t);

                int k=0;
            while(l!=0){
                for(i=k;i<nlivre;i++)
                if (strcmp(titre[i],srchl)==0)
                {
                    printf("---------------------");
                    printf("Titre : %s\n",titre[i]);
                    printf("Auteur : %s\n",auteur[i]);
                    printf("Prix :%d dDH\n",prix[i]);
                    printf("Quantite en stock : %d\n",stock[i]);
                    k=i+1;
                    break;
                }
            l--;
            }


            break;

        case 4://Modifier

            printf("saisissez le titre du livre pour modifier la quantit  :\n");
            //fflush(stdin);
            gets(srchl);
            gets(srchl);
            indice=0;
            for (i=0; i<nlivre; i++)
            {
                if(strcmp(srchl,titre[i])==0)
                {
                    indice = 1;
                    break;
                }
            }
            if(indice==0)
            {
                printf("Aucune livre trouvez");
            }
            else
            {
                printf("votre liver existe \n");
                printf("Il ya %d en stock. \n",stock[i]);
                printf("Donnez la nouvelle quantite en stock :");
                scanf("%d",&stock[i]);
            }
            break;

        case 5:
            //supprimer de livre
            printf("saisissez le titre du livre a supprimer :\n");
            //fflush(stdin);
            gets(srchl);
            gets(srchl);
            indice=0;
            for (i=0; i<nlivre; i++)
            {
                if(strcmp(srchl,titre[i])==0)
                {
                    indice = 1;
                    pos=i;
                    break;
                }
            }
            if(indice==0)
            {
                printf("Aucune livre trouvez :(");
            }
            else
            {
                for(j=pos; j<nlivre; j++)
                {
                    // titre[j]=titre[j+1];
                    strcpy(titre[j],titre[j+1]);
                    strcpy(auteur[j],auteur[j+1]);

                    prix[j]=prix[j+1];
                    stock[j]=stock[j+1];
                }
                nlivre=nlivre-1;
                printf("\nLivre supprime avec succes :)");
            }
            indice=0;
            break;

        case 6:
            for(j=0; j<nlivre; j++)
            {
                total+=stock[j];
            }
            printf("\nLe nombre total des livers en stock est : %d",total);
            break;

        default :   printf("Choix IMPOSSIBLE !!"); break;

        }
   } }while (choix !=0);

    return 0;
}
