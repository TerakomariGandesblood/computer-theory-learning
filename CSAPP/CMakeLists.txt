set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_library(csapp STATIC lib/csapp.c)
add_library(csapp::csapp ALIAS csapp)
target_link_libraries(csapp PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(csapp PUBLIC lib)

add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter05)
add_subdirectory(chapter07)
add_subdirectory(chapter08)
add_subdirectory(chapter09)
add_subdirectory(chapter10)
add_subdirectory(chapter11)
add_subdirectory(chapter12)
