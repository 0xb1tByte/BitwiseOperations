#include <stdio.h>
#include <stdint.h>
#include "header.h"


int main(int argc, char **argv)
{
    uint8_t state[] = {0x45, 0x84, 0x22, 0x7B, 0x38, 0xC1, 0x79, 0x55};
    
// *************************************************************************************************//
    // ========== Testing getBit()  ==========  //
            // state [0] = 0100 0101 , bit at position 3 = 0 (we count from the right side starting from 0)
           // state [1] = 1000 0100 , bit at position 3 = 0
           // state [2] = 0010 0010 , bit at position 3 = 0
           // state [3] = 0111 1011 , bit at position 3 = 1
           // state [4] = 0011 1000 , bit at position 3 = 1
           // state [5] = 1100 0001 , bit at position 3 = 0 
           // state [6] = 0111 1001 , bit at position 3 = 1
           // state [7] = 0101 0101 , bit at position 3 = 0
           printf("== Testing getBit == \n");
           uint8_t stateCounter1 = 0;
           uint8_t bitValue = 0;
           printf(" - get bit at position 3 for each element in state \n");
           for (;stateCounter1 < 8; stateCounter1++)
            {
                // get bit at position 3 for each element in state
              bitValue = getBit(state[stateCounter1],3);
              printf("     state [%d] = %d \n" , stateCounter1 , state[stateCounter1]);
               printf("     Binary value = ");
               print8Bits(state[stateCounter1]);
              printf("     Bit at position 3 = %d\n",bitValue);
              printf("\n");
           } // end_for
    // ======== end Testing getBit()  Part ========  //
    
     // ========== Testing copyBit()  ==========  //
            // state [0] = 0100 0101 ==> 0100 1101 = 77 
           // state [1] = 1000 0100 ==> 1000 1100 = 140
           // state [2] = 0010 0010 ==> 0010 0010 = 34
           // state [3] = 0111 1011 ==> 0111 0011 = 115
           // state [4] = 0011 1000 ==> 0011 0000 = 48
           // state [5] = 1100 0001 ==>1100 0001 = 193
           // state [6] = 0111 1001 ==> 0111 0001 = 113
           // state [7] = 0101 0101 ==> 0101 1101 = 93
          printf("== Testing copyBit == \n");
          uint8_t temp [8] = {0};
          uint8_t stateCounter2 = 0;
            memcpy (temp, state,sizeof(state));
            printf(" - set bit at position 3 with value of bit at position 2 for each element in state \n");
           for (;stateCounter2 < 8; stateCounter2++)
            {
                // set bit at position 3 with value of bit at position 2 for each element in state
                // ** Debugging ** 
               printf("    before : state [%d] = %d \n" , stateCounter2 , state[stateCounter2]);
               printf("    Binary value = ");
               print8Bits(state[stateCounter2]);
               printf("\n");
               state[stateCounter2] = copyBit(state[stateCounter2],3, getBit(state[stateCounter2],2) ); 
               printf("    after : state [%d] = %d \n",stateCounter2,state[stateCounter2]);
                printf("    Binary value = ");
               print8Bits(state[stateCounter2]);
               printf("\n");
               printf("\n");
            } // end_for
    // ======== end Testing copyBit() Part ========  //
// *************************************************************************************************//
	return 0;
} // end main


uint8_t getBit(uint8_t state , uint8_t bitPosition)
{
return ( (state >> bitPosition ) & 0x1);
} 


uint8_t copyBit(uint8_t state , uint8_t bitPosition, uint8_t bitValue)
{
uint8_t mask = ~(1 << bitPosition );
state = (state  & mask); // clear bit 
return (state | (bitValue << bitPosition ) );    
}

void print8Bits(uint8_t a)
{
    uint8_t i;

    for(i=0x80;i!=0;i>>=1) {
        printf("%c",(a&i)?'1':'0');
        if (i==0x10)
            printf(" ");
    }
}