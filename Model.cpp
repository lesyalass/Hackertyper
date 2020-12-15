#include "Model.h"

Model::Model()
{
    std::ifstream MyReadFile("../text.txt");
    char changingText[255];
    counter = 0;
    int i = 0;
    while (!MyReadFile.eof())
    {
        MyReadFile.getline(changingText, 255);
        text = text + String(changingText) + String("\n");
    }
}

Model::~Model() = default;

void Model::AddSymbol()
{
    counter ++;
}

String Model::GetVisibleText()
{
    return text.split(counter)[0];
}

