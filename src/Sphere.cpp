#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(float3 position, float radius)
	: Intersectable(position, quat())
	, radius{radius}
{

}

bool Sphere::Intersect(const Ray& ray) const
{
    float3 oc = position - ray.GetOrigin();
   
    float a = sqrLength(ray.GetDirection());
    float b = -2.f * dot(ray.GetDirection(), oc);
    float c = sqrLength(oc) - radius * radius;

    float discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}
