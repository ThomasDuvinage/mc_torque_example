#pragma once

#include <mc_control/mc_controller.h>


#include "api.h"

struct TorqueTest_DLLAPI TorqueTest : public mc_control::MCController
{
  TorqueTest(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;
};