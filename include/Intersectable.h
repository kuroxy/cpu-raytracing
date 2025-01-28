#pragma once


class Ray;


class Intersectable
{
public:
	Intersectable() = default;
	Intersectable(float3 position, quat rotation);
	virtual ~Intersectable() {};

	virtual bool Intersect(const Ray& ray) const = 0;

	const float3& GetPosition() const { return position; }
	const quat& GetRotation() const { return rotation; }

	void SetPosition(const float3& newPosition) { position = newPosition; }
	void SetRotation(const quat& newRotation) { rotation = newRotation; }

protected:
	float3 position{ 0.f };
	quat rotation{};

};

