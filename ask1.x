struct mo {
    int b<>;
    float m;
};

struct min_max {
    int b<>;
    int min;
    int max;
};

struct ay {
    int b<>;
    float res<>;
    int a;
};

program FIND_M {
    version FIND_VERS {
        mo FIND(mo) = 1;
    } = 1;
} = 0x23451111;

program FIND_MIN_MAX {
    version MIN_MAX_VERS {
        min_max FIND_MN(min_max) = 1;
    } = 1;
} = 0x23451112;

program CALC_AY {
    version AY_VERS {
        ay FIND_AY(ay) = 1;
    } = 1;
} = 0x23451113;