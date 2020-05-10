#include <iostream>
#include <vector>
#include "olcConsoleGameEngine.h"
#include "implementation.h"


class GameLoop : public olcConsoleGameEngine
{
public:
	GameLoop()
	{
		m_sAppName = L"Kulki";
	}

private:
	std::vector<BallDrawing*> vecBalls; // Main vector where we store our balls 
	
	// Pointers to handle mouse clicks
	BallDrawing* pSelectedBall = nullptr;
	olcSprite *spriteBalls = nullptr;
	bool bSelectedLineStart = false;

	// Functions for adding balls of different collors
	void AddRedBalls(float x, float y)
	{
		BallDrawing *a = new RedBallDrawing(x, y, vecBalls.size());
		vecBalls.emplace_back(a);
	}

	void AddYellowBalls(float x, float y)
	{
		BallDrawing *a = new YellowBallDrawing(x, y, vecBalls.size());
		vecBalls.emplace_back(a);
	}

	void AddBlueBalls(float x, float y)
	{
		BallDrawing *a = new BlueBallDrawing(x, y, vecBalls.size());
		vecBalls.emplace_back(a);
	}

public:
	bool OnUserCreate()
	{
		// Loop for adding balls
		for (int i = 0; i < 7; i++)
		{
			AddRedBalls(((float)rand() / (float)RAND_MAX) * ScreenWidth(), ((float)rand() / (float)RAND_MAX) * ScreenHeight());
			AddYellowBalls(((float)rand() / (float)RAND_MAX) * ScreenWidth(), ((float)rand() / (float)RAND_MAX) * ScreenHeight());
			AddBlueBalls(((float)rand() / (float)RAND_MAX) * ScreenWidth(), ((float)rand() / (float)RAND_MAX) * ScreenHeight());
		}
		return true;
	}

	//	Main Loop
	bool OnUserUpdate(float fElapsedTime)
	{
		if (m_mouse[0].bPressed || m_mouse[1].bPressed)
		{
			pSelectedBall = nullptr;
			for (auto &ball : vecBalls)
			{
				if (ball->PO->IsPointInCircle(m_mousePosX, m_mousePosY))
				{
					pSelectedBall = ball;
					break;
				}
			}
		}
		
		if (m_mouse[0].bHeld)
		{
			if (pSelectedBall != nullptr)
			{
				pSelectedBall->PO->SetPX(m_mousePosX);
				pSelectedBall->PO->SetPY(m_mousePosY);
			}
		}

		if (m_mouse[0].bReleased)
		{
			pSelectedBall = nullptr;
		}

		if (m_mouse[1].bReleased)
		{
			if (pSelectedBall != nullptr)
			{
				// Apply velocity
				pSelectedBall->PO->SetVX(5.0f * ((pSelectedBall->PO->GetPX()) - (float)m_mousePosX));
				pSelectedBall->PO->SetVY(5.0f * ((pSelectedBall->PO->GetPY()) - (float)m_mousePosY));
			}
			pSelectedBall = nullptr;
		}

		Observer Obs; // Observer object. It is supposed to take care of listing collided balls

		// Multiple simulation updates with small time steps 
		int nSimulationUpdates = 4;

		// The max number of solving queues for collisions
		int nMaxSimulationSteps = 15;

		// Quantify time for better simulations 
		float fSimElapsedTime = fElapsedTime / (float)nSimulationUpdates;

		// Main simulation loop
		for (int i = 0; i < nSimulationUpdates; i++)
		{
			// Setting Simulation Time for all balls
			for (auto &ball : vecBalls)
				ball->PO->SetSTR(fSimElapsedTime);
			// Erode simulation time on a per objec tbasis, depending upon what happens
			for (int j = 0; j < nMaxSimulationSteps; j++)
			{
				// Update Ball Positions
				for (auto &ball : vecBalls)
				{
					if (ball->PO->GetSTR() > 0.0f)
					{
						ball->PO->UpdatePosition();
					}
				}
				// Work out static collisions with walls and displace balls that overlap
				for (auto &ball : vecBalls)
				{
					// Against other balls
					for (auto &target : vecBalls)
					{
						if (ball->PO->GetID() != target->PO->GetID()) // Do not check against self
						{
							if (ball->PO->DoCirclesOverlap(target))
							{
								// Collision has occured
								Obs.AddCollision(ball, target);
								// Displacing both balls to solve the static collision
								ball->PO->Displace(target);
							}
						}
					}
					// Time displacement - we knew the velocity of the ball, so we can estimate the distance it should have covered
					// however due to collisions it could not do the full distance, so we look at the actual distance to the collision
					// point and calculate how much time that journey would have taken using the speed of the object. Therefore
					// we can now work out how much time remains in that timestep.
					float fActualTime = ball->PO->GetActualDistance() / ball->PO->GetIntendedSpeed();

					// Checking remaining time after solving collisions
					ball->PO->SetSTR(ball->PO->GetSTR() - fActualTime);
				}

				// Now work out dynamic collisions
				for (auto each : Obs)
				{
					BallDrawing *ball = each.first;
					ball->PO->DynamicCollision(each.second);
				}
				// Clear the list of collisions
				Obs.RemoveCollisions();
			}
		}

		// Clearing The Screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), ' ');

		// Drawing All Balls
		for (auto ball : vecBalls)
			ball->Draw(this);

		// Draw the Line while holding mouse button
		if (pSelectedBall != nullptr)
			DrawLine(pSelectedBall->PO->GetPX(), pSelectedBall->PO->GetPY(), m_mousePosX, m_mousePosY, PIXEL_SOLID, FG_MAGENTA);

		return true;
	}

};
