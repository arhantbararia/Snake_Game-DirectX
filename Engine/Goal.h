#pragma once


#include "Snake.h"
#include "Board.h"
#include <random>


class Goal
{

private:
	static constexpr Color foodColor = Color(50, 0, 255);
	location loc;

public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;

	const location GetLocation() const;
};



/*
*TODO :: 

	 Adjustable board position
	Border drawn around board
	Padding between board tiles
	Display title screen
	Give the Snek a pattern of colors for its segments
	Make it so the Snek speeds up over time
	
*/