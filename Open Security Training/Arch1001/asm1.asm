asm (   assembly template   :
        output operands     :           /*optional*/
        input operands      :           /*optional*/
        list of clobbered registers     /*optional*/
);

        #include <stdio.h>
        void main(){
            int myVar = 0xabcd;
            // value into register from C variable.
            asm("movl %0, %%eax" : : "r" (myVar) );
            asm("mov $0x1234, %eax");
            // value into C variable from register
            asm("movl %%eax, %0" : "=r" (myVar) );
            printf("myVar = %x\n", myVar);
        }
