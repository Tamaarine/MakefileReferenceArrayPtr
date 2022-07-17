#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 5; // This is a number
    int * ptrNum = &num; // This is a pointer to the number we just created
    
    printf("My number is %d and the pointer is %p\n", num, ptrNum);
    printf("Address of the pointer is %p\n", &ptrNum); // To find the address of the pointer, do &ptrNum, it is type int ** because it is a pointer to a memory address, and the memory
    // address it is pointing to is ptrNum's memory address. 
    
    // Let's switch to figuring out the implicit addition when doing pointer arthimetic 
    // Take char * for example, which is a pointer to a char or you can treat it as a String
    // If we do examplePtr[1] == *(examplePtr + 1), and internally it will add only 1 byte because char is one byte.
    char example = 'a';
    char example2 = 'b';
    char * examplePtr = &example;
    
    printf("My char is %c\n", example);
    printf("My char is %p\n", &example2);
    printf("The pointer to my char is %p\n", examplePtr);
    
    // And since b is allocated right next to 'a' by checking out the element right after examplePtr it will print b
    printf("Pointer arthiemetic: %c vs %c\n", examplePtr[1], *(examplePtr + 1));
    
    // An array internally resolves to a pointer which points to the first element
    int nums[] = {400, 500, 600};
    int * arrPtr = nums;
    
    printf("array %p\n", nums);
    printf("array %p\n", arrPtr);
    
    // Internally it is adding 2 * 4 bytes to the pointer in order to get to 600's memory address. 
    printf("same operation %d %d\n", nums[2], *(arrPtr + 2));
    
    printf("memory address of 400: %p\n", arrPtr + 0);
    printf("memory address of 500: %p\n", arrPtr + 1);
    printf("memory address of 600: %p\n", arrPtr + 2);
    printf("Size of int %ld\n", sizeof(int));
    
    int twoD[3][3] = {{800, 900, 1000}, 
                {500, 100, 200},
                {-1, -2, -3}};
    
    int (*ptrPtr)[3] = twoD; 
    
    printf("2d array %p\n", twoD );
    printf("2d array %p\n", ptrPtr);
    
    // When doing pointer arthimetic it adds on the most outer layer first, then the inner layer
    // ptrPtr + 1, will first add 8 bytes, navigating between the 2d arrays (moving down rows)
    // Then you will dereference it to get the actual array pointer back in order to navigate
    // on the array element level, adding 4 bytes according to which column of number you are picking
    printf("Same operation %d %d\n", twoD[1][2], *(*(ptrPtr + 1) + 2));
    


    return 0;
}
