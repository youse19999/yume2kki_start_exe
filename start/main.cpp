#include <iostream>
#include <Windows.h>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
    char output_buffer[256];

    char output_buffer2[256];

    char output_buffer_printf[256];

    BOOL create_process_result;

    HRSRC txt_data_result = FindResourceA(0x0, MAKEINTRESOURCEA(0x67), "txt");

    HGLOBAL resources = LoadResource(0x0, txt_data_result);
    LPCSTR resource_pointer = (LPCSTR)LockResource(resources);

    HRSRC txt_data_result2 = FindResourceA(0x0, MAKEINTRESOURCEA(0x68), "txt");

    HGLOBAL resources2 = LoadResource(0x0, txt_data_result2);
    LPCSTR resource_pointer2 = (LPCSTR)LockResource(resources2);

    size_t maxed_uVar1 = strlen(resource_pointer);

    wsprintfA(output_buffer,"%s %s", resource_pointer, resource_pointer2);

    strcpy_s(output_buffer2, output_buffer);

    for (int i = 0; i < maxed_uVar1; i++)
    {
        if (output_buffer2[i] == '\\') {
            output_buffer2[i] = '\0';
            SetCurrentDirectoryA(output_buffer2);
        }
    }

    STARTUPINFOA start_up_info;
    PROCESS_INFORMATION process_information;

    ZeroMemory(&start_up_info, sizeof(start_up_info));
    ZeroMemory(&process_information, sizeof(process_information));

    process_information.dwThreadId = 0;

    create_process_result = CreateProcessA((LPCSTR)0x0, output_buffer, (LPSECURITY_ATTRIBUTES)0x0,
        (LPSECURITY_ATTRIBUTES)0x0, 0, 0x10, (LPVOID)0x0, (LPCSTR)0x0, 
        &start_up_info,&process_information);

    if (create_process_result == 0) {
        wsprintfA(output_buffer_printf, "ƒQ[ƒ€‚Ì‹N“®‚ÉŽ¸”s‚µ‚Ü‚µ‚½B\n%s‚ð’¼ÚŽÀs‚µ‚Ä‚­‚¾‚³‚¢B", resource_pointer);
        MessageBoxA((HWND)0x0, output_buffer_printf, "ƒQ[ƒ€‹N“®‚ÉŽ¸”s", 0);
    }

    return 0;
}