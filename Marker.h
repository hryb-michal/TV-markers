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
	bool operator==(const Marker& other){
		return (this->type == other.type &&
				this->startPosition.x == other.startPosition.x &&
				this->startPosition.y == other.startPosition.y &&
				this->startPosition.z == other.startPosition.z);
	}
	bool operator!=(const Marker& other){
		return !(*this == other);
	}

	enum Type
	{
		ARROW,
		DRAWING
	} type;

	Position startPosition;
};

#endif	// MARKER_H_