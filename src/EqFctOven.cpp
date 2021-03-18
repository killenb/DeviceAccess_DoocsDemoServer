#include "EqFctOven.h"

void EqFctOven::update() {
  static const double gain = 100.0;

  try {
    if(!oven.isFunctional()) {
      oven.open();
    }

    // a simple proportional controller
    hwTemperature.read();
    hwHeatingCurrent = gain * (setpoint.value() - hwTemperature);
    hwHeatingCurrent.write();

    // No exception until here -> Device is working. Clear the error flag.
    set_error(no_error);

    // update the doocs properties
    temperature.set_value(hwTemperature);
    heatingCurrent.set_value(hwHeatingCurrent);
  }
  catch(ctk::runtime_error& e) {
    set_error(device_error, e.what());
  }
}
