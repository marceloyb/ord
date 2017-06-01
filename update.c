#include <stdio.h>
#include <string.h>

void zerabuffer(char buffer[]){
  int i;
  for (i = 0; i < 64; i++){
    buffer[i] = '\0';
  }
}

void cabecalho(){
  printf ("\n Insira a opcao desejada:\n(1) Inserir novo registro\n(2) Alterar um registro existente\n(3) Sair\n");
}

void writerec(FILE *file, char buffer[]){
  char last[30], name[30], address[30], city[30], state[30], zip[30];
  int tamanho;
  // colocar um seek aqui para ir até o final do arquivo
  // fseek (file, ndereg*64+4, SEEK_SET);
  printf("\n\nDigite o Sobrenome, ou <ENTER> para sair\n>>>");
  gets(last);
  while (strlen(last) > 0){
    zerabuffer(buffer);
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
}

int get_rec (FILE *file, char buffer[]){
  int i;
  if(fread(&i, 4, 1, file) == 0)
    return 0;
  fread(buffer, i, 1, file);
  buffer[i] = '\0';
  return i;
}

int main (){

  char buffer[65], file_name[30];
  char *field;
  int reg_cont = 0, opcao;
  printf ("Nome do arquivo: \n");
  scanf ("%[^\n]", file_name);
  __fpurge(stdin);

  FILE *file = fopen (file_name, "r+");
  if (file == NULL){
    FILE *file = fopen (file_name, "w+");
    fwrite (&reg_cont, sizeof(int), 1, file);
  }
  else{
    fread(&reg_cont, sizeof(int), 1, file);
  }

  cabecalho();
  scanf ("%i", &opcao);
  __fpurge(stdin);
  while(opcao != 3){
    switch(opcao){
      case(1):{
        writerec(file, buffer);
      }
      case(2):{
        //find&write
      }
    }
    cabecalho();
    scanf ("%i", &opcao);
    __fpurge(stdin);
  }
  fclose(file);
}
