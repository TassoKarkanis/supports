#include <cassert>
#include <iterator>
#include <Raceway.h>


void
Raceway::add_endpoint(Endpoint_H endpoint)
{
    // segment should not be null
    assert(endpoint);
    
    assert(!endpoint->reinforced()); // should be unreinforced initially

    // assert(!"unimplemented");
    m_endpoints.insert(endpoint);
}

void
Raceway::add_segment(Segment_H segment)
{
    // segment should not be null
    assert(segment);

    // end-points should be filled out
    assert(segment->start());
    assert(segment->end());

    // end-points should be already added to the raceway already
    assert(m_endpoints.find(segment->start()) != m_endpoints.end());
    assert(m_endpoints.find(segment->end()) != m_endpoints.end());

    // assert(!"unimplemented");
    m_segments.insert(segment);
}

const Raceway::Endpoints
Raceway::endpoints() const
{
    return m_endpoints;
}

const Raceway::Segments&
Raceway::segments() const
{
    return m_segments;
}

int
Raceway::degree(Endpoint_H endpoint) const
{
    // assert(!"unimplemented");
    // endpoint should not be null
    assert(endpoint);

    int degree = 0;
    for (auto i : m_segments){
        if (i.get()->start() == endpoint || i.get()->end() == endpoint){
             degree++;
        }
    }
    return degree;
}
