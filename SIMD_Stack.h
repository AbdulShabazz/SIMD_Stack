#include <vector>

template<typename T, std::size_t N>
class SIMD_Stack {
public:
    SIMD_Stack() {
        for(auto& vec : vectors) {
            vec.push_back(1);
        }
    }
    
    std::vector<T>& operator[](std::size_t i) {
        return vectors[i];
    }
    
    const std::vector<T>& operator[](std::size_t i) const {
        return vectors[i];
    }
    
private:
    std::vector<std::vector<T>, N> vectors;
};
