#include "Utils.hpp"

Direction nextDirection(Direction dir) {
    return static_cast<Direction>((dir + 1) & 0b11);
}