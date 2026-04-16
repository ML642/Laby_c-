#include "vector3.hpp"

namespace l2
{

void vector3_init(Vector3& vec)
{
    int size=vec.VECTOR_SIZE;
    double arr[3]={0};
    vec.v[0]=0;
    vec.v[1]=0;
    vec.v[2]=0;
}

void vector3_init(Vector3& vec, double x, double y, double z)
{
    double arr[3]={x,y,z};
    vec.v[0]=x;
    vec.v[1]=y;
    vec.v[2]=z;
}

double vector3_length(const Vector3& vec)
{   

    double vec_size=sqrt(vec.v[0]*vec.v[0]+vec.v[1]*vec.v[1]);
    return sqrt(vec_size*vec_size + vec.v[2] * vec.v[2]);
}

void vector3_mul(Vector3& vec, double a)
{
    for(int i=0;i<3;i++){
        vec.v[i]=vec.v[i] * a;
    }
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

Vector3* vector3_add(const Vector3& vec1, const Vector3& vec2){
    double tab[3]={vec1.v[0]+vec2.v[0],vec1.v[1]+vec2.v[1],vec1.v[2]+vec2.v[2]};
    Vector3* nowy_wektor = new Vector3();
    
    nowy_wektor->v[0]=tab[0];
    nowy_wektor->v[1]=tab[1];
    nowy_wektor->v[2]=tab[2];
    
    return nowy_wektor;
};

void vector3_print(const Vector3& vec){
    std::cout<<"[";
    for(int i=0;i<vec.VECTOR_SIZE-1;i++){
        std::cout<<vec.v[i]<<',';
    };
    std::cout<<vec.v[2];
    std::cout<<"]"<<" "<<vec.VECTOR_SIZE<<'\n';
};

}  