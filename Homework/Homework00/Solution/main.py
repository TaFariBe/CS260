'''
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
'''

def and_table():
    print("A | B | A AND B")
    print("---------------")
    for A in [0,1]:
        for B in [0,1]:
            print(f"{A} | {B} |    {A and B}")
    print()
    
def or_table():
    print("A | B | A OR B")
    print("---------------")
    for A in [0,1]:
        for B in [0,1]:
            print(f"{A} | {B} |   {A or B}")
    print()
    
def imp_table():
    print("A | B | A -> B")
    print("---------------")
    for A in [0,1]:
        for B in [0,1]:
            print(f"{A} | {B} |    {int(not A) or B}")
    print()
    
if __name__ == "__main__":
    and_table()
    or_table()
    imp_table()