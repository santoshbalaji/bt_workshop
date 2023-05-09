cmake_minimum_required(VERSION 3.8)
project(bt_training)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(behaviortree_cpp REQUIRED)

include_directories(include)

add_executable(
  startup
  src/runner.cpp
  src/say_something.cpp
  src/think_something.cpp)

ament_target_dependencies(
  startup
  behaviortree_cpp
)

install(TARGETS
startup
DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY config
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
