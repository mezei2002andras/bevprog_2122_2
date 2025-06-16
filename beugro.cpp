#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugr� �rv�nyes, amely nem tartalmaz semmilyen v�ltoztat�st a main()-ben,
        �s m�r nincs benne kommentezve semmi
    - nem tartalmaz #undefine-t, az "ellenoriz"-en k�v�l nem tartalmaz #define sorokat, �s azt sem szabad megv�ltoztatni
    - warningokat bekapcsolva nem ad "no return statement" warningot
*/

// Innentol

bool az_egyik_a_val_kezdodik(string a, string b)
{
    bool kezdodik = false;
    if(a[0] == 'a' || b[0] == 'a')
        {
            kezdodik = true;
        }
    else kezdodik = false;
    return kezdodik;
}

string vissza(string a)
{
    cout << "elolre: "<< a << endl;
    string forditva;
    for (int i = a.size(); i >= 0; i--)
    {
        char temp = a[i];
        forditva.push_back(temp);
    }
    forditva.push_back('\0');
    cout << "forditva: "<< forditva << endl;
    reverse(a.begin(), a.end());
    return a;
    //return forditva;
}

struct K
{
    int a;
    int b;
};

void kezel (K& a)
{
    a.b = a.a;
}

int osszesen(K a)
{
    int valami = 0;
    valami = a.a + a.b;
    return valami;
}

vector<int> rejtveny()
{
    vector<int> valami = {0, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    return valami;
}
// Idaig

int main()
{
    int pont = 0;
    srand(time(0));


    ellenoriz(az_egyik_a_val_kezdodik("abc","bca") &&
        az_egyik_a_val_kezdodik("bca","abc") &&
        !az_egyik_a_val_kezdodik("bca","bca") , pont)

    string randomszo;
    for (int i=0;i<5;i++) {
        char c = "qwertyuiop"[rand()%10];
        randomszo = randomszo + c;
    }
    for (int i=0;i<5;i++) {
        char c = "asdfghjklm"[rand()%10];
        randomszo = randomszo + c;
    }
    cout <<"main kiiras: " << vissza(randomszo) << "itt a vege" << endl;
    ellenoriz(vissza("abc") == "cba" &&
        vissza(vissza(randomszo))==randomszo &&
        vissza(randomszo)!=randomszo , pont)

    K k;
    int vel = rand()%100;
    k.a = vel;
    kezel(k);
    ellenoriz(k.b==k.a , pont)
  
    const K kc = {2,2};
    ellenoriz(osszesen(k)==vel*2 && osszesen(kc)==4, pont)
      
    vector<int> valami = rejtveny();
    int sum=0; int szorzat=1;
    for (int a : valami) {
        sum+=a;
        szorzat *= a;
    }
    ellenoriz(valami.size() == 10 && szorzat == 0 && sum == 10 , pont)


    cout << endl << pont << "/5 pont";
}
