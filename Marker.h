#ifndef TV_MARKERS_MARKER_H_
#define TV_MARKERS_MARKER_H_

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

	enum class Type
	{
		ARROW = 0,
		DRAWING = 1
	} type;

	Position startPosition;
};

#endif	// TV_MARKERS_MARKER_H_