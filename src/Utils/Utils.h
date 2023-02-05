#pragma once

#ifndef UTILS_H
#define UTILS_H

const float PI{ 3.14159f };
const float TWO_PI{ 2.0f * PI };

bool IsEqual(float x, float y, int precision = 2);

bool IsGreaterOrEqual(float x, float y);

bool IsLesserOrEqual(float x, float y);


#endif // !UTILS_H
