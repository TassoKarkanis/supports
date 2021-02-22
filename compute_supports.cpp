#include <cassert>
#include <cmath>
#include <compute_supports.h>

void
compute_supports(Raceway& raceway, Supports& supports)
{
//    assert(!"unimplemented");

    // Checking which endpoints need to be reinforced.
    // Generally from out-degree point-of-view of a vertex.
    for(auto endpoint: raceway.endpoints()){
        // If more than two segments are adjacent to the
        // same endpoint, the endpoint needs to be "reinforced".
        if(raceway.degree(endpoint) > 2){
            endpoint.get()->set_reinforced(true);
        }
    }

    // segment supports std::vector container of Vectors
    std::vector<Vector> segment_supports;
    // frequently used Vectors and variables declared outside the loop
    Vector norm_start_end, start_support, end_support, auxiliary_support;
    double separation = 0, support_nums = 0, segment_distance = 0;

    for(auto segment: raceway.segments()){
        // calculate the normalized vector
        norm_start_end = (segment.get()->end_pos() - segment.get()->start_pos()).normalized();

        // calculate and add support adjacent to the segment start
        start_support = segment.get()->start_pos() + norm_start_end;
        segment_supports.push_back(start_support);

        // copy initial support vector endpoint to auxiliary support vector.
        // relevant to this, new support vectors will be added.
        auxiliary_support = start_support;

        // calculate the support location immediately before the segment end position
        end_support = segment.get()->end_pos() - norm_start_end;

        // calculate the segement length
        segment_distance = distance(start_support, end_support);

        // if the condition passes, it means extra support is required
        if(segment_distance > 10){

            // calculate the number of supports required
            support_nums = segment_distance/10.0;

            // check if only one additional support vector is required
            if(int(support_nums) == 1){
                auxiliary_support = auxiliary_support + (0.5 * segment_distance * norm_start_end);
                segment_supports.push_back(auxiliary_support);
            }
            else{
                // calculate the partition or space between the new supports
                separation = (segment_distance + 10)/(std::ceil(support_nums) + 1);

                for(int i = 0; i < int(support_nums); i++){
                    // calculate and add new supports based on separation and auxiliary_support vector location
                    auxiliary_support = auxiliary_support + (int(separation) * norm_start_end);
                    segment_supports.push_back(auxiliary_support);
                }
            }

        }

        // add the end_support segment to supports vector container
        segment_supports.push_back(end_support);

        // insert vector supports to the supports map
        supports.insert(std::pair<Segment_H, std::vector<Vector>>(segment, segment_supports));

        // clear the vector container for new segment support vectors
        segment_supports.clear();
    }

}
