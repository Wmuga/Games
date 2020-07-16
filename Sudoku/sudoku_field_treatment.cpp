#include "sudoku_field_treatment.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <algorithm>

sudoku_field_treatment::sudoku_field_treatment(char* filename)
{
    std::ifstream fin(filename);
    fin>>this->cell_size_w;
    fin>>this->cell_size_h;
    fin>>this->field_cells_w;
    fin>>this->field_cells_h;
    this->max_size = this->cell_size_w*this->field_cells_w;
    for (size_t i=0;i<this->max_size;i++)
    {
        std::vector<int> buffer_line;
        for (size_t j=0;j<max_size;j++)
        {
            int buffer_int;
            fin>>buffer_int;
            buffer_line.push_back(buffer_int);
        }
        (this->field).push_back(buffer_line);
    }
    fin.close();
}

void sudoku_field_treatment::show_data(){
    printf("Cell:\n\twidth:%d\n\theight:%d\nField:\n\twidth cells:%d\n\theight cells:%d\n",
           this->cell_size_w,this->cell_size_h,this->field_cells_w,this->field_cells_h);
}

void sudoku_field_treatment::show_field(){
    size_t digits_count = ceil(log(this->field_cells_h*this->cell_size_h)/log(10));
    for (size_t i=0;i<this->max_size;i++)
    {
        for (size_t j=0;j<this->max_size;j++)
        {
            printf("%*d|",digits_count,this->field[i][j]);
        }
        printf("\n");
        for (size_t j=0;j<this->max_size*(digits_count+1);j++) printf("-");
        printf("\n");
    }
}

void sudoku_field_treatment::show_field_treared(){
    size_t digits_count = ceil(log(this->field_cells_h*this->cell_size_h)/log(10));
    for (size_t i=0;i<this->max_size;i++)
    {
        for (size_t j=0;j<this->max_size;j++)
        {
            printf("%*d|",digits_count,this->field_treated[i][j]);
        }
        printf("\n");
        for (size_t j=0;j<this->max_size*(digits_count+1);j++) printf("-");
        printf("\n");
    }
}

void sudoku_field_treatment::create_sudoku_easy()
{
    this->field_treated = this->field;
    size_t tries_count=0;
    while(tries_count!=this->max_size*this->max_size)
    {
        bool flag =true;
        while (flag)
        {
            flag = true;
            size_t x,y;
            do{
                x = rand()%this->max_size;
                y = rand()%this->max_size;
            }while(!this->field_treated[y][x]);
            int buffer = this->field_treated[y][x];
            this->field_treated[y][x]=0;
            if(last_standing(x,y) or last_standing_line(x,y) or last_standing_cell(x,y))
            {
                flag=false;
                tries_count=0;
            }
            else{
                this->field_treated[y][x]=buffer;
                tries_count++;
                if (tries_count==this->max_size*this->max_size) flag=false;
            }
        }
    }
}
/*
void sudoku_field_treatment::create_sudoku_normal() {
    this->field_treated=this->field;
    //init vector of sollutions
    for (size_t y=0;y<this->max_size;y++) {
        std::vector<std::set<int> > buffer;
        for (size_t x = 0; x < this->max_size; x++)
        {
            std::set<int> empty_set{};
            buffer.push_back(empty_set);
        }
        this->field_to_solve.push_back(buffer);
    }
    //gen
}
*/

bool sudoku_field_treatment::last_standing_cell(size_t x, size_t y)
{
    std::set<int> digits_cell = get_all_filled_cell(x,y);
    std::set<int> digits_lines = get_all_filled(x,y);
    std::set<int> possible_solutions;
    for (int i=1;i<=this->cell_size_h*this->cell_size_w;i++)
        if (std::find(digits_cell.begin(),digits_cell.end(),i)==digits_cell.end() and
        std::find(digits_lines.begin(),digits_lines.end(),i)==digits_lines.end()
        ) possible_solutions.emplace(i);
    return possible_solutions.size()==1;
}

bool sudoku_field_treatment::last_standing(size_t x, size_t y)
{
    return (get_all_filled(x,y)).size()==this->max_size-1;
}

bool sudoku_field_treatment::last_standing_line(size_t x, size_t y)
{
    //row
    std::vector<std::set<int> > solutions_row;
    for (size_t i=0;i<this->max_size;i++)
        solutions_row.push_back(get_all_solutions(i,y));
    for(int solution: solutions_row[x])
    {
        bool is_unique = true;
        for (size_t i=0;i<this->max_size && is_unique;i++)
        {
            if (i!=x && solutions_row[i].size()!=0)
            {
                if (std::find(solutions_row[i].begin(),solutions_row[i].end(),solution)!=solutions_row[i].end()) is_unique=false;
            }
        }
        if (is_unique) return true;
    }
    //column
    std::vector<std::set<int> > solutions_column;
    for (size_t i=0;i<this->max_size;i++)
        solutions_column.push_back(get_all_solutions(x,i));
    for(int solution: solutions_column[y])
    {
        bool is_unique = true;
        for (size_t i=0;i<this->max_size && is_unique;i++)
        {
            if (i!=y && solutions_column[y].size()!=0)
            {
                if (std::find(solutions_column[i].begin(),solutions_column[i].end(),solution)!=solutions_column[i].end()) is_unique=false;
            }
        }
        if (is_unique) return true;
    }
    //if nothing found
    return false;
}

std::set<int> sudoku_field_treatment::get_all_filled(size_t x, size_t y)
{
   std::set<int> used_digits;
    for (size_t i=0;i<this->max_size;i++)
        if (this->field_treated[y][i]) used_digits.emplace(this->field_treated[y][i]);
    for (size_t i=0;i<this->max_size;i++)
        if (this->field_treated[i][x]) used_digits.emplace(this->field_treated[i][x]);
    return used_digits;
}

std::set<int> sudoku_field_treatment::get_all_filled_cell(size_t x, size_t y) {
    size_t cell_x = x/(this->field_cells_w);
    size_t cell_y = y/(this->field_cells_h);
    std::set<int> filled_digits;
    for (size_t i=0;i<this->cell_size_w;i++) for (size_t j=0;j<this->cell_size_h;j++)
        {
        if(this->field_treated[cell_y*this->field_cells_h+j][cell_x*this->field_cells_w+i]) filled_digits.emplace(this->field_treated[cell_y*this->field_cells_h+j][cell_x*this->field_cells_w+i]);
        }
    return filled_digits;
}

std::set<int> sudoku_field_treatment::get_all_solutions(size_t x, size_t y)
{
    std::set<int> used_digits = get_all_filled(x,y);
    std::set<int> possible_solutions;
    for (int i=1;i<=this->max_size;i++) if (std::find(used_digits.begin(),used_digits.end(),i)==used_digits.end()) possible_solutions.emplace(i);
    return possible_solutions;
}

void sudoku_field_treatment::field_out(char* filename){
    std::ofstream fout(filename);
    fout<<this->cell_size_w << " " <<this->cell_size_h << " " <<this->field_cells_w << " " << this->field_cells_h << "\n";
    for (size_t i=0;i<this->max_size;i++)
    {
        for (size_t j=0;j<this->max_size;j++)
        {
           fout<<this->field_treated[i][j]<< " ";
        }
        fout<<"\n";
    }
    fout.close();
}


sudoku_field_treatment::~sudoku_field_treatment(){}
