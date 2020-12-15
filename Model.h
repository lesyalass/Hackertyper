#include "String.h"
#include <fstream>
#include <iostream>
#pragma once

class Model
{
    public:
        Model();
        ~Model();
        void AddSymbol();
        String GetVisibleText();
    private:
        String text;
        int counter;
};