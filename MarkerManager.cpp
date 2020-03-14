#include "MarkerManager.h"

#include <sstream>


MarkerManager::MarkerManager()
{
	parser = std::make_unique<MarkersParser>();
	markers = parser->parse();
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


bool MarkerManager::addMarker(Marker marker)
{
	return false;
}


bool MarkerManager::removeMarker()
{
	return false;
}

