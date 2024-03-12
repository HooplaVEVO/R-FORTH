#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

int ParseType(const char *token);
int SplitString(char *str, char *tokens[], const int maxTokens);

int main() {
    int maxTokens = 50;
    int stk_cap = 20;
    char *tokens[maxTokens];
    int_stack_t* stk; 
    int_stack_init(stk, stk_cap);
    char str[256]; 
    printf("This is Myles Kaufman's implementation of Forth in C. Type quit to close the program.");
    while (1) {
        fgets(str, sizeof(str), stdin);
        int tokenCount = SplitString(str, tokens, maxTokens);

        if (strcmp(str, "quit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            //Creating a token struct for every line of input and determining what to do with it.
            for (int i = 0; i < tokenCount; i++) {
                token_t *t = token_allocate();
                token_new(t);
                token_init(t, tokens[i], ParseType(tokens[i]));

                //If token is of type NUMBER, convert to int and push to the stack.
                if (token_type(t)==NUMBER) {
                    char *endptr;
                    long int tokenInt = strtol(token_text(t), &endptr, 10);
                    int_stack_push(stk,tokenInt);
                    printf("Integer pushed to stack successfully. Result: %ld\n", tokenInt);
                    token_free(t);
                }

                //If token is of type OPERATOR, call the specific stack operation.
                if (token_type(t) == OPERATOR) {
                    switch (*token_text(t)) {
                        case '+':
                            int_stack_add(stk);
                            break;
                        case '-':
                            int_stack_sub(stk);
                            break;
                        case '*':
                            int_stack_mul(stk);
                            break;
                        case '/':
                            int_stack_div(stk);
                            break;
                        default:
                            printf("WARNING: Unidentified Operator\n");
                            break;
                    }
                    token_free(t);
                }
                //If word is of type symbol, do nothing for now
                if(token_type(t)==SYMBOL){
                    //Do stuff
                    token_free(t);
                }
                //If token is of WORD type, just check for all stack operations for now
                if(token_type(t)==WORD){
                    if(strcmp(token_text(t), "swap") == 0){
                        int_stack_swap(stk);
                    }
                    if(strcmp(token_text(t), "dup") == 0){
                        int_stack_dup(stk);
                    }
                    if(strcmp(token_text(t), "rot") == 0){
                        int_stack_rot(stk);
                    }
                    if(strcmp(token_text(t), "drop") == 0){
                        int_stack_drop(stk);
                    }
                    if(strcmp(token_text(t), "over") == 0){
                        int_stack_over(stk);
                    }
                    if(strcmp(token_text(t), "2swap") == 0){
                        int_stack_2swap(stk);
                    }
                    if(strcmp(token_text(t), "2drop") == 0){
                        int_stack_2drop(stk);
                    }
                    if(strcmp(token_text(t), "2over") == 0){
                        int_stack_2over(stk);
                    }
                    if(strcmp(token_text(t), "2dup") == 0){
                        int_stack_2dup(stk);
                    }
                    token_free(t);
                }
                int_stack_print(stk,stdout);
            }
            
        }
    }
    return 0;
}

int ParseType(const char *token) {
    if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
        return OPERATOR;
    } else if (isalpha(*token)) {
        return WORD;
    } else if (isdigit(*token)) {
        return NUMBER;
    } else {
        return SYMBOL;
    }
}

int SplitString(char *str, char *tokens[], const int maxTokens) {
    int i = 0;
    for (i = 0; i < maxTokens; i++) {
        char *token = strtok(i == 0 ? str : NULL, " \t\n");
        tokens[i] = token;
        if (token == NULL) {
            break;
        }
    }
    return i;
}