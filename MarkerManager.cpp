#include "MarkerManager.h"

#include <sstream>


MarkerManager::MarkerManager()
{
	parser = new MarkersParser();
	markers = parser->parse();
}


string MarkerManager::getMarker(int i)
{
	stringstream stream;
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

