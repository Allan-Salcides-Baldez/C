#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdio_ext.h>

FILE *usuariosponteiro;
FILE *assentosponteiro;
FILE *espetaculosponteiro;
FILE *temporariousuarioponteiro;
FILE *temporarioespetaculoponteiro;
FILE *matrizponteiro;
FILE *temporariomatrizponteiro;
//FILE *criaponteiro;

struct Usuarios{
	char login[20];
	char senha[20];
	char tipo; //G = Gerente, B = Bilheteiro
};

typedef struct Usuarios Usuarios;

struct Espetaculos{
	char id[3];
	char titulo[20];
	char direcao[20];
	int duracao; //Duração da Peça (em minutos)
	int faixaetaria;
	char data[8]; //Data da sessão (dd/mm/aa)
	char horario[5]; //Horário da sessão (hh:mm)
};

typedef struct Espetaculos Espetaculos;

struct Assentos{
	char sessao[3]; //ID da sessao
	char fileira;
	char cadeiras[16]; //cada uma das 16 cadeiras da fileira na ordem crescente
};

typedef struct Assentos Assentos;

/*Cada cadeira pode conter os seguintes caracteres:
“X”, “C”, “ “, ou “*”. Onde: X = ocupado pago, C = ocupado cortesia, * = Não liberado para venda e
“.“ = vazio.*/

int main(){

	char matrizteatro[7][16];

	matrizponteiro = fopen("matimprimearq1.txt","w");
					
	if(matrizponteiro == NULL){
		printf("\nErro!\n");
		exit(0);
	}

	for(int w = 0; w < 7; w++){
		for(int t = 0; t < 16; t++){
			matrizteatro[w][t] = '*';
			fprintf(matrizponteiro, "%c", matrizteatro[w][t]);						
		}
		fprintf(matrizponteiro, "\n");
	}
					
	fclose(matrizponteiro);

	matrizponteiro = fopen("matimprimearq1.txt","r");

	if(matrizponteiro == NULL){
		printf("\nErro!\n");
		exit(0);
	}

	assentosponteiro = fopen("assentosmat2.txt","a");

	if(assentosponteiro == NULL){
		printf("\nErro!\n");
		exit(0);
	}

	temporariomatrizponteiro = fopen("tempmat.txt","w");

	if(temporariomatrizponteiro == NULL){
		printf("\nErro!\n");
		exit(0);
	}

	char sessaovar[3];
	char fileiravar[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0'};
	int cont = 0;
	char cadeiravar[16];
	char vet[16];
	char cadeiramat[16];
	char vet1[16];
	//Assentos a;

	//printf("Sessao: ");
	//scanf("%s", sessaovar);
                                     //------------------------------------------------------------------
	/*for(int x = 0; x < 7; x++){     // OBS DEU ERRADO fscanf matriz arquivo fprintf assento arquivo
		printf("Fileira A a G: ");
		scanf(" %c", &fileiravar);
		//__fpurge(stdin);
		fprintf(assentosponteiro, "%s %c ", sessaovar, fileiravar);
		//__fpurge(stdin);
		fscanf(matrizponteiro," %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4], &vet[5], &vet[6], &vet[7], &vet[8], &vet[9], &vet[10], &vet[11], &vet[12], &vet[13], &vet[14], &vet[15]);
		//__fpurge(stdin);
		for(int y = 0; y < 16; y++){
			matrizteatro[x][y] = vet[y];
			fprintf(assentosponteiro, "%c", matrizteatro[x][y]);
			//__fpurge(stdin);					
		}
		fprintf(assentosponteiro, "\n");
		//__fpurge(stdin);
	}*/

	printf("Entre com o ID: ");
	scanf("%s", sessaovar);

	//certo
	while(fscanf(matrizponteiro,"%s", cadeiramat) != EOF){
		//strcpy(cadeiravar, cadeiramat);
		fprintf(assentosponteiro, "%s %c %s\n", sessaovar, fileiravar[cont], cadeiramat);
		cont = cont + 1;
	}	

	//errado
	while(fscanf(matrizponteiro, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", &vet1[0], &vet1[1], &vet1[2], &vet1[3], &vet1[4], &vet1[5], &vet1[6], &vet1[7], &vet1[8], &vet1[9], &vet1[10], &vet1[11], &vet1[12], &vet1[13], &vet1[14], &vet1[15]) != EOF){
		fprintf(temporariomatrizponteiro, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", vet1[0], vet1[1], vet1[2], vet1[3], vet1[4], vet1[5], vet1[6], vet1[7], vet1[8], vet1[9], vet1[10], vet1[11], vet1[12], vet1[13], vet1[14], vet1[15]);
	}	

		
	fclose(assentosponteiro);
	fclose(temporariomatrizponteiro);
	fclose(matrizponteiro);

	//while(fscanf(matrizponteiro,"%s  %c" %s, sessao, Aloop2.senha, &Aloop2.tipo) != EOF){
	//if((strcmp(Apaga.login, Aloop2.login) != 0) && (strcmp(Apaga.senha, Aloop2.senha) != 0)){
}
