#ifndef MARKER_MANAGER_H_
#define MARKER_MANAGER_H_

#include <vector>
#include <string>
#include <memory>
#include <functional>

#include "Marker.h"
#include "MarkersParser.h"

class MarkerManager
{
public:
	MarkerManager();

	void displayAllMarkers();

	std::string getMarker(int i);
	int numMarkers();

	bool addMarker(const Marker&);
	bool removeMarker(const Marker&);

private:
	std::unique_ptr<MarkersParser> parser;
	std::vector<Marker> markers;
	bool sorted {false};
};

#endif // MARKER_MANAGER_H_
