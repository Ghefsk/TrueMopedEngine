#include "Random.h"
#include <random>
#include <ctime>
namespace Random
{
	std::minstd_rand randomGen; 

	void Random::init()
	{
		randomGen.seed(std::time(nullptr));
	}

	int Random::intInRange(int low, int high)
	{
		std::uniform_int_distribution<int> distribution{ low, high };
		return distribution(randomGen);
	}

	float Random::floatInRange(float low, float high)
	{
		std::uniform_real_distribution<float> distribution{ low, high };
		return distribution(randomGen);
	}

}
 

