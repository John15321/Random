#pragma once
#include <iostream>
#include "olcConsoleGameEngine.h"

class BallDrawing;
class BallPhysics;
class Observer;

class BallPhysics
{
private:
	float px, py; // Position
	float vx, vy; // Velocity
	float ax, ay; // Acceleration
	float ox, oy; // Where the Ball started
	float radius; // Radius
	float mass; // Mass
	float friction; // Friction
	float fSimTimeRemaining; // Time left for the simulation
	int id; // ID
public:
	//	GETTING VALUES
	float GetPX() { return px; } // Get Position X
	float GetPY() { return py; } // Get Position Y
	float GetVX() { return vx; } // Get Velocity X
	float GetVY() { return vy; } // Get Velocity Y
	float GetAX() { return ax; } // Get Acceleration X
	float GetAY() { return ay; } // Get Acceleration Y
	float GetOX() { return ox; } // Get Origin Position X
	float GetOY() { return oy; } // Get Origin Position Y
	float GetRadius() { return radius; } // Get Radius
	float GetMass() { return mass; } // Get Mass
	float GetFriction() { return friction; } // Get Friction
	float GetSTR() { return fSimTimeRemaining; } // Get Remaining Simluation Time
	int   GetID() { return id; } // Get ID
//	SETTING VALUES
	void SetPX(const float &val) { px = val; } // Set Position X
	void SetPY(const float &val) { py = val; } // Set Position Y
	void SetVX(const float &val) { vx = val; } // Set Velocity X
	void SetVY(const float &val) { vy = val; } // Set Velocity Y
	void SetAX(const float &val) { ax = val; } // Set Acceleration X
	void SetAY(const float &val) { ay = val; } // Set Acceleration Y
	void SetOX(const float &val) { ox = val; } // Set Origin Position X
	void SetOY(const float &val) { oy = val; } // Set Origin Position Y
	void SetRadius(const float &val) { radius = val; } // Set Radius
	void SetMass(const float &val) { mass = val; } // Set Mass
	void SetFriction(const float &val) { friction = val; } // Set Friction 
	void SetSTR(const float &val) { fSimTimeRemaining = val; } // Set Remaining Simluation Time
	void SetID(const int &val) { id = val; } // Set ID
	float GetDistanceFrom(float tpx, float tpy) // Getting distance from a point
	{
		return sqrtf((px - tpx)*(px - tpx) + (py - tpy)*(py - tpy));
	}
	float GetIntendedSpeed() // Getting one dimensional vector of velocity
	{
		return sqrtf(vx * vx + vy * vy);
	}
	float GetActualDistance() // Getting distance to another ball
	{
		return sqrtf((px - ox)*(px - ox) + (py - oy)*(py - oy));
	}
	void UpdateVelocity(float tvx, float tvy) // Updating velocity for the ball
	{
		vx = tvx;
		vy = tvy;
	}
	void UpdatePosition() // Updating balls position 
	{
		if (fSimTimeRemaining > 0.0f)
		{
			ox = px;						// Store original position this epoch
			oy = py;

			ax = -vx * friction;			// Apply drag
			ay = -vy * friction;

			vx += ax * fSimTimeRemaining;	// Update Velocity
			vy += ay * fSimTimeRemaining;

			px += vx * fSimTimeRemaining;	// Update position
			py += vy * fSimTimeRemaining;

			// Teleporting balls that are going outside of the window ( collision on borders may cause problems)
			if (px < 0) px += 320;
			if (px >= 320) px -= 320;
			if (py < 0) py += 240;
			if (py >= 240) py -= 240;

			// Stop when velocity is neglible
			if (fabs(vx*vx + vy * vy) < 0.05f)
			{
				vx = 0;
				vy = 0;
			}
		}
	}
	void DynamicCollision(BallDrawing *target); // Solving Dynamic Collisions for two colliding balls 
	void Displace(BallDrawing *target); // Displacing two balls away from each other
	bool IsPointInCircle(float x, float y); // Checking if a point is inside our ball
	bool DoCirclesOverlap(BallDrawing *target); // Checking if our ball overlaps with a different one
};

class BallDrawing
{
public:
	virtual void Draw(olcConsoleGameEngine *func) {} // Virtual function for drawing Balls, function recives a pointer to olcConsoleGameEngine class is there
	// to enable the Draw() function to use methods that belong to the engine 							
	BallPhysics *PO; // A pointer to the physical object
};


class Observer
{
private:
	std::vector<std::pair<BallDrawing*, BallDrawing*> > vecCollidingPairs; // Vector for storing pointers to Balls that collided
	using iterator = std::vector<std::pair<BallDrawing*, BallDrawing*> >::iterator; // Iterator to iterate through balls that collided 

public:
	void AddCollision(BallDrawing *ball, BallDrawing *target) // Add another pair of balls that collided to the vector 
	{
		vecCollidingPairs.push_back({ ball, target });
	}
	void RemoveCollisions() // Clearing the vector from collided pairs of balls after solving them
	{
		vecCollidingPairs.clear(); 
	}
	iterator begin() { return vecCollidingPairs.begin(); } // Iterator that starts at the beginning of the vector 
	iterator end() { return vecCollidingPairs.end(); } // Iterator that starts at the end of the vector

};










