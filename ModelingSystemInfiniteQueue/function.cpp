#include "include.h"
double getRandom_uniformRealDistribution(double const& start, double const& end)
{
	std::mt19937 gen((std::random_device())());
	std::uniform_real_distribution<> nd(start, end);
	double res = std::abs(int((nd(gen)) * 100 + 0.5) / 100.0);
	return res;
}


int giveNumberPC(double const& prob1, double const& prob2)
{
	double random = getRandom_uniformRealDistribution(0.0, 1.0);
	if (random > 0 && random < prob1)
		return 1;
	else
	{
		if (random >= prob1 && random <= prob1 + prob2)
			return 2;
		else
			return 3;
	}
	return 0;
}