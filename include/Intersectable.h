#pragma once
#include "Ray.h"


struct RayHitInfo
{
	float3 worldPosition{ 0.f };
	float3 worldNormal{ 0.f };
	float distance{ 0.f };
	bool hit{ false };
	bool front_face{ false };

	void set_face_normal(const Ray& r, const float3& outwardNormal) {
		// Sets the hit record normal vector.
		// NOTE: the parameter `outward_normal` is assumed to have unit length.

		front_face = dot(r.GetDirection(), outwardNormal) < 0;
		worldNormal = front_face ? outwardNormal : -outwardNormal;
	}

};



class Intersectable
{
public:
	Intersectable() = default;
	Intersectable(float3 position, quat rotation);
	virtual ~Intersectable() {};

	virtual RayHitInfo Intersect(const Ray& ray, float rayTMin, float rayTMax) const = 0;


	const float3& GetPosition() const { return position; }
	const quat& GetRotation() const { return rotation; }

	void SetPosition(const float3& newPosition) { position = newPosition; }
	void SetRotation(const quat& newRotation) { rotation = newRotation; }

protected:
	float3 position{ 0.f };
	quat rotation{};

};

