#include <stdio.h>
#include <string.h>


int get_rec (FILE *file, char buffer[]){
  int i;
  if(fread(&i, 2, 1, file) == 0)
    return 0;
  fread(buffer, i, 1, file);
  buffer[i] = '\0';
  return i;
}

typedef struct linearindex{
  int ID;
  int offset;
}elemIndex;

void bubble(elemIndex v[], int qtd ) {
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j].ID > v[j+1].ID)
        {
            aux = v[j].ID;
        v[j].ID = v[j+1].ID;
        v[j+1].ID=aux;
        }
     }
     k--;
  }
}

int main () {
  elemIndex Indice;
  char file_name[30];
  char buffer[512];
  short rec_length;
  int tamanho = 0, offset = 0, i=0;
  char *token;
  printf ("Insira o nome do arquivo a ser lido\n");
  scanf ("%[^\n]", file_name);
  __fpurge(stdin);
  FILE *file = fopen (file_name, "rb");
  fread (&tamanho, 1, sizeof(tamanho), file);
  elemIndex vetor[tamanho];
  offset = sizeof(tamanho);
  rec_length = get_rec(file, buffer);
  while (rec_length > 0){
    token = strtok (buffer, "|");
    vetor[i].ID = atoi (token);
    vetor[i].offset = offset;
    offset = offset + rec_length + 2;
    rec_length = get_rec(file, buffer);
    i++;
  }
  bubble (vetor, 100);

  for (i = 0; i <= 99; i++)
    printf ("\n%i", vetor[i].ID);

  return 0;
}
