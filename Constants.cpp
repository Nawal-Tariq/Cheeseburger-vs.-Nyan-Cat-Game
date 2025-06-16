#ifndef CONSTANTS_H
#define CONSTANTS_H

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

template <typename T>
T clamp(T value, T minVal, T maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

#endif // CONSTANTS_H
#pragma once
