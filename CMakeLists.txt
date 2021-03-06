cmake_minimum_required(VERSION 3.7)
project(sentry)
option(WITH_PROF "Enable profiling and coverage report analysis" OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake)
include(GNUInstallDirs)

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckLibraryExists)
INCLUDE(CheckSymbolExists)
INCLUDE(CheckFunctionExists)
include(CheckStructHasMember)

INCLUDE(cmake/FindCURL.cmake)
INCLUDE(cmake/findjson.cmake)
# be pedantic
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
      "Choose the type of build, options are: Debug Release"
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)


message("CMAKE_C_FLAGS_DEBUG is ${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_RELEASE is ${CMAKE_C_FLAGS_RELEASE}")





# assuming target "my_prog" exists
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
IF(CMAKE_BUILD_TYPE MATCHES Debug)
  message("Debug build.")
ELSEIF(CMAKE_BUILD_TYPE MATCHES Release)
  message("Release build.")
ELSE()
  message("Some other build type.")
ENDIF()

#lib sentry
check_library_exists(${JSON_LIBRARY}   json_object_object_get_ex    ""   JSON_OLD)
check_library_exists(${JSON_LIBRARY}   json_object_new_int64    ""   JSON_OLD64)


CHECK_STRUCT_HAS_MEMBER("struct json_object_iter" key json.h HAVE_JSON_OBJECT_ITER LANGUAGE C)


set(LIB_SRC deps/list/list_node.c deps/list/list_iterator.c deps/list/list.c src/main.c src/url.c)

add_library(sentry SHARED ${LIB_SRC})
set_target_properties(sentry PROPERTIES  VERSION 1.0
  SOVERSION 1
    PUBLIC_HEADER "api/sentry.h;deps/list/list.h")
configure_file(sentry.pc.in sentry.pc @ONLY)

target_include_directories(sentry PUBLIC . deps/url deps/list api/ include/)
target_include_directories(sentry PRIVATE ${JSON_INCLUDE_DIRS})

set(LIB_LINK ${CURL_LIBRARY} ${JSON_LIBRARY})

target_link_libraries(sentry ${LIB_LINK})
link_directories()

install(TARGETS sentry
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sentry)
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



add_test(sentry_test sentry_test)

#add_test(sentry_test COMMAND sentry_test)
add_custom_target(check COMMAND sentry_test)

# Have cmake create a compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WITH_PROF)
		message("PROFiling enabled")
		include(cmake/coverage.cmake)
		APPEND_COVERAGE_COMPILER_FLAGS()

    set(COVERAGE_LCOV_EXCLUDES '../tests/*' 'ctest.h')
		#setup_target_for_coverage(sentry_coverage sentry_test coverage)
	  SETUP_TARGET_FOR_COVERAGE_LCOV(NAME coverage EXECUTABLE sentry_test DEPENDENCIES sentry sentry_test)	


    include(Coveralls)
    coveralls_setup(
        "${LIB_SRC}" 
        ON
        "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
endif()



