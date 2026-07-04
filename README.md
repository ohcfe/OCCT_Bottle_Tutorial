# OpenCascade (OCCT) example project

Following occt version 7.9.3 example here:
https://github.com/Open-Cascade-SAS/OCCT/blob/OCCT-793/dox/tutorial/tutorial.md

Not using the current 8.0 example here:
https://dev.opencascade.org/doc/overview/html/occt__tutorial.html

because the mainstream arch `opencascade` package hasn't hit 8.0 yet, and the 8.0 based tutorial is not backward compatible.

## Prerequisite
the `opencascade` package, and `cmake`

## Building
```
mkdir build
cd build
cmake ..
make
```
## Running
```
occt_bottle_example <width> <height> <thickness>
```
where `<width>`, `<height>`, and `<thickness>` are floating-point values for the model parameters

The program will write the resulting geometry to a STEP file in `OCCT_Bottle.stp`

## Visualizing the result
Import the STEP file into your CAD package of choice. Works well with freecad


