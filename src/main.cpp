#include "main.h"
#include "kappaAux/odomInput.hpp"
#include "kappaAux/odomInput2Imu.hpp"
#include "kappaAux/odomInput3Imu.hpp"
#include "kappaAux/odomInput4.hpp"
#include "kappaAux/odomInput41.hpp"
#include "kappaAux/odomInput4Imu.hpp"
#include "kappaAux/odomInput4Imu2.hpp"
#include "kappaAux/odomInput4Imu3.hpp"
#include "kappaAux/odomInput4Imu4.hpp"
#include "kappaAux/odomInputChen1.hpp"
#include "kappaAux/odomInputChenImu.hpp"


void initialize() {
  okapi::Logger::setDefaultLogger(std::make_shared<okapi::Logger>(std::make_unique<okapi::Timer>(), "/ser/sout", okapi::Logger::LogLevel::debug));
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {

  auto data = std::make_shared<kappa::FileInput<5>>("/usd/odomInputTelem.csv");
  auto odom1 = std::make_shared<OdomInput>(OdomInput::OdomVals{13.3125, 5.4375},
      std::make_unique<okapi::PassthroughFilter>(),
      std::make_unique<okapi::PassthroughFilter>(),
      std::make_unique<okapi::PassthroughFilter>(),
      std::make_shared<kappa::ArrayOutputLogger<double,6>>()
    );

  auto odom2 =
      std::make_shared<OdomInput4>(OdomInput4::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom3 =
      std::make_shared<OdomInput2Imu>(OdomInput2Imu::OdomVals{6.65625, 5.4375},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom4 =
      std::make_shared<OdomInput3Imu>(OdomInput3Imu::OdomVals{13.3125, 5.4375},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom5 =
      std::make_shared<OdomInput4Imu>(OdomInput4Imu::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom6 =
      std::make_shared<OdomInput4Imu2>(OdomInput4Imu2::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom7 =
      std::make_shared<OdomInput4Imu3>(OdomInput4Imu3::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom8 =
      std::make_shared<OdomInput4Imu4>(OdomInput4Imu4::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom9 =
      std::make_shared<OdomInput41>(OdomInput41::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom10 =
      std::make_shared<OdomInputChen1>(OdomInputChen1::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto odom11 =
      std::make_shared<OdomInputChenImu>(OdomInputChenImu::OdomVals{13.3125, 10.875},
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_unique<okapi::PassthroughFilter>(),
        std::make_shared<kappa::ArrayOutputLogger<double,6>>()
      );

  auto t = pros::millis();

  auto count = 0;

  while(true) {
    data->get();

    if (!(count % 1)) {
      //odom1->set(data->getValue()); // Decent Performance (.76, .52, .005) (3 encoder)
      //odom2->set(data->getValue()); // Good Performance (-.55, -.47, .019) (4 encoder)
      //odom3->set(data->getValue()); // Decent Performance (.61, .06, .001) (2 encoder/imu - known to be unreliable in certain scenarios)
      //odom4->set(data->getValue()); // Poor Performance (1.68, .66, 0) (3 encoder/imu)
      //odom5->set(data->getValue()); // Poor Performance (1.00, 1.06, 0) (4 encoder/imu - maybe improved with sensor fusion or removing resolution optimizer?)
      //odom6->set(data->getValue()); // Good Performance (.52, .12, .000) (4 encoder/imu w/removed resolution optimizer)
      //odom7->set(data->getValue()); // Disappointing Performance (.94, -1.03, .001) (4 encoder/imu w/fusion heading calculation)
      //odom8->set(data->getValue()); // Good Performance (.52, .12, .000) (4 encoder/imu w/both above changes)
      //odom9->set(data->getValue()); // Decent Performance (-.88, .2, .019) (4 encoder w/resolution optimizer)
      //odom10->set(data->getValue()); // Decent Performance (-.88, .20. .019) (nonnegligibly less intensive)
      //odom11->set(data->getValue()); // Good Performance (.51, .12, .001) (nonnegligibly less intensive, w/ imu)
    }

    count++;
    pros::Task::delay_until(&t, 2);
  }

}
