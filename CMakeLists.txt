cmake_minimum_required(VERSION 2.8)
project(Lua-Cairo C)

set(BINDING_MAJOR "0")
set(BINDING_MINOR "1")

set(MAJOR "1")
set(MINOR "14")
set(PATCH "8")

set(VERSION "${BINDING_MAJOR}.${BINDING_MINOR} for Cairo ${MAJOR}.${MINOR}.${PATCH}")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Path where to install docs
set(WITH_DOCSDIR "share/docs/Lua-Cairo"
    CACHE STRING "Path to install examples")
# Lua version: JIT, 51, 52, and 53, default: 5.2
set(WITH_LUAVER "53"
    CACHE STRING "Version of Lua to use")

set(
	SOURCES
        src/cairo.c
        src/context.c
        src/image_surface.c
        src/font_face.c
        src/font_options.c
        src/path.c
        src/scaled_font.c
        #src/png.c
        src/surface.c
        src/text.c
        src/transformation.c
        #TODO: make conditional
        src/pangocairo.c
        src/xcb_surface.c
)

configure_file(
	${CMAKE_SOURCE_DIR}/cmake/config.h.in
	${CMAKE_SOURCE_DIR}/build/config.h
)

include_directories(${CMAKE_SOURCE_DIR}/build)

find_package(Cairo REQUIRED)
#TODO: make conditional
find_package(XCB REQUIRED)
find_package(Pango REQUIRED)
find_package(GLIB REQUIRED)
find_package(Pangocairo REQUIRED)

if (WITH_LUAVER MATCHES "53")
	find_package(Lua53 REQUIRED)
	set(LUA_INCLUDES ${LUA53_INCLUDE_DIR})
	set(LUA_LIBRARIES ${LUA53_LIBRARIES})
	set(LUA_LIBDIR "lib/lua/5.3" CACHE STRING "Lua C Module Install Path")
elseif (WITH_LUAVER MATCHES "52")
	find_package(Lua52 REQUIRED)
	set(LUA_LIBRARIES ${LUA52_LIBRARIES})
	set(LUA_INCLUDES ${LUA52_INCLUDE_DIR})
	set(LUA_LIBDIR "lib/lua/5.2" CACHE STRING "Lua C Module Install Path")
elseif (WITH_LUAVER MATCHES "51")
	find_package(Lua51 REQUIRED)
	set(LUA_INCLUDES ${LUA_INCLUDE_DIR})
	set(LUA_LIBRARIES ${LUA51_LIBRARIES})
	set(LUA_LIBDIR "lib/lua/5.1" CACHE STRING "Lua C Module Install Path")
elseif (WITH_LUAVER MATCHES "JIT")
	find_package(LuaJIT REQUIRED)
	set(LUA_INCLUDES ${LUAJIT_INCLUDE_DIR})
	set(LUA_LIBRARIES ${LUAJIT_LIBRARIES})
	set(LUA_LIBDIR "lib/lua/5.1" CACHE STRING "Lua C Module Install Path")
elseif (WITH_LUAVER MATCHES "user")
#	the source selects the right code based on the LUA_VERSION_NUM define,
#	so if the builder just wants to directly point us at the headers and
#	install location, that's all we need to know.
	set(LUA_INCLUDES ${LUA_INCLUDE_DIR})
	set(LUA_LIBDIR "lib/lua" CACHE STRING "Lua C Module Install Path")
else ()
	message(FATAL_ERROR "Unknown Lua version ${WITH_LUAVER}, must be 51, 52, 53, JIT, or user")
endif ()

include_directories(
	${CAIRO_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}
	${LUA_INCLUDES}
        #TODO: make conditional
        ${XCB_INCLUDE_DIRS}
	${GLIB_INCLUDE_DIRS}
	${PANGO_INCLUDE_DIRS}
	${PANGOCAIRO_INCLUDE_DIRS}
)

if (WIN32)
	add_definitions("/D_CRT_SECURE_NO_WARNINGS")
else ()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif ()


# Common code for modules
add_subdirectory(common)

add_library(
	Cairo
	MODULE
	${SOURCES}
)

set_target_properties(
	Cairo
	PROPERTIES
	PREFIX ""
)

target_link_libraries(
	Cairo
        common
	${CAIRO_LIBRARIES}
	${LUA_LIBRARIES}
	#TODO: Make conditioonal
        ${XCB_LIBRARIES}
	${GLIB_LIBRARIES}
	${PANGO_LIBRARIES}
	${PANGOCAIRO_LIBRARIES}
)

install(
	TARGETS Cairo
	DESTINATION ${LUA_LIBDIR}
)


# For the examples and tutorials
#add_subdirectory(examples)
#add_subdirectory(tutorials)

# For Windows DLL
#if (WIN32)
	#add_subdirectory(windows)
#endif ()

# CPack configuration
if (WIN32)
	set(CPACK_PACKAGE_NAME "Lua-Cairo")
	set(CPACK_NSIS_PACKAGE_NAME "Lua-Cairo")

	# This determine the *target* architecture
	if (CMAKE_SIZEOF_VOID_P MATCHES "8")
		set(WINARCH "amd64")
	else ()
		set(WINARCH "x86")
	endif ()

	if (MINGW)
		set(GENERATOR "MinGW")
	else ()
		set(GENERATOR "VC")
	endif ()

	set(CPACK_GENERATOR "ZIP")
	set(CPACK_MONOLITHIC_INSTALL FALSE)

	set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
	set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README")

	set(CPACK_PACKAGE_VENDOR "Malikania")
	set(CPACK_PACKAGE_VERSION "${VERSION}")
	set(CPACK_PACKAGE_VERSION_MAJOR ${MAJOR})
	set(CPACK_PACKAGE_VERSION_MINOR ${MINOR})
	set(CPACK_PACKAGE_FILE_NAME "Lua-Cairo-${VERSION}-${GENERATOR}-${WINARCH}")
	set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README")
	set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Lua-Cairo")
else ()
	set(CPACK_GENERATOR "TGZ")
endif ()

set(CPACK_SOURCE_PACKAGE_FILE_NAME "Lua-Cairo-${VERSION}-source")
set(CPACK_SOURCE_GENERATOR "ZIP;TGZ")
set(CPACK_SOURCE_IGNORE_FILES ".hg;_build_;.git")

include(CPack)
