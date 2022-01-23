#include <stdio.h>
#include <assert.h>

void printOnConsole(int AIndex_i , const char* AmajorColor_c , const char* AminorColor_c)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
     if(AIndex_i == 2)
     {
       assert( majorColor[0] == AmajorColor_c);
       assert( minorColor[1] == AminorColor_c);
     }
    printf("%d | %s | %s\n", AIndex_i , AmajorColor_c, AminorColor_c);
}


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
       for(j = 0; j < 5; j++) 
       {
            //printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
           printOnConsole(i * 5 + j , majorColor[i] ,  minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
