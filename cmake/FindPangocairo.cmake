# - Try to find Pango
# Once done, this will define
#
#  Pango_FOUND - system has Pango
#  Pango_INCLUDE_DIRS - the Pango include directories
#  Pango_LIBRARIES - link these to use Pango

find_package(PkgConfig)
pkg_check_modules(PC_LIBPANGOCAIRO QUIET pangocairo)
set(LIBPANGOCAIRO_DEFINITIONS ${PC_LIBPANGOCAIRO_CFLAGS_OTHER})
find_path(LIBPANGOCAIRO_INCLUDE_DIR pango/pangocairo.h
	HINTS ${PC_LIBPANGOCAIRO_INCLUDE_DIR} ${PC_LIBPANGOCAIRO_INCLUDE_DIRS}
		        PATH_SUFFIXES pango )
find_library(LIBPANGOCAIRO_LIBRARY NAMES pangocairo libpangocairo libpangocairo-1.0 pangocairo-1.0 
	HINTS ${PC_LIBPANGOCAIRO_LIBDIR} ${PC_LIBPANGOCAIRO_LIBRARY_DIRS})
set(PANGOCAIRO_LIBRARIES ${LIBPANGOCAIRO_LIBRARY} )
set(PANGOCAIRO_INCLUDE_DIRS ${LIBPANGOCAIRO_INCLUDE_DIR})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libpangocairo DEFAULT_MSG
	LIBPANGOCAIRO_LIBRARY PANGOCAIRO_INCLUDE_DIRS)
mark_as_advanced(PANGOCAIRO_INCLUDE_DIRS PANGOCAIRO_LIBRARIES)

