#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "teste.h"


void findCod(char *path, char COD_REDE[8]){
  int i, j;
  long size = strlen(path);
  for(i=0; i<size; i++){
    if (path[i] == '.' && isdigit(path[i+1]) && isdigit(path[i+2]) && isdigit(path[i+3])) {
      i++;
      for(j=0; i<size; j++){
        COD_REDE[j] = path[i];
        i++;
      }
    }
  }
}

int main (int argc, char **argv)
{
  int i;
  long lSize;
  FILE *pFile;
  FILE *pOut;
  T_REGISTRO registro;
  char COD_REDE[8];

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  //argv[1]="C:\\Users\\caio.luzano\\Desktop\\monit\\monit\\arquivos\\comunicacao.005";

  /*if (argc <= 1){
    printf("ERRO: Necessario executar por linha de comando e passar um arquivo para \nprocessamento.\n");
    printf("Exemplo: 'openDRVCOM.exe Comunicacao.XXX'\n");
    system("pause");
    return 0;
  } */

  findCod(argv[1], COD_REDE);

  pFile = fopen (argv[1], "rb");
  pOut = fopen ("ComunicacaoFMT.CSV", "a+");

  if (pFile == NULL){
    printf ("Falha ao abrir arquivo de entrada!\n");
    return 1;
  }else if(pOut == NULL){
    printf ("Falha ao abrir arquivo de saida!\n");
    return 1;
  }

  fseek (pFile, 0, SEEK_END);
  fseek (pOut, 0, SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);
  rewind (pOut);

  memset (&registro, 0x00, sizeof (registro));
  fread (&registro, sizeof (char), lSize, pFile);

  for (i = 0; i < registro.Comunicacao.QtdeCanaisTotal; i++)
  {

    fprintf(pOut, "%d%02d%d;%d;%s;;%s;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, registro.Comunicacao.HorarioAmostragem, "010", COD_REDE, registro.Comunicacao.IdentificacaoAutorizador, registro.Canal[i].IdentificacaoCanal, registro.Canal[i].EstadoConexao, registro.Canal[i].HorarioUltimaConexao, registro.Canal[i].HorarioUltimaQueda, registro.Canal[i].QtdeQuedas, registro.Canal[i].QtdeTx, registro.Canal[i].HorarioUltimoTx, registro.Canal[i].QtdeRx, registro.Canal[i].HorarioUltimoRx);

  }

  fclose (pFile);
  fclose (pOut);
  return 0;
}
