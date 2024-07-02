/*
    Create an Adaptor which accepts

    a) a data of string values
    b) a function with the following signature
        i) input parameter : one string by lvalue reference
        ii) output : void

    Adaptor should be used to perform operations on string values which are

    1) identify vowels
    2) print the last 3 characters of each string
    3) print the first non-vowel character of each string
*/

///////////////////////////////////////////////

// include things

#include <iostream>
#include <functional>
#include <vector>

//////////////////////////////////////////////

// create aliases

using Logic = std::function<void(std::string)>;

using DtaContainer = std::vector<std::string>;

// declare and define the adaptor logic here

void Adaptor(const Logic fn, const DtaContainer &data)
{
    if(data.empty()){
        std::cout<<"Null Array";
    }
    for (const std::string &st : data)
    {
        fn(st);
    }
}

void FindVowels(const std::string &val)
{
    if (val == "")
    {
        std::cerr << "Cannot find vowels on a blank string \n";
    }
    bool atleastOneVowelFound{false};
    bool flag{false};
    for (char c : val)
    {
        if (c)
        {

            if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
            {
                atleastOneVowelFound = true;
                std::cout << c << "\n";
                flag = true;
            }

            
        }
    }
    
    if (!atleastOneVowelFound)
    {
        std::cerr << "No Vowels are found";
        flag = true;
    }
    if(!flag){
        std::cerr << "NUll Array";
    }
}

void LastThreeCharacters(const std::string &val)
{
    if (val == "")
    {
        std::cerr << "Cannot find last three characters  on a blank string \n";
    }

    if (val.length() < 3)
    {
        std::cout << "Size is less than 3 so printing the whole string\n";
        std::cout << val << std::endl;
    }
    else
    {
        std::cout << val[val.length() - 3] << " " << val[val.length() - 2] << " " << val[val.length() - 1] << std::endl;
    }
}

void FirstNonvowelCharacters(const std::string &val)
{
    if (val == " ")
    {
        std::cerr << "Cannot find  characters  on a blank string \n";
    }
    int count{0};
    for (char c : val)
    {
        if (!(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u'))
        {
            count++;
            std::cout << c << std::endl;
            break;
        }
    }
    if (count == 0)
    {
        std::cout << "All are vowels" << std::endl;
    }
}
///////////
///////////

// client code :
//  Demonstrate adaptor
int main()
{
    std::vector<std::string> data1{"", "abcd", "xyz", "aei"};
    std::vector<std::string> data2{"", "", "", ""};
    std::vector<std::string> data3{};
    try
    {
        // Adaptor(&FindVowels, data1);
        //  Adaptor(&FindVowels,data2);
        Adaptor(&FindVowels, data3);
    }
    catch (std::invalid_argument &ex)
    {
        std::cerr << ex.what() << "\n";
    }

    // // Adaptor([](const std::string &st)
    // //         { std::cout << st.length(); }, data1);

    // try
    // {
    //     Adaptor(&FirstNonvowelCharacters, data1);
    //     // Adaptor(&FindVowels,data2);
    //     // Adaptor(&FindVowels,data3);
    // }
    // catch (std::invalid_argument &ex)
    // {
    //     std::cerr << ex.what() << "\n";
    // }

    // try
    // {
    //     Adaptor(&LastThreeCharacters, data1);
    //     // Adaptor(&FindVowels,data2);
    //     // Adaptor(&FindVowels,data3);
    // }
    // catch (std::invalid_argument &ex)
    // {
    //     std::cerr << ex.what() << "\n";
    // }
}

///////////////////////////////////////////////

/*
    1) findVowels
        scenario 1 : string value has atleat 1 vowel ---------> print it
        scenario 2 : string has no vowel character ------------> exception case ------> std::cerr
        scenario 3 : the input container is blank --------> exception case ------> break from the loop (throw an exception)
        scenario 4 : a certain string is blank ""-----> exception case --------> std::cerr
*/