#include <stdio.h>
#include <assert.h>

#define MAX_PAIRNUMBER 25
static int PairNumber;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct color_pair
{
    const char* Major_Color;
    const char* Minor_Color;
};

void printOnConsole(int i, const color_pair AColor_Pair);
void colormap(int Apairnumber);



void colormap(int Apairnumber)
{   
    color_pair LColor_Pair;
 
    LColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    LColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
 
    printOnConsole(Apairnumber,LColor_Pair);
}

void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}
    
int main() {
   
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
       colormap(PairNumber);
    }
    return 0;
}
