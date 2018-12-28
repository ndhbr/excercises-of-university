#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distanceFromPointAToPointB(double *, double *);

int main(int argc, char *argv[]) {
    double points[3][2];
    double distancePoint1ToPoint2, distancePoint1ToPoint3, distancePoint2ToPoint3;
    double finalWay;

    if(argc != 7)
    {
        printf("Fehler bei der Eingabe.\n");
        return 1;
    }

    points[0][0] = atof(argv[1]);
    points[0][1] = atof(argv[2]);
    points[1][0] = atof(argv[3]);
    points[1][1] = atof(argv[4]);
    points[2][0] = atof(argv[5]);
    points[2][1] = atof(argv[6]);

    distancePoint1ToPoint2 = distanceFromPointAToPointB(points[0], points[1]);
    distancePoint1ToPoint3 = distanceFromPointAToPointB(points[0], points[2]);
    //distancePoint2ToPoint3 = sqrt(pow(distancePoint1ToPoint2, 2) + pow(distancePoint1ToPoint3, 2));
    distancePoint2ToPoint3 = distanceFromPointAToPointB(points[1], points[2]);

    finalWay = distancePoint1ToPoint2 + distancePoint2ToPoint3;

    if((distancePoint1ToPoint3 + distancePoint2ToPoint3) < finalWay)
        finalWay = distancePoint1ToPoint2 + distancePoint2ToPoint3;
    if((distancePoint1ToPoint2 + distancePoint1ToPoint3) < finalWay)
        finalWay = distancePoint1ToPoint2 + distancePoint1ToPoint3;

    printf("%f", finalWay);

    return 0;
}

double distanceFromPointAToPointB(double *pointA, double *pointB)
{
    double a = pow((pointA[0] - pointB[0]), 2);
    double b = pow((pointA[1] - pointB[1]), 2);
    double result = sqrt(a + b);

    return result;
}