#include <cassert>
#include <cmath>
#include <compute_supports.h>

void
compute_supports(Raceway& raceway, Supports& supports)
{
    // assert(!"unimplemented");
 
    // endpoints should not be empty
    assert(raceway.endpoints().size() > 0);
 
    // segments should not be empty
    assert(raceway.segments().size() > 0);
 
 
    for (auto i : raceway.endpoints()){
        if (raceway.degree(i) >= 2){
            i->set_reinforced(true);
        }
    }
    
    for (auto i : raceway.segments()){
        Vector dist_vctr = (i->end_pos() - i->start_pos()).normalized();
        std::vector<Vector> supprt_positions;
        supprt_positions.push_back(i->start_pos()+dist_vctr);
        int segment_length = distance(i->end_pos(), i->start_pos());

        if (segment_length > 12){ 
            int rem = segment_length-2;
            int num_supports = ceil(rem/10.0)-1;
            double diff = rem/(num_supports+1.0);
            for (int i = 1; i <=  num_supports; i++){    
                Vector n_position = supprt_positions[0]+i*diff*dist_vctr;
                supprt_positions.push_back(n_position);
            }
        }

        supprt_positions.push_back(i->end_pos()-dist_vctr); 
        supports[i] = supprt_positions;

    }
}
