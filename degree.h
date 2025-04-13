#pragma once

enum DegreeProgram {
	SECURITY,
	NETWORK,
	SOFTWARE
};

inline std::string degreeProgramToString(DegreeProgram degree) {
    switch (degree) {
    case DegreeProgram::SECURITY: return "SECURITY";
    case DegreeProgram::NETWORK: return "NETWORK";
    case DegreeProgram::SOFTWARE: return "SOFTWARE";
    default: return "UNKNOWN";
    }
}
