#include <cassert>
#include <TestData.h>

void
TestData::populate(Raceway& raceway, NamedEndpoints& eps, NamedSegments& segs)
{
    //assert(!"unimplemented");
    assert(endpoints.size() > 0);

    assert(segments.size() > 0);

    for (int i = 0; i < endpoints.size(); i++){
        Vector n_endpoint = Vector(endpoints[i].x, endpoints[i].y, endpoints[i].z);
        Endpoint_H endpoint_ptr (new Endpoint(n_endpoint)); 
        endpoint_ptr->set_reinforced(false);
        raceway.add_endpoint(endpoint_ptr);
        eps.insert(std::make_pair(endpoints[i].name, endpoint_ptr));
    }

    for (int i = 0; i < segments.size(); i++){
        Segment_H segment_ptr (new Segment(eps[segments[i].start_name], eps[segments[i].end_name])); 
        raceway.add_segment(segment_ptr);
        segs.insert(std::make_pair(segments[i].name, segment_ptr));
    }

}
