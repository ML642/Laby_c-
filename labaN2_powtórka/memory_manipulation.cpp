#include "memory_manipulation.hpp"

namespace l2
{

std::byte* memcpy(std::byte* dst, const std::byte* src, size_t size)
{
    
    for(int i=0;i<size;i++){
        dst[i]=src[i];
    };
    return dst;
}

std::byte* memmove(std::byte* dst, const std::byte* src, size_t size)
{
    // STAGE 5: Implement me!
}

}  // namespace l2