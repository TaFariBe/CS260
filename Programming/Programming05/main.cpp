#include <iostream>
#include <string>
#include <sstream> 
#include "Inputs.h"
#include "LogicPair.h"

using namespace std;
using namespace dshw;

string table_header(int num_inputs, string title)
{
    stringstream out;
    for (int i = 0; i < num_inputs; i++)
    {
        out << "in" << (i + 1) << "|";
    }
    out << " " << title << endl;
    out << string(num_inputs * 4 + title.length() + 1, '-');
    return out.str();
}

LogicPair AND(const Inputs& inputs);
LogicPair OR(const Inputs& inputs);
LogicPair XOR(const Inputs& inputs);
LogicPair NOT(const LogicPair& p);
LogicPair NAND(const Inputs& inputs);
LogicPair NOR(const Inputs& inputs);
LogicPair XNOR(const Inputs& inputs);

void truthTable(Inputs inputs, LogicPair (*logicFunc)(const Inputs&));

int main()
{
    const int INPUT_COUNT = 3; // Play around with this number. No less than 2, no more than 5.

    Inputs inputs(INPUT_COUNT);

    truthTable(inputs, AND);
    truthTable(inputs, OR);
    truthTable(inputs, XOR);
    truthTable(inputs, NAND);
    truthTable(inputs, NOR);
    truthTable(inputs, XNOR);

    return 0;
}