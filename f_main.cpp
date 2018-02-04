#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#include "f_sdl.h"
#include "h_oscil.h"

uint32_t my_ticks;
// Speeds in mm/ms
CHarmonic_Oscillator oscillator(2000, 10, 6000);
int s_x = 0;
int s_y = 0;
int oscillator_callback(void* disp);

int main(int argc, char** argv) {
	SDL_Display disp(480, 640);
	disp.Clear(0x0000);
	my_ticks = disp.GetTicks();
	disp.AddCallBack(oscillator_callback, 0);
	disp.Flush();
	while(true) {
		disp.Clear(0x0000);
		disp.Block(s_x, s_y, 64, 64, 0xFF0000);
		disp.Update();
	}
}

int oscillator_callback(void* disp) {
	SDL_Display* my_disp = (SDL_Display*)disp;
	if(my_disp->GetTicks() - my_ticks > 10) {
		oscillator.Update();
		fprintf(stdout, "Kinetic Energy: %f, Oscillator potential: %f\n", oscillator.T, oscillator.V);
		s_x = 280+oscillator.x;
		s_y = 240;
		my_ticks = my_disp->GetTicks();
	}
	return CALLBACK_OK;
}
