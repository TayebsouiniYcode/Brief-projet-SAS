#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct compte{ char cin[10]; char nom[20]; char prenom[20]; float montant;};

struct compte c[1000];
int nbrAccount = 0;

void cleanCls(){system("cls||clear");}

bool addAccount(int n){
	int i;
	//if (n==0) n = 1;

	for (i = 0 ; i < n; i++){
		printf("Entrer le CIN : ");
		scanf("%s", c[nbrAccount].cin);
		
		printf("Entrer le nom : ");
		scanf("%s", c[nbrAccount].nom);
		
		printf("Entrer le prenom : ");
		scanf("%s", c[nbrAccount].prenom);
		
		printf("Entrer le montant : ");
		scanf("%f", &c[nbrAccount].montant);
		nbrAccount++;
		
		cleanCls();
		
		printf("\n \n \n Compte ajouter avec succes \n \n \n");
	}
	
} 

//fonction operationS
bool operations(){
	int _choix, i;
	char cin[10];
	float operationValue;
	
	printf("Entrer le CIN du compte : ");
	scanf("%s", cin);

	
	do {
		cleanCls();
		
		printf("\n\n\n\n\n\n");
		printf("\t \t \t 1. Depot \n \n \n");
		printf("\t \t \t 2. Retrait \n \n \n");
		printf("\t \t \t 00. Menu principale \n");
		printf("Entrer un choix : ");
		scanf("%d", &_choix);
		
		switch (_choix) {
			case 1 : 
				cleanCls();
					for(i = 0; i < nbrAccount; i++) {
						if (strcmp(cin, c[i].cin) == 0) {
							printf("Entrer la valeur de depot : ");
							scanf("%f", &operationValue);
							c[i].montant += operationValue;
							
							printf("Le montant est : %g", c[i].montant);
						}
					}
				break;
			case 2 : 
				cleanCls();
				for(i = 0; i < nbrAccount; i++) {
						if (strcmp(cin, c[i].cin) == 0) {
							printf("Entrer la valeur de retrait : ");
							scanf("%f", &operationValue);
							if (c[i].montant >= operationValue)
								c[i].montant -= operationValue;
							else 
								printf("Votre solde est inferieur à %g \n", operationValue);
							
							printf("Le montant est : %g \n \n \n", c[i].montant);
						}
					}
				break;
			default : printf("Votre choix n exist pas \n");
		}
	}while (_choix != 0);
	cleanCls();
}
bool getCIN() {
	int i;
	char cin[10];
	bool Trouve = false;
		printf("Entrer le CIN : ");
		scanf("%s", cin);
		for (i = 0; i < nbrAccount ; i++) {
			if(strcmp(c[i].cin, cin) == 0){
				Trouve = true;
			}
		}
		if (Trouve) {
			printf("CIN Trouve \n");
		} else {
			printf("CIN non trouve \n");
		}
}

void affichage() {
	cleanCls();
	struct compte tempCompte;
	int _choix, __choix;
	int i, j;
	char cin[10];
	do {
		printf("\t \t \t 1. tri par nom  \n \n \n");
		printf("\t \t \t 2. tri par montant \n \n \n");
		printf("\t \t \t 3. Recherche par CIN \n \n \n");
		printf("\t \t \t 00. Menu principale \n \n \n");
		printf("Entrer votre choix : ");
		scanf("%d", &_choix);
		
		switch (_choix) {
			case 1 : 
				printf("\t \t \t 1. ASC \n \n \n");
				printf("\t \t \t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &__choix);
				switch (__choix) {
					case 1 : 
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        if(strcmp(c[j].prenom, c[j+1].prenom) > 0)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
					case 2 :
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        //if(c[j].montant > c[j+1].montant)
						        if(strcmp(c[j].prenom, c[j+1].prenom) < 0)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
				}
				break;
			case 2 : 
				printf("\t \t \t 1. ASC \n \n \n");
				printf("\t \t \t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &__choix);
				switch (__choix) {
					case 1 :
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        if(c[j].montant > c[j+1].montant)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
					case 2 : 
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        if(c[j].montant < c[j+1].montant)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
				}

				break;
				case 3 :
						getCIN();
						break;
		}

	}while (_choix != 0);
}

bool fedilisation() {
	// Tri 
	int i, j;
	struct compte tempCompte;
	for(i = 0 ; i < nbrAccount ; i++)
	{
	    for(j = 0 ; j < nbrAccount-i-1 ; j++)
	    {
	        if(c[j].montant < c[j+1].montant)
	        {
	        	tempCompte = c[j+1];
	            c[j+1]=c[j];
	            c[j]=tempCompte;
	        }
	    }
	}
	//top 3
	for (i = 0 ; i < 3 ; i++) {
		c[i].montant += (c[i].montant * 1.3) / 100;
	}
	
	cleanCls();
	printf("Les trois premier compte a ajouter 1.3 %s avec succes", "%");
}

void getAccount() {
	int i;
	
	printf("NOM \t | PRENOM \t | CIN \t | MONTANT |");
	
	for(i = 0; i < nbrAccount; i++) {
		printf("%s \t %s \t %s \t %f", c[i].nom, c[i].prenom, c[i].cin, c[i].montant);
	}
}


//charge array to file;
/*
void setArrayToFile(struct compte _c) {
	FILE *file;
	file = fopen("db.txt", "w");
	fprintf(file, "%s;%s;%s;%f,", _c.cin, _c.nom, _c.prenom, _c.montant);
	fclose(file);
}
*/
int main(){
	int choix, nbrNewAccount, i;
	char cin[10];

	do {
		//cleanCls();
		
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t 1. Introduire un compte \n\n\n");
		printf("\t\t\t\t 2. Introduire plusieurs comptes \n\n\n");
		printf("\t\t\t\t 3. Operations \n\n\n");
		printf("\t\t\t\t 4. Consultation \n\n\n");
		printf("\t\t\t\t 5. Fidelisation \n\n\n");
		printf("\t\t\t\t 0. Quitter \n\n\n");
		
		printf("Entrer votre choix : ");
		scanf("%d", &choix);
		
		switch (choix) {
			case 1 : 
				addAccount(1);
				break;
			case 2 :
				printf("Entrer le nombre des comptes que vous voulez cree : ");
				scanf("%d", &nbrNewAccount);
				addAccount(nbrNewAccount);
				break;
			case 3 :
				operations();
				break;
			case 4 : 
				affichage();
				break;
			case 5 : 
				fedilisation();
				break;
			case 6 : 
				getAccount();
				break;
			case 7 :
				printf("les comptes : %d", nbrAccount);
				break;
		}
			
	} while(choix != 0);
	
	/*
	for (i = 0 ; i < nbrAccount ; i++) {
		setArrayToFile(c[i]);
	}
	*/
	
	FILE *file;
	file = fopen("db.txt", "w");
	for(i = 0; i < nbrAccount; i++){
		fprintf(file, "%s;%s;%s;%f,", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
	}
	
	fclose(file);
	return 0;
}
