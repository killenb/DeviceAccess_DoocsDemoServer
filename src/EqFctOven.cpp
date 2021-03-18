#include "EqFctOven.h"

void EqFctOven::update() {
  static const double gain = 100.0;

  if(!oven.isOpened()) {
    oven.open();
  }

  // a simple proportional controller
  hwTemperature.read();
  hwHeatingCurrent = gain * (setpoint.value() - hwTemperature);
  hwHeatingCurrent.write();

  // update the doocs properties
  temperature.set_value(hwTemperature);
  heatingCurrent.set_value(hwHeatingCurrent);
}
