// main file to use classes

#include <cmath>
#include "Config.h"
#include "Points.hpp"
#include "Approximation.hpp"

double MyFunction(double x){
    return (x/2);
}
int main(int argc, char* argv[]){

    //std::string config_file;
    //if (argc==2){
    //    config_file = argv[1];
    //}
    //else{
    //    config_file = "config2.csv";
    //}
    //Config c(config_file);
    Points points("config2.csv");
    double *x = points.x();
    std::cout<< x[3];
    VectorXd coeff;

    if (points.GetType() == "Approximation"){
        Fitting d(points);
        coeff = d.CalculateCoeff();
        d.printSolution(coeff);
        double err = d.CalculateError(coeff);
    }

    else if (points.GetType() == "Piecewise"){

        PieceWiseInterpolation d(points);

        coeff = d.CalculateCoeff();
        d.printSolution(coeff);
        double err = d.CalculateError(coeff);

    }
    else if ( (points.GetType() == "Polynomial")){
        Interpolation d(points);
        std::cout << "Polynomial " << std::endl;
        coeff = d.CalculateCoeff();
        std::cout << coeff << std::endl;
        d.printSolution(coeff);
    }
    else if (points.GetType() == "PiecewiseContinuous"){
        PieceWiseInterpolation d(points);
        std::cout << "Polynomial " << std::endl;
        coeff = d.CalculateCoeff();
        std::cout << coeff << std::endl;
        d.printSolution(coeff);
        double err = d.CalculateError(coeff);
    }

    return 0;

}

