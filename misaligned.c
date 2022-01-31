#include <stdio.h>
#include <assert.h>

 const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
 const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct color_pair
{
    char* Major_Color;
    char* Minor_Color;
};

color_pair colormap(int pairnumber)
{
    color_pair Lcolor_pair;
    
    Lcolor_pair.Major_Color = majorColor[(pairnumber-1)\5];
    Lcolor_pair.Minor_Color = minorColor[(pairnumber-1)%5];
    
    return Lcolor_pair;
}
printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("%d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}
    
int main() {
    color_pair Color_Pair;
    int i;
    for(i=1; 25 >= i ; i++)
    {
       Color_Pair =colormap(i);
       printOnConsole(i,&Color_Pair);
    }
   // int result = printColorMap();
   // assert(result == 25);
   // printf("All is well (maybe!)\n");
    return 0;
}
