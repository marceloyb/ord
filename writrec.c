#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
  char last[30], name[30], address[30], city[30], state[30], zip[30];
  char caracter;
  char file_name[30];
  char buffer[100];
  int tamanho;


  printf ("Nome do arquivo a ser escrito: \n");
  scanf ("%[^\n]", file_name);
  __fpurge(stdin);

  FILE *file = fopen (file_name, "w");

  printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
  gets(last);
  while (strlen(last) > 0){
    buffer[0] = '\0';
    strcat(buffer, last);
    strcat(buffer, "|");
    printf ("\nDigite o nome\n");
    gets (name);
    strcat(buffer, name);
    strcat (buffer, "|");
    printf ("\nDigite o endereco\n");
    gets(address);
    strcat(buffer, address);
    strcat(buffer, "|");
    printf ("\nDigite a cidade\n");
    gets(city);
    strcat(buffer, city);
    strcat (buffer, "|");
    printf ("\nDigite o estado\n");
    gets(state);
    strcat(buffer, state);
    strcat(buffer, "|");
    printf ("\nDigite o CEP\n");
    gets(zip);
    strcat(buffer, zip);
    strcat(buffer, "|");
    tamanho = strlen(buffer);
    fwrite (&tamanho, sizeof(tamanho), 1, file);
    fwrite (buffer, tamanho, 1, file);
    printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
    gets(last);
  }
  fclose (file);


}
