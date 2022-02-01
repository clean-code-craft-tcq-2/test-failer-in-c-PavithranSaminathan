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

void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}

color_pair colormap(int Apairnumber, color_pair AColor_Pair, void (*Print_Output)(int,color_pair))
{   
    
    AColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    AColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
    
    (*Print_Output)(Apairnumber,AColor_Pair);
    
    return LColor_Pair;
}


    
int main()
{    
    color_pair Color_Pair;  
    
    void (*Print_Output)(int,color_pair)=&printOnConsole;
    
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
       Color_Pair=colormap(PairNumber,Color_Pair,&printOnConsole);
    //   printOnConsole(Apairnumber,Color_Pair);
    }
    return 0;
}
