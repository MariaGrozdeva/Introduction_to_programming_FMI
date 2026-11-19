#include <iostream>

unsigned lowbit(unsigned v)
{
    return v & -v;
}

void findThreeUnique(const int* arr, int n, int* out)
{
    // x = a ^ b ^ c
    unsigned x = 0;
    for (int i = 0; i < n; ++i)
    {
        x ^= (unsigned)arr[i];
    }

    // f(v) = lowbit(v ^ x). Двойките дават еднакво f и се унищожават, така че y = f(a) ^ f(b) ^ f(c).
    // Тъй като (a^x) ^ (b^x) ^ (c^x) = 0, точно два от тези най-десни бита съвпадат, а третият е различен -> y != 0 и точно едно от трите числа има f(v) == y.
    unsigned y = 0;
    for (int i = 0; i < n; ++i)
    {
        y ^= lowbit((unsigned)arr[i] ^ x);
    }

    // Числото с f(v) == y е първото уникално.
    unsigned a = 0;
    for (int i = 0; i < n; ++i)
    {
        if (lowbit((unsigned)arr[i] ^ x) == y)
        {
            a ^= (unsigned)arr[i];
        }
    }

    // Остават b и c, b ^ c = x ^ a. Разделяме както в задача 2, но a е в масива веднъж, затова го махаме от групата му.
    unsigned bc = x ^ a;
    unsigned diff = lowbit(bc);
    unsigned b = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((unsigned)arr[i] & diff)
        {
            b ^= (unsigned)arr[i];
        }
    }
    if (a & diff)
    {
        b ^= a;
    }

    out[0] = (int)a;
    out[1] = (int)b;
    out[2] = (int)(bc ^ b);
}

int main()
{
    int arr[] = {9, 18, 9, -50, 12, 18, 15, 12, -50, 7, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res[3];

    findThreeUnique(arr, n, res);
    std::cout << res[0] << " " << res[1] << " " << res[2] << std::endl;

    return 0;
}
