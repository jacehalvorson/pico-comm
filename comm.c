#include <stdio.h>
#include <string.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

int main() {
    datetime_t start_time = {
        .year = 2024,
        .month = 6,
        .day = 10,
        .dotw = 1,
        .hour = 23,
        .min = 25,
        .sec = 0
    };

    datetime_t current_time;
    (void)memset((void *)&current_time, 0, sizeof(current_time));

    // Initialize the serial port
    stdio_init_all();

    // Start the RTC
    rtc_init();
    rtc_set_datetime(&start_time);

    while (1)
    {
        if (rtc_get_datetime(&current_time))
            printf("Current time: %d-%d-%d %d:%d:%d\n", current_time.year, current_time.month, current_time.day, current_time.hour, current_time.min, current_time.sec);
        else
            printf("Unable to get current time\n");

        sleep_ms(2000);
    }
}