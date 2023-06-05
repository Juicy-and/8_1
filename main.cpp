#include <iostream>

class Bad_length : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания. "; }
};

int function(std::string str, int forbidden_length)
{
        std::cout << "Введите запретную длину: ";
        std::cin >> forbidden_length;
        do {
            std::cout << "Введите слово: ";
            std::cin >> str;
            if (str.length() == forbidden_length) throw Bad_length();
            else
                std::cout << "Длина слова " << str << " равна " << str.length() << std::endl;
        } while (true);
        return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str;
    try
    {
       function(str, str.length());
    }
    catch (const Bad_length& ex) { std::cout << ex.what() << std::endl; }
}
