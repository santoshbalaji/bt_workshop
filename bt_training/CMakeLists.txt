cmake_minimum_required(VERSION 3.8)
project(bt_training)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

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

add_executable(
  run_ex_3
  src/runner_ex_3.cpp
  src/charger_scanner.cpp
  src/dock_to_charger.cpp
  src/reset_to_home.cpp
  src/alarm.cpp
  src/publish_to_charger.cpp)

add_executable(
  run_ex_4
  src/runner_ex_4.cpp
  src/charger_request_subscriber.cpp
  src/charger_dock.cpp)

add_executable(
  run_ex_51
  src/runner_ex_51.cpp
  src/async_navigate_to_pose.cpp
  src/object_scanner.cpp
  src/reset_to_home.cpp
  src/alarm.cpp)

add_executable(
  run_ex_52
  src/runner_ex_52.cpp
  src/async_navigate_to_pose.cpp
  src/object_scanner.cpp
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

ament_target_dependencies(
  run_ex_3
  behaviortree_cpp
  rclcpp
  std_msgs
)

ament_target_dependencies(
  run_ex_4
  behaviortree_cpp
  rclcpp
  std_msgs
)

ament_target_dependencies(
  run_ex_51
  behaviortree_cpp
)

ament_target_dependencies(
  run_ex_52
  behaviortree_cpp
)

install(TARGETS
run_ex_1
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_2
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_3
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_4
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_51
DESTINATION lib/${PROJECT_NAME})

install(TARGETS
run_ex_52
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
