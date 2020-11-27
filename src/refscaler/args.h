#ifndef __ARGS_H__
#define __ARGS_H__
#include <argp.h>
#include <stdlib.h>

/* This structure is used by main to communicate with parse_opt. */
struct arguments {
    long body;
    long enc;
    long ref;
};

/*
   OPTIONS.  Field 1 in ARGP.
   Order of fields: {NAME, KEY, ARG, FLAGS, DOC}.
*/
static struct argp_option options[] = {
    {"body",  'b', "BODY", 0,
        "Character's BODY score (Default: 5)"},
    {"ref",   'r', "REF", 0,
        "Character's base REF score (Default: 5)"},
    {"enc",   'e', "ENC", 0,
        "Character's unscaled ENC (Default: 0)"},
    {NULL, 'h', NULL, OPTION_ARG_OPTIONAL, "Print this help."},
    {0}
};

/*
   PARSER. Field 2 in ARGP.
   Order of parameters: KEY, ARG, STATE.
*/
static error_t parse_opt (int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *)state->input;
    switch (key) {
        case 'b':
            arguments->body = strtol(arg, NULL, 10);
            break;
        case 'e':
            arguments->enc = strtol(arg, NULL, 10);
            break;
        case 'r':
            arguments->ref = strtol(arg, NULL, 10);
            break;
        case 'h':
            argp_help(state->root_argp, stdout, ARGP_HELP_SHORT_USAGE | ARGP_HELP_LONG | ARGP_HELP_DOC, state->name);
            exit(0);
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/*
   ARGS_DOC. Field 3 in ARGP.
   A description of the non-option command-line arguments
     that we accept.
*/
static char args_doc[] = "";

/*
  DOC.  Field 4 in ARGP.
  Program documentation.
*/
static char doc[] = "Calculate REF scaled according to TMD house rules";

/*
   The ARGP structure itself.
*/
static struct argp argp = {options, parse_opt, args_doc, doc};
#endif // __ARGS_H__
