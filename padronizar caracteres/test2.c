#include <stdio.h>

int main(int argc, char* argv[] ){

	printf("%d",argc);

	FILE *fp;

	fp= fopen(argv[1],"w");
	fclose(fp);	
	printf("%sTESTE\n", argv[1]);
}