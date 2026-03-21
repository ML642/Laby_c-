enum Color {
    Red,
    Orange,
    Green,
    Violet
};
enum FruitType{
    Apple,
    Orange,
    Plum
};

struct Fruit {
    Color color ;
    FruitType fruit_type;
};

static Fruit dojrzale_jablko={Red,Apple};
static Fruit niedojrzale_jablko={Green,Apple};

static Fruit niedojrzale_pomarancze={Plum,Orange};
static Fruit dojrzale_pomarancze={Orange,Orange};

