#include <gtest/gtest.h>

#include "token.hh"
#include "int_stack.hh"

TEST(TokenTest, Initialization)
{
    token_t *token = token_allocate();
    token_new(token);
    token_init(token, "test_token", WORD);

    EXPECT_EQ(token_type(token), WORD);
    EXPECT_EQ(strcmp(token_text(token), "test_token"), 0);
}

TEST(TokenTest, Addition)
{
    int_stack_t *stack = int_stack_init(stack,5);
    token_t *t1, *t2 = token_allocate();
    token_new(t1);
    token_new(t2);
    token_init(t1, "13", NUMBER);
    token_init(t2, "18", NUMBER);
    int_stack_push(stack,atoi(token_text(t1)));
    int_stack_push(stack,atoi(token_text(t2)));
    EXPECT_EQ(int_stack_add(stack), 31);
}

TEST(TokenTest, Subtraction)
{
    int_stack_t *stack = int_stack_init(stack,5);
    token_t *t1, *t2 = token_allocate();
    token_new(t1);
    token_new(t2);
    token_init(t1, "13", NUMBER);
    token_init(t2, "18", NUMBER);
    int_stack_push(stack,atoi(token_text(t1)));
    int_stack_push(stack,atoi(token_text(t2)));
    EXPECT_EQ(int_stack_sub(stack), -5);
}

TEST(TokenTest, Multiplication)
{
    int_stack_t *stack = int_stack_init(stack,5);
    token_t *t1, *t2 = token_allocate();
    token_new(t1);
    token_new(t2);
    token_init(t1, "7", NUMBER);
    token_init(t2, "8", NUMBER);
    int_stack_push(stack,atoi(token_text(t1)));
    int_stack_push(stack,atoi(token_text(t2)));
    EXPECT_EQ(int_stack_mul(stack), 56);
}

TEST(TokenTest, Subtraction)
{
    int_stack_t *stack = int_stack_init(stack,5);
    token_t *t1, *t2 = token_allocate();
    token_new(t1);
    token_new(t2);
    token_init(t1, "5", NUMBER);
    token_init(t2, "100", NUMBER);
    int_stack_push(stack,atoi(token_text(t1)));
    int_stack_push(stack,atoi(token_text(t2)));
    EXPECT_EQ(int_stack_sub(stack), 20);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}