#pragma once
#include <iostream>
#include "olcConsoleGameEngine.h"
#include "abstracts.h"
void BallPhysics::DynamicCollision(BallDrawing *target)
{
	// Distance between balls
	float fDistance = GetDistanceFrom(target->PO->GetPX(), target->PO->GetPY());

	// Normal
	float nx = (target->PO->GetPX() - px) / fDistance;
	float ny = (target->PO->GetPY() - py) / fDistance;

	// Tangent
	float tx = -ny;
	float ty = nx;

	// Dot Product Tangent
	float dpTan1 = vx * tx + vy * ty;
	float dpTan2 = target->PO->GetVX() * tx + target->PO->GetVY() * ty;

	// Dot Product Normal
	float dpNorm1 = vx * nx + vy * ny;
	float dpNorm2 = target->PO->GetVX() * nx + target->PO->GetVY() * ny;

	// Converting momentum into 1D vector
	float m1 = (dpNorm1 * (mass - target->PO->GetMass()) + 2.0f * target->PO->GetMass() * dpNorm2) / (mass + target->PO->GetMass());
	float m2 = (dpNorm2 * (target->PO->GetMass() - mass) + 2.0f * mass * dpNorm1) / (mass + target->PO->GetMass());

	// Update balls velocities
	vx = (tx * dpTan1 + nx * m1);
	vy = (ty * dpTan1 + ny * m1);
	target->PO->UpdateVelocity(tx * dpTan2 + nx * m2, ty * dpTan2 + ny * m2);
}




void BallPhysics::Displace(BallDrawing *target)
{
	float fDistance = GetDistanceFrom(target->PO->GetPX(), target->PO->GetPY());
	float fOverlap = 0.5f * (fDistance - radius - target->PO->GetRadius());
	px = (px - fOverlap * (px - target->PO->GetPX()) / fDistance);
	py = (py - fOverlap * (py - target->PO->GetPY()) / fDistance);
	target->PO->SetPX(target->PO->GetPX() - fOverlap * (target->PO->GetPX() - px) / fDistance);
	target->PO->SetPY(target->PO->GetPY() - fOverlap * (target->PO->GetPY() - py) / fDistance);
}

bool BallPhysics::IsPointInCircle(float x, float y)
{
	return fabs((x - GetPX())*(x - GetPX()) + (y - GetPY())*(y - GetPY())) <= (GetRadius())*(GetRadius());
}

bool BallPhysics::DoCirclesOverlap(BallDrawing *target)
{
	return fabs((target->PO->GetPX() - GetPX())*(target->PO->GetPX() - GetPX()) + (target->PO->GetPY() - GetPY())*(target->PO->GetPY() - GetPY())) <= (target->PO->GetRadius() + GetRadius())*(target->PO->GetRadius() + GetRadius());
}
