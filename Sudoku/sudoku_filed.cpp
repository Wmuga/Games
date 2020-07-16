#include "sudoku_filed.h"
#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>

sudoku_field_create::sudoku_field_create(size_t size_w, size_t size_h){
    this->cell_size_w = size_w;
    this->cell_size_h = size_h;
    this->field_cells_w = size_h;
    this->field_cells_h =  size_w;
    create_field();
}
sudoku_field_create::~sudoku_field_create(){
}

void sudoku_field_create::create_field(){
    srand(time(0));
    create_standart_grid();
    size_t max_size=this->field_cells_w*this->cell_size_w;
    for (int actions_count=0;actions_count<rand()%100+10;actions_count++)
    {
        int action = rand()%5;
        switch(action)
            {
        default:
            break;
        case(0):
            transpose();
            this->u_transp++;
            break;
        case(1):{
            size_t n1,n2;
            n1 = rand()%this->cell_size_w;
            do
            {
                n2 = rand()%this->cell_size_w;
            }while(n2==n1);
            size_t nc=rand()%this->field_cells_w;
            swap_raws(nc*this->field_cells_w+n1,nc*this->field_cells_w+n2);
            this->u_swap_raws++;
            break;
        }
        case(2):{
            size_t n1,n2;
            n1 = rand()%this->cell_size_h;
            do
            {
                n2 = rand()%this->cell_size_h;
            }while(n2==n1);
            size_t nc=rand()%this->field_cells_h;
            swap_colums(nc*this->field_cells_h+n1,nc*this->field_cells_h+n2);
            this->u_swap_colums++;
            break;
        }
        case(3):
            {
            size_t na1 = rand()%this->field_cells_w;
            size_t na2; do { na2 = rand()%this->field_cells_w;} while (na1==na2);
            swap_cells_h(na1,na2);
            this->u_swap_areas_h++;
            break;
            }
        case(4):
            {
            size_t na1 = rand()%this->field_cells_h;
            size_t na2; do{ na2 = rand()%this->field_cells_h;}  while (na1==na2);
            swap_cells_v(na1,na2);
            this->u_swap_areas_v++;
            break;
            }
            }
    }
}

void sudoku_field_create::swap_raws(size_t nraw1, size_t nraw2){
    std::vector<int> buffer_line = this->field[nraw1];
    this->field[nraw1] = this->field[nraw2];
    this->field[nraw2] = buffer_line;
}

void sudoku_field_create::swap_colums(size_t ncolum1, size_t ncolum2){
    transpose();
    swap_raws(ncolum1,ncolum2);
    transpose();
}

void sudoku_field_create::swap_cells_h(size_t ncell1, size_t ncell2)
{
    for (size_t i=0;i<cell_size_h;i++)
    {
        swap_raws(ncell1*field_cells_h+i,ncell2*field_cells_h+i);
    }
}

void sudoku_field_create::swap_cells_v(size_t ncell1, size_t ncell2)
{
    transpose();
    swap_cells_h(ncell1,ncell2);
    transpose();
}

void sudoku_field_create::create_standart_grid(){
    size_t max_size=this->field_cells_w*this->cell_size_w;
    size_t start_elem=1;
    for (size_t i=0;i<max_size;i++)
    {
        size_t current_element = start_elem;
        std::vector<int> line;
        for (size_t j=0;j<max_size;j++)
        {
            line.push_back(current_element);
            current_element++;
            if (current_element>max_size) current_element-=max_size;
        }
        start_elem+=cell_size_w;
        if (start_elem>max_size) start_elem=start_elem-max_size+1;
        this->field.push_back(line);
    }
}

void sudoku_field_create::transpose(){
    std::vector<std::vector<int> > field_temp;
    size_t buffer;

    buffer=this->cell_size_h;
    this->cell_size_h = this->cell_size_w;
    this->cell_size_w = buffer;

    buffer=this->field_cells_h;
    this->field_cells_h=this->field_cells_w;
    this->field_cells_w=buffer;

    size_t max_size=this->field_cells_w*this->cell_size_w;
    for (size_t i=0;i<max_size;i++)
    {
        std::vector<int> new_line;
        for (size_t j=0;j<max_size;j++) new_line.push_back(field[j][i]);
        field_temp.push_back(new_line);
    }
    this->field=field_temp;
}

void sudoku_field_create::show_data(){
    printf("Cell:\n\twidth:%d\n\theight:%d\nField:\n\twidth cells:%d\n\theight cells:%d\n\n\n"
           "Used functions:\n\tTransposition:%d\n\tSwap raws:%d\n\tSwap columns:%d\n\tSwap areas horizontal:%d\n\t"
           "Swap areas vertical:%d\n",
           this->cell_size_w,this->cell_size_h,this->field_cells_w,this->field_cells_h,
           this->u_transp,this->u_swap_raws,this->u_swap_colums,this->u_swap_areas_h,this->u_swap_areas_v);
}

void sudoku_field_create::show_field(){
    size_t digits_count = ceil(log(this->field_cells_h*this->cell_size_h)/log(10));
    size_t max_size=this->field_cells_w*this->cell_size_w;
    for (size_t i=0;i<max_size;i++)
    {
        for (size_t j=0;j<max_size;j++)
        {
            printf("%*d|",digits_count,this->field[i][j]);
        }
        printf("\n");
        for (size_t j=0;j<max_size*(digits_count+1);j++) printf("-");
        printf("\n");
    }
}

void sudoku_field_create::field_out(char* filename){
    size_t max_size=this->field_cells_w*this->cell_size_w;
    std::ofstream fout(filename);
    fout<<this->cell_size_w << " " <<this->cell_size_h << " " <<this->field_cells_w << " " << this->field_cells_h << "\n";
    for (size_t i=0;i<max_size;i++)
    {
        for (size_t j=0;j<max_size;j++)
        {
           fout<<this->field[i][j]<< " ";
        }
        fout<<"\n";
    }
    fout.close();
}
