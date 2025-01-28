#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(float3 position, float radius)
	: Intersectable(position, quat())
	, radius{radius}
{

}

RayHitInfo Sphere::Intersect(const Ray& ray) const
{
    RayHitInfo hit{};
    float3 oc = position - ray.GetOrigin();
   
    float a = sqrLength(ray.GetDirection());
    float b = -2.f * dot(ray.GetDirection(), oc);
    float c = sqrLength(oc) - radius * radius;

    float discriminant = b * b - 4 * a * c;
  

    if (discriminant < 0.f)
    {
        hit.hit = false;
        return hit;
    }

    float solved = (-b - std::sqrt(discriminant)) / (2.0f * a);

    if (solved > 0.0) {
        float3 hitPosition = ray.At(solved);
        float3 normal = normalize(hitPosition - position);
        hit.hit = true;
        hit.worldPosition = hitPosition;
        hit.worldNormal = normal;

        return hit;
    }
    return hit;
}
