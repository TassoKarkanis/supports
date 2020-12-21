#include <Segment.h>

Segment::Segment(Endpoint_H start_, Endpoint_H end_)
    : m_start(start_), m_end(end_)
{
}

Endpoint_H
Segment::start() const
{
    return m_start;
}

Endpoint_H
Segment::end() const
{
    return m_end;
}

const Vector&
Segment::start_pos() const
{
    return start()->position();
}

const Vector&
Segment::end_pos() const
{
    return end()->position();
}
