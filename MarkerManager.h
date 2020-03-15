#ifndef TV_MARKERS_MARKER_MANAGER_H_
#define TV_MARKERS_MARKER_MANAGER_H_

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

	bool isValidMarker(const Marker&);
	bool addMarker(const Marker&);
	bool removeMarker(const Marker&);

	void sortMarkers();

private:
	std::unique_ptr<MarkersParser> parser;
	std::vector<Marker> markers;
	bool sorted {false};
};

#endif // TV_MARKERS_MARKER_MANAGER_H_
