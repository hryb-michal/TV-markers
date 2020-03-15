#ifndef TV_MARKERS_MARKERSPARSER_H_
#define TV_MARKERS_MARKERSPARSER_H_

#include <vector>

#include "Marker.h"


class MarkersParser
{
public:
	std::vector<Marker> parse();
	void save(const std::vector<Marker>&);
};

#endif	// TV_MARKERS_MARKERSPARSER_H_