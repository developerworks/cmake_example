include_directories(${PROJECT_SOURCE_DIR}/libhello)
#link_directories(${PROJECT_BINARY_DIR}/lib)

set(APP_SRC main.c)
set(REALLOC1 realloc1.c)
set(REALLOC2 realloc2.c)
set(STRNDUP strndup.c)
set(LONGEST_PREFIX_MATCH longest_prefix_match.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(hello ${APP_SRC})
add_executable(realloc1 ${REALLOC1})
add_executable(realloc2 ${REALLOC2})
add_executable(strndup ${STRNDUP})
add_executable(longest_prefix_match ${LONGEST_PREFIX_MATCH})

target_link_libraries(hello libhello)
