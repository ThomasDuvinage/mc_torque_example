#include "TorqueTest.h"

TorqueTest::TorqueTest(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::MCController(rm, dt, config, Backend::Tasks)
{
  dynamicConstraintTest = std::make_unique<mc_solver::DynamicsConstraint>(robots(), robot().robotIndex(), solver().dt(), std::array<double, 3>({0.1, 0.01, 0.5}), 1.0, false);
  contactConstraintTest = std::make_unique<mc_solver::ContactConstraint>(timeStep, mc_solver::ContactConstraint::ContactType::Acceleration);
  
  solver().addConstraintSet(dynamicConstraintTest);
  solver().addConstraintSet(contactConstraintTest);
  solver().addTask(postureTask);
  solver().setContacts({{}});

  addContact({robot().name(), "ground", "LeftFoot", "AllGround"});
  addContact({robot().name(), "ground", "RightFoot", "AllGround"});

  mc_rtc::log::success("TorqueTest init done ");
}

bool TorqueTest::run()
{
  return mc_control::MCController::run(mc_solver::FeedbackType::ClosedLoopIntegrateReal);
}

void TorqueTest::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::MCController::reset(reset_data);
}

CONTROLLER_CONSTRUCTOR("TorqueTest", TorqueTest)
