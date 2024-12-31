#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void binary(va_list args);
void reverse(va_list args);
int is_smile(const char *ptr);
void smile();


void my_printf(const char *format, ...) {
    va_list args;  // declares a variable to hold the argument list
    va_start(args, format);  // initializes va_list with the last fixed argument (format)

    const char *ptr = format;  // pointer to traverse the string

    // loop through each character in the string
    while (*ptr) {

        if (is_smile(ptr)) {  // check if current substring matches ":smile:"
            smile();  // if yes --> output smiley face
            ptr += 7;  // update pointer
        }

        else if (*ptr == '%') { // check if the current character is %. if yes --> format specifier
            ++ptr;  // go to the next character

            // determine which format specifier it is and use the corresponding function
            switch (*ptr) {

                // %d --> decimal
                case 'd': {
                    // decimal(args);
                    break;
                }

                // %x --> hexadecimal
                case 'x': {
                    // hexadecimal(args);
                    break;
                }

                // %c --> character
                case 'c': {
                    // character(args);
                    break;
                }

                // %s --> string
                case 's': {
                    // string(args);
                    break;
                }

                // %b --> binary
                case 'b': {
                    binary(args);
                    break;
                }

                // %r --> reverse
                case 'r': {
                    reverse(args);
                    break;
                }

                // if it is an undefined format specifier, print % and the next character
                default:
                    putchar('%');
                    putchar(*ptr);
                    break;
            }


        // if the current character is not %, print it using putchar
        } else {
            putchar(*ptr);
        }
        ++ptr;  // go to the next character
    }

    va_end(args);  // cleans up memory used by va_list
}

// decimal modifiers - flags, width, precision
    // Flags: +, -, 0, ' '
    // Width: number
    // Precision: .number
void decimal(va_list args, const char **format) {
}


// hexadecimal modifiers - flags, width, precision
    // Flags: +, -, 0, ' '
    // Width: number
    // Precision: .number
void hexadecimal(va_list args) {
}


// character modifiers - flags, width
    // Flags: -, 0
    // Width: number
void character(va_list args) {
}


// string modifiers - flags, width, precision
    // Flags: -, 0
    // Width: number
    // Precision: .number
void string(va_list args) {
}


// convert decimal to binary
void binary(va_list args) {
    int num = va_arg(args, int);  // get integer from variable argument list
    // if num is 0, print '0'
    if (num == 0) {
        putchar('0');
        return;
    }
    char binaryDigits[32];  // array to store binary digits
    int index = 0;
    // convert decimal to binary
    while (num != 0) {
        int remainder = num % 2;  // find remainder (0 or 1)
        // store string representation of remainder in binary array
        if (remainder == 1) {
            char binaryDigit = '1';
            binaryDigits[index++] = binaryDigit;
        }
        else {
            char binaryDigit = '0';
            binaryDigits[index++] = binaryDigit;
        }
        num = num / 2;  // move to the next bit by dividing current num by 2
    }
    // reverse binary array and print digits
    for (int i = index - 1; i >= 0; i--) {
        putchar(binaryDigits[i]);
    }
}


// reverses string
void reverse(va_list args) {
    const char *str = va_arg(args, const char *);  // get the string argument from the list
    int length = 0;
    // find the length of the string
    while (str[length] != '\0') {
        ++length;
    }
    // loop through the string backwards and print each character
    for (int i = length - 1; i >= 0; --i) {
        putchar(str[i]);
    }
}


// checks if the current substring matches ":smile:"
int is_smile(const char *ptr) {
    const char *smile_str = ":smile:";  // target string
    // loop through target string
    while (*smile_str) {
        if (*ptr != *smile_str) {  // if they don't match, return 0 (false)
            return 0;
        }
        ++ptr;  // move to next char in input string
        ++smile_str;  // move to next char in target string
    }
    return 1;  // if the strings match, return 1 (true)
}


// outputs a smiley face
void smile() {
    const char *text_smiley = ":)";  // smiley face string to output
    // loop through chars in string
    while (*text_smiley) {
        putchar(*text_smiley++);  // output char and update pointer
    }
}


int main() {
    my_printf("Hello! I am %b years old in binary.\n", 22);
    my_printf(":smile:\n");
    my_printf(" Hello, World! Here's a smile :smile: \n");
    my_printf("My name backwards is %r\n", "Dina Abrahim");
    // my_printf("The current date and time is %T.\n");
    // my_printf("Hello! My name is %s and I am %d years old.\n", "Dina", 22);
    return 0;
}
