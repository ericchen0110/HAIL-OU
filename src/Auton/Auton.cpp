#include "Auton.hpp"

namespace Auton{

void init(){

}

void skills(){

}

void match(){

}

void test(){
    profiler->setTarget(Path::Test::path);
	profiler->waitUntilSettled();
	profiler->setTarget(-4_ft);
	profiler->waitUntilSettled();
	profiler->setTarget(90_deg);
	profiler->waitUntilSettled();
}

}