add_executable( pocket_config_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/pocket_config_test.cc" )

message( STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}" )

target_include_directories( pocket_config_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc" )