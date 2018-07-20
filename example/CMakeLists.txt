
cmake_minimum_required(VERSION 3.9)
project(sentry_example VERSION 1.0.0 DESCRIPTION "Sentry C Library usage")

include(findSentry.cmake)

set(LIB_LINK ${SENTRY_LIBRARY})


add_executable(sentry_example main.c)
target_link_libraries(sentry_example ${LIB_LINK})
target_include_directories(sentry_example PRIVATE ${SENTRY_INCLUDE_DIRS})
