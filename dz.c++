#include <iostream>
#include <windows.h>
using namespace std;

struct Students
{
    string surname;
    string name;
    string patronymic;
    int grade[4];
    double average;
};
int main()
{
setlocale(0,"");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int N;
cout <<"введи кол-во студентов ";
cin >> N;
Students* stud = new Students[N];
for(int i=0;i<N;i++)
{
    cout<<"введи фамилию "<<i+1<<" ого студента:"<<endl;
    cin>>stud[i].surname;
    cout<<"введи имя "<<i+1<<" ого студента:"<<endl;
    cin>>stud[i].name;
    cout<<"введи отчество "<<i+1<<" ого студента:"<<endl;
    cin>>stud[i].patronymic;
    cout<<"введи 4 оценки его оценки:"<<endl;
    for(int j=0;j<4;j++)
    {
        cin>>stud[i].grade[j];
    }
}
for (int i = 0; i < N; i++)
{
    cout<<i+1<<" "<<stud[i].surname;
    cout<<" "<<stud[i].name;
    cout<<" "<<stud[i].patronymic;
    for (int j = 0; j < 4; j++)
    {
        cout<<stud[i].grade[j]<<" ";
    }
    cout<<endl;
}
cout<<"Средний балл каждого студента:"<<endl;
for (int i = 0; i < N; i++)
{
    cout<<i+1<<" "<<stud[i].surname;
    int sumOfGrades = 0;
    for (int j = 0; j < 4; j++)
    {
        sumOfGrades += stud[i].grade[j];
    }
    stud[i].average =(float)sumOfGrades / 4;
    cout<<" "<<stud[i].average<<endl;
}

float SumOfAverage=0;
    for (int i = 0; i < N; i++)
    {
        SumOfAverage += stud[i].average;
    }

    float GroupAverage=SumOfAverage/N;

    int StudentsAverageHigher = 0;

    for (int i = 0; i < N; i++)
    {
        if (stud[i].average > GroupAverage)
        {
            cout << StudentsAverageHigher + 1 << " " << stud[i].surname << " " << stud[i].average << endl;
            StudentsAverageHigher++;
        }
    }

    if (StudentsAverageHigher == 0)
        cout << "в группе нету студентов средний балл которых выше по группе\n";

    cout << "список задолжников в группе\n";

    int debtors = 0;
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (stud[i].grade[j] == 2&&flag==false)
            {
                cout << debtors + 1 << " " << stud[i].surname << endl;
                flag = true;
                debtors++;
            }
        }
    }
    if (debtors == 0)
    {
        cout << "в группе нету задолжников\n";
    }

    cout << "список отличников\n";
    
    int HonorStudent = 0;
    for (int i = 0; i < N; i++)
    {
        int five = 0;
        for (int j = 0; j < 4; j++)
        {
            if (stud[i].grade[j] == 5)
                five++;
        }
        if (five == 4)
        {
            cout << HonorStudent + 1 << " " << stud[i].surname << endl;
            HonorStudent++;
        }
    }
    if (HonorStudent == 0)
    {
        cout << "в группе нету отличников\n";
    }
}