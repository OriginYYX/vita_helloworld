

#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/kernel/processmgr.h>

#include "utils.h"
#include "draw.h"

int main()
{
	init_video();
	/* Square variables */
	int speed = 1;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	/* Input variables */
	SceCtrlData pad;
	

	while (1) {
		clear_screen();

		/* Read controls and touchscreen */
		sceCtrlPeekBufferPositive(0, &pad, 1);

		if (pad.buttons & SCE_CTRL_START) {
			break;
		}

		font_draw_string(10, 10, RGBA8(0, 0, 255, 255), "PSVita demo by YYX!");
		font_draw_stringf(168, 118, RGBA8(0, 165, 0, 165), "%d ", a);
		font_draw_stringf(744, 118, RGBA8(0, 100, 0, 100), "%d ", b);
		font_draw_stringf(168, 409, RGBA8(0, 233, 0, 165), "%d ", c);
		font_draw_stringf(744, 409, RGBA8(0, 165, 0, 165), "%d ", d);
		/* Move the rectangle */
		if (pad.buttons & SCE_CTRL_UP) {
			a += speed;
			
			if (a > 9) a -= 10;
		} else 	if (pad.buttons & SCE_CTRL_DOWN) {
			b += speed;
			
			if (b > 9) b -= 10;
		}
		if (pad.buttons & SCE_CTRL_LEFT) {
			c += speed;
			
			if (c > 9) c -= 10;
		} else 	if (pad.buttons & SCE_CTRL_RIGHT) {
			d += speed;
			
			if (d > 9) d -= 10;
		}
		if (a==0&&b==5&&c==2&&d==4){
			font_draw_string(327, 342, RGBA8(0, 0, 255, 255), "What joy it is beholding me!");
		}
		

		
		draw_circle(SCREEN_W / 2, SCREEN_H / 2, 50, RGBA8(0,0,255,255));
		swap_buffers();
		sceDisplayWaitVblankStart();
	}
	end_video();
	sceKernelExitProcess(0);
	return 0;
}
