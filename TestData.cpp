#include <cassert>
#include <TestData.h>

void
TestData::populate(Raceway& raceway, NamedEndpoints& eps, NamedSegments& segs)
{
    // add endpoints to the raceway object
    for(auto test_endpoint: endpoints){
        // create a new vector
        Vector *vector = new Vector(test_endpoint.x, test_endpoint.y, test_endpoint.z);

        // create a new endpoint and add it to the raceway object
        Endpoint_H endpoint = std::make_shared<Endpoint>(*vector);
        endpoint.get()->set_reinforced(false); // should be un-reinforced initially
        raceway.add_endpoint(endpoint);

        // insert the endpoint into the map
        eps.emplace(std::pair<std::string, Endpoint_H>(test_endpoint.name, endpoint));
    }

    // ddd segments to the raceway object
    for(auto test_segment: segments){
        // generate a new segment
        Segment_H segment = std::make_shared<Segment>(eps[test_segment.start_name], eps[test_segment.end_name]);

        // add segment to the raceway object
        raceway.add_segment(segment);

        // insert the segment into the map
        segs.emplace(std::pair<std::string, Segment_H>(test_segment.name, segment));
    }
}
