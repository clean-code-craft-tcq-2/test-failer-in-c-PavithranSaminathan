#include <stdio.h>
#include <assert.h>

#define MAX_PAIRNUMBER 25U
static int pairnumber;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct color_pair
{
    const char* Major_Color;
    const char* Minor_Color;
};

void colormap(int Apairnumber)
{   
    color_pair LColor_Pair;
 
    LColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    LColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
 
    printOnConsole(pairnumber,LColor_Pair);
}

void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}
    
int main() {
   
    for(pairnumber=1; MAX_PAIRNUMBER >= pairnumber ; pairnumber++)
    {
       colormap(pairnumber,Color_Pair);
    }
    return 0;
}
