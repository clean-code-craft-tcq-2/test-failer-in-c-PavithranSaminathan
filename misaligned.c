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

void (*Print_Output)(int,const color_pair);

void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}

void colormap(int Apairnumber, color_pair AColor_Pair, void (*Print_Output)(int,color_pair))
{   
    
    AColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    AColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
    
    Print_Output(Apairnumber,AColor_Pair);
}

void TestFun(int Apairnumber,const char* Major_C , const char * Minor_C, const color_pair AColor_Pair)
{
    colormap(Apairnumber,&AColor_Pair,Print_Output);   
    
 //   assert(AColor_Pair.Major_Color ==Major_C);
    assert(AColor_Pair.Minor_Color ==Minor_C);
}

    
int main()
{    
    color_pair Color_Pair;  
    
    void (*Print_Output)(int,const color_pair)=printOnConsole;
    
   void (*AssertFun)(int,const char*,const char*,const color_pair) = TestFun;
    
    
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
       colormap(PairNumber,Color_Pair,Print_Output);    
    }
    
    AssertFun(2, "White","Orange",Color_Pair);
    
    
    return 0;
}
