// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	// anything that happens only once at application start goes here
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	elapsedTime += deltaTime;

	for (int y = 0; y < screen->height; y++)
	{
		for (int x = 0; x < screen->width; x++)
		{
			float r = static_cast<float>(x) / screen->width;
			float g = static_cast<float>(y) / screen->height;
			float b = sin(elapsedTime)*.5f+.5f;

			screen->pixels[x + y * screen->width] = make_color(r, g, b, 1.f);
		}
	}




}