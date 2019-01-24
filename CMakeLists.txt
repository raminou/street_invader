cmake_minimum_required (VERSION 3.1)

project (Game)

set (CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH build/${CMAKE_BUILD_TYPE})

include_directories(headers)

include_directories(SFML-2.5.1/include)

link_directories(SFML-2.5.1/lib)

file(GLOB_RECURSE
	source_files
	src/*)

add_executable (game
	${source_files})


target_link_libraries(game sfml-graphics)
target_link_libraries(game sfml-window)
target_link_libraries(game sfml-system)
