/**** Includes  ***/
#include <stdio.h>
#include <assert.h>

/****** Macros /Defines  **********/
#define MAX_PAIRNUMBER 25

static int PairNumber;


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


struct color_pair
{
    const char* Major_Color;
    const char* Minor_Color;
};

/*** Function declaration ****/
void (*Print_Output)(int,const color_pair);
void (*AssertFun)(int,const char*,const char*,color_pair);

/**! Breif :- Function to print data on console ***/
void printOnConsole(int i, const color_pair AColor_Pair)
{
    printf("\n %d, %s %s",i,AColor_Pair.Major_Color,AColor_Pair.Minor_Color);
}

/**! Breif :- Function to map color pair against pair number ***/
color_pair colormap(int Apairnumber, color_pair AColor_Pair, void (*Print_Output)(int,color_pair))
{       
    AColor_Pair.Major_Color = majorColor[(Apairnumber-1)/5];
    AColor_Pair.Minor_Color = minorColor[(Apairnumber-1)%5];
    
    Print_Output(Apairnumber,AColor_Pair);    
    return AColor_Pair;
}

/***! Breif :-  Assert Function to check color pair against Pair number*/

void TestFun(int APairNumber,const char* Major_C , const char * Minor_C, color_pair AColor_Pair , void (*Print_Output)(int,color_pair))
{
    AColor_Pair =  colormap(APairNumber,AColor_Pair,Print_Output);   
  
    assert(AColor_Pair.Major_Color ==Major_C);
    assert(AColor_Pair.Minor_Color ==Minor_C);
}

    
int main()
{    
    color_pair Color_Pair;  
    
    void (*Print_Output)(int,const color_pair)=&printOnConsole; 
    void (*AssertFun)(int,const char*,const char*,color_pair, void (*Print_Output)(int,color_pair)) =&TestFun;
    
    for(PairNumber=1; MAX_PAIRNUMBER >= PairNumber ; PairNumber++)
    {
       colormap(PairNumber,Color_Pair,Print_Output);    
    }
    
    AssertFun(2,  "White",      "Orange",   Color_Pair,     Print_Output);
    AssertFun(5,  "White",      "Slate",    Color_Pair,     Print_Output);
    AssertFun(6,  "Red",        "Blue",     Color_Pair,     Print_Output);
    AssertFun(11, "Black",      "Blue",     Color_Pair,     Print_Output);
    AssertFun(20, "Yellow",     "Slate",    Color_Pair,     Print_Output);
    AssertFun(25, "Violet",     "Slate",    Color_Pair,     Print_Output);
    return 0;
}
