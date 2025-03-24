#pragma once
#ifndef TETROMINO_H
#define TETROMINO_H

#include "Init.h"
#include <vector>
#include <SDL.h>

enum class TetrominoType { I, O, T, L, J, S, Z };

class Tetromino {
public:
	Tetromino(TetrominoType type, int startX, int startY);
	void move(int dx);
	void update();
	void rotate();
	void handleEvent(SDL_Event& e);
	void render(SDL_Renderer* gRenderer); // Render Tetris pieces
	std::vector<SDL_Rect> getBlocks() const;

private:
	TetrominoType type;
	std::vector<std::vector<int>> shape;
	SDL_Color color;
	int x, y;          // Position on the grid
	int velocityX;     // Horizontal movement speed
	int fallSpeed;     // Fall speed (controlled in update)
	Uint32 lastFallTime;
	void setShape();
};

#endif // TETROMINO_H

