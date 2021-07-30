#pragma once


class  location
{
public:

	int x;
	int y;

	void Add(const location& val)
	{
		x += val.x;
		y += val.y;
	}

	bool operator==(const location& rhs)const
	{
		return x == rhs.x && y == rhs.y;
	}
};