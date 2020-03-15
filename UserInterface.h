//
// Created by mhryb on 3/14/20.
//

#ifndef TV_MARKERS_USERINTERFACE_H_
#define TV_MARKERS_USERINTERFACE_H_

#include "MarkerManager.h"

class UserInterface {
public:
    void run();
private:
    void list_options();
    MarkerManager marker_manager {};

};


#endif //TV_MARKERS_USERINTERFACE_H_
