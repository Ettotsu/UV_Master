cmake_minimum_required(VERSION 3.16)
project(UV_Master)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Local source files here
SET(TARGET_SRC
    src/player.cpp
    src/game.cpp
    )

add_executable(UV_Master src/main.cpp ${TARGET_SRC})
target_link_libraries(UV_Master PRIVATE sfml-graphics)
target_compile_features(UV_Master PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET UV_Master
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:UV_Master>
        VERBATIM)
endif()

install(TARGETS UV_Master)
