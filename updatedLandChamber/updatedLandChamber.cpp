#include "landChamber.h"
#include <iostream>



void getReport(LandChamber& landCh);

void addLand(LandChamber& landCh);

void addHolder(LandChamber& landCh);

void addHolderToLand(LandChamber& landCh);

void Menu(LandChamber& landCh);



int main()
{
    setlocale(LC_ALL, "");
    LandChamber mainChamber;
	while (true)
		Menu(mainChamber);
	  
}

void getReport(LandChamber& landCh)
{
    int choice;
    std::cout << "Если хотите вывести общую площадь, введите 1, если диапазон, введите 2\n";
    std::cin >> choice;
    std::system("cls");
    switch (choice)
    {
    case 2:
        int startId, endId;
        std::cout << "Введите с какого индекса по какой хотите вывести площадь\n";
        std::cin >> startId >> endId;
        std::system("cls");
        std::cout << "Площадь земли:\n" << landCh.getSFromTo(startId, endId) << std::endl;
        break;
    default:
        std::cout << "Площадь земли:\n" << landCh.getTotalS() << std::endl;
        break;
    }
    
}

void addLand(LandChamber& landCh)
{
    std::vector<double> sides;
    int landType, i = 0;
    double Temp;    
    std::cout << "Введите тип площади имущества\n";
    std::cout << "0 - Квадрат, 1 - Круг, 2 - Прямоугольник, 3 - Треугольник\n";
    std::cin >> landType;
    do
    {
        std::cout << "Введите сторону №" << i + 1 << std::endl;
        std::cin >> Temp;
        sides.push_back(Temp);
        i++;
    } while (i < landType);
    landCh.addLand(landType, sides);
}

void addHolder(LandChamber& landCh)
{
    std::string name;
    std::cout << "Введите имя владельца\n";
    std::cin.ignore();
    std::getline(std::cin, name);
    landCh.addHolder(name);
}

void addHolderToLand(LandChamber& landCh)
{
    int landId, holderId;
    std::cout << "Введите id владельца\n";
    std::cin >> holderId;
    std::cout << "Введите id участка\n";
    std::cin >> landId;
    landCh.addHolderToLand(landId, holderId);
}

void Menu(LandChamber & landCh)
{
    int choice;
    std::string path;
    std::cout << "/================МЕНЮ================\\\n";
    std::cout << "| 1)Вывести отчёт                    |\n";
    std::cout << "| 2)Добавить участок в базу          |\n";
    std::cout << "| 3)Добавить нового владельца в базу |\n";
    std::cout << "| 4)Добавить участку владельца       |\n";
    std::cout << "| 5)Выход                            |\n";
    std::cout << "\\====================================/\n";
    std::cin >> choice;
    std::system("cls");
    switch (choice)
    {
    case 1:
        getReport(landCh);        
        break;
    case 2:
        addLand(landCh);
        break;
    case 3:
        addHolder(landCh);
        break;
    case 4:
        addHolderToLand(landCh);
        break;
    case 5:
        exit(0);
    default:
        break;
    }
    std::system("pause");
    std::system("cls");
}
