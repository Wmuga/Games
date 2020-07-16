typedef unsigned int size_t;
#include <vector>
class sudoku_field_create
    {
    size_t cell_size_w;
    size_t cell_size_h;
    size_t field_cells_w;
    size_t field_cells_h;
    std::vector<std::vector<int> > field;

    size_t u_transp=0;
    size_t u_swap_raws=0;
    size_t u_swap_colums=0;
    size_t u_swap_areas_v=0;
    size_t u_swap_areas_h=0;

    public:
        sudoku_field_create(size_t size_w, size_t size_h);
        ~sudoku_field_create();
        void show_data();
        void show_field();
        void field_out(char* filename);

    private:
        void create_field();
        void swap_raws(size_t nraw1,size_t nraw2);
        void swap_colums(size_t ncolum1, size_t ncolum2);
        void swap_cells_v(size_t ncell1, size_t ncell2);
        void swap_cells_h(size_t ncell1, size_t ncell2);
        void transpose();
        void create_standart_grid();

    };
    /*
class sudoku_game:
    {
    public:
    };
*/
