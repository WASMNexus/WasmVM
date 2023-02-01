// Copyright 2023 Luis Hsu. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "dump.hpp"
#include <Util.hpp>

#include <variant>

std::ostream& WasmVM::operator<<(std::ostream& stream, WasmImport& import){
    stream << "  (import " << import.module << " " << import.name;
    std::visit(overloaded {
        [&](index_t typeidx){
            stream << " (func (type " << typeidx << " ) )";
        },
        [&](WasmVM::TableType table){
            stream << " (table " << table.limits.min;
            if(table.limits.max){
                stream << " " << table.limits.max.value();
            }
            switch(table.reftype){
                case RefType::funcref :
                    stream << " funcref";
                break;
                case RefType::externref :
                    stream << " externref";
                break;
            }
            stream << " )";
        },
        [&](auto){
            // TODO:
        }
    }, import.desc);
    stream << " )" << std::endl;
    return stream;
}