// email.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int function1(std::string email);
int function2(int fi, std::string email);

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "Задание 2. Проверка корректности email-адреса\n\n";

    std::cout << "Enter a email adress: ";
    std::string email;
    std::cin >> email;

    int fi = function1(email);
    int f2i =function2(fi, email);

     

    if (f2i < 0) std::cout << "NO";
    else  std::cout << "YES";



}

// первая функция.. проверка ДО @
int function1(std::string email)
{
    //создаем словарь
     
    std::string check = ".-@0123456789abcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~";

    int flag =0; // флажок поиска недопустимых переменных
    int j = 0;
    for (int i = 0; i < email.length(); i++)
    {
        
        for (; j < check.length(); j++)
        {
            if (email[0] == '.') return -1;  // если первая точка

            if (i > 64) return -1;  //если первая половина до @ больше 64

            if (i > 0)
            {
                if (email[i] == '.' && email[i - 1] == '.')
                    return -1; // если две точки подряд
            }

            //единственно правильный вариант
            if (email[i] == '@' && email[i - 1] != '.') return i; // если мы находим собачку '@' И перед ней нет точки(по условию)  выходим и возвращаем значение i

            if (email[i] == check[j]) // если мы находим совпадение
            {
                j = 0;
                flag++;  // проверка на недопустимые символы
                break;
            }
            
            
            
        }
        if (flag -1 != i) return -1; // проверка на недопустимые символы
        
    }
    
    return -1;
}



// вторая функция.. проверка ПОСЛЕ @
int function2(int  fi, std::string email) // передаем значение i , и наш емеил
{
    //создаем словарь
    
    std::string check = ".-0123456789abcdefghijklmnopqrstuvwxyz";

    int i = fi + 1;// создаем новый счетчик
    if (i <= 1) return -1;  // проверка на смысл проверять вторую часть

    if (email[i] == '.') return -1;// проверка на первую точку '.'  после знака @

    int flag = 0; // флажок поиска недопустимых переменных

    for (; i < email.length(); i++)
    {
        int j = 0;
        for (; j < check.length(); j++)
        {
            if ((email.length() - (i + 1)) > 63) return -1;                //если вторая половина после @ больше 63 

            if (email[i] == '.' && email[i - 1] == '.') return -1; // если две точки подряд
            
            if (email[i] == check[j]) // если совпадение найдено
            {
                j = 0;
                flag++; // проверка на недопустимые символы..
                break;
            }
            
        }
        if (flag  + fi != i) return -1; // проверка на недопустимые символы..
    }
    return 1;
}

