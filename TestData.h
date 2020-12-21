#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <map>
#include <string>
#include <vector>
#include <Raceway.h>

// Structure to help in writing hard-coded tests of support computation.
struct TestEndpoint
{
    std::string name;
    double x;
    double y;
    double z;
};

// Structure to help in writing hard-coded tests of support computation.
struct TestSegment
{
    std::string name;
    std::string start_name;
    std::string end_name;
};

// Structure for hard-coding test data for support computation.
// Endpoints and segments can be defined as data and can be assigned
// names which are useful for testing the results of the support
// computation.  This class can create a Raceway from the hard-coded
// endpoints and segment vectors.
struct TestData
{
    using NamedEndpoints = std::map<std::string, Endpoint_H>;
    using NamedSegments = std::map<std::string, Segment_H>;
    
    std::vector<TestEndpoint> endpoints;
    std::vector<TestSegment> segments;

    // Populate a Raceway object from the hard-coded test data.  Also returns
    // maps of the testing names for the endpoint/segment objects that were
    // added into the raceway.
    void populate(Raceway& raceway, NamedEndpoints& eps, NamedSegments& segs);
};


#endif
