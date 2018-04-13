#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int copy_file(char *old_filename, char  *new_filename){
  FILE  *ptr_old, *ptr_new;
  errno_t err = 0, err1 = 0;
  int  a;

  err = fopen_s(&ptr_old, old_filename, "rb");
  err1 = fopen_s(&ptr_new, new_filename, "wb");

  if(err != 0)
    return  -1;

  if(err1 != 0)
  {
    fclose(ptr_old);
    return  -1;
  }

  while(1)
  {
    a  =  fgetc(ptr_old);

    if(!feof(ptr_old))
      fputc(a, ptr_new);
    else
      break;
  }

  fclose(ptr_new);
  fclose(ptr_old);
  return  0;
}

int main (int argc, char **argv)
{
  DIR* dir = opendir("C:\\Users\\caio.luzano\\Desktop\\monit\\nxlog1");
  if (dir){
    /* Directory exists. */
    if(copy_file("\\\\TI02951\\conf\\nxlog.conf", "C:\\Users\\caio.luzano\\Desktop\\monit\\nxlog1\\nxlog.conf") == 0)
      printf("Copy Successful\n");
    else
      fprintf(stderr, "Error during copy!");

      closedir(dir);
  }
  else if (ENOENT == errno){
    if(copy_file("\\\\TI02951\\conf\\nxlog.conf", "C:\\Users\\caio.luzano\\Desktop\\monit\\nxlog2\\nxlog.conf") == 0)
      printf("Copy Successful\n");
    else
      fprintf(stderr, "Error during copy!");

    /* Directory does not exist. */
  }
  else{
      printf("não abriu, fodeu\n");
      /* opendir() failed for some other reason. */
  }
  return (0);
}
