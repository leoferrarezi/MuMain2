#ifdef __ANDROID__

#include <imgui.h>

void ImGui_ImplOpenGL2_NewFrame()
{
}

void ImGui_ImplOpenGL2_RenderDrawData(ImDrawData* draw_data)
{
	(void)draw_data;
}

void ImGui_ImplWin32_NewFrame()
{
}

#endif // __ANDROID__
