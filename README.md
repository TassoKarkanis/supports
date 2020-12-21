# Supports: C++ Exercise

## Introduction

A "raceway" is a directed acyclic graph.  The edges of the graph are
"segments" and the vertices are "endpoints".  Endpoints have positions
in a 3D Cartesian space.  Segments are straight lines between their
start and end endpoints.  Segments are always at least 5 units long.

Raceway segments need to be held up by a sequence of "supports".
Every support should be thought of as being located at a point along a
segment.  Each segment requires at least two supports located exactly
1 unit from both endpoints.  Also, the distance between two adjacent
supports along a segment must not exceed 10 units.  Supports should be
evenly spaced along the segment.  Finally, if more than two segments
are adjacent to the same endpoint, the endpoint needs to be
"reinforced".

## Exercise

The primary challenge in this exercise is to implement an algorithm to
compute support positions for the raceway, and to specify which
endpoints need to be reinforced.  All good code has associated unit
tests, so there is some infrastructure for writing tests for the
support computation.  The secondary challenge is to fill out some
parts of the test infrastructure.

Look for `assert(!"unimplemented")` in the code, remove these asserts,
and fill in the required code instead.  The header files include
documentation about the methods that need to be implemented.
Specifically, you should make changes to:

* `Raceway.cpp`
* `TestData.cpp`
* `compute_supports.cpp`

Also, in `Raceway.h`, you may add additional data members to
the `Raceway` class if you like.  Otherwise, keep the interfaces the
same.  Make sure all the tests in `tests.cpp` pass (i.e. that the
`supports` executable runs without any assertions).
