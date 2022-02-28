#include <iostream>
#include <ctime>
#include "clui.h"
using namespace std;
#define size_title 101
#define size_import 401
struct task
{
    char *title = new char[100];
    char *description = new char[400];
    int import;
    int day;
    int month;
    int year;
};
void entry(int task_num, task *&s)
{
    change_color_rgb(10, 245, 10);
    cout << "write the title:"
         << "  (between 1 to 100)" << endl;
    cin.ignore();
    cin.getline(s[task_num].title, 100);
    // cin >> s[task_num].title;
    clear_screen();
    cout << "write the description:"
         << "  (between 1 to 400)" << endl;
    cin.getline(s[task_num].description, 400);
    //cin >> s[task_num].description;
    clear_screen();
    cout << "write value of import:"
         << "  (between 1 to 10)" << endl;
    cin >> s[task_num].import;
    clear_screen();
    cout << "enter the month:" << endl;
    cin >> s[task_num].month;
    clear_screen();
    cout << "enter the day:" << endl;
    cin >> s[task_num].day;
    clear_screen();
    cout << "enter the year:" << endl;
    cin >> s[task_num].year;
    clear_screen();
    cout << "|o| your task added successfuly |o| " << endl
         << "         back to main menu";
    reset_color();
    delay(1000);
}
void delete_task(task *s, int n, int task_num)
{
    char answer;
    int page;
    clear_screen();
    change_color_rgb(150, 115, 59);
    cout << "Are you sure?(y/n)" << endl;
    cin >> answer;
    if (answer == 'n')
    {
        clear_screen();
        cout << "== back to main munu ==";
    }
    else
    {
        task_num++;
        clear_screen();
        task *array = new task[1000];
        // char *array = new char[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = s[i];
        }
        for (int j = n + 1; j < task_num - 1; j++)
        {
            array[j] = s[j + 1];
        }
        //  array[n - 1] = n;
        delay(700);
        delete[] s;

        //  s = new task[n];
        s = array;
        task_num--;
        //delete[] s[n].title;
        //delete[] s[n].description;
        cout << "                                      deleting";
        delay(500);
        cout << ".";
        delay(500);
        cout << ".";
        delay(500);
        cout << "." << endl;
        delay(500);
        clear_screen();
        cout << "|o| your task completely delete |o| " << endl
             << "      == back to main munu ==       ";
    }
    delay(2000);
    reset_color();
}
int detail(task *s, int n, int &task_num)
{
    int page;
    clear_screen();
    cout << "detail of task" << n << ":" << endl;
    cout << "::> " << s[n - 1].title << endl;
    cout << "::> " << s[n - 1].description << endl;
    cout << "::> " << s[n - 1].import << endl;
    cout << "::> " << s[n - 1].month << "/" << s[n - 1].day << "/" << s[n - 1].year << endl;
    cout << "=================================" << endl;
    delay(300);
    cout << "|press '0' to go to main menu" << endl
         << "|press '1' to go back page" << endl
         << "|press '2' to delete task" << endl;
    cin >> page;
    if (page == 2)
    {
        delete_task(s, n - 1, task_num);
    }
    /*  if (page == 1)
    {
        return 1;
    }*/
    return page;
}
void swap(task &s, task &t)
{
    task temp = s;
    s = t;
    t = temp;
}
void sort_tasks(task *&s, int size)
{
    size++;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (s[j + 1].import > s[j].import)
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}
void show(int task_num, task *s)
{
    int n;
    change_color_rgb(10, 100, 200);
    if (task_num == -1)
    {
        cout << "there is no tasks" << endl;
        cout << ":::::::::::::::::" << endl;
        cout << "* press '0' and I think that's beautiful :)" << endl;
        cin >> n;
    }
    else
    {
        sort_tasks(s, task_num);
        cout << ". . . . . . . . . . . . . . sort by importance . . . . . . . . . . . . . ." << endl;
        for (int i = 0; i <= task_num; ++i)
        {
            cout << i + 1 << ")" << endl;
            cout << "::> " << s[i].title << endl;
            cout << "::> " << s[i].month << "/" << s[i].day << "/" << s[i].year << endl;
            cout << "::> " << s[i].import << endl;
            cout << "-----------------------" << endl;
        }
        delay(300);
        cout << "|for details press the number of task" << endl
             << "|press '0' to back in main menu" << endl;
        cin >> n;
        if (n == 0)
        {
            clear_screen();
            cout << "//back to main menu//";
            delay(900);
        }
        else
        {
            if (detail(s, n, task_num) == 1)
            {
                clear_screen();
                show(task_num, s);
            }
        }
    }
    reset_color();
}
int main()
{
    init_clui();
    int n, task_num = -1;
    change_color_rgb(255, 85, 0);
    cout << "****** Welcome to this program ******" << endl
         << "            press a char !           " << endl;
    reset_color();
    char t = getch();
    task *s = new task[1000];
    clear_screen();
    while (n != 3)
    {
        change_color_rgb(165, 114, 232);
        //cursor_to_pos(5, 1);
        cout << "................................................................" << endl;
        // restore_cursor();
        cout << "menu of tasks:" << endl;
        cout << "1)set a new task" << endl;
        cout << "2)show tasks" << endl;
        cout << "3)exit" << endl;
        reset_color();
        cin >> n;
        clear_screen();
        if (n == 1)
        {
            task_num++;
            entry(task_num, s);
            clear_screen();
        }
        if (n == 2)
        {
            show(task_num, s);
            clear_screen();
        }
    }
    reset_color();
    change_color_rgb(149, 232, 226);
    cout << "have a nice time :)" << endl;
    reset_color();
    delay(2000);
    for (int i = 0; i <= task_num; i++)
    {
        delete s[i].title;
        delete s[i].description;
    }
    quit();
    return 0;
}