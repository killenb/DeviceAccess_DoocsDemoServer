#ifndef EQ_FCT_OVEN_H
#define EQ_FCT_OVEN_H

#include <eq_fct.h>
#include <ChimeraTK/Device.h>
namespace ctk = ChimeraTK;

class EqFctOven : public EqFct {
  D_float temperature{this, "TEMPERATURE"};
  D_int heatingCurrent{this, "HEATING_CURRENT"};
  D_float setpoint{this, "SETPOINT"};

  ctk::Device oven{"oven"};
  ctk::ScalarRegisterAccessor<int> hwHeatingCurrent{oven.getScalarRegisterAccessor<int>("heater.heatingCurrent")};
  ctk::ScalarRegisterAccessor<float> hwTemperature{oven.getScalarRegisterAccessor<float>("heater.temperatureReadback")};

 public:
  void update() override;

  static constexpr int code = 10;
  int fct_code() override { return code; }
};

#endif // EQ_FCT_OVEN_H
