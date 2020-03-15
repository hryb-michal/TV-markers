//
// Created by mhryb on 3/15/20.
//

#ifndef TV_MARKERS_SORTINGFUNCTIONS_HPP
#define TV_MARKERS_SORTINGFUNCTIONS_HPP

namespace Sorting {

    float cartesian_distance(const Marker& marker){
        float x = marker.startPosition.x;
        float y = marker.startPosition.y;
        float z = marker.startPosition.z;
        return sqrt((x*x) + (y*y) + (z*z));
    }
}

#endif //TV_MARKERS_SORTINGFUNCTIONS_HPP
