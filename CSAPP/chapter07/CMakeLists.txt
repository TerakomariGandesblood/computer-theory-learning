# SHARED 必须大写
add_library(mymalloc SHARED mymalloc.c)

add_executable(intr intr.c)
target_link_libraries(intr dl)
