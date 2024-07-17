#include<stack>
#include<iostream>
#include<optional>

std::optional<std::string> StackReverseString(std::string & data){
    std::stack<char> reversed_Charater{};

    for(const char c : data){
        reversed_Charater.push(c);
    }

    std::string result{};

    while (!reversed_Charater.empty())
    {
        result = result + reversed_Charater.top();
        reversed_Charater.pop();
    }

    if(result.empty()){
        return std::nullopt;
    }
    return result;
    
}

void TakeInput(std::string & data){
    std::cin >> data ;
}

int main(){

    std::string data;
    TakeInput(data);
    if(auto result = StackReverseString(data); result.has_value()){
        std::cout<< result.value();
    }
    else{
        std::cout << "Input seemed to be blank";
    }

}