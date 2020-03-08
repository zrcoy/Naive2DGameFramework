#pragma once

int myAtoi_s(const char* singleChar)
{
    return static_cast<int>(*singleChar - '0');
}

int myAtoi_m(const char* chars)//transfer pure number chars into integers
{
    int res = 0;
    int sign = 1;
    int i = 0;
    if (chars[0] == '-')
    {
        sign = -1;
    }
    for (; chars[i] != '\0'; i++)
    {
        res += res * 10 + (chars[i] - '0');
    }
    return res;
}
