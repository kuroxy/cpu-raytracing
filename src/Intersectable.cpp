#include "precomp.h"
#include "Intersectable.h"

Intersectable::Intersectable(float3 position, quat rotation)
	: position{position}
	, rotation{rotation}
{
}
