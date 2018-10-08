//
// Created by kaiser on 18-10-8.
//

int int_size_is_32() {
    unsigned test = ~0U;
    test >>= 15;
    test >>= 15;
    test >>= 1;
    return test == 1;
}
