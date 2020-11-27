#include <stdio.h>
#include <math.h>
#include "args.h"

const char *argp_program_version = "Refscaler 0.1";
const char *argp_program_bug_address = "<timothy.rice@unimelb.edu.au>";

double body_scale(long body) {
    if(body >= 11) {
        body = 11;
    }
    switch(body) {
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
        case 11:
            return 0.25;
    }
}

int main(int argc, char** argv) {
    /* Set argument defaults */
    struct arguments args = { 5, 0, 5 };
    argp_parse(&argp, argc, argv, 0, 0, &args);

    double enc_scaled = (double)args.enc*body_scale(args.body);
    double ref_scale_factor = (10.0 - enc_scaled)/10.0;
    printf("%d\n", (int)ceil(args.ref*ref_scale_factor));
    return 0;
}
