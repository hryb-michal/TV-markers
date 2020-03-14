#ifndef MARKER_H_
#define MARKER_H_

struct Position
{
	float x;
	float y;
	float z;
};

struct Marker
{
	enum Type
	{
		ARROW,
		DRAWING
	} type;

	Position startPosition;
};

#endif	// MARKER_H_