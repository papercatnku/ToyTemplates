add_executable(pocket_param_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/pocket_paramgen_test.cc" )
target_include_directories( pocket_param_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc" )