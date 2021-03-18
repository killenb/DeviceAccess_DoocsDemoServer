#ifndef EQ_FCT_OVEN_H
#define EQ_FCT_OVEN_H

#include <eq_fct.h>

class EqFctOven : public EqFct {
    D_float temperature{this, "TEMPERATURE"};
    D_int   heatingCurrent{this, "HEATING_CURRENT"};


public:
    void update() override;

    static constexpr int code = 10;
    int   fct_code() override { return code; }
};

#endif // EQ_FCT_OVEN_H
