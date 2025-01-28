#include "precomp.h"
#include "Camera.h"

Camera::Camera(uint windowWidth, uint windowHeight, float focalLength)
	: windowWidth{windowWidth}
	, windowHeight{windowHeight}
	, viewportHeight{2.f}
	, viewportWidth{ 2.f * (static_cast<float>(windowWidth) / static_cast<float>(windowHeight)) }
	, focalLength{focalLength}
	, viewportU{ float3(viewportWidth, 0.f, 0.f)}
	, viewportV{ float3(0.f, -viewportHeight,0.f)}
	, pixelDeltaU { viewportU / static_cast<float>(windowWidth) }
	, pixelDeltaV{ viewportV / static_cast<float>(windowHeight) }
	, viewportUpperLeft { position - float3(0, 0, focalLength) - viewportU / 2.f - viewportV / 2.f }
	, pixel00Loc{ viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV) }
{
}

