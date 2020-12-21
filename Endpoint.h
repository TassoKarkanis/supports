#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <memory>
#include <Vector.h>

class Endpoint;
using Endpoint_H = std::shared_ptr<Endpoint>;

class Endpoint
{
public:
    Endpoint(const Vector& pos);

    void set_reinforced(bool reinforced_);
    bool reinforced() const;

    const Vector& position() const;

private:
    Vector m_pos;
    bool m_reinforced;
};

#endif
