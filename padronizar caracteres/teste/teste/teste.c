#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int AK_fprintf (FILE *fp, char* format, ...)
{
  char buf [5000];
  int size;
  va_list arglist;

  memset (buf, 0x00, sizeof (buf));

  if (format == NULL || fp == NULL)
    return (0);

  va_start (arglist, format);
  vsprintf (buf, format, arglist);

  size = fwrite (buf, strlen (buf), sizeof (char), fp);
  va_end (arglist);

  return (size);
}

int main (int argc, char **argv)
{
  int i;
  FILE *fp;

  fp = fopen ("saida.txt", "w+");
  AK_fprintf (fp, "Comecou!\n");

  for (i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
    AK_fprintf (fp, argv[i]);
    AK_fprintf (fp, "\n");
  }

  AK_fprintf (fp, "Acabou!\n");
  fclose (fp);
}
