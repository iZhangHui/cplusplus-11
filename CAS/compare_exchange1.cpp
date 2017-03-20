// Demonstrates how compare_exchange_strong either changes the value of the atomic variable or the variable used for comparison.
// This section is incomplete
// Reason: more practical use of the strong CAS would be nice, such as where Concurrency in Action uses it
#include <atomic>
#include <iostream>

std::atomic<int>  ai;

int  tst_val= 4;
int  new_val= 5;
bool exchanged= false;

void valsout()
{
    std::cout << "ai= " << ai
	      << "  tst_val= " << tst_val
	      << "  new_val= " << new_val
	      << "  exchanged= " << std::boolalpha << exchanged
	      << "\n";
}

int main()
{
    std::cout << "std::atomic<int> is lock free? " << ai.is_lock_free() << std::endl;
    ai= 3;
    valsout();

    // tst_val != ai   ==>  tst_val is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();

    // tst_val == ai   ==>  ai is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();
}
// Output:
// ai= 3  tst_val= 4  new_val= 5  exchanged= false
// ai= 3  tst_val= 3  new_val= 5  exchanged= false
// ai= 5  tst_val= 3  new_val= 5  exchanged= true