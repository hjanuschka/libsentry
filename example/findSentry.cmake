find_path(SENTRY_INCLUDE_DIR NAMES sentry/sentry.h)
find_library(SENTRY_LIBRARY NAMES sentry)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SENTRY DEFAULT_MSG
  SENTRY_LIBRARY
  SENTRY_INCLUDE_DIR
)

if(SENTRY_FOUND)
  set(SENTRY_LIBRARIES ${SENTRY_LIBRARY})
  # hack to get old and new layout working:
  set(SENTRY_INCLUDE_DIRS ${SENTRY_INCLUDE_DIR})
endif()

mark_as_advanced(
  SENTRY_LIBRARY
  SENTRY_INCLUDE_DIR
)


