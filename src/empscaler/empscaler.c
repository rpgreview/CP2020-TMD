#include <stdio.h>
#include <math.h>
#include "args.h"

const char *argp_program_version = "Empscaler 0.1";
const char *argp_program_bug_address = "<timothy.rice@unimelb.edu.au>";

double cool_scale(long cool) {
    switch(cool) {
        case 1:
            return 2.0;
        case 2: case 3:
            return 1.5;
        case 4: case 5: case 6: case 7:
            return 1.0;
        case 8: case 9:
            return 0.75;
        case 10:
            return 0.5;
        default:
            return -1;
    }
}

int main(int argc, char** argv) {
    /* Set argument defaults */
    struct arguments args = { 0, 5, 5 };
    argp_parse(&argp, argc, argv, 0, 0, &args);

    double hc_scaled = args.base_humanity_cost*cool_scale(args.cool);
    double humanity_remaining = (100.0 - hc_scaled)/100.0;
    printf("%d\n", (int)floor(args.emp*humanity_remaining));
    return 0;
}
