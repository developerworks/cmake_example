# 源码清单
set(LIB_SRC hello.c)
# 库输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_definitions("-DLIBHELLO_BUILD")

# 库名称
add_library(libhello SHARED ${LIB_SRC})

# 改名
set_target_properties(libhello PROPERTIES OUTPUT_NAME "hello")
