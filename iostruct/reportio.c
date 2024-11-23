// reportio.c: review inputs and outputs and report appropriately
// NOTE: this version will just look at high output, not retention

#include "event.h"
#include <stdio.h>
#include <string.h>

void flag_large_differentials(const Event events[], int event_count) {
  int total = 0;
  for(int i = 0; i < event_count; ++i) {
    // TODO: add code processing the events; if the event is an output,
    //       subtract from the total; if it's an input, add
    //       On add, if the total is >= 1000 then report such as
    //       "after consuming coffee at 8:20, intake exceeds output by 1050 ml"
    //       You'll use printf with %s for strings, %d for ints

  }
  printf("the final fluid differential is %d ml\n", total);
}
