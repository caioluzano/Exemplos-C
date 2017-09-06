#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "se_path.h"

#define prefixo "bkp.\0"
#define sufixo  ".cnf\0"

int main(int argc, char *argv[]){

	FILE *Empresas, *logErros;

	int  qtdE = 0;
	int  first = 1;
	char linha[12 + 1];
	char nArq[40 + 1];
	char Flinha[12 + 1];
	char novonome[16 + 1];

	memset(linha, 0, sizeof(linha));
	memset(Flinha, 0, sizeof(Flinha));
	memset(nArq, 0, sizeof(nArq));
	memset(novonome, 0, sizeof(novonome));

	if (argc <= 1){
		printf("ERRO: Necessario executar por linha de comando e passar um arquivo para \nprocessamento.\n");
		printf("Exemplo: 'RenomearEmpresas.exe EmpresasRaizen.txt'\n");
		system("pause");
		return(0);
	} 
	else{

		memcpy(nArq, argv[1], 40);

		if ((Empresas = fopen(nArq, "r")) == NULL){
			printf("ERRO:Nao foi possivel abrir o arquivo %s\n\n", nArq);
			return(0);
		}
		if ((logErros = fopen("logdeERROS.txt", "w")) == NULL){
			printf("ERRO:Nao foi possivel abrir o arquivo logdeERROS.txt\n\n");
			return(0);
		}
	}
	
	printf("Procurando empresas cadastradas...\n\n");
		
	while (!feof(Empresas)){

		memset(novonome, 0, sizeof(novonome));

		memset(Flinha, 0, sizeof(Flinha));

		fgets(linha, sizeof(linha), Empresas);

		if ((strlen(linha) < 9) || (strlen(linha) > 9)){
			printf("\nERROR: Linha invalida - %s\n", linha);
			fprintf(logErros,"\nERROR: Linha invalida - %s\n", linha);
			first = 1;
			continue;
		}

		memcpy(Flinha, linha, 8);

		if (SE_PathExist(strcat(Flinha, sufixo))){

			memcpy(novonome, prefixo, 4);
			strcat(novonome, Flinha);

			if (rename(Flinha, novonome)) {
				printf("\nERRO: ao renomear o Arquivo!\n");
				printf("%s\n\n", Flinha);
				fprintf(logErros, "\nERRO: ao renomear o Arquivo!\n");
				fprintf(logErros, "%s\n\n", Flinha);
			}
			else{
				qtdE++;
			}
		}
		else{
			if (first == 1){
				printf("Empresas no arquivo que nao estao na pasta: \n\n");
				fprintf(logErros, "Empresas no arquivo que nao estao na pasta: \n\n");
				first = 0;
			}
			printf("%s \n", Flinha);
			fprintf(logErros, "%s \n", Flinha);
		}
	}
	printf("\nFinalizado com sucesso!\n\n");
	printf("Quantidade de empresas renomeadas: %d\n \n", qtdE);
	qtdE = 0;
	fclose(Empresas);
	fclose(logErros);
	return(0);
}