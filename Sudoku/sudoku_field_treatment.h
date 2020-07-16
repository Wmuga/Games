typedef unsigned int size_t;
#include <vector>
#include <set>
class sudoku_field_treatment
    {
    size_t cell_size_w;
    size_t cell_size_h;
    size_t field_cells_w;
    size_t field_cells_h;
    size_t max_size;
    std::vector<std::vector<int> > field;
    std::vector<std::vector<int> > field_treated;
    std::vector<std::vector<std::set<int> > > field_to_solve;

public:
    sudoku_field_treatment(char* filename);
    void show_data();
    void show_field();
    void create_sudoku_easy();
    void create_sudoku_normal();
    void show_field_treared();
    void field_out(char* filename);
    ~sudoku_field_treatment();

private:
    //methods
    bool last_standing(size_t x, size_t y);
    bool last_standing_line(size_t x, size_t y);
    bool last_standing_cell(size_t x, size_t y);
    bool triplet(size_t x, size_t y);
    bool hidden_pair(size_t x, size_t y);
    //needed
    std::set<int> get_all_filled(size_t x, size_t y);
    std::set<int> get_all_solutions(size_t x,size_t y);
    std::set<int> get_all_filled_cell(size_t x, size_t y);
    bool check_solved(size_t x, size_t y);
    };
