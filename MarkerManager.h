#ifndef MARKER_MANAGER_H_
#define MARKER_MANAGER_H_

#include <vector>
#include <string>
#include <memory>

#include "Marker.h"
#include "MarkersParser.h"

class MarkerManager
{
public:
	MarkerManager();

	std::string getMarker(int i);
	int numMarkers();

	bool addMarker(Marker);
	bool removeMarker();

private:
	std::unique_ptr<MarkersParser> parser;
	std::vector<Marker> markers;
};

#endif // MARKER_MANAGER_H_
