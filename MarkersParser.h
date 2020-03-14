#ifndef MARKERSPARSER_H_
#define MARKERSPARSER_H_

#include <vector>

#include "Marker.h"


class MarkersParser
{
public:
	std::vector<Marker> parse();
	void save(const std::vector<Marker>&);
};

#endif	// MARKERSPARSER_H_