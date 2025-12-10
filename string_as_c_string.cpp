#include "string_as_c_string.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


static void reverse_segment(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}


static int is_word_all_caps(char* start, char* end) {
    int has_alpha = 0;
    char* p = start;
    while (p <= end) {
        if (isalpha(*p)) {
            has_alpha = 1;
            if (!isupper(*p)) {
                return 0;
            }
        }
        p++;
    }
    return has_alpha;
}

void process_string_c_string(char* str) {
    
    int len = strlen(str);
    if (len == 0) return;

    int is_long = (len > 10);
    int has_caps_word = 0;

    char* P1 = NULL;
    char* E1 = NULL;
    char* PN = NULL;
    char* EN = NULL;

    char* current = str;
    int word_count = 0;

    while (*current != '\0') {
        if (isspace(*current)) {
            current++;
        }
        else {
            char* word_start = current;
            while (*current != '\0' && !isspace(*current)) {
                current++;
            }
            char* word_end = current - 1;

            word_count++;
            if (P1 == NULL) {
                P1 = word_start;
                E1 = word_end;
            }
            PN = word_start;
            EN = word_end;

            if (is_long && !has_caps_word) {
                if (is_word_all_caps(word_start, word_end)) {
                    has_caps_word = 1;
                }
            }
        }
    }

    int condition_met = is_long && has_caps_word;

    if (word_count < 2) {
        return;
    }

    if (condition_met) {
        

        reverse_segment(str, str + len - 1);

        current = str;
        while (*current != '\0') {
            if (isspace(*current)) {
                current++;
            }
            else {
                char* word_start = current;
                while (*current != '\0' && !isspace(*current)) {
                    current++;
                }
                char* word_end = current - 1;
                reverse_segment(word_start, word_end);
            }
        }
    }
    else {
        

        char* segment_start = P1;
        char* segment_end = EN;

        int L_N = EN - PN + 1;
        int L_1 = E1 - P1 + 1;

        reverse_segment(segment_start, segment_end);
        reverse_segment(segment_start, segment_start + L_N - 1);

        char* W1_R_start = segment_end - L_1 + 1;
        reverse_segment(W1_R_start, segment_end);

        char* S_start = segment_start + L_N;
        char* S_end = W1_R_start - 1;

        if (S_start < S_end) {
            reverse_segment(S_start, S_end);
        }
    }
}