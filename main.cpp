//
// Created by mustafayanikdorugu on 17.09.2024.
//

#include <iostream>
#include <vector>

#include "Recorder.hpp"

int main () {

    drivers::Recorder recorder{std::string{"/home/mustafayanikdorugu/Desktop/outputfile.txt"}};
    std::vector<std::uint8_t> m_bit_stream{0xfe, 0xab, 0x01, 0x02};

    auto span = std::span{m_bit_stream.data(), m_bit_stream.size()};

    std::span<char> char_span(reinterpret_cast<char*>(span.data()), span.size());

    recorder.write(char_span);

    return 0;
}