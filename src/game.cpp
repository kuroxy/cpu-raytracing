// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include "Ray.h"
#include "Camera.h"



float4 RayColor(const Ray& r) {
	float3 direction = r.GetDirection();
	float a = 0.5 * (direction.y + 1.0);

	return (1.0 - a) * float4(1.f, 1.f, 1.f, 1.f) + a * float4(0.5f, 0.7f, 1.f,1.f);
}




// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	screen->Clear(make_color(1.f));


	Camera camera(SCR_WIDTH, SCR_HEIGHT, 1.f);



	for (int y = 0; y < screen->height; y++)
	{
		for (int x = 0; x < screen->width; x++)
		{

			float3 pixelCenter = camera.GetPixel00Loc() + (static_cast<float>(x) * camera.GetPixelDeltaU()) + (static_cast<float>(y) * camera.GetPixelDeltaV());

			float3 rayDirection = pixelCenter - camera.GetPosition();
			Ray r(camera.GetPosition(), rayDirection);

			screen->pixels[x + y * screen->width] = make_color(RayColor(r));
		}
	}

}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	elapsedTime += deltaTime;


	/*
	
		Game logic

	*/



	



}