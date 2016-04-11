#include <version.h>
#include <Symbolic.h>

#include <iostream>

int main()
{
    // Print Build info
    std::cout << "Commit Hash: " << _HASH  << std::endl <<
                 "Commit Date: " << _DATE  << std::endl <<
                 "     Branch: " << _BRANCH << std::endl;

    //  build function
    // ======================

    auto x = sym::make_var("x");
    auto y = sym::make_var("y");

            // x * y * 2
    auto f = sym::mult(sym::mult(x, y), sym::make_val(2));

    // print ((x * y) * 2)
    std::cout << "Function: ";  sym::print(f);


    //  full eval
    // ======================

    // Create a context
    sym::Context ctx = {
        {"x", sym::make_val(2)},
        {"y", sym::make_val(2)}
    };

    auto ret = f->full_eval(ctx);
    std::cout << "full_eval Result: " << ret << " Expected: " << 2 * 2 * 2 << std::endl;


    //  partial eval
    // ======================

    // Create a context
    sym::Context ctx2 = {
        {"x", sym::make_val(2)}
    };

    auto partial_f =f->partial_eval(ctx2);
    std::cout << "Partial Function: ";  sym::print(partial_f);

    //  free memory
    // ======================

    // free function memory
    delete f;
    delete partial_f;

    // free ctx memory
    for(sym::Context::value_type& a: ctx)
        delete a.second;

    for(sym::Context::value_type& a: ctx2)
        delete a.second;

    return 0;
}
