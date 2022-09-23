#include <stdbool.h>

bool mx_isspace(char c) {
    if ((c >= 9
    && c <= 13)
    || (c == ' ')
    || (c == '\0')) {
        return true;
    }
    return false;
}
