#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) { 
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) { 

        FILE *arquivo = fopen(argv[i], "r");

        if (arquivo == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        int contador;
        char c;

        while (fread(&contador, sizeof(int), 1, arquivo) == 1) {

            fread(&c, sizeof(char), 1, arquivo);

            for (int j = 0; j < contador; j++) {
                printf("%c", c);
            }
        }

        fclose(arquivo);
    }

    return 0;
}
