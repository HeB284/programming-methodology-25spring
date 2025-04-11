#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > INT_MAX - b)) {
        throw std::overflow_error("integer overflow in add");
    }
    if ((b < 0) && (a < INT_MIN - b)) {
        throw std::overflow_error("integer underflow in add");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0) && (a > INT_MAX + b)) {
        throw std::overflow_error("integer overflow in sub");
    }
    if ((b > 0) && (a < INT_MIN + b)) {
        throw std::overflow_error("integer underflow in sub");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            if (a > INT_MAX / b)
                throw std::overflow_error("integer overflow in mul");
        } else {
            if (b < INT_MIN / a)
                throw std::overflow_error("integer underflow in mul");
        }
    } else {
        if (b > 0) {
            if (a < INT_MIN / b)
                throw std::overflow_error("integer underflow in mul");
        } else {
            if ((a != 0) && (b < INT_MAX / a))
                throw std::overflow_error("integer overflow in mul");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("divide by zero");
    }
    if ((a == INT_MIN) && (b == -1)) {
        throw std::overflow_error("division overflow");
    }
    return a / b;
}
