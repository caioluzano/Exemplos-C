#include <stdio.h>
#include <string.h>

static void RemoveAcentos (char *Pal)
{
  unsigned char Carac;
  unsigned char Acentuados[] = " ãõáéíóúàèìòùäëïöüâêîôûçñÃÕÁÉÍÓÚÀÈÌÒÙÄËÏÖÜÂÊÎÔÛÇÑ";
  unsigned char    Caretas[] = " aoaeiouaeiouaeiouaeioucnAOAEIOUAEIOUAEIOUAEIOUCN";
  long i, l, j, x;

  i = 0;
  l = strlen(Pal);

  while (i<l)
  {
    Carac = Pal[i];
    for (x=0; x<strlen(Acentuados); x++)
      if (Carac == Acentuados[x])
      {
        j = x;
        break;
      }
      else j = 0;
      if (j) Pal[i] = Caretas[j];
      if (Pal[i] < ' ' || Pal[i] > 126) Pal[i] = 0x20;
      i++ ;
  }
}

int main (void)
{
  char buffer [32];

  strcpy (buffer, "açúcar união");
  printf ("Antes: <%s>\n", buffer);

  RemoveAcentos (buffer);
  printf ("Depois: <%s>\n", buffer);

  system ("pause");
  return (0);
}
