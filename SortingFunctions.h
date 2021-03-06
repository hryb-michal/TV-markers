//
// Created by mhryb on 3/15/20.
//

#ifndef TV_MARKERS_SORTINGFUNCTIONS_H_
#define TV_MARKERS_SORTINGFUNCTIONS_H_

#include <cmath>

namespace Sorting {

    float cartesian_distance(const Marker& marker){
        float x = marker.startPosition.x;
        float y = marker.startPosition.y;
        float z = marker.startPosition.z;
        return sqrt((x*x) + (y*y) + (z*z));
    }
}

#endif //TV_MARKERS_SORTINGFUNCTIONS_H_
