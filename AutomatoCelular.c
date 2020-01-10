#include <stdio.h>
#include <stdlib.h>

int main(){
  char *CAprev, *CAatu;
  int bit, n, l, rule, M, N;

  printf("Comprimento da linha: ");
  scanf("%d", &N);
  printf("Quantidade de linhas: ");
  scanf("%d", &M);
  printf("Regra de 0 a 255: ");
  scanf("%d", &rule);

  // Alocar dois vetores char, um para a linha prévia e outra para a linha atual
  CAprev = (char*) malloc(N*sizeof(char));
  CAatu = (char*) malloc(N*sizeof(char));

  for(n = 0; n < N; n++)  CAprev[n] = 0;

  // Inicializa tendo apenas um estado ativo no meio da linha prévia
  CAprev[N/2] = 1;

  for(l = 2; l <= M; l++){
    for(n = 1; n < N - 1; n++){
      bit = CAprev[n-1] << 2 | CAprev[n] << 1 | CAprev[n+1];  // codifica cada vizinho para um bit em bit
      CAatu[n] = (rule &(1 << bit)) != 0;  // 1<<bit faz 2^bit deslocamentos de bits | rule &(1<<bit) realiza a verificação se dentro de rule a vizinhança coincide | != 0 garante que armazenará apenas 1 ou 0
    }

    // Print do vetor CAprev
    for(int p = 0; p < N; p++){
      if(CAprev[p] == 0) printf("  ");
      else  printf("O ");
    }
    puts("");

    // Copia o Vetor
    for(int p = 0; p < N; p++)  CAprev[p] = CAatu[p];
    system("sleep 0.18");
  }
}
