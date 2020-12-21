# Supports: C++ Exercise

## Introduction

A "raceway" is a directed acyclic graph.  The edges of the graph are
"segments" and the vertices are "endpoints".  Endpoints have positions
in a 3D Cartesian space.  Segments are straight lines between their
start and end endpoints.  Segments are always at least 5 units long.

Raceway segments need to be held up by "supports".  Supports should be
thought of as being located at a point along a segment.  Each segment
requires a support exactly 1 unit from both endpoints.  Also, the
distance between two adjacent supports along a segment must not exceed
10 units.  Supports should be evenly spaced along the segment.
Finally, if more than two segments are adjacent to and endpoint, the
endpoint needs to be "reinforced".

## Exercise

Look for `assert(!"unimplemented")` in the code and fill in the code.
In `Raceway.h`, you may add additional data members to the `Raceway`
class if you like.  Otherwise, keep the interfaces the same.  Make
sure all the tests in `tests.cpp` pass (i.e. that the `supports`)
executable runs without any assertions).
