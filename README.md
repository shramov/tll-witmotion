# tll-witmotion

Protocol decoder for [WitMotion](https://www.wit-motion.com/) angular sensors
built using [TLL](https://github.com/shramov/tll) framework.

## Installation

This package depends on [TLL](https://github.com/shramov/tll) and [fmtlib](https://fmt.dev/) and
uses [meson](https://mesonbuild.com/) as a build system. After installing dependencies run (for
Unix-like systems):

```
meson setup build
ninja -vC build
```

## Usage

Load `tll-witmotion` module, create channel `witmotion+serial:///dev/ttyXXX`
and listen for `Time`, `Acceleration`, `AngularVelocity` and `Angle` messages.
They are defined in [schema
file](https://github.com/shramov/tll-witmotion/blob/master/src/witmotion.yaml)

> **NOTE:** Values for angles and velocity are not in degress or m/s, they have
> to be converted before usage. See comments in yaml file for exact meaning.
