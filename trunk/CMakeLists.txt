cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
set (PROJECT SmartHouse)
project (${PROJECT})

set (HEADERS
	smart_house/cWindow.h
	smart_house/cHouse.h
	smart_house/cFloor.h
	smart_house/cRoom.h
	smart_house/cString.h
)
set (SOURCES
	smart_house/main.cpp
	smart_house/cWindow.cpp
	smart_house/cHouse.cpp
	smart_house/cFloor.cpp
	smart_house/cRoom.cpp
	smart_house/cString.cpp
)


macro (add_app_executable BUILD_TYPE)
	add_executable (${PROJECT}-${BUILD_TYPE} ${HEADERS} ${SOURCES})

	if ("${BUILD_TYPE}" STREQUAL "debug")
		set_target_properties (${PROJECT}-${BUILD_TYPE} PROPERTIES COMPILE_FLAGS "${CMAKE_C_FLAGS_DEBUG}")
	elseif ("${BUILD_TYPE}" STREQUAL "release")
		set_target_properties (${PROJECT}-${BUILD_TYPE} PROPERTIES COMPILE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
	endif()
endmacro()

MESSAGE("Current OS is ${CMAKE_SYSTEM_NAME}") 

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	add_app_executable ("debug")
	add_app_executable ("release")
else ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	add_executable (${PROJECT} ${HEADERS} ${SOURCES})
endif()
