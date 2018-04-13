#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main(int argc, char **argv){
    setlocale(LC_CTYPE, "");
    FILE *f = fopen(argv[1], "r+");
    FILE *facada = fopen("C:\\Program Files (x86)\\nxlog\\conf\\saida.txt", "w");
    if (!f)
        return 1;

    for (wchar_t c; (c = fgetwc(f)) != WEOF;){
        switch (c) {
            case L'à': c=L'a'; break;
            case L'á': c=L'a'; break;
            case L'ã': c=L'a'; break;
            case L'ä': c=L'a'; break;
            case L'â': c=L'a'; break;
            case L'À': c=L'A'; break;
            case L'Á': c=L'A'; break;
            case L'Ã': c=L'A'; break;
            case L'Ä': c=L'A'; break;
            case L'Â': c=L'A'; break;
            case L'è': c=L'e'; break;
            case L'é': c=L'e'; break;
            case L'ë': c=L'e'; break;
            case L'ê': c=L'e'; break;
            case L'È': c=L'E'; break;
            case L'É': c=L'E'; break;
            case L'Ë': c=L'E'; break;
            case L'Ê': c=L'E'; break;
            case L'ì': c=L'i'; break;
            case L'í': c=L'i'; break;
            case L'ï': c=L'i'; break;
            case L'î': c=L'i'; break;
            case L'Ì': c=L'I'; break;
            case L'Í': c=L'I'; break;
            case L'Ï': c=L'I'; break;
            case L'Î': c=L'I'; break;
            case L'ò': c=L'o'; break;
            case L'ó': c=L'o'; break;
            case L'ô': c=L'o'; break;
            case L'õ': c=L'o'; break;
            case L'ö': c=L'o'; break;
            case L'Ò': c=L'O'; break;
            case L'Ó': c=L'O'; break;
            case L'Ô': c=L'O'; break;
            case L'Õ': c=L'O'; break;
            case L'Ö': c=L'O'; break;
            case L'ù': c=L'u'; break;
            case L'ú': c=L'u'; break;
            case L'ü': c=L'u'; break;
            case L'û': c=L'u'; break;
            case L'Ù': c=L'U'; break;
            case L'Ú': c=L'U'; break;
            case L'Ü': c=L'U'; break;
            case L'Û': c=L'U'; break;
            case L'ç': c=L'c'; break;
            case L'ñ': c=L'n'; break;
            case L'Ç': c=L'C'; break;
            case L'Ñ': c=L'N'; break;
            default:     break;
        }
        wprintf(L"%lc", c);
        fputwc(c, facada);
    }

    fclose(f);
    return 0;
}