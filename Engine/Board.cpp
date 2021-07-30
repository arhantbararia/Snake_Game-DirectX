#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	: gfx(gfx)
{

}

void Board::drawCell(const location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.y < width);
	assert(loc.y >= 0);			// limit checks
	assert(loc.y < height);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::GetGridHeight() const
{
	return height;
}

int Board::GetGridWidth() const
{
	return width;
}

bool Board::isInsideBoard(const location& loc) const
{

	return loc.x > 0 && loc.x < width&& loc.y > 0 && loc.y < height;
}
