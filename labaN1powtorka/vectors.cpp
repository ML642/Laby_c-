#include "vectors.hpp"

namespace vectors{
    std::vector<int> reverse (std::vector<int>* old)
{
    std::vector<int> answer;
    if(!old->size())return answer;

    for(int i=old->size()-1;i>=0;i--){
        answer.push_back((*old)[i]);
    };

    return answer;
};
    int max(std::vector<int>* vec){
        int Max=-99999999;
        for(int i=0;i<vec->size();i++){
            if((*vec)[i]>Max)Max=(*vec)[i];
        };
        return Max;
    
    };

};