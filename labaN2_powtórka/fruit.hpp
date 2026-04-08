#pragma once 

enum class Color{
    Red,
    Orange,
    Green,
    Violet
};

enum class Fruittype{
    Apple,
    Orange,
    Plum
};

struct Fruit {
    Color color;
    Fruittype type;
};

static const Fruit dojrzale_jablko={Color::Red,Fruittype::Apple};
static const Fruit dojrzale_pomarancza={Color::Orange,Fruittype::Orange};
static const Fruit dojrzala_sliwka={Color::Violet,Fruittype::Plum};


