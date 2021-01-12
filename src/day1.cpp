//
// Created by Ernst, Michael on 11.12.2020.
//

#include <day01/day1.h>
#include <utilslib/FileLoader.h>
#include <iostream>
#include <list>
#include <algorithm>    // find

using namespace std;

int findValue()
{
    // vars
    int retValueMultiplied = -1;
    int value;
    int target_value;
    // input
    auto retList = FileLoader::ReadIntListFromFile("input.txt");

    // iterative loop
    for (auto it = retList.begin(); it != retList.end(); it++)
    {
        value = (*it);
        target_value = 2020 - value;

        auto find_it = std::find(retList.begin(), retList.end(), target_value);
        if (find_it != retList.end())
        {
            // found a value :
            cout << "found a value: " << value << " " << target_value << endl;
            retValueMultiplied = value * target_value;
            cout << "muliplied : " << retValueMultiplied << endl;
            exit(0);
        }

    }
    return retValueMultiplied;
}

