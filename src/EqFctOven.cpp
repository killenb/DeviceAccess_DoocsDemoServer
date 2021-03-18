#include "EqFctOven.h"

void EqFctOven::update() {
  static int i{0};
  heatingCurrent.set_value(i++);
}
