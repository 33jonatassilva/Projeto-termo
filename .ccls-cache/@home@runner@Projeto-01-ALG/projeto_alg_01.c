/*
  * Jônatas de Brito Silva
  * TIA: 32283792
*/


#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#define TOTALTEN 6

// TOTALTEN é igual ao número total de tentativas que o usuário terá.


// Função conta_letras: retorna a quantidade de caracteres que existem no array, nesse caso, em cada palavra.

int conta_letras(char vet[]){
  int tamanho = strlen(vet);
  return tamanho;
}

// Função existe: retorna true se a palavra existe no arquivo txt e false caso contrário.

bool existe(char vet[]){

  FILE *arquivo;
  int cont = 0;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");

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
// Olhar função strcmp()
}
// Função compara_array: compara a palavra digitada pelo usuário com a que foi sorteada.

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

  int loop = 0;
  int tentativas = 0;
  int aleat;
  int cont = 0;
  srand(time(NULL));
  
  FILE *arquivo;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");
  if (arquivo == NULL){
    printf("Erro ao tentar abrir o arquivo!");
  }else{
  do{
  aleat = rand() % 6622;
  do{
    fgets(c, 12, arquivo);
    cont++;
  }while(cont < aleat);
  }while(conta_letras(c) != 7);
  printf("A palavra sorteada é: %s", c);
  printf("Você tem %d tentativa(s)", TOTALTEN);
  
  time_t start = time(NULL);
  char palavra[12];
  // Pede ao jogador para que digite uma palavra com 5 letras.
  do{
  printf("\nDigite uma palavra com 5 letras por favor: ");
  scanf("%s", palavra);

  // Verifica a quantidade de letras da palavra digitada e se ela está no arquivo de palavras.
  while(conta_letras(palavra) != 5 || existe(palavra) == false){
    printf("\n=>=>=>=>=>||PALAVRA INVALIDA||<=<=<=<=<=\n");
    printf("Você ainda tem %d tentativa(s)\n", TOTALTEN-tentativas);
    printf("Digite outra palavra: ");
    scanf("%s", palavra);
    }
    
  // Após passar pela verificação, o número de tentativas é incrementado em 1.
    tentativas++;
    
  
  // Mostra na tela a palavra digitada pelo jogador com letras maiúsculas.
  printf("+ - --------- - +\n");
  printf("|");
  for(int i = 0; i < 5; i++) {
    printf(" %c ", toupper(palavra[i]));
    }
  printf("|\n|");

  // Mostra na tela quais letras da palavra digitada pelo jogador estão na posição correta.
  for(int i =  0; i < 5; i++){
    if(palavra[i] == c[i]){
    printf(" ^ ");
    loop = 1;
    }

  // Mostra na tela quais letras da palavra digitada pelo jogador 
  // estão na palavra sorteada, mas não está na posição correta.
  if (loop == 0){ 
    for (int j = 0; j < 5; j++){
      if (palavra[i] == c[j]){
        printf(" ! ");
        loop = 1;
        break;
        }
      }
    }
  // Mostra na tela quais letras da palavra digitada pelo jogador
  // não existem na palavra sorteada.
  if(loop == 0){
      printf(" X ");
      loop = 1;
    }
  loop = 0;
  }
    printf("|");
    printf("\n+ - --------- - +\n");
    

    // Se o jogador acertar a palavra dá os parabéns e pede para digitar o nome.
    if(compara_array(palavra, c)){
    time_t diff = time(NULL) - start;
    printf("Parabéns vc acertou!!!\n");
    
    char dados[30];
    FILE * arq;
    arq = fopen("scores.txt", "a");
    printf("Digite o seu nome: ");
    scanf("%s", dados);
    fprintf(arq, "%s acertou a palavra [%s] em %d tentativa(s) e em %li segundo(s)\n", dados, palavra, tentativas, diff);
    fclose(arq);
    break;
  }
    if(tentativas < TOTALTEN){
    printf("\nVocê tem %d tentativa(s)", TOTALTEN-tentativas);
    }
  }while(tentativas <= TOTALTEN-1);

  // Se o número de tentativas for excedidas, avisa ao jogador e 
  // mostra qual é a palavra sorteada.
  if (compara_array(palavra, c) == false){
  printf("\n++++++++|| NÚMERO DE TENTATIVAS EXCEDIDAS ||++++++++\n");
  printf("A PALAVRA ERA: %s", c);}
  }
}
