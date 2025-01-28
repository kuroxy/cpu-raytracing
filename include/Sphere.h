#pragma once
#include "Intersectable.h"

class Sphere : public Intersectable
{
public:
	Sphere() = default;
	Sphere(float3 position, float radius);

	bool Intersect(const Ray& ray) const override;

	float GetRadius() const { return radius; }
	void SetRadius(float newRadius) { radius = newRadius; }

private:
	float radius{ 1.f };
};

