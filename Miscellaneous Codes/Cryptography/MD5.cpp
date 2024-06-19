#include <iostream>

int main() {
    std::string data = "Hello World";
    std::string data_hex_digest;

    md5 hash;
    hash.update(data.begin(), data.end());
    hash.hex_digest(data_hex_digest);

    std::cout << data_hex_digest << std::endl;
}