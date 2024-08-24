#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void basic_shape()
{
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200, x4 = 200, y4 = 100;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
    delay(1500);
}

void translation()
{
    cleardevice(); // Clear the previous drawing
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200, x4 = 200, y4 = 100;
    int del_x, del_y;
    cout << "Enter the change in x direction: ";
    cin >> del_x;
    cout << "Enter the change in y direction: ";
    cin >> del_y;
    x1 += del_x;
    x2 += del_x;
    x3 += del_x;
    x4 += del_x;
    y1 += del_y;
    y2 += del_y;
    y3 += del_y;
    y4 += del_y;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

void scaling()
{
    cleardevice(); // Clear the previous drawing
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200, x4 = 200, y4 = 100;
    float scale_x, scale_y;
    cout << "Enter the scaling factor in x: ";
    cin >> scale_x;
    cout << "Enter the scaling factor in y: ";
    cin >> scale_y;
    if (scale_x <= 3 && scale_y <= 3)
    {
        x1 *= scale_x;
        x2 *= scale_x;
        x3 *= scale_x;
        x4 *= scale_x;
        y1 *= scale_y;
        y2 *= scale_y;
        y3 *= scale_y;
        y4 *= scale_y;
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x4, y4);
        line(x4, y4, x1, y1);
    }
    else
    {
        cout << "ERROR: Factor is too big to scale in window";
    }
}

void rotation()
{
    cleardevice(); // Clear the previous drawing
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200, x4 = 200, y4 = 100;
    float angle;
    cout << "Enter the angle by which the shape is to be rotated: ";
    cin >> angle;
    float final_angle = (angle * M_PI / 180); // Use M_PI for better precision
    float cos_theta = cos(final_angle);
    float sin_theta = sin(final_angle);

    int a1 = (int)(x1 * cos_theta - y1 * sin_theta);
    int b1 = (int)(x1 * sin_theta + y1 * cos_theta);
    int a2 = (int)(x2 * cos_theta - y2 * sin_theta);
    int b2 = (int)(x2 * sin_theta + y2 * cos_theta);
    int a3 = (int)(x3 * cos_theta - y3 * sin_theta);
    int b3 = (int)(x3 * sin_theta + y3 * cos_theta);
    int a4 = (int)(x4 * cos_theta - y4 * sin_theta);
    int b4 = (int)(x4 * sin_theta + y4 * cos_theta);

    line(a1, b1, a2, b2);
    line(a2, b2, a3, b3);
    line(a3, b3, a4, b4);
    line(a4, b4, a1, b1);
}



void scanfillalgo(){
	
}






int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int choice;
    cout << "The default shape is\n";
    basic_shape();
    do
    {
        cout << "Enter the appropriate choice\n";
        cout << "1. Translation\n2. Scaling\n3. Rotation\n4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        case 4:
            cout << "Program terminated successfully";
            break;
        default:
            cout << "Invalid choice. Please enter again.";
        }
    } while (choice != 4);

    getch();
    closegraph();
    return 0;
}
