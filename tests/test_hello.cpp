#include <cassert>
#include "../my_code/hello.h"

using namespace std;

int main() {
	int ret = sayHello();
    assert(ret == 1);
    return ret;
}
