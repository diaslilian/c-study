#include <stdio.h>
int main(int argc, char const *argv[])
{
  /*int i = 0;

  printf("%d ", i--);
  printf("%d ", --i);
  printf("%d ", i + 1);
*/

  int x;
  for (x = 0; x <= 100; x = x + 2)
  {
    printf("%d ", x);
  }
}