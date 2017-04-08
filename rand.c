#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range
 * https://en.wikipedia.org/wiki/Pseudorandom_number_generator
 */


//function declarations
long random_at_most(long max);

int main(){
    srand(time(NULL));   // should only be called once
    int r = rand();      // returns a pseudo-random integer between 0 and RAND_MAX
    printf("The value of RAND_MAX = %d and the random number generated is: %d\n",RAND_MAX, r);
    int j;
    for( j=0; j<100 ;j++){
        printf("The value of the random integer in the range of 0 and 30 is: %ld\n",random_at_most(30));
    }
    
    
}

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_at_most(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do {
   x = random();
  }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}
