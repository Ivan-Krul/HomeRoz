#include "executor.h"
#include "tableinp.h"
#include "tablerend.h"

IInputModule* im;
IRenderModule* ir;

void AtExit() {
	delete im, ir;
}

int main() {
	im = new TableInp();
	ir = new TableRend();
	atexit(AtExit);
	Executor exe(im, ir);
	while (1) {
		exe.Input();
		exe.Update();
	}
}
