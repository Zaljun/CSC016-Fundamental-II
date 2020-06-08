// measure execution time 

#include <chrono>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
/*  requires C++11 
    auto start = std::chrono::system_clock::now();
    double j = 1;
    for (int i = 1; i < 5000000; i++)
        j = i*i/j;

     auto end = std::chrono::system_clock::now();
     auto elapsed =  std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
     cout << elapsed.count() << '\n';
*/

    clock_t timer_start, timer_end, duration;
    timer_start = clock();
    
    // some nonsense computation 
    double j = 1;
    for (int i = 1; i < 5000000; i++)
        j = i*i/j;
        
    timer_end = clock();        // time() = > returns time in seconds
    duration = (double)(timer_end - timer_start)*1000/CLOCKS_PER_SEC;
    
    cout << duration  << endl;
    
}
