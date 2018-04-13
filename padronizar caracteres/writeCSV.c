#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


int main (int argc, char **argv)
{
  int i = 1;
  long lSize;
  FILE *pOut;
  char COD_REDE[8];

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);


  pOut = fopen ("ComunicacaoFMT.CSV", "w+");

  if (pOut == NULL){
    printf ("Falha ao abrir arquivo de entrada!\n");
    return 1;
  }

  fseek (pOut, 0, SEEK_END);
  lSize = ftell (pOut);
  rewind (pOut);

  //fprintf(pOut, "%d%02d%d;%d;%s;;%s;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, registro.Comunicacao.HorarioAmostragem, "010", COD_REDE, registro.Comunicacao.IdentificacaoAutorizador, registro.Canal[i].IdentificacaoCanal, registro.Canal[i].EstadoConexao, registro.Canal[i].HorarioUltimaConexao, registro.Canal[i].HorarioUltimaQueda, registro.Canal[i].QtdeQuedas, registro.Canal[i].QtdeTx, registro.Canal[i].HorarioUltimoTx, registro.Canal[i].QtdeRx, registro.Canal[i].HorarioUltimoRx);
  fprintf(pOut, "20180327;1521860399;010;;003;Rede;192.168.53.151:22027;0;1521830101;1521830075;%d;0;0;0;0\n", i);
  i = i + 1;
  system("pause");  
  fseek (pOut, 0, SEEK_END);
  fprintf(pOut, "20180327;1521860399;010;;003;Rede;192.168.53.151:22027;0;1521830101;1521830075;%d;0;0;0;0\n", i);
  i = i + 1;
  system("pause");  
  fseek (pOut, 0, SEEK_END);
  fprintf(pOut, "20180327;1521860399;010;;003;Rede;192.168.53.151:22027;0;1521830101;1521830075;%d;0;0;0;0\n", i);
  i = i + 1;
  system("pause");  
  fseek (pOut, 0, SEEK_END);
  fprintf(pOut, "20180327;1521860399;010;;003;Rede;192.168.53.151:22027;0;1521830101;1521830075;%d;0;0;0;0\n", i);
  i = i + 1;
  system("pause");
  

  fclose (pOut);
  return 0;
}
