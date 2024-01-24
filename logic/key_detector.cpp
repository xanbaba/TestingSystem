#include "key_detector.h"

#include <conio.h>

key key_detector::detect()
{
    if (_kbhit())
    {
        const auto button = static_cast<key>(_getch());
        switch (button) {
        case key::none:
        case key::up:
        case key::down:
        case key::enter:
            return button;
        }
    }
    return key::none;
}
