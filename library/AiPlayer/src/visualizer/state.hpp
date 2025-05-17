#ifndef STATE
#define STATE

#include <atomic>

using namespace std;

namespace Visualizer {
typedef struct state {
	atomic<bool> pause{true};
	atomic<bool> preciseMode{true};
	state();
} state;
} // namespace Visualizer

#endif // STATE
