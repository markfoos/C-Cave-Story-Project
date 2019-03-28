#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"

class Graphics;

class Player : public AnimatedSprite {
	
public:
	Player();
	Player(Graphics &graphics, Vector2);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	// moves the player left by -dx
	void moveLeft();

	// moves the player right by dx
	void moveRight();

	// stop moving the player
	void stopMoving();
	void jump();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle> &others);
	void handleSlopeCollisions(std::vector<Slope> &others);

	const float getX() const;
	const float getY() const;

private:
	float _dx, _dy;

	Direction _facing;
	
	bool _grounded;

};
#endif