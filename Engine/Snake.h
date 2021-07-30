#pragma once
#include "Board.h"
#include "Colors.h"

class Snake
{
private:

	class Segment			//class for different segments of snake (which grow with eating)
	{
	private:
		location loc;
		Color c;

	public:
		void InitHead(const location& in_loc);
		void InitBody();
		
		void Follow(const Segment& next);
		void MoveBy(const location& delta_loc);

		void Draw(Board& brd) const;

		const location& Getlocation() const;

	
	};

private:
	static constexpr Color headColor = Color( 0, 255, 0);
	static constexpr Color bodyColor = Color(245, 140, 0);
	static constexpr int nSegmentsMax = 10;
	Segment segments[nSegmentsMax];
	int nSegments = 1;

public:
	Snake(const location& loc);
	void MoveBy(const location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;

	location GetNextHeadLocation(const location& delta_loc) const;

	bool isInTileExceptEnd(const location& tail) const;
};