#ifndef SEGMENT_H
#define SEGMENT_H

#include <Endpoint.h>
#include <memory>

class Segment;
using Segment_H = std::shared_ptr<Segment>;

class Segment
{
public:
    Segment(Endpoint_H start_, Endpoint_H end_);

    Endpoint_H start() const;
    Endpoint_H end() const;

    const Vector& start_pos() const;
    const Vector& end_pos() const;

private:
    Endpoint_H m_start;
    Endpoint_H m_end;
};

#endif
