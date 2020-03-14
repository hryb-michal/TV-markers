#pragma once

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