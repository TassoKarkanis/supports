#ifndef SEGMENT_H
#define SEGMENT_H

#include <Endpoint.h>
#include <memory>

class Segment;
using Segment_H = std::shared_ptr<Segment>;

// Represents a segment in the raceway.  A segment is created with the
// endpoints at the start and end of the segment.
class Segment
{
public:
    Segment(Endpoint_H start_, Endpoint_H end_);

    // Return the start/end endpoint.
    Endpoint_H start() const;
    Endpoint_H end() const;

    // Return the start/end endpoint positions (convenience methods).
    const Vector& start_pos() const;
    const Vector& end_pos() const;

private:
    Endpoint_H m_start;
    Endpoint_H m_end;
};

#endif
