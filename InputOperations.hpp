//
// Created by mhryb on 3/15/20.
//

#ifndef TV_MARKERS_INPUTOPERATIONS_H_
#define TV_MARKERS_INPUTOPERATIONS_H_

#include <iostream>
#include <limits>
#include <vector>

#include "Marker.h"

namespace InputOperations {

    void throw_buffer_exception(){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid input");
    }

    Marker marker_input(){
        Marker marker;
        std::cout << "\nEnter marker type and XYZ coordinates.\n"
                     "(4 values separated by spaces, any additional values will be ignored):\n> ";
        int marker_type {-1};
        std::vector<float> coordinates {0, 0, 0};

        std::cin >> marker_type;
        if(!std::cin.good()){
            throw_buffer_exception();
        }

        for(int i = 0; i < coordinates.size(); ++i){
            float val = 0;
            std::cin >> val;
            if(!std::cin.good()){
                throw_buffer_exception();
            }
            else {
                coordinates[i] = val;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        marker.type = static_cast<Marker::Type>(marker_type);
        marker.startPosition.x = coordinates[0];
        marker.startPosition.y = coordinates[1];
        marker.startPosition.z = coordinates[2];
        return marker;
    }
}

#endif //TV_MARKERS_INPUTOPERATIONS_H_
