#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

namespace ariel
{
    /**
     * @brief fill mat from outside in.
     * Outer Loop: Counts the number of rings to fill [min(row, col)/2].
     * Inner loop: In each iteration we fill in the top and bottom rows,
     * as well as the first and last column, according to the ring in the outer loop. 
     * time complixity: o(n^2)
     * @param cols 
     * @param rows 
     * @param ch1 
     * @param ch2 
     * @return string 
     */
    string mat(int cols, int rows, char ch1, char ch2)
    {
        if (cols % 2 == 0 || rows % 2 == 0 )
        {
            throw invalid_argument("Mat size is always odd");
        }
        if(cols < 0 || rows < 0){
            throw invalid_argument("Mat size can't be negative");
        }
        if(ch1 < '!' || ch1>'~' || ch2<'!' || ch2>'~'){
            throw invalid_argument("invalid argument of char");
        }

        vector< vector<char> > arr(rows, vector<char> (cols, ch1));
        try
        {
            int enter = min(cols, rows) / 2;
            char currCh = ch1;
            for (size_t i = 0; i <= enter; i++)
            {
                for (size_t j = i; j < cols - i; j++)
                {
                    arr[i][j] = currCh;
                    arr[rows - 1 - i][j] = currCh;
                }

                for (size_t j = i; j < rows - i; j++)
                {
                    arr[j][i] = currCh;
                    arr[j][cols - 1 - i] = currCh;
                }
                currCh = (currCh == ch1) ? ch2 : ch1;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        string ans = string("");
        try
        {
            for (int i = 0; i < rows; i++)
            {

                for (int j = 0; j < cols; j++)
                {
                    ans += arr[i][j];
                }
                ans += "\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        return ans;
    }
}