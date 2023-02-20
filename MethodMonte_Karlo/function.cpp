#include "include.h"

//Частотный тест
bool differLittle_MX_DX(double const& coord, double const& a)
{
	double M_X = a / 2.0;
	double D_X = (a * a) / 12.0;
	double standardDeviation = sqrt(D_X);
	return (coord > M_X - standardDeviation && coord < M_X + standardDeviation);
}

std::vector<double> getRandomPoint(bool const uniform, double const& start_rect,double const& end_rectangle, int const& countPoint)
{
	std::vector<double> vector;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(start_rect, end_rectangle);
	for (int i = 0; i < countPoint; i++)
	{
		double coord = int((double)dist(gen) * 100 + 0.5) / 100.0;
		if (uniform == true && differLittle_MX_DX(coord, end_rectangle) == true)
			vector.push_back(coord);
		else
			if (uniform == false)
				vector.push_back(coord);
			else
				i--;
	}
	return vector;
}

bool insideTringle(std::map<std::string, double> triangleVertexCoord, double x, double y)
{
	double tempa = (triangleVertexCoord["xa"] - x) * (triangleVertexCoord["yb"] - triangleVertexCoord["ya"]) -
		(triangleVertexCoord["xb"] - triangleVertexCoord["xa"]) * (triangleVertexCoord["ya"] - y);
	double tempb = (triangleVertexCoord["xb"] - x) * (triangleVertexCoord["yc"] - triangleVertexCoord["yb"])
		- (triangleVertexCoord["xc"] - triangleVertexCoord["xb"]) * (triangleVertexCoord["yb"] - y);
	double tempc = (triangleVertexCoord["xc"] - x) * (triangleVertexCoord["ya"] - triangleVertexCoord["yc"])
		- (triangleVertexCoord["xa"] - triangleVertexCoord["xc"]) * (triangleVertexCoord["yc"] - y);
	return (tempa < 0 && tempb < 0 && tempc < 0 || tempa > 0 && tempb > 0 && tempc > 0 || tempa == 0 && tempb == 0 && tempc == 0);
}

double functionTringle(int const& x, int const& numVar)
{
	if (x >= 0 && x < numVar)
		return int((double)(10.0 * x / numVar) * 100 + 0.5) / 100.0;
	else
		return int((double)(10.0 * ((x - 20.0) / (numVar - 20.0))) * 100 + 0.5) / 100.0;
}

double functionIntegral(double const& x, int const& numVar)
{
	return sqrt(11.0 - numVar * 2.0 * sin(x) * cos(x));
}

double step_h(const double a, const double b, unsigned int count_segment)
{
	return (b - a) / (count_segment);
}

std::vector<double> getXMonteCarlo(const double a, const double b, unsigned int count_segment)
{
	std::vector<double> vec_x;
	double h = step_h(a, b, count_segment);
	for (double x = a; x <= b; x += h)
		vec_x.push_back(x);
	return vec_x;
}

std::vector<double> getYMonteCarlo(std::vector<double> & x, int const& numVar)
{
	std::vector<double> y;
	for (int i = 0; i < x.size(); i++)
		y.push_back(functionIntegral(x[i], numVar));
	return y;
}

void getCoordinateMonteCarloIntegral(std::vector<double> & x, std::vector<double> & y, int const& numVar, const int& count_segment)
{
	x = getXMonteCarlo(0, 5, count_segment);
	y = getYMonteCarlo(x, numVar);
}


void findMax_MinFuncMonteCarlo(std::vector<double>& y, double& max, double& min)
{
	max = y[0];
	min = y[0];
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] > max) max = y[i];
		if (y[i] < min) min = y[i];
	}
}

double method_Sympsona(const double a, const double b, unsigned int count_segment,int const& numVar)
{
	double h = (b - a) / count_segment;
	double summa = functionIntegral(a,numVar) + functionIntegral(b,numVar);
	for (int i = 1; i <= count_segment; i++)
	{
		if (i % 2 == 0)
			summa += 2 * functionIntegral(a + i * h,numVar);
		else
			summa += 4 * functionIntegral(a + i * h,numVar);
	}

	summa *= h / 3;
	return summa;
}
