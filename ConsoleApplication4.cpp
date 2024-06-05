#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int len = 10;



void MakeArr(int arr[10][10])
{

    int n1, n2;
    int o = 3;
    int t = 2;
    int pos = 1;
    for (int i = 0; i < 5;)
    {


        n1 = rand() % 10;
        n2 = rand() % 10;
        if (arr[n1][n2] == 1 || arr[n1 - 1][n2] == 1 || arr[n1 - 1][n2 - 1] == 1 || arr[n1 + 1][n2 + 1] == 1 || arr[n1][n2 - 1] == 1 || arr[n1][n2 + 1] == 1 || arr[n1 + 1][n2] == 1 || arr[n1 - 1][n2 + 1] == 1 || arr[n1 + 1][n2 - 1] == 1)
            continue;
        else
        {
            int m = rand() % 2;

            if (pos == 1)
            {
                if (t == 0)
                    pos--;

                else
                {
                    t--;

                }
            }
            else if (pos == 0)
            {
                o--;
            }
            


            i++;
            switch (pos)
            {
            case 0:
            {
                arr[n1][n2] = 1;

                break;
            }
            case 1:
            {
                if (m == 1)
                {
                    if (n1 == 0)
                    {
                        arr[n1][n2] = 1;
                        arr[n1 + 1][n2] = 1;

                    }
                    else if (n1 <= 9)
                    {
                        arr[n1][n2] = 1;
                        arr[n1 - 1][n2] = 1;

                    }

                }
                else
                    if (n2 == 9)
                    {
                        arr[n1][n2] = 1;
                        arr[n1][n2 - 1] = 1;

                    }
                    else if (n2 >= 0)
                    {
                        arr[n1][n2] = 1;
                        arr[n1][n2 + 1] = 1;

                    }

                break;
            }
            }



        }
    }
}



void MakeDask(int arr1[10][10], int arr2[10][10])
{
    cout << "игрок" << endl;
    cout << ' ';
    for (int a = 0; a < len; a++)
        cout << "   " << a;
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < len; j++)
        {
            if (arr1[i][j] == 1)
                cout << "#" << "   ";
            else if (arr1[i][j] == 2)
                cout << "X" << "   ";
            else if (arr1[i][j] == 4)
                cout << "%" << "   ";
            else
                cout << "0" << "   ";
        }
        cout << endl;
    }
    cout << endl << endl;

    cout << "бот" << endl << ' ';
    for (int a = 0; a < len; a++)
        cout << "   " << a;
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < len; j++)
        {
            if (arr2[i][j] == 2)
                cout << "X" << "   ";
            else if (arr2[i][j] == 4)
                cout << "%" << "   ";
            else
                cout << "0" << "   ";
        }
        cout << endl;
    }
}

void BamBam(int arr1[10][10], int arr2[10][10])
{
    MakeArr(arr1);
    MakeArr(arr2);

    int coung = 0;
    int counb = 0;

    do
    {
        MakeDask(arr1, arr2);

        if (coung == 7 || counb == 7)
            break;

        int n1;
        int n2;
        cout << "введите первую координату   ";
        cin >> n1;
        cout << "введите вторую координату   ";
        cin >> n2;
        cout << "Jawohl, mein Fuhrer" << endl << endl;

        if (arr2[n1][n2] == 2 || arr2[n1][n2] == 4)
            continue;
        

        if (arr2[n1][n2] == 1)
        {
            arr2[n1][n2] = 2;
            coung++;
        }
        else
            arr2[n1][n2] = 4;


        n1 = rand() % 10;
        n2 = rand() % 10;
        do
        {
            if (arr1[n1][n2] == 2 || arr1[n1][n2] == 4)
            {
                n1 = rand() % 10;
                n2 = rand() % 10;
            }
            else break;
        } while (true);
        if (arr1[n1][n2] == 1)
        {
            arr1[n1][n2] = 2;
            counb++;
        }
        else
            arr1[n1][n2] = 4;

        
    } while (true);

    if (coung == 7)
        cout << "игрок победил";
    else
        cout << "бот победил";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int arr1[len][len];
    int arr2[len][len];

    BamBam(arr1, arr2);


}
