#pragma once
class Camera
{
public:
	Camera() = default;
	Camera(uint windowWidth, uint windowHeight, float focalLength);



	const float3& GetPixel00Loc() const { return pixel00Loc; }
	const float3& GetPixelDeltaU() const { return pixelDeltaU; }
	const float3& GetPixelDeltaV() const { return pixelDeltaV; }

	const float3& GetPosition() const { return position; }



private:
	float3 position{0.f};
	
	
	float focalLength{ 1.f };
	
	
	uint windowWidth{0};
	uint windowHeight{0};
	
	float viewportWidth{ 0.f };
	float viewportHeight{ 0.f };

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	float3 viewportU{0.f};
	float3 viewportV{ 0.f };


	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	float3 pixelDeltaU{0.f};
	float3 pixelDeltaV{0.f};


	// Calculate the location of the upper left pixel.
	float3 viewportUpperLeft{0.f};
	float3 pixel00Loc{0.f};


};
