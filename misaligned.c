/**** Includes  ***/
#include "misaligned.h"
#include <assert.h>


/**! Breif :- Function to print data on console ***/
void printOnConsole(int PairNumber, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",PairNumber , AColor_Pair.Major_Color, AColor_Pair.Minor_Color);
}

/**! Breif :- Function to map color pair against pair number ***/
color_pair colormap(int Apairnumber)
{       
    color_pair LColor_Pair;
    
    LColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    LColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
    
    return LColor_Pair;
}

/***! Breif :-  Assert Function to check color pair against Pair number*/

void TestFun(int APairNumber,const char* Major_C , const char * Minor_C)
{
    color_pair AColor_Pair;
    
    AColor_Pair= colormap(APairNumber);   
  
    assert(AColor_Pair.Major_Color ==Major_C);
    assert(AColor_Pair.Minor_Color ==Minor_C);
}
    
int main()
{    
    color_pair Color_Pair;  
      
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
         Color_Pair=colormap(PairNumber); 
         printOnConsole(PairNumber,Color_Pair);  
    }
    
    TestFun(2,  "White",      "Orange" );
    TestFun(5,  "White",      "Slate"  );
    TestFun(6,  "Red",        "Blue"   );
    TestFun(11, "Black",      "Blue"   );
    TestFun(20, "Yellow",     "Slate"  );
    TestFun(25, "Violet",     "Slate"  );
    return 0;
}
