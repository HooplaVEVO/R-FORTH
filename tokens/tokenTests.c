#include <stdio.h>
#include "token.h"

int main(int argc,char** argv){
    token_t *t1 = token_allocate();
    enum Type var = WORD;
    token_init(t1,"this is a string", var);
    token_print_text(t1);
    token_print_type(t1);

    return 0;
}