#ifndef RACEWAY_H
#define RACEWAY_H

#include <set>

#include <Segment.h>
#include <Endpoint.h>

class Raceway
{
public:
    using Segments = std::set<Segment_H>;
    using Endpoints = std::set<Endpoint_H>;
    
    Raceway() = default;

    void add_endpoint(Endpoint_H endpoint);
    void add_segment(Segment_H segment);

    const Endpoints endpoints() const;
    const Segments& segments() const;

    int degree(Endpoint_H endpoint) const;

private:
    Segments m_segments;
    Endpoints m_endpoints;
    // TODO: you may add more data members here
};

#endif
