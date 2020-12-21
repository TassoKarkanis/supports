#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <memory>
#include <Vector.h>

class Endpoint;
using Endpoint_H = std::shared_ptr<Endpoint>;

// Represents an endpoint in the raceway.  The endpoint has a 3D
// position and a flag to indicate whether or not it needs to be
// reinforced.
class Endpoint
{
public:
    Endpoint(const Vector& pos);

    // Set whether or not this endpoint needs to be reinforced.
    void set_reinforced(bool reinforced_);

    // Return whether or not this endpoint needs to be reinforced.
    bool reinforced() const;

    // Return the position of the endpoint.
    const Vector& position() const;

private:
    Vector m_pos;
    bool m_reinforced;
};

#endif
