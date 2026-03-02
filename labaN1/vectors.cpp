#include <vector>
#include <iostream>

namespace vectors{
    std::vector<int> reverse (std::vector<int>* old){
        std::vector<int> new1;
        if(old->size()==0)return new1;
        
        
        int count=0;
        for(int i=old->size()-1;i>=0;i--){
            new1.push_back((*old)[i]);
            count++;
        }
        return new1;
};
    int max(std::vector<int>* vec){
        int max=-9999;
        for(int i=0;i<vec->size();i++){
            if((*vec)[i]>max)max= (*vec)[i];
        }
        return max;
    };
    

}