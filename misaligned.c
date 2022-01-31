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



color_pair colormap(int Apairnumber)
{   
    color_pair LColor_Pair;
 
    LColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    LColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
 
    
}

void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}
    
int main() {
    
    color_pair Color_Pair;
    
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
       Color_Pair=colormap(PairNumber);
       printOnConsole(Apairnumber,Color_Pair);
    }
    return 0;
}
test main()
{
    color_pair Color_Pair;
    Color_Pair=colormap(5);
    assert(LColor_Pair.Major_Color == "White");
    assert(LColor_Pair.Minor_Color == "Slate"); 
}
