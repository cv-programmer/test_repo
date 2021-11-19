/*
 * @Author: Junhu Li
 * @Date: 2021-11-15 19:37:12
 * @version: 
 * @LastEditors: Junhu Li
 * @LastEditTime: 2021-11-17 16:49:35
 * @Description: 用于简单测试
 * @FilePath: \code\cpp_primer5th\test.cpp
 * Talk is cheap, Show me the code
 */
#include <iostream>

int main()
{
    double pi = 3.14;
    const int &r = pi;
    std::cout << r << std::endl;
    return 0;
}