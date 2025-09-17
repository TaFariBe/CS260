/*
-   Create 3 separate functions that display the truth tables for AND, OR, and Implication (->). 
-   The output for each function should be as follows: 
 
A | B | A AND B 
-------------- 
0 | 0 |    0 
0 | 1 |    0 
1 | 0 |    0 
1 | 1 |    1 
 
A | B | A OR B 
-------------- 
0 | 0 |   0 
0 | 1 |   1 
1 | 0 |   1 
1 | 1 |   1 
 
A | B | A -> B 
-------------- 
0 | 0 |   1 
0 | 1 |   1 
1 | 0 |   0 
1 | 1 |   1 
*/

#include <iostream>

using namespace std;


void and_table()
{
    cout << "A | B | A AND B" << endl;
    cout << "---------------" << endl;

    for (int A = 0; A <= 1; A++)
    {
        for (int B = 0; B <= 1; B++)
        {
            cout << A << " | " << B << " |    " << (A && B) << endl;
        }
    }
    cout << "\n";
}

void or_table()
{
    cout << "A | B | A OR B" << endl;
    cout << "---------------" << endl;

    for (int A = 0; A <= 1; A++)
    {
        for (int B = 0; B <= 1; B++)
        {
            cout << A << " | " << B << " |   " << (A || B) << endl;
        }
    }
    cout << "\n";
}

void imp_table()
{
    cout << "A | B | A -> B" << endl;
    cout << "---------------" << endl;

    for (int A = 0; A <= 1; A++)
    {
        for (int B = 0; B <= 1; B++)
        {
            cout << A << " | " << B << " |    " << (!A || B) << endl;
        }
    }
    cout << "\n";
}

int main()
{
    and_table();
    or_table();
    imp_table();
}
