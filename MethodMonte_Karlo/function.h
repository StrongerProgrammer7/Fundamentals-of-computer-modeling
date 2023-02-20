#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include "include.h"

bool differLittle_MX_DX(double const& coord, double const& a);
std::vector<double> getRandomPoint(bool const uniform, double const& start_rect, double const& end_rectangle, int const& countPoint);
bool insideTringle(std::map<std::string, double> triangleVertexCoord, double x, double y);
double functionTringle(int const& x, int const& numVar);
double functionIntegral(double const& x, double const& numVar);
double functionPolar(double const& A, double const& B, double const& phi, bool isIntegral);
double step_h(const double a, const double b, unsigned int count_segment);
std::vector<double> getXMonteCarlo(const double a, const double b, unsigned int count_segment);
std::vector<double> getYMonteCarlo(std::vector<double>& x, int const& numVar);
void getCoordinateMonteCarloIntegral(std::vector<double>& x, std::vector<double>& y, int const& numVar, const int& count_segment);
void findMax_MinFuncMonteCarlo(std::vector<double>& y, double& max, double& min);
double method_Sympsona(const double a, const double b, unsigned int count_segment, int const& numVar,bool isPolar);
double method_LeftRectangle(const double a, const double b, unsigned int count_segment);

#endif