#ifndef WASMVM_PP_STRUCTURE_MODULE
#define WASMVM_PP_STRUCTURE_MODULE

#include <vector>
#include <string>
#include <Types.hpp>
#include <structures/WasmImport.hpp>
#include <structures/WasmFunc.hpp>
#include <structures/WasmExport.hpp>
#include <structures/WasmElem.hpp>
#include <structures/WasmData.hpp>

namespace WasmVM {

struct WasmModule {
    std::string id;
    std::vector<FuncType> types;
    std::vector<WasmImport> imports;
    std::vector<WasmFunc> funcs;
    std::vector<TableType> tables;
    std::vector<MemType> mems;
    std::vector<WasmExport> exports;
    std::vector<WasmElem> elems;
    std::vector<WasmData> datas;
};

}

#endif