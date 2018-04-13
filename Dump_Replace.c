#include <stdio.h>
#include <string.h>

#define SE_MAX(A,B) (((A)>(B))?(A):(B))
#define SE_MIN(A,B) (((A)<(B))?(A):(B))

static void Dump (char *buffer, short tam)
{
  int i, j;
  char *p;
  char linha [80];
  char val [3];

  p = buffer;

  while ((p - buffer) < tam)
  {
    memset (linha, ' ', 80);
    linha [79] = 0;
    linha [23] = '-';
    i = (int)(tam - (p - buffer));
    for (j = 0; j <  SE_MIN(16, i); j++)
    {
      sprintf (val, "%02x", (unsigned char) *p);
      memcpy (&linha [3*j], val, 2);
      if ((*p >= 32) && (*p <= 125))
        linha [j + 60] = *p;
      else
        linha [j + 60] = '.';
      p++;
    }
    fprintf (stderr, "%s\n", linha);
  }
}

void ReplaceChrStr (char *buffer, int tam_buffer, char old_chr, char new_chr)
{
  int i;
  char *ptr = buffer;

  for (i = 0; i < tam_buffer; i++)
  {
    if (*ptr == old_chr)
      *ptr = new_chr;

    ptr++;
  }
}

int main (void)
{
  FILE *pFile;
  char buffer [100];

  memset (buffer, 0x00, sizeof (buffer));

  if ((pFile = fopen ("ListaIFs.txt", "r")) == NULL)
  {
    printf ("Falha na abertura do arquivo!\n");
    return 1;
  }

  if (fgets (buffer, sizeof (buffer), pFile) != NULL)
  {
    printf ("\nbuffer antes: \n");
    Dump (buffer, sizeof (buffer));

    ReplaceChrStr (buffer, sizeof (buffer), 0x0A, 0x00);

    printf ("\nbuffer depois: \n");
    Dump (buffer, sizeof (buffer));
  }

  fclose (pFile);
  system ("pause");

  return 0;
}
