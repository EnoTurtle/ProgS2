#include "tp1.h"
#include <QApplication>
#include <time.h>
#include <math.h>
#include <cmath>

#define return_and_display(result) return _.store(result);

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot
    // check n

    // z= x + iy        point = x + iy
    //  z*z + point = (((z.x)*(z.x))+((z.y)*(z.y))+ point.x) + i (2*(z.x)*(z.y)+point.y)
    bool retour = true;
    double module_z = sqrt( pow( ((z.x)*(z.x))+((z.y)*(z.y)) , 2 ));
    if(module_z <= 2 && n>0){
//       z = (z*z)+point
        float temp = z.x;
        z.x = (((z.x)*(z.x))-((z.y)*(z.y))+ point.x);
        z.y = (2*(temp)*(z.y)+point.y);
        return(isMandelbrot(z, n-1, point));
    }
    else if(module_z > 2){
        retour = false;
        return int(retour);
//        return_and_display(int(retour));
    }
    return int(retour);

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}
