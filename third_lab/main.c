#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define pi acos(-1)

void MyFlush(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
    return;
}
void CorrectInputU(unsigned int* inputVar)
{
    while (!scanf("%u", inputVar))
    {
        MyFlush();
        printf("Enter valid data!\n");
    }
    return;
}
struct Data
{
    unsigned int s;
    unsigned int h;
    unsigned int v;
    double q;
};
struct Data* CreateArr(unsigned int* n)
{
    return (struct Data*)malloc(*n * sizeof(struct Data));
}
double CalculateWaterFlow(unsigned int* h, unsigned int* s, unsigned int* v)
{
    return *h * *s * *v * pi / 2;

}
void FillArr(struct Data* arr, unsigned int* n)
{
    unsigned int i = 0;
    for (; i < *n; ++i)
    {
        printf("#%u h = ", i);
        CorrectInputU(&arr[i].h);
        printf("#%u s = ", i);
        CorrectInputU(&arr[i].s);
        printf("#%u v = ", i);
        CorrectInputU(&arr[i].v);
        arr[i].q = CalculateWaterFlow(&arr[i].h, &arr[i].s, &arr[i].v);
    }
}
void GetStreamInfo(struct Data* arr, unsigned int* n)
{
    unsigned int i = 0;
    for (; i < *n; ++i)
    {
        printf("water flow #%u per second - %lf\n", i, arr[i].q);
    }
    return;
}

int main()
{
    unsigned int n;
    printf("Enter a number of measurements\n");
    CorrectInputU(&n);
    struct Data* arr = CreateArr(&n);   
    FillArr(arr, &n); 
    GetStreamInfo(arr, &n);
    system("pause");
    return 0;
}