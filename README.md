# DeviceAccess DoocsDemoServer

Complete DOOCS server example from the DeviceAccess lecture of the 2021 DOOCS tutorial and lecture series.

## Installation

```
$ meson setup builddir
$ cd builddir
$ ninja
```

## Running the server

Just run `./oven_server` from the build directory. The complete config to run on the local RPC number 610498009 is already there.

* Try modifying the `readbackTemperature` with QtHardMon by running `QtHardMon oven.dmap` from the build directory, and observe the histories of the temperature and the heating current.
