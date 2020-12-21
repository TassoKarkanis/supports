#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <map>
#include <string>
#include <vector>
#include <Raceway.h>

struct TestEndpoint
{
    std::string name;
    double x;
    double y;
    double z;
};

struct TestSegment
{
    std::string name;
    std::string start_name;
    std::string end_name;
};

struct TestData
{
    using NamedEndpoints = std::map<std::string, Endpoint_H>;
    using NamedSegments = std::map<std::string, Segment_H>;
    
    std::vector<TestEndpoint> endpoints;
    std::vector<TestSegment> segments;

    void populate(Raceway& raceway, NamedEndpoints& eps, NamedSegments& segs);
};


#endif
