#include "MarkerManager.h"

#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

float cartesian_distance(const Marker& marker){
	float x = marker.startPosition.x;
	float y = marker.startPosition.z;
	float z = marker.startPosition.z;
	return sqrt((x*x) + (y*y) + (z*z));
}

std::function<float(const Marker&)> current_distance_fn = cartesian_distance;

auto distance_predicate = [] (const Marker& a, const Marker& b) {return current_distance_fn(a) <= current_distance_fn(b);};

MarkerManager::MarkerManager()
{
	parser = std::make_unique<MarkersParser>();
	markers = parser->parse();
	std::sort(markers.begin(), markers.end(), distance_predicate);
	sorted = true;
}

void MarkerManager::displayAllMarkers(){
	for(int i = 0; i < markers.size(); ++i){
		std::cout << getMarker(i) << std::endl;
		std::cout << "i: " << i << std::endl;
	}
}

std::string MarkerManager::getMarker(int i)
{
	std::stringstream stream;
	Marker marker = markers.at(i);

	stream << marker.type << " - ";
	stream << "(" << marker.startPosition.x;
	stream << ", " << marker.startPosition.y;
	stream << ", " << marker.startPosition.z << ")";

	return stream.str();
}

int MarkerManager::numMarkers()
{
	return markers.size();
}


bool MarkerManager::addMarker(const Marker& marker)
{
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

