#pragma once

enum class key
{
    none = 0,
    up = 72,
    down = 80,
    enter = 13
};

class key_detector
{
public:
    static key detect();
};
