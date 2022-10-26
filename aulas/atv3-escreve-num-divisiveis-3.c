#include <stdio.h>

// Código que deve ser inserido aqui
int identificarDivisivelPor3(int matriz[5][5])
{
  int index, aux;

  for (index = 0; index < 5; index++)
  {
    for (aux = 0; aux < 5; aux++)
    {
      if (matriz[index][aux] % 3 == 0)
      {
        printf("Número divisível por 3 encontrado na linha %d, coluna %d, número %d\n", index + 1, aux + 1, matriz[index][aux]);
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  // Matriz com valores fixo para nao fazer a leitura
  int matriz[5][5] = {{15, 9, 23, 43, 49},
                      {3, 36, 55, 53, 18},
                      {12, 42, 51, 57, 34},
                      {6, 32, 28, 25, 62},
                      {72, 91, 81, 16, 41}};

  identificarDivisivelPor3(matriz);

  return 0;
}