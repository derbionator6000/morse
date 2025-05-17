#ifndef OPTIONS_H
#define OPTIONS_H

//constants

//used for -h or --help
extern const char * const HELPTEXT;

//used for --programmer-info -> outputs developer data
extern const char * const PROGRAMMER_INFO;

//used in case the user used encode and decode together
extern const char * const WARNING_TEXT;


//structs
extern const struct option longopts[];


//outputs HELPTEXT, PROGRAMMER_INFO, WARNING_TEXT
void error_text();

void info_text();

void help_text();







#endif