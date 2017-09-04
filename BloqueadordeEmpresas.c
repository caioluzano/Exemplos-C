#include <stdio.h> 
#include <stdlib.h>
#include "dirent.h"
#include <string.h>

int main(void)
{
	FILE *TodosFMT;

	int  Nlinha = 0;
	int  Nantigonome = 0;
	int  qtdE = 0;
	int  first = 1;
	char antigonome[8 + 1] = " ";
	char linha[10];
	char novonome[16 + 1] = " ";
	char prefixo[4 + 1] = "bkp.\0";
	char sufixo[4 + 1] = ".cnf";

	memset(antigonome, 0, sizeof(antigonome));
	memset(linha, 0, sizeof(linha));
	memset(novonome, 0, sizeof(novonome));

	if ((TodosFMT = fopen("EmpresasRaizen.txt", "r")) == NULL){
		printf("ERRO:Nao foi possivel abrir o arquivo EmpresasBloqueadas.txt\n\n");
		system("pause");
		exit(1);
		return(0);
	}


	fgets(linha, 80, TodosFMT);

	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d)
	{
		printf("Procurando empresas cadastradas...\n\n");
		while ((dir = readdir(d)) != NULL)
		{
			memset(antigonome, 0, sizeof(antigonome));

			memset(novonome, 0, sizeof(novonome));

			memcpy(antigonome, dir->d_name, 8);

			Nlinha = atoi(linha);

			Nantigonome = atoi((const char*)antigonome);

			while (Nantigonome > Nlinha){
				if (fgets(linha, 80, TodosFMT) == NULL){
					break;
				}
				Nlinha = atoi(linha);
			}

			if (Nantigonome == Nlinha){	

				memcpy(novonome,prefixo,4);
				strcat(novonome, antigonome);
				strcat(novonome, sufixo);
				
				if (rename(dir->d_name, novonome)) {
					printf("\nERRO: ao renomear o Arquivo!\n");
					printf("%s\n\n", dir->d_name);
				}
				else{
					qtdE++;
				}
			}
			else{
				if (first == 1){
					printf("Empresas na pasta nao renomeadas: \n");
					first = 0;
				}
				if (strstr(dir->d_name, ".cnf")){

					    printf("%s                          \n", dir->d_name);

				}
			}
		}
		closedir(d);
		printf("\nFinalizado com sucesso!\n\n");
	}
	printf("Quantidade de empresas renomeadas: %d\n \n", qtdE);
	qtdE = 0;
	system("pause");
	exit(1);
	return(0);
}