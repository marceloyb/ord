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

  char file_name[30];
  char buffer[100];
  int rec_length;
  char *token;
  printf ("Insira o nome do arquivo a ser lido\n");
  scanf ("%[^\n]", file_name);
  __fpurge(stdin);
  FILE *file = fopen (file_name, "r");
  rec_length = get_rec(file, buffer);
  while (rec_length > 0){
    token = strtok (buffer, "|");
    while (token != NULL){
        printf ("%s\n", token);
        token = strtok(NULL, "|");
    }
    rec_length = get_rec(file, buffer);
  }
  fclose(file);
}
