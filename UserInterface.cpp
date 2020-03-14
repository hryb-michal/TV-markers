//
// Created by mhryb on 3/14/20.
//

#include "UserInterface.hpp"
#include <iostream>
#include <string>
#include <map>

Marker marker_input(){
    Marker marker;
    std::cout << "Enter type and XYZ coordinates, separated by spaces:\n";
    int input_type;
    std::cin >> input_type >> marker.startPosition.x >> marker.startPosition.y >> marker.startPosition.z;   //TODO: input guards
    marker.type = static_cast<Marker::Type>(input_type);
    return marker;
}

void UserInterface::list_options() {
    std::cout << "add - provides input menu to add marker\n";
    std::cout << "display - displays all markers, sorted by closest to (0,0,0)\n";
    std::cout << "remove - provides input menu to remove marker\n";
    std::cout << "exit - closes the program\n";
    std::cout << "help - shows this message\n";

}
void UserInterface::run(){
        std::cout << "Welcome to Michal's Marker Manager(TM)\n";
        std::cout << "Whenever you feel lost, type \"help\".\n";
        std::cout << "What do you want to do?\n";
        list_options();

        std::string action = "exit";
        while(true){
            std::cin >> action;

            if (action == "display") {
                std::cout << "Current markers:\n";
                marker_manager.displayAllMarkers();
            }
            else if(action == "exit") {
                std::cout << "Bye!\n";
                return;
            }
            else if(action == "help"){
                list_options();
            }
            else if(action == "add"){
                Marker marker = marker_input();
                bool success = marker_manager.addMarker(marker);
                success ? std::cout << "Operation successful!\n" : std::cout <<  "Operation failed! Possible memory shortage.\n";
            }
            else if(action == "remove"){
                Marker marker = marker_input();
                bool success = marker_manager.removeMarker(marker);
                success ? std::cout << "Operation successful!\n" : std::cout <<  "Operation failed! Please double-check provided input.\n";
            }
            else {
                std::cout << "Sorry, unknown command. Try one of these instead:\n";
                list_options();
            }

            std::cout << "what do you want to do now?\n";
        }

}
