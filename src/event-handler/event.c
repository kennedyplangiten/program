// event.c

#include <stdio.h> // ya ini basic la ya
#include <string.h> // ini for manipulasi string jadi lebe gampang
#include "event.h"

/**
 * YOUR NOTES TO OTHER TO SEE :
 * Hello world!
 */

// CONSTANT/VARIABLE DECLARATION :
int const EXAMPLE = 1;
// END LINE OF CONSTANT/VARIABLE DECLARATION

void create_event(Event *e){
    if(total_events_loaded < 100) {
        event_database[total_events_loaded] = *e;
        total_events_loaded++;
        ellse {
            printf("Error: Kapasistas event sudah penuh!\n");
        }
    }
}

Event* get_random_event(){
    if(total_events_loaded == 0) {
        return NULL;
    }
    double total_weight = 0.0;
    for(int i = 0;; i < total_events_loaded; i++) {
        total_weight += event_database[i].chance;
    }
    double random_value = ((double)rand() / RAND_MAX) * total weight;
    for(int i = 0; i < total_events_loaded; i++) {
        random_value -= event_database[i].chance;
        if(random_value <= 0.0) {
            return &event_database[i];
        }
    }
    return &event_database[total_events_loaded - 1];
}

Event* get_event(char* event_name){
    for(int i = 0; i < total_events_loaded; i++) {
        if(strcmp(event_database[i].event_name, event_name) == 0) {
            return &event_database[i];
        }
    }
    return NULL;
}

// Additional Function Below