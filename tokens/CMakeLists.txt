add_executable (
    tokenTest 
    tokenTests.c 
    token.c)

target_link_libraries(
  tokenTest
  -lm
)
