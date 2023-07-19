/*
  * Jônatas de Brito Silva
  * TIA: 32283792

  OBS: Professor, testa o meu código no replit pra que a formatação dos prints fique certinha! Obrigado!
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#define TOTALTEN 6 

// TOTALTEN é igual ao número total de tentativas que o usuário terá.

// Função begin: abre o arquivo bannertermo.txt e printa todas as linhas.

void begin(){
  FILE *banner;
  char linha[100];
  banner = fopen("bannertermo.txt", "r");
  do{
  usleep(150000);
  fgets(linha, 100, banner);
  printf("%s", linha);
  }while(!feof(banner));
  fclose(banner);
  while (getchar() != '\n');
}

/* 
  Função existe: pesquisa a palavra digitada no arquivo sem_acento.txt 
  e se ela estiver retorna true, caso contrário, retorna false.
*/
bool existe(char vet[]){
  
  FILE *arquivo;
  int cont = 0;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");

  do
  {
    fgets(c, 12, arquivo);
    for (int i = 0; i < 5; i++){
      if (vet[i] == c[i]){ cont++; }
      }
    if (cont == 5){ return true; }
    cont = 0;
  }while (!feof(arquivo));
    fclose(arquivo); return false; }

/* 
  Função compara_array: compara a palavra digitada pelo usuário com a que foi sorteada, 
  se for igual retorna true, caso contrário, retorna false.
*/
bool compara_array(char vet[], char vet2[]){
  int aux = 0;
  for (int i = 0; i < 5; i++){
    if(vet[i] == vet2[i])  aux++; }
  if(aux == 5) { return true; }
  return false;
}


int main(void)
{
  int tentativas = 0;
  int aleat;
  int cont = 0;
  srand(time(NULL));
  
  FILE *arquivo;
  char c[12];
  
  arquivo = fopen("sem_acento.txt","r");
  if (arquivo == NULL) {printf("Erro ao tentar abrir o arquivo!");
  }else{
  do{
  aleat = rand() % 6622;
  do{
    fgets(c, 12, arquivo);
    cont++; }while(cont < aleat); }while(strlen(c) != 7);
    begin();
    printf("\n\t\t\t\t\t  A palavra sorteada é: %s", c);
    printf("\t\t\t\t\t    Você tem %d tentativa(s)", TOTALTEN);
  
  time_t start = time(NULL); // O tempo em segundos começa a ser contado.
  char palavra[12];
    
  do{
  printf("\n\t\t\tDigite uma palavra com 5 letras por favor: ");
  scanf("%s", palavra);

  // Verifica se quantidade de letras da palavra é 5 e se ela está no arquivo de palavras.
    
  while(strlen(palavra) != 5 || existe(palavra) == false){
    printf("\n\n\t\t\t\t=>=>=>=>=>||PALAVRA INVALIDA||<=<=<=<=<=\n");
    printf("\n\t\t\t\t\t  Você ainda tem %d tentativa(s)\n", TOTALTEN-tentativas);
    printf("\n\t\t\t\t\t\tDigite outra palavra: ");
    scanf("%s", palavra);
    }
    
  // Após passar pela verificação, o número de tentativas é incrementado em 1.
    
  tentativas++;
  char letter_digit[5];
  char palaux[5];  
  printf("\n\t\t\t\t\t\t\t+ ------------- +\n");
  printf("\t\t\t\t\t\t\t|");
    
  // Mostra na tela a palavra digitada pelo jogador com letras maiúsculas.
    
  for(int i = 0; i < 5; i++) {
    printf(" %c ", toupper(palavra[i])); 
    letter_digit[i] = c[i]; // letter_digit recebe a palavra sorteada.
    palaux[i] = palavra[i]; // palaux recebe a palavra digitada pelo usuário.
  }
  printf("|\n\t\t\t\t\t\t\t|");

  /* 
    Compara as letras da palavra digitada com as letras da palavra sorteada e armazena os caracteres
    correspondentes no array palaux, ou seja, ^ ! X, caso ocorra algum dos casos citados letter_digit
    recebe o caractere *.
  */  
  for(int i =  0; i < 5; i++){ 
    if(palaux[i] == letter_digit[i]){
      palaux[i] = '^';
      letter_digit[i] = '*';
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if (palaux[i] == letter_digit[j]){
        palaux[i] = '!';
        letter_digit[j] = '*';
      }
    }
  }
  for(int i = 0; i < 5; i++){
    if(palaux[i] != '^' && palaux[i] != '!'){
      palaux[i] = 'X';
    }
  }   
  for (int i = 0; i < 5; i++){
    printf(" %c ", palaux[i]);
  }

    printf("|");
    printf("\n\t\t\t\t\t\t\t+ ------------- +\n");
    
    // Se o jogador acertar a palavra dá os parabéns e pede para digitar o nome.
    
    if(compara_array(palavra, c)){
    time_t diff = time(NULL) - start; // O tempo para de ser contado, assim que o jogador acerta a palavra.
    printf("\n\t\t\t\t\t\t  Parabéns vc acertou!!!\n");
    
    char dados[30];
    FILE * arq;
    arq = fopen("scores.txt", "a");
    printf("\t\t\t\t\t\t  Digite o seu nome: ");
    scanf("%s", dados);
    fprintf(arq, "%s acertou a palavra [%s] em %d tentativa(s) e em %li segundo(s)\n", dados, palavra, tentativas, diff);
    fclose(arq);
    break;
  }
    if(tentativas < TOTALTEN) { printf("\n\t\t\t\t\t\t  Você tem %d tentativa(s)", TOTALTEN-tentativas); }
  }while(tentativas <= TOTALTEN-1);

  // Se o número de tentativas for excedidas, avisa ao jogador e mostra qual é a palavra sorteada.
  
  if (compara_array(palavra, c) == false){
  printf("\n\t\t\t++++++++|| NÚMERO DE TENTATIVAS EXCEDIDAS ||++++++++\n");
  printf("\t\t\t\t\t\t\tA PALAVRA ERA: %s", c); }
  }
}
    


    

