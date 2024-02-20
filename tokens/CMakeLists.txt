add_executable (
    tokenTest 
    tokenTests.c 
    token.c)

target_link_libraries(
  tokenTest
  -lm
)

add_executable(
  tokenInput
  main.c
  token.c
)
target_link_libraries(
  tokenInput
  -lm
)

add_executable(
  stackDemo
  int_stack_demo.c
  int_stack.c
)

target_link_libraries(
  stackDemo 
  -lm
)
