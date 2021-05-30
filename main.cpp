#include <iostream>
#include <vector>

using namespace std;

int posSumReal(vector<int> arr, int limit, int sum)
{
    int pos = 0;
    if (limit == 0 || sum <= 0 || arr.size() == 0)
    {
        return 0;
    }

    if (arr[0] == sum)
    {
        pos++;
        cout << "\nif stat - number of possibility are: " << pos << " ,i is: " << arr[0] << " ,Sum is: " << sum
             << " ,limit is: " << limit
             << endl;
    }
    else
    {
        cout << "else stat - number of possibility are: " << pos << " ,arr is at: " << arr[0] << " ,Sum is: " << sum
             << " ,limit is: "
             << limit << endl;

        vector<int> DeleteItemArr;
        DeleteItemArr = arr;
        DeleteItemArr.erase(DeleteItemArr.begin());
        pos += posSumReal(arr, limit - 1, sum - arr[0]) + posSumReal(DeleteItemArr, limit,
                                                                     sum);///TODO - check correct understanding. like doing another for loop j - will run once and then continue with the i loop

    }
    cout << "\n\tFinal number of possibility are: " << pos << " ,Sum is: " << sum << ",limit is: " << limit << "\n"
         << endl;
    return pos;
}

int main()
{
    cout << "\n****************************************" << flush;
    cout << "\n\t" << char(1) << " Backtracking " << char(1) << endl;
    cout << "****************************************\n" << flush;

    vector<int> CoinValueArray;
    int NumCoins = 0;
    int Sum = 0;
    int CoinVal = 0;
    int CoinsLimit = 0;


    cout << "Please enter the number of coins:\n" << flush;
    if (cin >> NumCoins)
    {
        cout << "Please enter the coins value\n" << flush;
        for (int i = 0; i < NumCoins; ++i)
        {
            cin >> CoinVal;
            CoinValueArray.emplace_back(CoinVal);
        }
    }
    cout << "Please enter the requested sum:\n" << flush;
    cin >> Sum;
    cout << "Please enter the coins limit:\n" << flush;
    cin >> CoinsLimit;
    int RealPossibilities = 0;


    RealPossibilities = posSumReal(CoinValueArray, CoinsLimit, Sum);

    cout
            << "\n**********************************************************************************************************"
            << endl;
    cout << "\tHooray! There are " << RealPossibilities << " possible partitions" << endl;
    cout
            << "**********************************************************************************************************\n"
            << endl;
    return 0;
}
/*
 *
 * The funk will go over a certain sum see if it's equal each time to an item if not it'll check the sum less then said item,
 * needs to be done recursively, adding as many items seeing if they equal to the sum according to the coin limit.
 *
 * TODO Reduction - think of how to make the problem in to smaller portions to create Recursion and in the end it'll stop at a certain point
 */