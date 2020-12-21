#include <cassert>
#include <cmath>
#include <map>
#include <iostream>
#include <string>
#include <vector>

#include <tests.h>
#include <Raceway.h>
#include <TestData.h>
#include <compute_supports.h>

namespace
{

// Returns whether two numbers are close within an epsilon.
bool
close(double a, double b, double epsilon = 1e-4)
{
    return std::fabs(a - b) < epsilon;
}

// Returns whether the distance between two points is within an epsilon.
bool
close(const Vector& a, const Vector& b, double epsilon = 1e-4)
{
    double d = distance(a, b);
    return close(d, 0, epsilon);
}

}

void
test1()
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"b", 0, 10, 0},
        },

        // segments
        {
            {"x", "a", "b"},
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;
    data.populate(raceway, endpoints, segments);

    // compute supports
    Supports supports;
    compute_supports(raceway, supports);

    // check "x"
    {
        Segment_H x = segments["x"];
        assert(supports[x].size() == 2);
        assert(close(distance(supports[x].front(), x->start_pos()), 1.0));
        assert(close(distance(supports[x].back(), x->end_pos()), 1.0));
    }

    // check reinforcement
    {
        assert(endpoints["a"]->reinforced() == false);
        assert(endpoints["b"]->reinforced() == false);
    }
}

void
test2()
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"b", 0, 10, 0},
            {"c", 0, -10, 0},
            {"d", 10, 0, 0},
        },

        // segments
        {
            {"x", "a", "b"},
            {"y", "a", "c"},
            {"z", "a", "d"},
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;
    data.populate(raceway, endpoints, segments);

    // compute supports
    Supports supports;
    compute_supports(raceway, supports);

    // check "x"
    {
        Segment_H seg = segments["x"];
        assert(supports[seg].size() == 2);
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    // check "y"
    {
        Segment_H seg = segments["y"];
        assert(supports[seg].size() == 2);
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    // check "z"
    {
        Segment_H seg = segments["z"];
        assert(supports[seg].size() == 2);
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    // check reinforcement
    {
        assert(endpoints["a"]->reinforced() == true);
        assert(endpoints["b"]->reinforced() == false);
        assert(endpoints["c"]->reinforced() == false);
        assert(endpoints["d"]->reinforced() == false);
    }
}

void
test3()
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"b", 0, 10, 0},
            {"c", 0, -10, 0},
            {"d", 29, 0, 0},
        },

        // segments
        {
            {"x", "a", "b"},
            {"y", "a", "c"},
            {"z", "a", "d"},
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;
    data.populate(raceway, endpoints, segments);

    // compute supports
    Supports supports;
    compute_supports(raceway, supports);

    // check "x"
    {
        Segment_H seg = segments["x"];
        assert(supports[seg].size() == 2);
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    // check "y"
    {
        Segment_H seg = segments["y"];
        assert(supports[seg].size() == 2);
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    // check "z"
    {
        Segment_H seg = segments["z"];
        assert(supports[seg].size() == 4);

        // check first and last
        assert(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        assert(close(distance(supports[seg].back(), seg->end_pos()), 1.0));

        // check first internal support
        Vector p1(10, 0, 0);
        assert(close(supports[seg][1], p1));

        // check second internal support
        Vector p2(19, 0, 0);
        assert(close(supports[seg][2], p2));
    }

    // check reinforcement
    {
        assert(endpoints["a"]->reinforced() == true);
        assert(endpoints["b"]->reinforced() == false);
        assert(endpoints["c"]->reinforced() == false);
        assert(endpoints["d"]->reinforced() == false);
    }
}
