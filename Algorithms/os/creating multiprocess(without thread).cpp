#include <iostream>
#include <windows.h>  // for CreateProcess

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Allocate memory
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a new process
    if (!CreateProcess(
            NULL,   // No module name (use command line)
            "notepad", // Command line (path to executable)
            NULL,   // Process handle not inheritable
            NULL,   // Thread handle not inheritable
            FALSE,  // Set handle inheritance to FALSE
            0,      // No creation flags
            NULL,   // Use parent's environment block
            NULL,   // Use parent's starting directory 
            &si,    // Pointer to STARTUPINFO structure
            &pi)    // Pointer to PROCESS_INFORMATION structure
    ) {
        std::cerr << "Failed to create process" << std::endl;
        return 1;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    std::cout << "Process created successfully." << std::endl;

    return 0;
}
