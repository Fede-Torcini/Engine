cmake_minimum_required(VERSION 3.10)

project(engine)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(abs_include_dir "." REALPATH)
set(include_dirs ${abs_include_dir})
    
file(GLOB_RECURSE header_files "*.h")
file(GLOB_RECURSE src_files "*.cpp")

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

get_filename_component(abs_include_dir "../Dependencies/SFML/include" REALPATH)
list(APPEND include_dirs ${abs_include_dir})
get_filename_component(abs_include_dir "include" REALPATH)
list(APPEND include_dirs ${abs_include_dir})

list(APPEND link_libs_debug sfml-graphics-s-d sfml-window-s-d sfml-audio-s-d sfml-system-s-d)
list(APPEND link_libs_release sfml-graphics-s sfml-window-s sfml-audio-s sfml-system-s)
list(APPEND link_libs_general opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg )

include_directories(${include_dirs})
link_directories("../Dependencies/SFML/lib" REALPATH)
add_definitions(-DSFML_STATIC)

add_executable(${PROJECT_NAME} ${src_files} ${header_files})

foreach(library IN ZIP_LISTS link_libs_debug)
    target_link_libraries(${PROJECT_NAME} debug ${library_0}) 
endforeach()

foreach(library IN ZIP_LISTS link_libs_release)
    target_link_libraries(${PROJECT_NAME} optimized ${library_0}) 
endforeach()
target_link_libraries(${PROJECT_NAME} ${link_libs_general}) 


set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
