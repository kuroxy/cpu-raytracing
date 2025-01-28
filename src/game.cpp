// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#include "precomp.h"
#include "game.h"
#include "Ray.h"
#include "Camera.h"
#include "Sphere.h"




float4 RayColor(const Ray& r, const Sphere& sphere) {


	if (sphere.Intersect(r))
		return float4(1.f, 0.f, 0.f,1.f);

	float3 direction = r.GetDirection();
	float a = 0.5f * (direction.y + 1.f);

	return (1.f - a) * float4(1.f, 1.f, 1.f, 1.f) + a * float4(0.5f, 0.7f, 1.f,1.f);
}






// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::Init()
{
	mainCamera = Camera(SCR_WIDTH, SCR_HEIGHT, 3.f);
	sphere = Sphere(float3(0.f, 0.f, -5.f), .5f);;
}

// -----------------------------------------------------------
// Main application tick function - Executed once per frame
// -----------------------------------------------------------
void Game::Tick( float deltaTime )
{
	elapsedTime += deltaTime;



	screen->Clear(make_color(1.f));

	float3 position = sphere.GetPosition();
	position.y = sin(elapsedTime)*2.f;
	sphere.SetPosition(position);

	for (int y = 0; y < screen->height; y++)
	{
		for (int x = 0; x < screen->width; x++)
		{

			float3 pixelCenter = mainCamera.GetPixel00Loc() + (static_cast<float>(x) * mainCamera.GetPixelDeltaU()) + (static_cast<float>(y) * mainCamera.GetPixelDeltaV());

			float3 rayDirection = pixelCenter - mainCamera.GetPosition();
			Ray r(mainCamera.GetPosition(), rayDirection);

			screen->pixels[x + y * screen->width] = make_color(RayColor(r, sphere));
		}
	}



	/*
	
		Game logic

	*/



	



}