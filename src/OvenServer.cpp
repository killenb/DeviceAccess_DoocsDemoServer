#include <doocs/Server.h>
#include "EqFctOven.h"

int main(int argc, char* argv[]) {
  doocs::Server server("oven_server");
  server.register_location_class<EqFctOven>();

  // Before we can start the server, we must set the DMap file path
  ChimeraTK::setDMapFilePath("oven.dmap");

  server.run(argc, argv);

  return 0;
}
