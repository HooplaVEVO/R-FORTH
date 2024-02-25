#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

int ParseType(const char *token);
int SplitString(char *str, char *tokens[], const int maxTokens);

int main() {
    int maxTokens = 10;
    char *tokens[maxTokens];
    char str[256]; 
    printf("Enter a line of input: ");
    fgets(str, sizeof(str), stdin);
    int tokenCount = SplitString(str, tokens, maxTokens);

    for (int i = 0; i < tokenCount; i++) {
        token_t *t = token_allocate();
        token_new(t);
        token_init(t, tokens[i], ParseType(tokens[i]));
        printf("Token #%d information: ", i);
        token_print_text(t);
        printf(", Type: ");
        token_print_type(t);
        printf("\n");
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