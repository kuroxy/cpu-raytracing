#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"

Sphere::Sphere(float3 position, float radius)
	: Intersectable(position, quat())
	, radius{radius}
{

}

RayHitInfo Sphere::Intersect(const Ray& ray, float rayTMin, float rayTMax) const
{
    RayHitInfo hit{};
    float3 oc = position - ray.GetOrigin();
   

    float a = sqrLength(ray.GetDirection());
    float h = dot(ray.GetDirection(), oc);
    float c = sqrLength(oc) - radius * radius;

    float discriminant = h * h - a * c;
 
    if (discriminant < 0.f)
    {
        hit.hit = false;
        return hit;
    }

    float sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    float root = (h - sqrtd) / a;
    if (root <= rayTMin || rayTMax <= root) {
        root = (h + sqrtd) / a;
        if (root <= rayTMin || rayTMax <= root)
        {
            hit.hit = false;
            return hit;
        }
    }

    hit.hit = true;
    hit.distance = root;
    hit.worldPosition = ray.At(root);
    hit.set_face_normal(ray, (hit.worldPosition - position) / radius);

    return hit;
}
