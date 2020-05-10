#pragma once
#include "olcConsoleGameEngine.h"
#include <vector>
#include "abstracts.cpp"


class RedBallPhysics : public BallPhysics
{
public:
	RedBallPhysics(float x, float y, int NewID = 0)
	{
		// Setting default position, speed etc.
		SetPX(x);
		SetPY(y);
		SetVX(0);
		SetVY(0);
		SetAX(0);
		SetAY(0);
		SetOX(0);
		SetOY(0);
		// Customizing Yellow Balls
		SetRadius(10.0f);
		SetMass(GetRadius() * 100.0f);
		SetFriction(0.8f);
		SetSTR(0.0f);
		SetID(NewID);
	}
};

class RedBallDrawing : public BallDrawing
{
public:
	RedBallDrawing(float x, float y, int NewID = 0)
	{
		PO = new RedBallPhysics(x, y, NewID);
	}

	void Draw(olcConsoleGameEngine *func) override
	{
		func->FillCircle(PO->GetPX(), PO->GetPY(), PO->GetRadius(), PIXEL_SOLID, FG_RED);
	}
};





class YellowBallPhysics : public BallPhysics
{
public:
	YellowBallPhysics(float x, float y, int NewID = 0)
	{
		// Setting default position, speed etc.
		SetPX(x);
		SetPY(y);
		SetVX(0);
		SetVY(0);
		SetAX(0);
		SetAY(0);
		SetOX(0);
		SetOY(0);
		// Customizing Yellow Balls
		SetRadius(15.0f);
		SetMass(GetRadius() * 300.0f);
		SetFriction(0.5f);
		SetSTR(0.0f);
		SetID(NewID);
	}
};

class YellowBallDrawing : public BallDrawing
{
public:
	YellowBallDrawing(float x, float y, int NewID = 0) // Creating BallPHysics
	{
		PO = new YellowBallPhysics(x, y, NewID);
	}

	void Draw(olcConsoleGameEngine *func) override // Drawing Yellow Ball
	{
		func->FillCircle(PO->GetPX(), PO->GetPY(), PO->GetRadius(), PIXEL_SOLID, FG_YELLOW);
	}
};




class BlueBallPhysics : public BallPhysics
{
public:
	BlueBallPhysics(float x, float y, int NewID = 0)
	{
		// Setting default position, speed etc.
		SetPX(x);
		SetPY(y);
		SetVX(0);
		SetVY(0);
		SetAX(0);
		SetAY(0);
		SetOX(0);
		SetOY(0);
		// Customizing Yellow Balls
		SetRadius(5.0f);
		SetMass(GetRadius() * 10.0f);
		SetFriction(0.5f);
		SetSTR(0.0f);
		SetID(NewID);
	}
};

class BlueBallDrawing : public BallDrawing
{
public:
	BlueBallDrawing(float x, float y, int NewID = 0)
	{
		PO = new BlueBallPhysics(x, y, NewID);
	}

	void Draw(olcConsoleGameEngine *func) override
	{
		func->FillCircle(PO->GetPX(), PO->GetPY(), PO->GetRadius(), PIXEL_SOLID, FG_BLUE);
	}
};




