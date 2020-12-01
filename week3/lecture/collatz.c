#include <stdio.h>

int collatz (int, int);

int main(void)
{
    // Should be a positive integer
    int number = 27;
    // Number of steps required for the  collatz algorithm to get to 1
    int steps = 0;
    steps = collatz(steps, number);
    printf("number of required steps = %i\n", steps);
    return 0;
}

int collatz (int steps, int number)
{
    if (number == 1)
        return steps;
    else if (number % 2 == 0)
    {
        steps++;
        collatz(steps, number/2);
    }
    else
    {
        steps++;
        collatz(steps, 3 * number + 1);
    }

}
// mine was correctt but the solution in the video
/*
if n == 1 return 0
else if n%2 == 0 return 1 + collatz(n/2)
else return 1 + collatz(3*n+1)
*/