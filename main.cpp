#include <Windows.h>
#include <tlhelp32.h>

#include <iostream>
#include <thread>
#include <array>


#include "enums.h"



struct Memory{
    DWORD pid = 0;
    HANDLE process_handle = nullptr;

    Memory() = default;
    ~Memory() {
        if(process_handle){
            CloseHandle(process_handle);
        }
    }

    explicit Memory(const char* process_name){
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(PROCESSENTRY32);

        const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        while (Process32Next(snapshot, &entry)){
            if(!strcmp(process_name, entry.szExeFile)){
                this->pid = entry.th32ProcessID;
                this->process_handle = OpenProcess(PROCESS_ALL_ACCESS, 0, this->pid);
                break;
            }
        }

        if (snapshot){
            CloseHandle(snapshot);
        }
    }

    uintptr_t get_module_address(const char* module_name) const{
        MODULEENTRY32 entry;
        entry.dwSize = sizeof(MODULEENTRY32);

        const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
        std::cout << pid << " - pid\n" << snapshot << " - snap\n";

        uintptr_t result = 0;

        while(Module32Next(snapshot, &entry)){
            //std::cout << "module_id: " <<  entry.th32ModuleID << " name: " << entry.szModule << "\n";
            if(!strcmp(module_name, entry.szModule)){
                result = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
                break;
            }

        }
        if (snapshot){
            CloseHandle(snapshot);
        }

        return result;
    }

    template<typename var>

    var read(uintptr_t address){
       var value;
       ReadProcessMemory(process_handle, reinterpret_cast<const void*>(address), &value, sizeof(var), nullptr);
       return value;
    }

    template <typename var>
    constexpr void write(const std::uintptr_t& address, const var& value) const noexcept {
        WriteProcessMemory(process_handle, reinterpret_cast<void*>(address), &value, sizeof(var), nullptr);
    }

};



inline void sleep_for_milliseconds(uint32_t milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


constexpr int get_weapon_paint(const short& item_definition ){
    switch(item_definition){
        case WEAPON_DEAGLE: return 711;
        case WEAPON_GLOCK: return 38;
        case WEAPON_AK47: return Case_Hardened;
        case WEAPON_AWP: return Dragon_Lore;
        case 61: return 653;
        default: return 0;
    }
}

int main(){

    Memory memory("csgo.exe");
    std::cout << "process id : " << memory.pid << "\n";

    const auto client = memory.get_module_address("client.dll");
    const auto engine = memory.get_module_address("engine.dll");


    std::cout << client << "\n";
    std::cout << engine;

    while(true){
        sleep_for_milliseconds(2);

        const auto& local_player = memory.read<uintptr_t>(client + offset::localPlayer);
        const auto& weapons = memory.read<std::array<unsigned long, 8>>(local_player + offset::weapons);

        for (const auto &handle : weapons){
            const auto& weapon = memory.read<std::uintptr_t>((client + offset::entityList + (handle & 0xFFF)* 0x10) - 0x10);

            if(!weapon) continue;

            if (const auto &paint = get_weapon_paint(memory.read<short>(weapon + offset::itemDefinitionIndex))){

                const bool should_update = memory.read<int32_t>(weapon + offset::fallbackPaintKit) != paint;

                memory.write<int32_t>(weapon + offset::m_iItemIDHigh, -1);

                memory.write<int32_t>(weapon + offset::fallbackPaintKit, paint);
                memory.write<float>(weapon + offset::m_flFallbackWear, 0.1f);


                if(should_update) {
                    memory.write<int32_t>(memory.read<uintptr_t>(engine + offset::clientState) + 0x174, -1);
                }
            }

        }

    }
}


//not mine
/*
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#include <cstdint>
#include <string_view>
#include <unistd.h>

struct Memory
{
    std::uintptr_t processId = 0;
    void* processHandle = nullptr;

    // Constructor that finds the process id
    // and opens a handle
    Memory(const std::string_view processName) noexcept
    {
        ::PROCESSENTRY32 entry = { };
        entry.dwSize = sizeof(::PROCESSENTRY32);

        const auto snapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        while (::Process32Next(snapShot, &entry))
        {
            if (!processName.compare(entry.szExeFile))
            {
                processId = entry.th32ProcessID;
                processHandle = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
                break;
            }
        }

        // Free handle
        if (snapShot)
            ::CloseHandle(snapShot);
    }

    // Destructor that frees the opened handle
    ~Memory()
    {
        if (processHandle)
            ::CloseHandle(processHandle);
    }

    // Returns the base address of a module by name
    const std::uintptr_t get_module_address(const std::string_view moduleName) const noexcept
    {
        ::MODULEENTRY32 entry = { };
        entry.dwSize = sizeof(::MODULEENTRY32);

        const auto snapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);

        std::uintptr_t result = 0;

        while (::Module32Next(snapShot, &entry))
        {
            if (!moduleName.compare(entry.szModule))
            {
                result = reinterpret_cast<std::uintptr_t>(entry.modBaseAddr);
                break;
            }
        }

        if (snapShot)
            ::CloseHandle(snapShot);

        return result;
    }

    // Read process memory
    template <typename T>
    constexpr const T Read(const std::uintptr_t& address) const noexcept
    {
        T value = { };
        ::ReadProcessMemory(processHandle, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
        return value;
    }

    // Write process memory
    template <typename T>
    constexpr void Write(const std::uintptr_t& address, const T& value) const noexcept
    {
        ::WriteProcessMemory(processHandle, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
    }
};*/
