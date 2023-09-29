#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));
  int secretNumber = rand() % 100 + 1;
  int guess;
  int attempts = 0;
  printf("This is a Number Guessing Game!\n");
  printf("Guess a number between 1 and 100.\n");

  do {

    printf("Enter your guess: ");
    scanf("%d", & guess);
    attempts++;
    if (guess < secretNumber) {
      printf("The number is greater than your guess.\n");
    } else if (guess > secretNumber) {
      printf("The number is smaller than your guess.\n");
    } else {
      printf("Congrats Mate! You've guessed the number (%d) in %d attempts.\n", secretNumber, attempts);
    }

  } while (guess != secretNumber);

  return 0;
}