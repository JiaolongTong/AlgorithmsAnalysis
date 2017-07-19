#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint32_t Roll_bit(char n, uint32_t * REGn){

        char flag = (* REGn>>n)&0x0001;
        if(flag)
    	    *REGn  &=~(1<<n) ;
	else
             *REGn  |= (1<<n) ;

        return (*REGn);
}


void main(){
         uint32_t a = 0x1234;
         uint32_t *p =&a;
         printf("yuanshi:%x \n",a);
         a=Roll_bit(12,p);
         printf("fanzhuan:%x \n",a);

}
