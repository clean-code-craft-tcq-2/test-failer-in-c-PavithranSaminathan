#ifndef misaligned_h
#define misaligned_h 

/**** Includes  ***/
#include <stdio.h>

/****** Macros /Defines  **********/
#define MAX_PAIRNUMBER 25

static int PairNumber;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

/*** Structure Declaration ***/
struct color_pair
{
    const char* Major_Color;
    const char* Minor_Color;
};

#endif
