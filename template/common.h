// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

// common.h is to be included in host and device code and stores
// global settings and defines.

#pragma once

constexpr uint SCR_WIDTH = 1280;
constexpr uint SCR_HEIGHT = 720;
constexpr float SCR_ASPECT = static_cast<float>(SCR_WIDTH)/ static_cast<float>(SCR_HEIGHT);




// #define FULLSCREEN

// constants
constexpr float PI = 3.14159265358979323846264f;
constexpr float INVPI = 0.31830988618379067153777f;
constexpr float INV2PI = 0.15915494309189533576888f;
constexpr float TWOPI = 6.28318530717958647692528f;
constexpr float SQRT_PI_INV = 0.56418958355f;
constexpr float LARGE_FLOAT = 1e34f;

