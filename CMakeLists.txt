cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")   
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI")
endif ()


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resource"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resource/Images"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)


add_executable(main ${SOURCES} "src/drawTile.h" "src/drawTile.cpp")
file(GLOB_RECURSE RESOURCE_FILES "resources/*")
target_sources(main PRIVATE ${RESOURCE_FILES})

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
target_link_libraries(main PRIVATE SFML::Audio)
target_link_libraries(main PRIVATE SFML::Window)
target_link_libraries(main PRIVATE SFML::System)
target_link_libraries(main PRIVATE SFML::Network)