#ifndef COMPUTE_SUPPORTS_H
#define COMPUTE_SUPPORTS_H

#include <map>
#include <vector>

#include <Raceway.h>
#include <Vector.h>

using Supports = std::map<Segment_H, std::vector<Vector>>;

void compute_supports(Raceway& raceway, Supports& supports);

#endif
