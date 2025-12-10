#define CATCH_CONFIG_MAIN
#define _CRT_SECURE_NO_WARNINGS
#include "catch.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>


#include "string_as_array.h" 
#include "string_as_c_string.h"
#include "string_from_file.h"

using namespace std;




string read_file() {
    
    char res[512] = "";
    FILE* in = fopen("output.txt", "r");
    if (in && fgets(res, 512, in) != NULL) {
        fclose(in);
       
        res[strcspn(res, "\n")] = 0;
    }
    return res;
}


void write_file(const char str[]) {
    FILE* out = fopen("input.txt", "w");
    if (!out) return;
    fputs(str, out);
    fputc('\n', out); 
    fclose(out);
}



TEST_CASE("Scenario 1: Full Reverse - Length > 10 and Has CAPS", "[full_reverse]") {
   
    char str_arr[256] = "a b C D e f";
    char str_c[256] = "a b C D e f";

   
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "f e D C b a") == 0);

    process_string_c_string(str_c);
    REQUIRE(strcmp(str_c, "f e D C b a") == 0);

    write_file("a b C D e f");
    process_file_string();
    REQUIRE(read_file() == "f e D C b a");
}

TEST_CASE("Scenario 1: Full Reverse - Long sentence with caps", "[full_reverse_long]") {
   
    char str_arr[256] = "This is a long test WORD sentence";
    char str_c[256] = "This is a long test WORD sentence";

   
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "sentence WORD test long a is This") == 0);

    process_string_c_string(str_c);
    REQUIRE(strcmp(str_c, "sentence WORD test long a is This") == 0);
}



TEST_CASE("Scenario 2a: Swap 1st and Last - Length <= 10 (No CAPS check needed)", "[swap_short]") {
   
    char str_arr[256] = "one two three";
    char str_c[256] = "one two three";

   
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "three two one") == 0);

    process_string_c_string(str_c);
    REQUIRE(strcmp(str_c, "three two one") == 0);

    write_file("first word last");
    process_file_string();
    REQUIRE(read_file() == "last word first");
}

TEST_CASE("Scenario 2b: Swap 1st and Last - Length > 10 but NO CAPS word", "[swap_no_caps]") {
    
    char str_arr[256] = "this is a long sentence";
    char str_c[256] = "this is a long sentence";

   
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "sentence is a long this") == 0);

    process_string_c_string(str_c);
    REQUIRE(strcmp(str_c, "sentence is a long this") == 0);
}

TEST_CASE("Scenario 2c: Swap 1st and Last - Only two words", "[swap_two_words]") {
    
    char str_arr[256] = "WordA WordB";
    char str_c[256] = "WordA WordB";

    
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "WordB WordA") == 0);

    process_string_c_string(str_c);
    REQUIRE(strcmp(str_c, "WordB WordA") == 0);
}



TEST_CASE("Edge Case: Empty string or one word", "[edge]") {
    char str_empty[256] = "";
    process_string_array(str_empty);
    REQUIRE(strcmp(str_empty, "") == 0);

    char str_one[256] = "SingleWord";
    process_string_array(str_one);
    REQUIRE(strcmp(str_one, "SingleWord") == 0);
}

TEST_CASE("Edge Case: Leading/Trailing/Multiple Spaces", "[spaces]") {
   
    char str_arr[256] = "  w1 w2 CAPS w4  ";

    
    process_string_array(str_arr);
    REQUIRE(strcmp(str_arr, "  w4 CAPS w2 w1  ") == 0);
}

TEST_CASE("File String Processing: Scenario 2 - No middle words", "[file_string_swap]") {
    write_file("First Last");
    process_file_string();
    string result = read_file();
    REQUIRE(result == "Last First");
}