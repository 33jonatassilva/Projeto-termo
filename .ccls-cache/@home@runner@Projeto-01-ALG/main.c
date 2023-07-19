#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Função conta_letras: retorna a quantidade de caracteres que existem no array

int conta_letras(char vet[]){
  int tamanho = strlen(vet);
  return tamanho;
}

bool existe(char vet[]){

  // Abrindo o arquivo
  FILE *arquivo;
  int cont = 0;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");
  if (arquivo == NULL)
  {
    printf("Erro ao tentar abrir o arquivo!");
    return -1;
  }

  // Pegando texto em arquivo, armazenando na variável c e 
  // comparando com a palavra recebida por meio do chamado da
  // função nesse caso o vetor de char, palavra.
  
  do
  {
  fgets(c, 12, arquivo);
  for (int i = 0; i < 5; i++){
    if (vet[i] == c[i]){
      cont++;
      }
    }
  if (cont == 5){
  return true;
  }
  cont = 0;
}while (!feof(arquivo));
  fclose(arquivo);
  return false;
}

bool compara_array(char vet[], char vet2[]){
  int aux = 0;
  for (int i = 0; i < 5; i++){
    if(vet[i] == vet2[i]){
      aux++;
    }
  }
  if(aux == 5){
    return true;
  }
  return false;
}



int main(void)
{

  // Inicia-se o jogo e sorteia uma palavra
  int ajuda = 0;
  int tentativas = 0;
  int aleat;
  int cont = 0;
  srand(time(NULL));
  
  FILE *arquivo;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");
  if (arquivo == NULL)
  {
    printf("Erro ao tentar abrir o arquivo!");
  }
  do{
  aleat = rand() % 6622;
  do{
    fgets(c, 12, arquivo);
    cont++;
  }while(cont < aleat);
  }while(conta_letras(c) != 7);

  printf("A palavra sorteada é: %s", c);

  // Pede ao jogador para que digite uma palavra com 5 letras
  
  char palavra[12];
  do{
  printf("\nDigite uma palavra com 5 letras por favor: ");
  scanf("%s", palavra);


  while(conta_letras(palavra) != 5 || existe(palavra) == false){
    printf("PALAVRA INVALIDA!!\n");
    printf("Digite outra palavra: ");
    scanf("%s", palavra);
    }
    tentativas++;
  
  if(compara_array(palavra, c)){
    printf("Parabéns vc acertou!!!");
    break;
  }else{


  
  printf("+ - --------- - +\n");
  printf("|");
  
  for(int i = 0; i < 5; i++){
    printf(" %c ", palavra[i]);
    }
  printf("|\n|");

  
  for(int i =  0; i < 5; i++){
    if(palavra[i] == c[i]){
    printf(" ^ ");
    ajuda = 1;
    }  
    if (ajuda == 0){ 
      for (int j = 1; j < 5; j++){
      if (palavra[i] == c[j]){
        printf(" ! ");
        ajuda = 1;
      }
      }
      }
    if(ajuda == 0){
        printf(" X ");
      ajuda = 1;
    }
    ajuda = 0;
}
    printf("|");
    printf("\n+ - --------- - +");
  }
  }while(tentativas <= 5);
  
  
  printf("\nNÚMERO DE TENTATIVAS EXCEDIDAS\n");
  printf("A PALAVRA ERA: %s", c);
  
}
