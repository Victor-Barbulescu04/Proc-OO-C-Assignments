// event.h: data for an intake or output event for a patient

#ifndef _event_h
#define _event_h

#define MAX_EVENT_NAME 40
#define MAX_TIME_LENGTH 5       // strlen("12:59")

// for bool data type
#include <stdbool.h>

typedef struct {
  char time[MAX_TIME_LENGTH + 1]; // add 1 for the null terminator
  // TODO: add fields for the milliliters, bool is_output, and the
  //       event name. Each should have the appropriate type. Use
  //       MAX_EVENT_NAME + 1 for the size of the event name string.

} Event;

// read events from input up to max_events items, setting count
void read_events(Event all_events[], int max_events, int *event_count);

// update the flag indicating whether the event is an intake or output
void determine_if_event_is_output(Event *an_event);

// classify events as either intakes or outputs
void classify_events(Event events[], int event_count);

// report when the running tally is too high
void flag_large_differentials(const Event events[], int event_count);

#endif
