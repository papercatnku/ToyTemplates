set(pt_inc "${CMAKE_CURRENT_LIST_DIR}/../pocket_tools/inc")
file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.cc")
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_LIST_DIR}/inc/*.hpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.h")


add_library(sdk_prototype STATIC ${SRCS} ${HDRS})

target_include_directories(
    sdk_prototype
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${pt_inc}
)

add_executable(sdk_prototype_test "${CMAKE_CURRENT_LIST_DIR}/test/main.cc")
target_link_libraries(sdk_prototype_test sdk_prototype)
