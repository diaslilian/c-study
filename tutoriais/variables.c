#include <stdio.h>
#include <stdlib.h>

int main()
{
  char characterName[] = "John";
  int characterAge = 35;

  printf("There once was a man named %s\n", characterName);
  printf("he was %d years old.\n", characterAge);
  printf("He really liked the name %s\n", characterName);
  printf("but did not like being %d.\n", characterAge);

  return 0;
}