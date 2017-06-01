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

void bubble(elemIndex v[], int qtd )
{
  int i;
  int j;
  int auxid, auxoffset;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j].ID > v[j+1].ID)
        {
            auxid = v[j].ID;
            auxoffset = v[j].offset;
        v[j].ID = v[j+1].ID;
        v[j].offset = v[j+1].offset;
        v[j+1].ID=auxid;
        v[j+1].offset = auxoffset;
        }
     }
     k--;
  }
}

int main (){

  elemIndex Indice;
  char file_name[30];
  char buffer[512];
  short rec_length;
  int tamanho = 0, offset = 0, i=0, busca = 0;
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

  printf ("\nInsira o indice desejado\n");
  scanf ("%i", &busca);
  offset = vetor[busca].offset;
  printf ("\n%i\n", offset);
  fseek(file, offset, SEEK_SET);
  fread (&tamanho, 2, 1, file);
  buffer[0] = "\0";
  fread (&buffer, tamanho, 1, file);
  printf ("%s", buffer);
  fclose(file);

}
