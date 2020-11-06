/*  Copyright (C) 2012-2020 by László Nagy
/*  Copyright (C) 2012-2020 by László Nagy
    This file is part of Bear.

    Bear is a tool to generate compilation database for clang tooling.

    Bear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ToolLD.h"
// #include "ToolWrapper.h"
#include "ToolGcc.h"
#include <regex>

namespace cs::semantic {
    const char* ToolLD::name() const {
        return "LD"; // UNSURE: Confirm this is just for debugging/logging
    }

    bool ToolLD::recognize(const fs::path& program) const {
        //R"(^ld$)"
        static const auto pattern = std::regex(R"((.*)ld(.*))");
        std::cout << "Debug Flag. Vikrammm was here" << std::endl;
        std::cout << program.filename().c_str() << std::endl;
        std::cmatch m;
        if (std::regex_match(program.filename().c_str(), m, pattern))
        {
            std::cout <<  "Check passes" <<  std::endl;
        
        }
        else
        {
            std::cout << "Check failed" << std::endl;
        }
        
        
        return std::regex_match(program.filename().c_str(), m, pattern);
    }

    rust::Result<SemanticPtrs> ToolLD::compilations(const report::Command &command) const {
        return ToolGcc().compilations(command);
    }
}
