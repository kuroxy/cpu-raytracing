#pragma once
#include "Intersectable.h"
#include <memory>

class IntersectableList : public Intersectable
{
public:
	IntersectableList() = default;
	IntersectableList(std::shared_ptr<Intersectable> object) {};

	RayHitInfo Intersect(const Ray& ray, float rayTMin, float rayTMax) const override;

	void Clear();

	void Add(std::shared_ptr<Intersectable> object);
public:
	std::vector<std::shared_ptr<Intersectable>> objects;
};

