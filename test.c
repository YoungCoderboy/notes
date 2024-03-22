#include <stdio.h>
#include <regex.h>

int is_power_of_two(const char *binary_str) {
    regex_t regex;
    int result;

    // Regex pattern to match a binary string with exactly one '1'
    const char *pattern = "^0*10*$";

    // Compile the regex
    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result != 0) {
        fprintf(stderr, "Error compiling regex: %s\n", pattern);
        return -1;
    }

    // Match the regex against the binary string
    result = regexec(&regex, binary_str, 0, NULL, 0);

    // Free the compiled regex
    regfree(&regex);

    return result == 0; // 0 indicates a match (power of two)
}

int main() {
    int t;
    scanf("%d",&t);

    while(t--)
    {
        char binary_str[100];
        scanf("%s", binary_str);
        printf("%s\n",is_power_of_two(binary_str) ? "True" : "False");
    }

   

    return 0;
}
