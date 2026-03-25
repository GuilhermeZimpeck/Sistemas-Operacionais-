#include <stdio.h>
#define MAX 100

int main(int argc, char * argv[])
{
    int i = 0;
    char ch;
    FILE *file[MAX];
 
    while(i != argc-1)
    {
        file[i] = fopen(argv[i+1],"r");
        
        if(file[i] == NULL){    //se o arquivo não existe = erro 
            printf("wcat: cannot open file");
            printf("\n");
            return 1;
        }

        while((ch = fgetc(file[i])) != EOF) //le todos arquivos passados
        {
            printf("%c", ch);
        }
        fclose(file[i]);        //fecha o arquivo que foi aberto
        i++;
    }
    
    return 0;
}
