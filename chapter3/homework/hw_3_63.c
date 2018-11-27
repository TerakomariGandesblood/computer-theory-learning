//
// Created by kaiser on 18-11-13.
//

long switch_prob(long x, long n) {
    long result = x;
    switch (n) {
        case 60:
        case 62:result *= 8;
            break;
        case 63:result >>= 3;
            break;
        case 64:result *= 15;
            x = result;
            break;
        case 65:x *= x;
            break;
        default:result += 75;
    }
    return result;
}