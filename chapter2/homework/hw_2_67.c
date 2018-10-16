//
// Created by kaiser on 18-10-8.
//

int int_size_is_32(void) {
    unsigned test = ~0U;
    test >>= 15;
    test >>= 15;
    test >>= 1;
    if (test == 1)
        return 1;
    else
        return 0;
}
