#include "precomp.h"
#include "IntersectableList.h"

RayHitInfo IntersectableList::Intersect(const Ray& ray, float rayTMin, float rayTMax) const
{
    RayHitInfo hitInfo;
    float closestSoFar = rayTMax;

    for (const auto& object : objects) {
        RayHitInfo tempHitInfo = object->Intersect(ray, rayTMin, rayTMax);
        if (tempHitInfo.hit && tempHitInfo.distance < closestSoFar)
        {
            hitInfo = tempHitInfo;
            closestSoFar = tempHitInfo.distance;
        }
    }

    return hitInfo;
}

void IntersectableList::Clear()
{
	objects.clear();
}

void IntersectableList::Add(std::shared_ptr<Intersectable> object)
{
	objects.push_back(object); 
}
