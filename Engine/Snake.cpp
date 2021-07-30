#include "Snake.h"
#include <assert.h>

Snake::Snake(const location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const location & delta_loc)
{
	
	for (int i = nSegments-1 ; i > 0; --i)
	{
		segments[i].Follow(segments[i-1]);

	}
	segments[0].MoveBy(delta_loc);
	
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

location Snake::GetNextHeadLocation(const location& delta_loc) const
{
	location l(segments[0].Getlocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::isInTileExceptEnd(const location& tail) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].Getlocation() == tail)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);

}

void Snake::Segment::Draw(Board & brd) const
{
	brd.drawCell(loc, c);
}

const location& Snake::Segment::Getlocation() const
{

	return loc;
}
