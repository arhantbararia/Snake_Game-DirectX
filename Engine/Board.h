#pragma once

#include "Graphics.h"
#include "location.h"


class Board
{
private:
	static constexpr int dimension = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;
	Graphics& gfx;

public: 
	Board(Graphics& gfx);
	void drawCell(const location& loc, Color c);

	int GetGridHeight() const ;
	int GetGridWidth() const;
	
	bool isInsideBoard(const location& loc) const;


};