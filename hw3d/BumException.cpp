#include "BumException.h"
#include <sstream>

BumException::BumException(int line, const char* file) noexcept
    : 
    line(line),
    file(file)
{}

const char* BumException::what() const noexcept
{
    std::ostringstream oss;
    oss << GetType() << std::endl
        << GetOriginString();
    whatBuffer = oss.str();
    return whatBuffer.c_str();
}

const char* BumException::GetType() const noexcept
{
    return "Bum Exception";
}

int BumException::GetLine() const noexcept
{
    return line;
}

const std::string& BumException::GetFile() const noexcept
{
    return file;
}

std::string BumException::GetOriginString() const noexcept
{
    std::ostringstream oss;
    oss << "[File] " << file << std::endl
        << "[Line] " << line;
    return oss.str();
}
