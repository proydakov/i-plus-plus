#include <iterator>
#include <iostream>
#include <immintrin.h>

template<typename Type, size_t Size>
struct alignas(32) avx2_t
{
    constexpr size_t size() const noexcept
    {
        return Size;
    }

    Type val[Size];

    static_assert(sizeof(val) == 32, "AVX2 require 32 byte alignment for data types.");
};

using avx2_int32vec_t = avx2_t<int, 8>;

void read(const char* name, avx2_int32vec_t& vec)
{
    std::cout << name << ": ";
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cin >> vec.val[i];
    }
}

void trace(const char* name, avx2_int32vec_t const& vec)
{
    std::cout << name << ": ";
    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec.val[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    using raw_ptr = __m256i*;
    using craw_ptr = const __m256i*;

    avx2_int32vec_t input1;
    avx2_int32vec_t input2;

    read("input1", input1);
    read("input2", input2);

    auto avx1 = _mm256_load_si256(reinterpret_cast<craw_ptr>(&input1));
    auto avx2 = _mm256_load_si256(reinterpret_cast<craw_ptr>(&input2));
    auto avx  = _mm256_add_epi32(avx1, avx2); 

    avx2_int32vec_t result;
    _mm256_store_si256(reinterpret_cast<raw_ptr>(&result), avx);
    trace("result", result);

    return 0;
}
