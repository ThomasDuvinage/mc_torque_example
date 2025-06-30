set(controller_SRC
  TorqueTest.cpp
)

set(controller_HDR
  TorqueTest.h
)

add_controller(${PROJECT_NAME} ${controller_SRC} ${controller_HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DTorqueTest_EXPORTS")

