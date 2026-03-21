#include "vector3.hpp"
#include <vector>
namespace l2
{

void vector3_init(Vector3& vec)
{
    for(int i=0;i<vec->VECTOR_SIZE;i++){
        vec->v[i]=str::vector(vec->VECTOR_SIZE);
    }
};

void vector3_init(Vector3& vec, double x, double y, double z)
{
    int arr=[x,y,z];
    for(int i=0;i<vec->VECTOR_SIZE;i++){
        vec->[i]=str::vector(vec->VECTOR_SIZE,arr[i]);
    }
};

double vector3_length(const Vector3& vec)
{
    // STAGE 1: Implement me!
}

void vector3_mul(Vector3& vec, double a)
{
    // STAGE 1: Implement me!
}

}  // namespace l2