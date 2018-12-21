#include "test_main.h"
#include "test_plain_data.h"

#include <one2many_counter_queue.h>

int main(int argc, char* argv[])
{
    perf_plain_test test;
    return test_main<one2many_counter_queue<data_t, std::uint64_t>, perf_plain_test>(test, argc, argv);
}