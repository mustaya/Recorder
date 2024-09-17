//
// Created by mustafayanikdorugu on 17.09.2024.
//

#pragma once

#include <fstream>
#include <span>
#include <string>

namespace drivers {
    class Recorder {
    public:
        // Default Constructor.
        Recorder() = delete;

        // Default Copy Constructor.
        Recorder(const Recorder &) = delete;

        // Default Move Constructor.
        Recorder(Recorder &&) = delete;

        // Default Copy Assignment Operator.
        Recorder &operator=(const Recorder &) = delete;

        // Default Move Assignment Operator.
        Recorder &operator=(Recorder &&) = delete;

        // Default Destructor.
        ~Recorder() = default;

        explicit Recorder(std::string_view file_name) :
        m_file_ofstream(std::string{file_name}, std::ios::binary | std::ios::app),
        m_file_ifstream(std::string{file_name}) {}

        auto write(const std::span<char> buffer) -> void {

            if (open()) {

                m_file_ofstream.write(buffer.data(), static_cast<std::ptrdiff_t>(buffer.size()));
            }
        }

        auto read(std::span<char> buffer, const std::ptrdiff_t &size) -> void {

            if (open()) {

                m_file_ifstream.read(buffer.data(), size);
            }
        }

    private:

        auto open() -> bool {

            if (!m_file_ofstream.is_open()) {

                std::cout << "File can't open !" << std::endl;

                return false;
            }
            return true;
        }
        std::ofstream m_file_ofstream;
        std::ifstream m_file_ifstream;
    };
}