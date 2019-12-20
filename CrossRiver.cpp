/*
一个猎人Hunter要带一棵胡萝卜Carrot，一只狗dog，两只老虎Tiger和一只羊sheep过河，
现在小船上只有三个座位，
没有人或狗在，老虎会吃羊，
*/
#include <iostream>
#include <string>
#include <array>
#include <map>
/*
dog sheep carrot tiger tiger
(dog ! sheep) && (sheep ! carrot)

   "tiger""dog""carrot""sheep"    "tiger" 
*/
using namespace std;

string list[6] = {"dog","sheep","carrot","tiger","tiger"};
map<string, int> Left, Right;

bool isOK(bool);
bool isOK(string , string);
void init();

int main()
{
    init();
/*
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            Left[list[i]]--, Left[list[j]]--;
            // cout << Left["dog"] << Left["sheep"] << Left["carrot"] << Left["tiger"] << Left["tiger"] << endl;
            if (isOK(0)&&isOK(list[i], list[j])) {
                cout << list[i] << "+" << list[j] << endl;
            }
            Left[list[i]]++, Left[list[j]]++;
        }
    }// 一开始只能带 sheep 和 tiger 到右边
     // 可以看作一开始左边"dog""carrot""tiger" ，右边"tiger""sheep"
*/


        return 0;
}

void init()
{
    Left["dog"] = 1, Left["sheep"] = 1;
    Left["carrot"] = 1, Left["tiger"] = 2;
    Right["dog"] = 0, Right["sheep"] = 0;
    Right["carrot"] = 0, Right["tiger"] = 0;
}

bool isOK(bool H)
{
    if(Left["dog"] && Left["sheep"])
        return false;
    else if (Left["sheep"] && Left["carrot"])
        return false;
    else if (Left["tiger"] && Left["sheep"])
        return false;
    return true;
}

bool isOK(string s1, string s2)
{
    if (s1 == "dog" && s2 == "sheep")
        return false;
    if (s1 == "sheep" && s2 == "carrot")
        return false;
    return true;
}