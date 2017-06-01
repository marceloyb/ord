#include <stdio.h>
#include <stdlib.h>

int readfield (FILE* arquivo, char campo[]){
  int i = 0;
  char caracter;
  caracter = getc (arquivo);
  while (caracter != EOF && caracter != '|'){
    campo[i] = caracter;
    i++;
    caracter = getc (arquivo);
  }
  campo[i] = '\0';
  return i;
}

int main(){
  char file_name[30];
  char str[30];
  int field_count = 0, field_length;

  printf ("\nNome do arquivo a ser lido: ");
  scanf ("%[^\n]", file_name);

  FILE *file = fopen(file_name, "r");

  if (!file){  // arquivo invalido
    printf ("\nNome do arquivo invalido\n");
    exit(1);
  }

  field_length = readfield(file, str);
  while (field_length > 0){
    field_count++;
    printf ("\n %d %s", field_count, str);
    field_length = readfield(file, str);
  }

  fclose (file);
}
