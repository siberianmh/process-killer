#include "nan.h"

#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>

#include <iostream>

using namespace Nan;
using namespace v8;

bool killProcessByName(const char *filename)
{
  HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
  PROCESSENTRY32 pEntry;
  pEntry.dwSize = sizeof(pEntry);
  BOOL hRes = Process32First(hSnapShot, &pEntry);
  bool success;
  while (hRes)
  {
    if (strcmp(pEntry.szExeFile, filename) == 0)
    {
      HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                    (DWORD)pEntry.th32ProcessID);
      if (hProcess != NULL)
      {
        success = TerminateProcess(hProcess, 9);
        CloseHandle(hProcess);
      }
    }
    hRes = Process32Next(hSnapShot, &pEntry);
  }
  CloseHandle(hSnapShot);
  if (success == true)
  {
    return true;
  }
  return false;
}

NAN_METHOD(KillProcessByName)
{
  auto argCount = info.Length();
  if (argCount != 1)
  {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsString())
  {
    Nan::ThrowTypeError("A string was expected for the first argument, but wasn't received.");
    return;
  }

  Nan::Utf8String subkeyArg(Nan::To<v8::String>(info[0]).ToLocalChecked());
  bool success = killProcessByName(std::string(*subkeyArg).c_str());
  info.GetReturnValue().Set(success);
}

NAN_MODULE_INIT(Init)
{
  Nan::SetMethod(target, "killProcessByName", KillProcessByName);
}

#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(registryNativeModule, Init)
#else
NODE_MODULE(registryNativeModule, Init);
#endif
