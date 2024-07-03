#include<iostream>
#include<optional>

/*
    factorial takes 2 int16_t by value and optionally retuens a size_t (sometimes , not always)

    OR

    Facorial function MAY OR MAY NOT RETURN A VALUE

*/
std::optional<size_t> Facoria(int16_t val) {
    if(val <0){
        return std::nullopt;
    }

    else {
        size_t total{1};
        for(size_t i = 2; i<=val ; i++){
            total += i;
        }
        return total;
    }

} 

int main(){

    if(std::optional<size_t> result = Facoria(-5); result.has_value()){
        std::cout << "Factorial is :" << result.value();

    }
    else{
        std::cerr << "Factor did not return a value \n";
    }
}