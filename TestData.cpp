#include <cassert>
#include <TestData.h>

void TestData::populate(Raceway &raceway, NamedEndpoints &eps, NamedSegments &segs)
{
    // Tanya: populate raceway object with endpoints
    for (auto &testEndpoint : endpoints)
    {
        // create new vector containing endpoint coordinates
        Vector *vector = new Vector(testEndpoint.x, testEndpoint.y, testEndpoint.z);

        // create new endpoint and set initial reinforcement value to false
        Endpoint_H endpoint_h = std::make_shared<Endpoint>(*vector);
        endpoint_h.get()->set_reinforced(false);

        // add endpoint to raceway object
        raceway.add_endpoint(endpoint_h);

        // add endpoint to map
        eps.insert(std::pair<std::string, Endpoint_H>(testEndpoint.name, endpoint_h));
    }

    // Tanya: populate raceway object with segments
    for (auto &testSegment : segments)
    {
        // create nnew segment
        Segment_H segment_h = std::make_shared<Segment>(eps[testSegment.start_name], eps[testSegment.end_name]);

        // add segment to raceway object
        raceway.add_segment(segment_h);

        // add segment to map
        segs.insert(std::pair<std::string, Segment_H>(testSegment.name, segment_h));
    }
}
