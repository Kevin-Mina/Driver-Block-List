// HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\CI\Config
// 0 para desativar
// 1 para ativar

#include <windows.h>
#include <iostream>

int main() {
    HKEY hKey;
    const char* subKey = "SYSTEM\\CurrentControlSet\\Control\\CI\\Config";
    const char* valueName = "VulnerableDriverBlocklistEnable"; // Defina o nome do valor conforme necessário

    LONG openResult = RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_SET_VALUE, &hKey);

    if (openResult == ERROR_SUCCESS) {
        DWORD data = 0; // Defina o valor que deseja, neste caso, 0
        DWORD dataSize = sizeof(data);

        LONG setResult = RegSetValueExA(hKey, valueName, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&data), dataSize);

        if (setResult == ERROR_SUCCESS) {
            std::cout << "Valor definido com sucesso para 0." << std::endl;
        }
        else {
            std::cerr << "Erro ao definir o valor: " << setResult << std::endl;
        }

        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Erro ao abrir a chave de registro: " << openResult << std::endl;
    }

    return 0;
}
