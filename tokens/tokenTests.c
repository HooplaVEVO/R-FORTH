#include <stdio.h>
#include "token.h"

int main(int argc,char** argv){
    token_t *t1 = token_allocate();
    token_new(t1);
    enum Type var = WORD;
    token_init(t1,"this is a string", var);
    printf("%d\n", token_text(t1));
    printf("%d\n",token_type(t1));

    return 0;
}