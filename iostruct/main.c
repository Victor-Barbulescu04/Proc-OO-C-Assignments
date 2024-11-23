// main for C program to process intakes and outputs

#include "event.h"
#include <stdio.h>

const int MAX_EVENTS = 50;

int main() {
  Event events[MAX_EVENTS];
  int count;

  read_events(events, MAX_EVENTS, &count);
  classify_events(events, count);
  flag_large_differentials(events, count);

  return 0;
}
