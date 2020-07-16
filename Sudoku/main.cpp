#include <iostream>
#include "sudoku_filed.h"
#include "sudoku_field_treatment.h"

int main(){
   sudoku_field_create test(3,3);
   test.show_data();
   std::cout<<"\n";
   test.show_field();
   test.field_out((char*)R"(D:\Documents\GitHub\Games\Sudoku\test.txt)");

   sudoku_field_treatment test2((char*)R"(D:\Documents\GitHub\Games\Sudoku\test.txt)");
   std::cout<<"\n";
   test2.show_data();
   std::cout<<"\n";
   test2.show_field();
   test2.create_sudoku_easy();
   std::cout<<"\n";
   test2.show_field_treared();
   test2.field_out((char*)R"(D:\Documents\GitHub\Games\Sudoku\test_easy_33.txt)");
}
