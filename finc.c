#include <stdio.h>
#include <string.h>

int get_rec (FILE *file, char buffer[]){
  int i;
  if(fread(&i, 4, 1, file) == 0)
    return 0;
  fread(buffer, i, 1, file);
  buffer[i] = '\0';
  return i;
}

int main (){
  char last[30], name[30], address[30], city[30], state[30], zip[30], searchkey[30];
  char* field;
  char caracter;
  char file_name[30];
  char buffer[100];
  int rec_length, match = 0;

  printf ("Nome do arquivo a ser lido: \n");
  scanf ("%[^\n]", file_name);
  __fpurge(stdin);

  FILE *file = fopen (file_name, "r");

  printf ("\nDigite o sobrenome da pessoa desejada\n");
  gets (searchkey);
  rec_length = get_rec (file, buffer);
  while (match != 1 && rec_length > 0){
    field = strtok(buffer, "|");
    if (strcmp(field, searchkey)==0){
      match = 1;
      break;
    }
    rec_length = get_rec(file, buffer);
  }
  if (match == 1){
    printf ("\n%s\n", field);
    field = strtok(NULL, "|");
    while (field != NULL){
      printf ("%s\n", field);
      field = strtok (NULL, "|");
    }
  }
  fclose(file);
}
