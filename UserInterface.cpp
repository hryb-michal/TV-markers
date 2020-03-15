//
// Created by mhryb on 3/14/20.
//

#include "UserInterface.hpp"

#include <iostream>
#include <string>

#include "InputOperations.hpp"

void UserInterface::list_options() {
    std::cout << "\nHere's list of all possible commands:\n";
    std::cout << "add - provides input menu to add marker\n";
    std::cout << "display - displays all markers, sorted by closest to (0,0,0)\n";
    std::cout << "remove - provides input menu to remove marker\n";
    std::cout << "exit - closes the program\n";
    std::cout << "help - shows this message\n";
}

void UserInterface::run(){
        std::cout << "Welcome to Michal's Marker Manager(TM)\n";
        std::cout << "Whenever you feel lost, type \"help\".\n";
        std::cout << "What do you want to do?\n> ";

        std::string action = "exit";
        while(true){
            std::cin >> action;

            if (action == "display") {
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
                try {
                    Marker marker = InputOperations::marker_input();
                    bool success = marker_manager.addMarker(marker);
                    success ? std::cout << "Marker added!\n" : std::cout << "Operation failed! Possible memory shortage or bad marker format.\n";
                }
                catch (std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else if(action == "remove"){
                try{
                    Marker marker = InputOperations::marker_input();
                    bool success = marker_manager.removeMarker(marker);
                    success ? std::cout << "Marker deleted!\n" : std::cout << "Operation failed! Please double-check provided input.\n";
                }
                catch (std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Sorry, unknown command. Try one of these instead:\n";
                list_options();
            }

            std::cout << "\nwhat do you want to do now?\n> ";
        }

}
