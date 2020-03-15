#include "MarkerManager.h"

#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

#include "SortingFunctions.hpp"

auto current_distance_fn = Sorting::cartesian_distance;

MarkerManager::MarkerManager()
{
	parser = std::make_unique<MarkersParser>();
	markers = parser->parse();
	sortMarkers();
}

void MarkerManager::displayAllMarkers()
{
	std::cout << "\nTotal marker count: " << numMarkers()  << std::endl;
	std::cout << "Current markers:\n";
	std::cout << "Type - (x, y, z)\n";
	for(int i = 0; i < markers.size(); ++i){
		std::cout << getMarker(i) << std::endl;
	}
}

std::string MarkerManager::getMarker(int i)
{
	std::stringstream stream;
	Marker marker = markers.at(i);

	stream << static_cast<int>(marker.type) << " - ";
	stream << "(" << marker.startPosition.x;
	stream << ", " << marker.startPosition.y;
	stream << ", " << marker.startPosition.z << ")";

	return stream.str();
}

int MarkerManager::numMarkers()
{
	return markers.size();
}

bool MarkerManager::isValidMarker(const Marker& marker)
{
	if (marker.type < Marker::Type::ARROW || Marker::Type::DRAWING < marker.type){
		return false;
	}
	return true;
}

bool MarkerManager::addMarker(const Marker& marker)
{
    if(!isValidMarker(marker)){
        return false;
    }
	if(!sorted){
		markers.push_back(marker);
	}
	else {
		float marker_dist = current_distance_fn(marker);
		auto position = std::find_if(markers.begin(), markers.end(),
										[marker_dist](const Marker& old_marker)
											{return marker_dist < current_distance_fn(old_marker);}
									);
		try{
			markers.insert(position, marker);
		} catch (std::bad_alloc) {
			return false;
		}
	}

	return true;
}

bool MarkerManager::removeMarker(const Marker& marker)
{
	auto marker_iterator = std::find(std::begin(markers), std::end(markers), marker);
	if(marker_iterator != markers.end()) {
		markers.erase(marker_iterator);
		return true;
	}
	else {
		return false;
	}


}

void MarkerManager::sortMarkers()
{
	auto sorting_predicate = [] (const Marker& a, const Marker& b) { return current_distance_fn(a) <= current_distance_fn(b); };
	try{
		std::sort(markers.begin(), markers.end(), sorting_predicate);
	} catch(...){
		sorted = false;
		return;
	}
	sorted = true;
}
