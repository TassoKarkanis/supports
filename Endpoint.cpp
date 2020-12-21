#include <Endpoint.h>

Endpoint::Endpoint(const Vector& pos)
    : m_pos(pos)
{
}

void
Endpoint::set_reinforced(bool reinforced_)
{
    m_reinforced = reinforced_;
}

bool
Endpoint::reinforced() const
{
    return m_reinforced;
}

const Vector&
Endpoint::position() const
{
    return m_pos;
}
