cmake_minimum_required(VERSION 3.8)
project(bt_training)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(behaviortree_cpp REQUIRED)

include_directories(include)

add_executable(
  run_ex_1
  src/runner_ex_1.cpp
  src/navigate_to_pose.cpp
  src/object_scanner.cpp
  src/reset_to_home.cpp
  src/alarm.cpp)

add_executable(
  run_ex_2
  src/runner_ex_2.cpp
  src/charger_scanner.cpp
  src/dock_to_charger.cpp
  src/reset_to_home.cpp
  src/alarm.cpp)

ament_target_dependencies(
  run_ex_1
  behaviortree_cpp
)

ament_target_dependencies(
  run_ex_2
  behaviortree_cpp
)

install(TARGETS
run_ex_1
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_2
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
