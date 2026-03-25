#include "vector3.hpp"
#include <vector>
#include <cmath>
#include <iostream>

namespace l2
{

void vector3_init(Vector3& vec)
{
    for(int i=0;i<vec.VECTOR_SIZE;i++){
        vec.v[i]=0;
    }
};

void vector3_init(Vector3& vec, double x, double y, double z)
{
    vec.v[0]=x;
    vec.v[1]=y;
    vec.v[2]=z;
};

double vector3_length(const Vector3& vec)
{
    double x=vec.v[0];
    double y=vec.v[1];
    double z=vec.v[2];
    double x_y=sqrt(x*x+y*y);
    double x_y_z=sqrt(x_y*x_y+z*z);
    
    return x_y_z;
}

void vector3_mul(Vector3& vec, double a)
{
    for(int i=0;i<vec.VECTOR_SIZE;i++){
        vec.v[i]=vec.v[i]*a;
    }
}
Vector3* vector3_add( Vector3& vec1, Vector3& vec2){
    Vector3* ans=new Vector3;

    double vec[3]={vector3_x(vec1)+vector3_x(vec2),vector3_y(vec1)+vector3_y(vec2),vector3_z(vec1)+vector3_z(vec2)};

    for(int i=0;i<vec1.VECTOR_SIZE;i++){
        ans->v[i]=vec[i];
    }

    return ans;
}
void vector3_print( Vector3& vec1)
{
    
    std::cout<<"["<<vector3_x(vec1)<<","<<vector3_y(vec1)<<","<<vector3_z(vec1)<<"]"<<vec1.VECTOR_SIZE<<'\n';

}


double vector3_x(const Vector3& vec){
    return vec.v[0];
};

double vector3_y(const Vector3& vec){
    return vec.v[1];
};

double vector3_z(const Vector3& vec){
    return vec.v[2];
};

}  // namespace l2