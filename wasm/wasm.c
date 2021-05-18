//  WebAssembly Interface for uLisp
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "wasm.h"

/// JSON Stream of Simulation Events:
/// [ { "bl_gpio_output_set": { "pin": 11, "value": 1 } }, 
///   { "time_delay": { "ticks": 1000 } }, 
///   ... 
/// ]
static char events[1024] = "[]";

/// Clear the JSON Stream of Simulation Events
void simulation_clear_events(void) {
    strcpy(events, "[]");
}

/// Return the JSON Stream of Simulation Events
char *simulation_get_events(void) {
    assert(events[0] == '[');
    assert(events[strlen(events) - 1] == ']');

    //  Erase the leading comma: "[,...]" becomes "[ ...]"
    if (events[1] == ',') { events[1] = ' '; }
    return events;
}

/// Preempt the uLisp task and allow background tasks to run.
/// Called by event() and sp_loop() in src/ulisp.c
void yield_ulisp(void) {
    //  TODO: If uLisp is running a loop or recursion,
    //  the Simulation Events buffer may overflow.
    //  If we have yielded too many times, stop.
}

/// Add a GPIO event to enable input (0 for to disable pullup/pulldown, 1 to enable pullup/pulldown)
int bl_gpio_enable_input(uint8_t pin, uint8_t pullup, uint8_t pulldown) { 
    //  TODO
    return 0; 
}

/// Add a GPIO event to enable output (0 for to disable pullup/pulldown, 1 to enable pullup/pulldown)
int bl_gpio_enable_output(uint8_t pin, uint8_t pullup, uint8_t pulldown) { 
    //  TODO
    return 0; 
}

/// Add a GPIO event to set output (0 for low, 1 for high)
int bl_gpio_output_set(uint8_t pin, uint8_t value) {
    //  How many chars in the Simulation Events buffer to keep
    int keep = 
        strlen(events)  //  Keep the existing events
        - 1;            //  Skip the trailing "]"
    snprintf(
        events + keep,
        sizeof(events) - keep,
        ", { \"gpio_output_set\": { "
            "\"pin\": %d, "
            "\"value\": %d "
        "} } ]",
        pin,
        value
    );
    return 0; 
}

/// Add a delay event. 1 tick is 1 millisecond
void time_delay(uint32_t ticks) { 
    //  TODO
}
