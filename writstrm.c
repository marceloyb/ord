#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIM_STR "|"

int main() {
    char first[30], last[30], address[30], city[20], state[15], zip[9];
    char filename[15];
    FILE* fd;

    printf("Entre com o nome do arquivo a ser criado: ");
    gets(filename);

    if ((fd = fopen(filename,"w")) == NULL) {
        printf("Erro na cria��o do arquivo --- programa abortado\n");
        exit(1);
    }

    printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
    gets(last);

    while(strlen(last) > 0) {
        printf("\nPrimeiro nome\n>>>");
        gets(first);
        printf("\nEndereco\n>>>");
        gets(address);
        printf("\nCidade\n>>>");
        gets(city);
        printf("\nEstado\n>>>");
        gets(state);
        printf("\nCEP\n>>>");
        gets(zip);

        /* envia strings para arquivo */
        fputs(last, fd);
        fputs(DELIM_STR, fd);
        fputs(first, fd);
        fputs(DELIM_STR, fd);
        fputs(address, fd);
        fputs(DELIM_STR, fd);
        fputs(city, fd);
        fputs(DELIM_STR, fd);
        fputs(state, fd);
        fputs(DELIM_STR, fd);
        fputs(zip, fd);
        fputs(DELIM_STR, fd);

        /* come�a a pr�xima entrada */
        printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
        gets(last);
    }

    /* fechar o arquivo */
    fclose(fd);
}
