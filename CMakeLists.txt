cmake_minimum_required(VERSION 3.9)
project(sentry VERSION 1.0.0 DESCRIPTION "Sentry C Library")
include(GNUInstallDirs)

INCLUDE(cmake/FindCURL.cmake)



#lib sentry

add_library(sentry SHARED src/main.c)
set_target_properties(sentry PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER api/sentry.h)
configure_file(sentry.pc.in sentry.pc @ONLY)
target_include_directories(sentry PRIVATE . deps/url)

set(LIB_LINK ${CURL_LIBRARY})

target_link_libraries(sentry ${LIB_LINK})
link_directories()

install(TARGETS sentry
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/sentry.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)


# library test tool
add_executable(sentry_lib_cli src/argtable3.c src/tools/lib_cli.c)
target_include_directories(sentry_lib_cli PUBLIC api/)
target_link_libraries(sentry_lib_cli sentry)

install(TARGETS sentry_lib_cli RUNTIME DESTINATION bin)


# tests
include(CTest)
enable_testing()

file(GLOB TEST_FILES tests/*.c)
add_executable(sentry_test src/test_main.c ${TEST_FILES})
target_include_directories(sentry_test PUBLIC include/)
target_include_directories(sentry_test PUBLIC deps/url/)
target_include_directories(sentry_test PUBLIC api/)
target_link_libraries(sentry_test sentry)
add_test(sentry_test COMMAND sentry_test)

#add_test(sentry_test COMMAND sentry_test)
add_custom_target(check COMMAND sentry_test)


