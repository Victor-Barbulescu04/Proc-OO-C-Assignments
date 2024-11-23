// readevents.c - code to read and classify the events

#include "event.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

void read_events(Event all_events[], int max_events, int *event_count) {
  char time[MAX_TIME_LENGTH + 1]; // add 1 for null terminator
  int milliliters;
  assert(MAX_EVENT_NAME < 80); 
  // issue: protect against buffer overrun by making sure no name is too
  //        long. One *can* use MAX_EVENT_NAME in the scanf format string,
  //        but it makes the code more obscure. So here's a case where we
  //        simply use a hard-coded constant with a check to make sure
  //        that it's large enough for the following code to make sense.
  char item[80];
  
  *event_count = 0;
  int fields_read = scanf("%5s %79s %d", time, item, &milliliters);
  // read until we read a partial record (< 3 elements), eof, or max_events
  while ( fields_read == 3 && !feof(stdin) && *event_count < max_events ) {
    // TODO: set the time, ml, event fields; do NOT set whether the
    //       event is an output since that's done elsewhere. Use strncpy
    //       for the strings.

    Event e;
    strncpy(e.time, time, MAX_TIME_LENGTH);
    e.time[MAX_TIME_LENGTH] = '\0';  // Ensure null termination

    strncpy(e.name, item, MAX_EVENT_NAME);
    e.name[MAX_EVENT_NAME] = '\0';  // Ensure null termination

    e.milliliters = milliliters;

    if (*event_count < max_events) {
      all_events[*event_count] = e;
      (*event_count)++;  // Increment the event count
    } else {
      fprintf(stderr, "Error: Cannot add more events, array is full.\n");
    }

    // note: is_output is set elsewhere
    // read for next time through loop
    fields_read = scanf("%5s %79s %d", time, item, &milliliters);
  }
}

void determine_if_event_is_output(Event *an_event) {
  // TODO: add code to set the flag indicating whether the event is
  //       an intake or output. Remember that urine, bloodloss, and
  //       diarrhea indicate output. Use strcmp to do the comparison,
  //       remembering it returns 0 if the strings are the same.

  if (strcmp(an_event->name, "urine") == 0 ||
    strcmp(an_event->name, "bloodloss") == 0 ||
    strcmp(an_event->name, "diarrhea") == 0) {
    an_event->is_output = 1;
    }

}

void classify_events(Event events[], int event_count) {
  for(int i = 0; i < event_count; ++i) {
    // TODO: call determine_if_event_is_output to set the intake/output flag
    // Note: if you're having problems, you might find it useful to print
    //       the data in events[] here (but comment it out for final submission)
    determine_if_event_is_output(&events[i]);
  }
}
