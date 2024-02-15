#include <stdio.h>
#include <ctype.h>
#include "token.h"

int main(int argc,char** argv){
    char* tokens[] = "";
    char* str = "";
    printf("Enter a line of input:");
    scanf("%c",str);
    int tokenCount = SplitString(str,tokens,100);
    for (int i=0;i<tokenCount;i++){
        token_t *t = token_allocate();
        token_new(t);
        token_init(t,tokens[i],ParseType(tokens[i]));
        printf("Token #%d information: ",i);
        token_print_text(t);
        printf(", Type: ");
        token_print_type(t);
        printf("\n");
    }
}
enum Type ParseType(char token){
    if(token=='+'||token=='-'||token=='*'||token=='/'){
        return enum OPERATOR;
    }
    else if(isalpha(token)){
        return enum WORD;
    } 
    else if (isdigit(token)){
        return enum NUMBER;
    }
    else{
        return enum SYMBOL;
    }
}

int SplitString(char *str, char *tokens[], const int maxTokens) {
    int i = 0;
    for (i = 0; i < maxTokens; i++) {
        char *token = strtok(str, " \t\n");
        str = NULL;
        tokens[i] = token;
        if (token == NULL) {
            break;
        }
    }
    return i;
}