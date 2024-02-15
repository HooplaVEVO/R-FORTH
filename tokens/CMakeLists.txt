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
