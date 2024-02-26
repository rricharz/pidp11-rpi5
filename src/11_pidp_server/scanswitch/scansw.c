/*
 * Version 1.0 Ian Schofield 1/1/2024
 * This is a build of scansw.c for the Pi 5.
 * It uses the gpiod library
 * 
*/
#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    const char* chipname = "gpiochip4";
    const char* consumer = "PiDP11";
    struct gpiod_chip* chip;
    struct gpiod_line* Row[3];
    struct gpiod_line* Col[12];
    struct gpiod_line* Led[6];

    int rows[] = { 16, 17, 18 };
    int cols[] = { 26, 27, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    int leds[] = { 20, 21, 22, 23, 24, 25 };
    int i, j, k, val;
    unsigned long SR, msk;

    // Open GPIO chip
    chip = gpiod_chip_open_by_name(chipname);
    // Open GPIO lines
    for(i = 0; i < 3; i++)
        Row[i] = gpiod_chip_get_line(chip, rows[i]);
    for(i = 0; i < 12; i++)
        Col[i] = gpiod_chip_get_line(chip, cols[i]);
    for(i = 0; i < 6; i++)
        Led[i] = gpiod_chip_get_line(chip, leds[i]);

    // Open Row/Col lines.
    // Setup cols for weak pullup
    // Setup rows for output .. all 1
    // Setup LEDs to input as not used here.

    for(i = 0; i < 3; i++)
        gpiod_line_request_output(Row[i], consumer, 1);
    for(i = 0; i < 12; i++)
        gpiod_line_request_input_flags(Col[i], consumer, GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP);
    for(i = 0; i < 6; i++)
        gpiod_line_request_input(Led[i], consumer);

    // Read 12 bits of data from each col x 3 rows
    // Set active row to 0 and others to 1 to select col data.
    // To debug ... uncomment printf lines and set while(1)

    if(1) {
        SR = 0;
        msk = 1;
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 3; k++) {
                val = gpiod_line_set_value(Row[k], j == k ? 0 : 1);
            }
            usleep(100);
            for(i = 0; i < 12; i++, msk <<= 1) {
                val = gpiod_line_get_value(Col[i]);
                // printf("%1d", val);
                if(val)
                    SR |= msk;
            }
        }
        // printf("\r");
        // fflush(stdout);
    }
    SR = ~SR & 017777777;

    // printf("\r\nSR:%08o\r\n", SR);
    printf("%lo\n", SR);

    // Close GPIO lines

    for(i = 0; i < 3; i++)
        gpiod_line_release(Row[i]);
    for(i = 0; i < 12; i++)
        gpiod_line_release(Col[i]);
    for(i = 0; i < 6; i++)
        gpiod_line_release(Led[i]);
    gpiod_chip_close(chip);
    return 0;
}
