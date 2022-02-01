#include <stdio.h>
#include <assert.h>

#define MAXIMUM_SIZE_UNDER_SMALL 38
#define MINIMUM_SIZE_IN_MEDIUM   39
#define MAXIMUM_SIZE_IN_MEDIUM   41
#define MINIMUM_SIZE_IN_LARGE    42


char size(int cms) {
    char sizeName = '\0';
    
    if(MAXIMUM_SIZE_UNDER_SMALL >= cms) 
    {
        sizeName = 'S';
    } 
    
    else if(MINIMUM_SIZE_IN_MEDIUM <= cms && MAXIMUM_SIZE_IN_MEDIUM >= cms) 
    {
        sizeName = 'M';
    }
    
    else if(MINIMUM_SIZE_IN_LARGE <= cms)
    {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S');
    assert(size(40) == 'M');
    assert(size(42) == 'L');
    assert(size(43) == 'L');
    
    
    printf("All is well (maybe!)\n");
    return 0;
}
