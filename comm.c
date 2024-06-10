#include <stdio.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

int main() {
    datetime_t current_time;

    // Initialize the serial port
    stdio_init_all();

    // Start the RTC
    rtc_init();

    while (1)
    {
        // Get the current time
        rtc_get_datetime(&current_time);
        printf("Current time: %d-%d-%d %d:%d:%d\n", current_time.year, current_time.month, current_time.day, current_time.hour, current_time.min, current_time.sec);

        sleep_ms(2000);
    }
}