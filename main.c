#include <stdio.h>
#include <stdbool.h>

//struct account
struct compte {
	int id;
	char cin[10];
	char nom[20];
	char prenom[20];
	float montant;
};


//function Clean
void cleanCls(){
	system("cls||clear");
}

//fonction
bool addAccount(){
	struct compte c;
	printf("Entrer le CIN : ");
	scanf("%s", c.cin);
	
	printf("Entrer le nom : ");
	scanf("%s", c.nom);
	
	printf("Entrer le prenom : ");
	scanf("%s", c.prenom);
	
	printf("Entrer le montant : ");
	scanf("%f", &c.montant);
	
	FILE *file;
	file = fopen("./db.txt", "a");
	fprintf(file, "%s %s %s %f \n", c.cin, c.nom, c.prenom, c.montant);
	//fgets(data, 50, file);
	//printf("%s", data);
	char str1[20], str2[20], str3[20];
	float montant;
	fscanf(file, "%s %s %s %f", str1, str2, str3, &montant);
	fclose(file);
	printf("Montant : ", montant);
	return true;
} 
int main(){
	int choix;
	char data[50];
	

	
	
	do {
		
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
			cleanCls();
				addAccount();
				break;
			case 2 : 
				printf("Votre choix est 2");
				break;
			case 3 : 
				printf("Votre choix est 3");
				break;
			case 4 : 
				printf("Votre choix est 4");
				break;
			case 5 : 
				printf("Votre choix est 5");
				break;
			case 6 : 
				cleanCls();
				break;
		}
		
		
	} while(choix != 0);
	
	
	return 0;
}
