if(EXISTS "/home/user/RK2/build/runTests[1]_tests.cmake")
  include("/home/user/RK2/build/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()
