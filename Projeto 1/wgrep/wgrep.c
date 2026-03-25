#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *arquivo;
    char linha[9999];
    char *palavra;
    int i = 0;

    palavra = argv[1];  //palavra passada para a busca

    if(argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");  //se apenas o programa for executo, sem passar arquivos ou a palavra de busca, retornando um ERRO
        exit(1);
    }
    if(argc == 2)
    {
        while(fgets(linha, sizeof(linha), stdin) != NULL)
        {
            if(strstr(linha, palavra) != NULL)  //se apenas for passado o programa e a palavra de busca, é printado o conteudo do stdin
            {
                printf("%s", linha);
            }
        }
        return 0;
    }
    
    while (i < argc - 2)
    {
        arquivo = fopen(argv[i + 2], "r");

        if (arquivo == NULL)
        {
            printf("wgrep: cannot open file\n");  //se o arquivo não existir retornara um ERRO
            exit(1);
        }

        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            if (strstr(linha, palavra) != NULL)
            {
                printf("%s", linha);  //exibe as linhas que contem a palavra passada por linha de comando
            }
        }

        fclose(arquivo);
        i++;
    }

    return 0;
}
