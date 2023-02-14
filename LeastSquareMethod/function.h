#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

double** fillMatrixA(int const& countOfVar, std::vector<double>sumCoordinate, int const& countNumber);
double* filllMatrixB(int const& countOfVar, std::vector<double>sumCoordinate);
void initializeVector(std::vector<double>& vec, int const& size);
double* filllMatrixBLn(int const& countOfVar, std::vector<double>sumCoordinateLn);
double** fillMatrixALn(int const& countOfVar, std::vector<double>sumCoordinateLn, int const& countNumber);

#endif