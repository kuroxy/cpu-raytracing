#pragma once


class Ray
{
public:
	Ray();

	Ray(const float3& origin, const float3& direction)
		: origin{ origin }
		, direction{ normalize(direction)} { }

	const float3& GetOrigin() const { return origin; }
	const float3& GetDirection() const { return direction; }

	float3 At(float t) const { return origin + t * direction; }

private:
	float3 origin;
	float3 direction;
};


