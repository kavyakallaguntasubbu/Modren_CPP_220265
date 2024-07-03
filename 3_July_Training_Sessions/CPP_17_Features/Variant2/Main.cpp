#include"Employee.h"
#include"BusinessOwner.h"
#include<variant>

using vrType = std::variant<BusinessOwner , Employee>;

void Display(vrType & v ){
    std::visit([](auto && val){
        std::cout << val <<"\n";},
        v
    );
}
int main(){
    vrType vr;

    Employee e1{"Kavya" , 800000};
    BusinessOwner b1{"kk",90000};

    vr = e1 ;

    Display(vr);

    vr = b1;
    Display(vr);

}