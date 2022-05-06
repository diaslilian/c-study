#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Especificadores de formato: scanf()

  // digitos
  // d ou i = números inteiros em base decimal
  // x = números inteiros em base hexadecimal
  // f = números em ponto flutuante(com casas decimais)
  // e = números em notação científica(com casas decimais)
  // c = caracteres alfanuméricos(texto)
  // s = sequência de caracteres alfanuméricos(texto)
  // [^chars] = Lê todos os dados digitados, exceto os especificados em "chars"

  int idade = 0;

  printf("Valor inicial da idade: %d. \n", idade);

  printf("Digite uma idade: \n");
  scanf("%d", &idade);

  printf("Idade informada: %d. \n", idade);

  return 0;
}