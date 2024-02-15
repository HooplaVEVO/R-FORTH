#include <stdio.h>
#include <stdlib.h>

#include "token.h"

token_t  *token_allocate() {
    return (token_t*) malloc(sizeof(token_t));
}

void token_new(token_t *token){
    token->token_text_t = "";
    token->token_type_t= 0;
}

void token_init(token_t *token, char text, enum Type type){
    token->token_text_t = text;
    token->token_type_t = type;
}

char token_text(token_t *token){
    return token->token_text_t;
}

enum Type token_type(token_t *token){
    return token->token_type_t;
}

void token_print_text(token_t *token){
    printf("%d",token->token_text_t);
}

void token_print_type(token_t *token){
    switch(token->token_type_t) {
        case 1:
            printf("Number");
            break;
        case 2:
            printf("Operator");
            break;
        case 3:
            printf("Symbol");
            break;
        case 4:
            printf("Word");
            break;
        case 0:
            printf("NULL");
            break;
    }
}