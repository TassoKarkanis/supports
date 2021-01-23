#include <iostream>
#include <cassert>
#include <cmath>

#include <compute_supports.h>
#include <Vector.h>

void compute_supports(Raceway &raceway, Supports &supports)
{
    // Tanya: go through endpoints and label any that need to be reinforced
    for (Endpoint_H endpoint : raceway.endpoints())
    {
        if (raceway.degree(endpoint) > 2)
        {
            // reinforce if endpoint connects more than two segments
            endpoint.get()->set_reinforced(true);
        }
    }

    // Tanya: iterate through each segment and add supports
    for (Segment_H segment : raceway.segments())
    {
        // create vector to hold supports for current segment
        std::vector<Vector> segment_supports;

        // get directon from segment start to end
        Vector normalized_start_to_end = (segment.get()->end_pos() - segment.get()->start_pos()).normalized();

        // add support one unit away from segment start
        Vector start_support = segment.get()->start_pos() + normalized_start_to_end;
        segment_supports.insert(segment_supports.end(), start_support);

        // calculate distance of middle section of segment
        // assume that the distance taken up by a support is negligible
        const int segment_distance = distance(segment.get()->start_pos(), segment.get()->end_pos()) - 12;

        // check if extra supports need to be added
        if (segment_distance > 0)
        {
            // special case where only one extra support needs to be added
            if (segment_distance <= 10)
            {
                // add support in the middle of segment
                const float spacing = (segment_distance + 10) / 2;

                // create extra support
                Vector extra_support = 0.5 * (segment.get()->start_pos() + segment.get()->end_pos());
                segment_supports.insert(segment_supports.end(), extra_support);
            }
            else
            {
                // calculate how many extra supports are needed
                const int num_extra_supports = std::ceil((float)segment_distance / 10.0);

                // calculate spacing between supports
                const float spacing = (float)(segment_distance + 10) / (float)(num_extra_supports + 1);

                // create extra supports
                for (int i = 0; i < num_extra_supports; i++)
                {
                    // 1 (space between start and first support)
                    // (i + 1) number of spaces that have already been covered
                    const int multiplier = 1 + (i + 1) * spacing;
                    Vector extra_support = segment.get()->start_pos() + multiplier * normalized_start_to_end;
                    segment_supports.insert(segment_supports.end(), extra_support);
                }
            }
        }

        // add support one unit away from segment end
        Vector end_support = segment.get()->end_pos() - normalized_start_to_end;
        segment_supports.insert(segment_supports.end(), end_support);

        // add segment supports to larger supports map
        supports.insert(std::pair<Segment_H, std::vector<Vector>>(segment, segment_supports));
    }
}
