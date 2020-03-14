#ifndef MARKER_MANAGER_H_
#define MARKER_MANAGER_H_

#include <vector>
#include <string>

#include "Marker.h"
#include "MarkersParser.h"

using namespace std;



class MarkerManager
{
public:
	MarkerManager();

	string getMarker(int i);
	int numMarkers();

	bool addMarker(Marker);
	bool removeMarker();

private:
	MarkersParser* parser;
	vector<Marker> markers;
};

#endif // MARKER_MANAGER_H_
